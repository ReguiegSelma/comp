/*
 * ============================================================
 *  OPTIMISATION DU CODE INTERMÉDIAIRE — MiniAlgo
 *  Fichier : optimiseur.c
 * ============================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "quadruplets.h"
#include "optimiseur.h"

/* Marqueur "quadruplet supprimé" : on remplace l'opcode par une valeur sentinelle */
#define Q_NOP  ((OpCode)99)

/* Accès pratiques */
#define QUADS  ci_get_quads()
#define NB     ci_get_nb()

/* ---- Prédicat : chaîne représente-t-elle un entier ? ---- */
static int est_entier(const char *s) {
    if (!s || !*s) return 0;
    const char *p = s;
    if (*p == '-' || *p == '+') p++;
    if (!*p) return 0;
    while (*p) { if (!isdigit((unsigned char)*p)) return 0; p++; }
    return 1;
}

/* ---- Prédicat : chaîne représente-t-elle un nombre (entier ou réel) ? ---- */
static int est_nombre(const char *s) {
    if (!s || !*s) return 0;
    const char *p = s;
    int pts = 0;
    if (*p == '-' || *p == '+') p++;
    if (!*p) return 0;
    while (*p) {
        if (*p == '.') { pts++; if (pts > 1) return 0; }
        else if (!isdigit((unsigned char)*p)) return 0;
        p++;
    }
    return 1;
}

/* ---- Prédicat : temporaire (commence par T suivi de chiffres) ? ---- */
static int est_temp(const char *s) {
    if (!s || s[0] != 'T') return 0;
    for (int i = 1; s[i]; i++)
        if (!isdigit((unsigned char)s[i])) return 0;
    return s[1] != '\0';
}

/* ---- Copie d'opérande ---- */
static void op_set(Operande *o, const char *s) {
    strncpy(o->nom, s ? s : "-", 31);
    o->nom[31] = '\0';
}

/* ================================================================== */
/*  PASSE 1 : Pliage de constantes                                     */
/*  Si arg1 et arg2 sont des littéraux numériques, on calcule         */
/*  le résultat à la compilation et on remplace par Q_ASGN.           */
/* ================================================================== */
void opt_pliage_constantes(void) {
    Quad *q = QUADS;
    int   n = NB;
    int   nb_changes = 0;

    for (int i = 0; i < n; i++) {
        if (q[i].op == Q_NOP) continue;

        /* Seules les opérations arithmétiques et de comparaison sont pliables */
        if (q[i].op != Q_ADD && q[i].op != Q_SUB &&
            q[i].op != Q_MUL && q[i].op != Q_DIV &&
            q[i].op != Q_GT  && q[i].op != Q_GE  &&
            q[i].op != Q_LT  && q[i].op != Q_LE  &&
            q[i].op != Q_EQ  && q[i].op != Q_NE) continue;

        const char *a = q[i].arg1.nom;
        const char *b = q[i].arg2.nom;

        if (!est_nombre(a) || !est_nombre(b)) continue;

        double va = atof(a);
        double vb = atof(b);
        double vr = 0.0;
        int    ires = 0;  /* résultat entier pour comparaisons */
        int    est_cmp = 0;

        switch (q[i].op) {
            case Q_ADD: vr = va + vb; break;
            case Q_SUB: vr = va - vb; break;
            case Q_MUL: vr = va * vb; break;
            case Q_DIV:
                if (vb == 0.0) {
                    fprintf(stderr,
                        "Erreur Semantique : division par zero (constante) "
                        "au quadruplet %d\n", i);
                    continue;   /* ne pas plier, laisser le quad en place */
                }
                vr = va / vb;
                break;
            case Q_GT:  ires = (va >  vb); est_cmp = 1; break;
            case Q_GE:  ires = (va >= vb); est_cmp = 1; break;
            case Q_LT:  ires = (va <  vb); est_cmp = 1; break;
            case Q_LE:  ires = (va <= vb); est_cmp = 1; break;
            case Q_EQ:  ires = (va == vb); est_cmp = 1; break;
            case Q_NE:  ires = (va != vb); est_cmp = 1; break;
            default: break;
        }

        /* Réécrire le quadruplet en ASGN avec la valeur calculée */
        char buf[32];
        if (est_cmp)
            snprintf(buf, sizeof(buf), "%d", ires);
        else if (est_entier(a) && est_entier(b) && q[i].op != Q_DIV)
            snprintf(buf, sizeof(buf), "%d", (int)vr);
        else
            snprintf(buf, sizeof(buf), "%g", vr);

        q[i].op = Q_ASGN;
        op_set(&q[i].arg1, buf);
        op_set(&q[i].arg2, "-");
        nb_changes++;
    }

    printf("[Optimisation] Pliage de constantes : %d quadruplet(s) modifie(s)\n", nb_changes);
}

