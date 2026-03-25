/*
 * ============================================================
 *  GÉNÉRATION DE CODE 8086 — MiniAlgo
 *  Fichier : codegen86.c
 *
 *  Produit un fichier .ASM au format NASM, exécutable en mode
 *  DOS réel 16 bits (programme .COM, org 100h).
 *
 *  Conventions :
 *    INTEGER  → mot 16 bits (DW)
 *    FLOAT    → double mot 32 bits (DD), traité via le FPU x87
 *    Temporaires → alloués comme variables DW dans la section data
 *    Tableaux    → zone DW n fois / DD n fois
 *
 *  Registres réservés par le générateur :
 *    AX, BX  — calculs entiers
 *    SI      — index tableau
 *    ST(0)   — calcul flottant (coprocesseur FPU)
 *
 *  Appels DOS utilisés :
 *    INT 21h AH=09h  — afficher chaîne terminée par '$'
 *    INT 21h AH=0Ah  — lire ligne depuis stdin (READ entier)
 *    INT 21h AH=4Ch  — quitter le programme
 * ============================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "quadruplets.h"
#include "symtable.h"
#include "codegen86.h"

/* ------------------------------------------------------------------ */
/*  Macros d'écriture                                                   */
/* ------------------------------------------------------------------ */
#define EMIT(fmt, ...)  fprintf(out, fmt "\n", ##__VA_ARGS__)
#define EMIT0(s)        fprintf(out, "%s\n", (s))
#define COMMENT(msg)    fprintf(out, "    ; %s\n", (msg))
#define BLANK()         fprintf(out, "\n")

static FILE *out = NULL;

/* Compteur global pour les labels locaux de division (unicité) */
static int div_counter = 0;

/* ------------------------------------------------------------------ */
/*  Prédicats sur les opérandes                                         */
/* ------------------------------------------------------------------ */

static int est_litterale(const char *s) {
    if (!s || !*s) return 0;
    const char *p = s;
    if (*p == '-' || *p == '+') p++;
    if (!*p) return 0;
    int pts = 0;
    while (*p) {
        if (*p == '.')  { pts++; if (pts > 1) return 0; }
        else if (!isdigit((unsigned char)*p)) return 0;
        p++;
    }
    return 1;
}

static int est_float_lit(const char *s) {
    return est_litterale(s) && (strchr(s, '.') != NULL);
}

static int est_int_lit(const char *s) {
    return est_litterale(s) && (strchr(s, '.') == NULL);
}

/* Vrai si la variable ou le temporaire est de type FLOAT */
static int est_float_var(const char *nom) {
    if (!nom || !*nom || strcmp(nom, "-") == 0) return 0;
    Symbole *s = ts_rechercher(nom);
    return (s && s->type == TYPE_FLOAT);
}

static int operation_flottante(const char *a, const char *b) {
    return est_float_lit(a) || est_float_lit(b)
        || est_float_var(a) || est_float_var(b);
}

/* ------------------------------------------------------------------ */
/*  Chargement d'un opérande entier dans AX ou BX                      */
/* ------------------------------------------------------------------ */

static void charge_reg(const char *reg, const char *op) {
    if (est_int_lit(op))
        EMIT("    mov  %s, %s", reg, op);          /* imm */
    else
        EMIT("    mov  %s, word [%s]", reg, op);   /* mémoire */
}

/* ------------------------------------------------------------------ */
/*  Chargement FPU (ST0 ← opérande)                                    */
/* ------------------------------------------------------------------ */

static void fpu_charge(const char *op) {
    if (est_float_lit(op))
        /* Littéral flottant : on a généré une constante _flt_N dans DATA */
        EMIT("    fld  dword [%s]", op);
    else if (est_float_var(op))
        EMIT("    fld  dword [%s]", op);
    else if (est_int_lit(op))
        /* Imm entier → via registre puis pile FPU */
        EMIT("    fild word [_%s_imm]", op);   /* géré séparément si besoin */
    else
        EMIT("    fild word  [%s]", op);       /* entier mémoire → FPU */
}

static void fpu_sauve(const char *res) {
    if (est_float_var(res))
        EMIT("    fstp dword [%s]", res);
    else
        EMIT("    fistp word [%s]", res);  /* troncature FPU → entier */
}