/* ================================================================== */
/*  PASSE 2 : Propagation de copies                                    */
/*  Si on trouve  ASGN X → Ti  puis plus loin  Ti  utilisé comme     */
/*  opérande (et Ti n'est pas réassigné entre-temps), on remplace     */
/*  Ti par X directement.                                              */
/* ================================================================== */
void opt_propagation_copies(void) {
    Quad *q = QUADS;
    int   n = NB;
    int   nb_changes = 0;

    for (int i = 0; i < n; i++) {
        if (q[i].op != Q_ASGN) continue;
        if (!est_temp(q[i].res.nom)) continue;  /* cible doit être un temporaire */

        const char *ti = q[i].res.nom;
        const char *src = q[i].arg1.nom;

        /* Chercher les utilisations de ti dans les quadruplets suivants */
        for (int j = i + 1; j < n; j++) {
            if (q[j].op == Q_NOP) continue;

            /* Si ti est réassigné → arrêter la propagation */
            if (strcmp(q[j].res.nom, ti) == 0) break;

            /* Remplacer les occurrences de ti dans arg1 et arg2 */
            if (strcmp(q[j].arg1.nom, ti) == 0) {
                op_set(&q[j].arg1, src);
                nb_changes++;
            }
            if (strcmp(q[j].arg2.nom, ti) == 0) {
                op_set(&q[j].arg2, src);
                nb_changes++;
            }
        }
    }

    printf("[Optimisation] Propagation de copies : %d occurrence(s) remplacee(s)\n", nb_changes);
}

/* ================================================================== */
/*  PASSE 3 : Élimination du code mort                                 */
/*  Un quadruplet ASGN est mort si son résultat (temporaire) n'est    */
/*  jamais lu dans la suite du code.                                   */
/* ================================================================== */
void opt_code_mort(void) {
    Quad *q = QUADS;
    int   n = NB;
    int   nb_suppr = 0;

    for (int i = 0; i < n; i++) {
        if (q[i].op != Q_ASGN) continue;
        if (!est_temp(q[i].res.nom)) continue;

        const char *ti = q[i].res.nom;
        int utilise = 0;

        for (int j = i + 1; j < n; j++) {
            if (q[j].op == Q_NOP) continue;
            /* Si ti est lu → pas mort */
            if (strcmp(q[j].arg1.nom, ti) == 0 ||
                strcmp(q[j].arg2.nom, ti) == 0) {
                utilise = 1; break;
            }
            /* Si ti est réécrit avant d'être lu → code mort */
            if (strcmp(q[j].res.nom, ti) == 0) break;
        }

        if (!utilise) {
            q[i].op = Q_NOP;
            nb_suppr++;
        }
    }

    printf("[Optimisation] Code mort : %d quadruplet(s) supprime(s)\n", nb_suppr);
}

/* ================================================================== */
/*  PASSE 4 : Élimination des sauts inutiles                          */
/*  GOTO Li suivi immédiatement de LABEL Li → GOTO supprimé           */
/* ================================================================== */
void opt_sauts_inutiles(void) {
    Quad *q = QUADS;
    int   n = NB;
    int   nb_suppr = 0;

    for (int i = 0; i < n - 1; i++) {
        if (q[i].op != Q_GOTO) continue;

        /* Chercher le prochain quad non-NOP */
        int j = i + 1;
        while (j < n && q[j].op == Q_NOP) j++;
        if (j >= n) continue;

        if (q[j].op == Q_LABEL &&
            strcmp(q[i].res.nom, q[j].res.nom) == 0) {
            q[i].op = Q_NOP;
            nb_suppr++;
        }
    }

    printf("[Optimisation] Sauts inutiles : %d quadruplet(s) supprime(s)\n", nb_suppr);
}