/* ------------------------------------------------------------------ */
/*  Section DATA                                                         */
/*  On y déclare :                                                       */
/*    1. Toutes les variables (VAR, CONST, TAB)                          */
/*    2. Tous les temporaires (Tn) utilisés dans les quadruplets        */
/*    3. Constantes flottantes littérales rencontrées dans le code      */
/*    4. Buffers I/O                                                     */
/* ------------------------------------------------------------------ */

/* Collecte de tous les temporaires et littéraux flottants utilisés */
static void generer_section_data(void) {
    Quad *q  = ci_get_quads();
    int   nb = ci_get_nb();

    BLANK();
    EMIT0("; ============================================================");
    EMIT0("; Section DATA — variables, temporaires, buffers");
    EMIT0("; ============================================================");
    BLANK();

    /* --- 1. Variables déclarées dans le programme --- */
    EMIT0("    ; Variables du programme");
    for (int b = 0; b < HASH_SIZE; b++) {
        Symbole *s = ts_get_bucket(b);
        while (s) {
            if (s->categorie == CAT_VAR) {
                if (s->type == TYPE_FLOAT)
                    EMIT("%-12s dd  0.0        ; FLOAT", s->nom);
                else
                    EMIT("%-12s dw  0          ; INTEGER", s->nom);
            } else if (s->categorie == CAT_CONST) {
                if (s->type == TYPE_FLOAT)
                    EMIT("%-12s dd  %g         ; CONST FLOAT", s->nom, s->valeur.rval);
                else
                    EMIT("%-12s dw  %d         ; CONST INTEGER", s->nom, s->valeur.ival);
            } else if (s->categorie == CAT_TAB) {
                if (s->type == TYPE_FLOAT)
                    EMIT("%-12s times %d dd 0.0  ; FLOAT[%d]",
                         s->nom, s->taille, s->taille);
                else
                    EMIT("%-12s times %d dw 0    ; INTEGER[%d]",
                         s->nom, s->taille, s->taille);
            }
            s = s->suivant;
        }
    }

    /* --- 2. Temporaires utilisés dans les quadruplets --- */
    BLANK();
    EMIT0("    ; Temporaires générés par le compilateur");
    /* On collecte les noms uniques commençant par 'T' suivi de chiffres */
    char declared[MAX_TEMPS][16];
    int  ndecl = 0;

    for (int i = 0; i < nb; i++) {
        const char *ops[3] = { q[i].arg1.nom, q[i].arg2.nom, q[i].res.nom };
        for (int k = 0; k < 3; k++) {
            const char *nm = ops[k];
            if (!nm || nm[0] != 'T') continue;
            int all_dig = 1;
            for (int c = 1; nm[c]; c++)
                if (!isdigit((unsigned char)nm[c])) { all_dig = 0; break; }
            if (!all_dig) continue;
            /* Vérifier si déjà déclaré */
            int found = 0;
            for (int d = 0; d < ndecl; d++)
                if (strcmp(declared[d], nm) == 0) { found = 1; break; }
            if (!found) {
                strncpy(declared[ndecl++], nm, 15);
                EMIT("%-12s dw  0          ; temporaire", nm);
            }
        }
    }

    /* --- 3. Constantes flottantes littérales inline --- */
    /* Pour les flottants comme 3.14, on génère _flt_0 dd 3.14 etc. */
    /* (dans cette implémentation on suppose qu'ils ont été propagés  */
    /*  dans les variables avant le codegen — stub minimal ici)       */

    /* --- 4. Buffers I/O --- */
    BLANK();
    EMIT0("    ; Buffers entrée/sortie");
    EMIT0("_obuf        times 24 db '$' ; tampon affichage (sortie)");
    EMIT0("_ibuf        db  255         ; capacité buffer lecture");
    EMIT0("             db  0           ; longueur réelle (rempli par DOS)");
    EMIT0("             times 253 db 0  ; données lues");
    EMIT0("_newline     db  13, 10, '$' ; retour chariot + saut de ligne");
    BLANK();
}

/* ------------------------------------------------------------------ */
/*  Routines utilitaires en assembleur (incluses dans le .asm)         */
/* ------------------------------------------------------------------ */

/* _write_int : affiche l'entier 16 bits signé dans AX */
static void generer_routine_write_int(void) {
    EMIT0("; --------------------------------------------------------");
    EMIT0("; _write_int : affiche AX (entier signé 16 bits)");
    EMIT0(";   Altère : AX BX CX DX SI  (sauvegarde sur pile)");
    EMIT0("; --------------------------------------------------------");
    EMIT0("_write_int:");
    EMIT0("    push bx");
    EMIT0("    push cx");
    EMIT0("    push dx");
    EMIT0("    push si");
    EMIT0("    mov  si, _obuf");
    EMIT0("    cmp  ax, 0");
    EMIT0("    jge  .wi_pos");
    EMIT0("    mov  byte [si], '-'");
    EMIT0("    inc  si");
    EMIT0("    neg  ax");
    EMIT0(".wi_pos:");
    EMIT0("    xor  cx, cx");
    EMIT0("    mov  bx, 10");
    EMIT0(".wi_loop:");
    EMIT0("    xor  dx, dx");
    EMIT0("    div  bx");
    EMIT0("    push dx");
    EMIT0("    inc  cx");
    EMIT0("    test ax, ax");
    EMIT0("    jnz  .wi_loop");
    EMIT0(".wi_build:");
    EMIT0("    pop  dx");
    EMIT0("    add  dl, '0'");
    EMIT0("    mov  [si], dl");
    EMIT0("    inc  si");
    EMIT0("    loop .wi_build");
    EMIT0("    mov  byte [si], '$'");
    EMIT0("    mov  dx, _obuf");
    EMIT0("    mov  ah, 09h");
    EMIT0("    int  21h");
    EMIT0("    mov  dx, _newline");
    EMIT0("    mov  ah, 09h");
    EMIT0("    int  21h");
    EMIT0("    pop  si");
    EMIT0("    pop  dx");
    EMIT0("    pop  cx");
    EMIT0("    pop  bx");
    EMIT0("    ret");
    BLANK();
}

/* _read_int : lit un entier depuis stdin, retourne la valeur dans AX */
static void generer_routine_read_int(void) {
    EMIT0("; --------------------------------------------------------");
    EMIT0("; _read_int  : lit un entier signé 16 bits depuis stdin");
    EMIT0(";   Retour   : AX = valeur lue");
    EMIT0(";   Altère   : AX BX CX DX SI");
    EMIT0("; --------------------------------------------------------");
    EMIT0("_read_int:");
    EMIT0("    push bx");
    EMIT0("    push cx");
    EMIT0("    push dx");
    EMIT0("    push si");
    /* Lire la ligne avec INT 21h AH=0Ah */
    EMIT0("    mov  dx, _ibuf");
    EMIT0("    mov  ah, 0Ah");
    EMIT0("    int  21h");
    /* Convertir ASCII → entier */
    EMIT0("    mov  si, _ibuf + 2      ; début des données lues");
    EMIT0("    xor  ax, ax             ; accumulateur");
    EMIT0("    xor  cx, cx             ; signe (0=positif)");
    EMIT0("    cmp  byte [si], '-'");
    EMIT0("    jne  .ri_digit");
    EMIT0("    mov  cx, 1              ; signe négatif");
    EMIT0("    inc  si");
    EMIT0(".ri_digit:");
    EMIT0("    mov  bl, [si]");
    EMIT0("    cmp  bl, 13             ; CR = fin de saisie");
    EMIT0("    je   .ri_done");
    EMIT0("    cmp  bl, 10             ; LF");
    EMIT0("    je   .ri_done");
    EMIT0("    sub  bl, '0'");
    EMIT0("    jb   .ri_done           ; caractère invalide");
    EMIT0("    cmp  bl, 9");
    EMIT0("    ja   .ri_done");
    EMIT0("    mov  bh, 0");
    EMIT0("    mov  dx, 10");
    EMIT0("    push bx");
    EMIT0("    mul  dx                 ; AX = AX * 10");
    EMIT0("    pop  bx");
    EMIT0("    add  ax, bx");
    EMIT0("    inc  si");
    EMIT0("    jmp  .ri_digit");
    EMIT0(".ri_done:");
    EMIT0("    test cx, cx");
    EMIT0("    jz   .ri_end");
    EMIT0("    neg  ax                 ; appliquer signe négatif");
    EMIT0(".ri_end:");
    EMIT0("    pop  si");
    EMIT0("    pop  dx");
    EMIT0("    pop  cx");
    EMIT0("    pop  bx");
    EMIT0("    ret");
    BLANK();
}

/* ------------------------------------------------------------------ */
/*  Traduction d'un quadruplet en séquence d'instructions 8086         */
/* ------------------------------------------------------------------ */