/* ================================================================== */
/*  PASSE 5 : Simplification algébrique                               */
/*  X + 0 → X,  X - 0 → X,  X * 1 → X,  X / 1 → X,  X * 0 → 0    */
/* ================================================================== */
void opt_simplification_algebrique(void) {
    Quad *q = QUADS;
    int   n = NB;
    int   nb_changes = 0;

    for (int i = 0; i < n; i++) {
        if (q[i].op == Q_NOP) continue;

        const char *a = q[i].arg1.nom;
        const char *b = q[i].arg2.nom;

        switch (q[i].op) {
            case Q_ADD:
                /* X + 0  →  X */
                if (strcmp(b, "0") == 0) {
                    q[i].op = Q_ASGN;
                    op_set(&q[i].arg2, "-");
                    nb_changes++;
                }
                /* 0 + X  →  X */
                else if (strcmp(a, "0") == 0) {
                    q[i].op = Q_ASGN;
                    op_set(&q[i].arg1, b);
                    op_set(&q[i].arg2, "-");
                    nb_changes++;
                }
                break;

            case Q_SUB:
                /* X - 0  →  X */
                if (strcmp(b, "0") == 0) {
                    q[i].op = Q_ASGN;
                    op_set(&q[i].arg2, "-");
                    nb_changes++;
                }
                break;

            case Q_MUL:
                /* X * 0  →  0 */
                if (strcmp(b, "0") == 0 || strcmp(a, "0") == 0) {
                    q[i].op = Q_ASGN;
                    op_set(&q[i].arg1, "0");
                    op_set(&q[i].arg2, "-");
                    nb_changes++;
                }
                /* X * 1  →  X */
                else if (strcmp(b, "1") == 0) {
                    q[i].op = Q_ASGN;
                    op_set(&q[i].arg2, "-");
                    nb_changes++;
                }
                else if (strcmp(a, "1") == 0) {
                    q[i].op = Q_ASGN;
                    op_set(&q[i].arg1, b);
                    op_set(&q[i].arg2, "-");
                    nb_changes++;
                }
                break;

            case Q_DIV:
                /* X / 1  →  X */
                if (strcmp(b, "1") == 0) {
                    q[i].op = Q_ASGN;
                    op_set(&q[i].arg2, "-");
                    nb_changes++;
                }
                break;

            default: break;
        }
    }

    printf("[Optimisation] Simplification algebrique : %d quadruplet(s) modifie(s)\n", nb_changes);
}

/* ================================================================== */
/*  Lancement de toutes les passes dans l'ordre                        */
/* ================================================================== */
void opt_optimiser(void) {
    printf("\n===== OPTIMISATION DU CODE INTERMÉDIAIRE =====\n");
    opt_simplification_algebrique();  /* avant le pliage pour nettoyer */
    opt_pliage_constantes();
    opt_propagation_copies();
    opt_code_mort();
    opt_sauts_inutiles();

    /* Compacter : retirer les Q_NOP de la liste */
    Quad *q = QUADS;
    int   n = NB;
    int   j = 0;
    for (int i = 0; i < n; i++)
        if (q[i].op != Q_NOP)
            q[j++] = q[i];

    /* Mettre à jour nb via une astuce : on expose un setter dans quadruplets.c */
    /* (voir ci_set_nb ci-dessous) */
    extern void ci_set_nb(int);
    ci_set_nb(j);

    int supprimes = n - j;
    printf("-----------------------------------------------\n");
    printf("Total : %d quadruplet(s) supprime(s)/modifie(s), "
           "%d quadruplet(s) restant(s)\n", supprimes, j);
    printf("===============================================\n\n");
}