static void traduire_quad(const Quad *q, int idx) {
    const char *a = q->arg1.nom;
    const char *b = q->arg2.nom;
    const char *r = q->res.nom;

    /* Commentaire lisible du quadruplet source */
    EMIT("    ; (%d) %-6s  %-10s %-10s %-10s",
         idx, 
         /* nom opcode */
         (q->op==Q_ADD)?"ADD":(q->op==Q_SUB)?"SUB":(q->op==Q_MUL)?"MUL":
         (q->op==Q_DIV)?"DIV":(q->op==Q_NEG)?"NEG":(q->op==Q_ASGN)?"ASGN":
         (q->op==Q_TASGN)?"TASGN":(q->op==Q_TLOAD)?"TLOAD":
         (q->op==Q_GT)?"GT":(q->op==Q_GE)?"GE":(q->op==Q_LT)?"LT":
         (q->op==Q_LE)?"LE":(q->op==Q_EQ)?"EQ":(q->op==Q_NE)?"NE":
         (q->op==Q_IFZ)?"IFZ":(q->op==Q_GOTO)?"GOTO":(q->op==Q_LABEL)?"LABEL":
         (q->op==Q_WRITE)?"WRITE":(q->op==Q_READ)?"READ":"HALT",
         a, b, r);

    int fp = operation_flottante(a, b)
          || operation_flottante(a, r)
          || est_float_var(r);

    switch (q->op) {

    /* ----------------------------------------------------------------
     * AFFECTATION :  res = arg1
     * ---------------------------------------------------------------- */
    case Q_ASGN:
        if (fp) {
            fpu_charge(a);
            fpu_sauve(r);
        } else {
            if (est_int_lit(a)) {
                EMIT("    mov  word [%s], %s", r, a);
            } else {
                charge_reg("ax", a);
                EMIT("    mov  word [%s], ax", r);
            }
        }
        break;

    /* ----------------------------------------------------------------
     * ADDITION :  res = arg1 + arg2
     * ---------------------------------------------------------------- */
    case Q_ADD:
        if (fp) {
            fpu_charge(a);
            fpu_charge(b);
            EMIT0("    faddp  st1, st0");
            fpu_sauve(r);
        } else {
            charge_reg("ax", a);
            charge_reg("bx", b);
            EMIT0("    add  ax, bx");
            EMIT("    mov  word [%s], ax", r);
        }
        break;

    /* ----------------------------------------------------------------
     * SOUSTRACTION :  res = arg1 - arg2
     * ---------------------------------------------------------------- */
    case Q_SUB:
        if (fp) {
            fpu_charge(a);
            fpu_charge(b);
            EMIT0("    fsubrp st1, st0");
            fpu_sauve(r);
        } else {
            charge_reg("ax", a);
            charge_reg("bx", b);
            EMIT0("    sub  ax, bx");
            EMIT("    mov  word [%s], ax", r);
        }
        break;

    /* ----------------------------------------------------------------
     * MULTIPLICATION :  res = arg1 * arg2
     * ---------------------------------------------------------------- */
    case Q_MUL:
        if (fp) {
            fpu_charge(a);
            fpu_charge(b);
            EMIT0("    fmulp  st1, st0");
            fpu_sauve(r);
        } else {
            charge_reg("ax", a);
            charge_reg("bx", b);
            EMIT0("    imul bx            ; DX:AX = AX * BX");
            EMIT("    mov  word [%s], ax  ; 16 bits bas du résultat", r);
        }
        break;

    /* ----------------------------------------------------------------
     * DIVISION :  res = arg1 / arg2
     * Inclut la vérification division par zéro à l'exécution
     * ---------------------------------------------------------------- */
    case Q_DIV: {
        int dc = div_counter++;
        if (fp) {
            fpu_charge(a);
            fpu_charge(b);
            EMIT0("    fdivrp st1, st0");
            fpu_sauve(r);
        } else {
            charge_reg("bx", b);
            /* Vérification division par zéro — arrêt contrôlé */
            EMIT0("    test bx, bx");
            EMIT("    jnz  .div_ok_%d", dc);
            EMIT0("    ; ERREUR RUNTIME : division par zero");
            EMIT0("    mov  dx, _err_divz");
            EMIT0("    mov  ah, 09h");
            EMIT0("    int  21h");
            EMIT0("    mov  ah, 4Ch");
            EMIT0("    mov  al, 1          ; code d'erreur 1");
            EMIT0("    int  21h");
            EMIT(".div_ok_%d:", dc);
            charge_reg("ax", a);
            EMIT0("    cwd                 ; étend AX signé → DX:AX");
            EMIT0("    idiv bx             ; AX = quotient, DX = reste");
            EMIT("    mov  word [%s], ax", r);
        }
        break;
    }

    /* ----------------------------------------------------------------
     * NÉGATION UNAIRE :  res = -arg1
     * ---------------------------------------------------------------- */
    case Q_NEG:
        if (fp) {
            fpu_charge(a);
            EMIT0("    fchs");
            fpu_sauve(r);
        } else {
            charge_reg("ax", a);
            EMIT0("    neg  ax");
            EMIT("    mov  word [%s], ax", r);
        }
        break;

    /* ----------------------------------------------------------------
     * LECTURE TABLEAU :  res = tab[index]
     * ---------------------------------------------------------------- */
    case Q_TLOAD: {
        Symbole *sym = ts_rechercher(a);
        int is_fp    = (sym && sym->type == TYPE_FLOAT);
        /* Calculer l'adresse : base + index * taille_elem */
        charge_reg("ax", b);           /* AX = index */
        EMIT0("    mov  si, ax");
        if (is_fp) {
            EMIT0("    shl  si, 2         ; index * 4 (FLOAT = DD)");
            EMIT("    fld  dword [%s + si]", a);
            fpu_sauve(r);
        } else {
            EMIT0("    shl  si, 1         ; index * 2 (INTEGER = DW)");
            EMIT("    mov  ax, word [%s + si]", a);
            EMIT("    mov  word [%s], ax", r);
        }
        break;
    }

    /* ----------------------------------------------------------------
     * ÉCRITURE TABLEAU :  tab[index] = valeur
     * arg1=tab, arg2=index, res=valeur
     * ---------------------------------------------------------------- */
    case Q_TASGN: {
        Symbole *sym = ts_rechercher(a);
        int is_fp    = (sym && sym->type == TYPE_FLOAT);
        charge_reg("bx", b);           /* BX = index */
        EMIT0("    mov  si, bx");
        if (is_fp) {
            EMIT0("    shl  si, 2");
            fpu_charge(r);
            EMIT("    fstp dword [%s + si]", a);
        } else {
            EMIT0("    shl  si, 1");
            charge_reg("ax", r);
            EMIT("    mov  word [%s + si], ax", a);
        }
        break;
    }

    /* ----------------------------------------------------------------
     * COMPARAISONS :  res = (arg1 op arg2)  →  0 ou 1
     * ---------------------------------------------------------------- */
    case Q_GT: case Q_GE: case Q_LT: case Q_LE:
    case Q_EQ: case Q_NE: {
        const char *jcc;
        switch (q->op) {
            case Q_GT: jcc = "jg";  break;
            case Q_GE: jcc = "jge"; break;
            case Q_LT: jcc = "jl";  break;
            case Q_LE: jcc = "jle"; break;
            case Q_EQ: jcc = "je";  break;
            case Q_NE: jcc = "jne"; break;
            default:   jcc = "jg";  break;
        }
        if (fp) {
            /* Comparaison flottante via FCOM */
            fpu_charge(a);
            fpu_charge(b);
            EMIT0("    fcompp");
            EMIT0("    fnstsw ax          ; statut FPU → AX");
            EMIT0("    sahf               ; AX → FLAGS");
            /* Pour la comparaison flottante, on inverse l'ordre
               car FCOM met a-b sur la pile : CF=1 si a<b */
        } else {
            charge_reg("ax", a);
            charge_reg("bx", b);
            EMIT0("    cmp  ax, bx");
        }
        EMIT("    %s  .cmp_t_%s_%d", jcc, r, idx);
        EMIT("    mov  word [%s], 0", r);
        EMIT("    jmp  .cmp_e_%s_%d", r, idx);
        EMIT(".cmp_t_%s_%d:", r, idx);
        EMIT("    mov  word [%s], 1", r);
        EMIT(".cmp_e_%s_%d:", r, idx);
        break;
    }

    /* ----------------------------------------------------------------
     * SAUT CONDITIONNEL :  si arg1 == 0  →  sauter vers res
     * ---------------------------------------------------------------- */
    case Q_IFZ:
        EMIT("    mov  ax, word [%s]", a);
        EMIT0("    test ax, ax");
        EMIT("    jz   %s", r);
        break;

    /* ----------------------------------------------------------------
     * SAUT INCONDITIONNEL
     * ---------------------------------------------------------------- */
    case Q_GOTO:
        EMIT("    jmp  %s", r);
        break;

    /* ----------------------------------------------------------------
     * ÉTIQUETTE (cible de saut)
     * ---------------------------------------------------------------- */
    case Q_LABEL:
        EMIT("%s:", r);
        break;

    /* ----------------------------------------------------------------
     * WRITE :  afficher arg1
     * ---------------------------------------------------------------- */
    case Q_WRITE: {
        Symbole *sv = ts_rechercher(a);
        if (sv && sv->type == TYPE_FLOAT) {
            /* Affichage flottant : troncature vers entier pour affichage */
            EMIT0("    ; Affichage FLOAT (troncature en entier)");
            EMIT("    fld  dword [%s]", a);
            EMIT0("    fistp word [_obuf]");
            EMIT0("    mov  ax, word [_obuf]");
        } else if (est_int_lit(a)) {
            EMIT("    mov  ax, %s", a);
        } else {
            EMIT("    mov  ax, word [%s]", a);
        }
        EMIT0("    call _write_int");
        break;
    }

    /* ----------------------------------------------------------------
     * READ :  lire depuis stdin dans res
     * ---------------------------------------------------------------- */
    case Q_READ:
        EMIT0("    call _read_int       ; résultat dans AX");
        EMIT("    mov  word [%s], ax", r);
        break;

    /* ----------------------------------------------------------------
     * HALT :  fin du programme
     * ---------------------------------------------------------------- */
    case Q_HALT:
        COMMENT("Fin du programme");
        EMIT0("    mov  ah, 4Ch");
        EMIT0("    mov  al, 0");
        EMIT0("    int  21h");
        break;

    default:
        EMIT("    ; ??? opcode non géré : %d", (int)q->op);
        break;
    }

    BLANK();
}

/* ================================================================== */
/*  Point d'entrée : cg_generer                                        */
/* ================================================================== */
void cg_generer(FILE *sortie, const char *nom_prog) {
    out = sortie;
    div_counter = 0;

    Quad *q  = ci_get_quads();
    int   nb = ci_get_nb();

    /* ---- En-tête du fichier ---- */
    EMIT0("; ============================================================");
    EMIT(";  Code assembleur 8086 — programme : %s", nom_prog);
    EMIT0(";  Généré par le compilateur MiniAlgo");
    EMIT0(";  Format : NASM, .COM DOS 16 bits (org 100h)");
    EMIT0(";");
    EMIT0(";  Pour assembler :");
    EMIT(";    nasm -f bin %s.asm -o %s.com", nom_prog, nom_prog);
    EMIT0("; ============================================================");
    BLANK();
    EMIT0("    bits 16");
    EMIT0("    org  100h");
    BLANK();
    EMIT0("    jmp  _start            ; sauter la section data");
    BLANK();

    /* ---- Section DATA ---- */
    generer_section_data();

    /* Message d'erreur division par zéro (dans DATA) */
    EMIT0("_err_divz    db  'ERREUR: division par zero', 13, 10, '$'");
    BLANK();

    /* ---- Routines utilitaires ---- */
    EMIT0("; ============================================================");
    EMIT0("; Routines utilitaires");
    EMIT0("; ============================================================");
    BLANK();
    generer_routine_write_int();
    generer_routine_read_int();

    /* ---- Corps du programme ---- */
    EMIT0("; ============================================================");
    EMIT(";  Corps du programme : %s", nom_prog);
    EMIT0("; ============================================================");
    EMIT0("_start:");
    EMIT0("    finit                  ; initialiser le coprocesseur FPU");
    BLANK();

    /* Traduction quadruplet par quadruplet */
    for (int i = 0; i < nb; i++)
        traduire_quad(&q[i], i);

    /* Sécurité : si HALT n'a pas été émis, on ajoute un retour DOS */
    if (nb == 0 || q[nb-1].op != Q_HALT) {
        BLANK();
        COMMENT("Retour DOS (sécurité)");
        EMIT0("    mov  ah, 4Ch");
        EMIT0("    mov  al, 0");
        EMIT0("    int  21h");
    }

    BLANK();
    EMIT0("; Fin du fichier assembleur");

    printf("[Génération 8086] %d quadruplet(s) traduit(s) → %s.asm\n",
           nb, nom_prog);
}
