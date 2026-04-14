/*
 * ============================================================
 *  ANALYSEUR SYNTAXIQUE, SÉMANTIQUE + GÉNÉRATION CI — MiniAlgo
 *  Outil : Bison
 *  Version complète : vérifications + génération de quadruplets
 * ============================================================
 */

%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symtable.h"
#include "quadruplets.h"
#include "optimiseur.h"
#include "codegen86.h"

extern int  yylex(void);
extern int  line_num;
extern int  col_num;
extern char *yytext;

int nb_erreurs = 0;
TypeDonnee type_courant = TYPE_INCONNU;
static char nom_prog_global[MAX_ID_LEN + 1] = "prog";

void erreur_syntaxique(const char *msg) {
    fprintf(stderr, "Erreur Syntaxique : ligne %d , colonne %d , element \"%s\" -- %s\n",
            line_num, col_num, yytext, msg);
    nb_erreurs++;
}

void erreur_semantique(int ligne, const char *nom, const char *msg) {
    fprintf(stderr, "Erreur Semantique : ligne %d , element \"%s\" -- %s\n",
            ligne, nom, msg);
    nb_erreurs++;
}

void yyerror(const char *s) { erreur_syntaxique(s); }

Symbole *verifier_declare(const char *nom, int ligne) {
    Symbole *s = ts_rechercher(nom);
    if (!s) erreur_semantique(ligne, nom, "variable non declaree");
    return s;
}
%}

%union {
    int        ival;
    float      rval;
    char       sval[9];
    TypeDonnee tval;
    char       temp[64];
}

%token TOK_PROGRAM TOK_DECL TOK_ENDDECL TOK_BEGIN TOK_END
%token TOK_INTEGER TOK_FLOAT TOK_CONST
%token TOK_IF TOK_ELSE TOK_FOR TOK_WHILE
%token TOK_WRITE TOK_READ
%token TOK_GE TOK_LE TOK_EQ TOK_NE TOK_GT TOK_LT
%token TOK_AND TOK_OR TOK_NOT

%token <ival> TOK_ENTIER
%token <rval> TOK_REEL
%token <sval> TOK_IDF

%left  TOK_OR
%left  TOK_AND
%right TOK_NOT
%left  TOK_EQ TOK_NE
%left  TOK_GT TOK_GE TOK_LT TOK_LE
%left  '+' '-'
%left  '*' '/'
%right UMINUS

%type <tval> type_simple
%type <temp> expression
%type <temp> nom_programme
%type <temp> mark_ifz
%type <temp> partie_else_ci
%type <temp> boucle_for
%type <temp> boucle_while

%%

programme
    : TOK_PROGRAM nom_programme
      TOK_DECL declarations TOK_ENDDECL
      TOK_BEGIN instructions TOK_END
      {
          ci_emettre(Q_HALT, "-", "-", "-");
          ts_afficher();
          ci_afficher();

          if (nb_erreurs == 0) {
              opt_optimiser();
              printf("\n--- Code intermediaire apres optimisation ---\n");
              ci_afficher();

              char asm_file[64];
              snprintf(asm_file, sizeof(asm_file), "%s.asm", nom_prog_global);
              FILE *f = fopen(asm_file, "w");
              if (f) {
                  cg_generer(f, nom_prog_global);
                  fclose(f);
                  printf("[Generation] Fichier assembleur : %s\n\n", asm_file);
              }
              printf("Compilation reussie -- aucune erreur.\n");
          } else {
              printf("\nCompilation terminee avec %d erreur(s).\n", nb_erreurs);
          }
      }
    ;

nom_programme
    : TOK_IDF
      {
          strncpy(nom_prog_global, $1, MAX_ID_LEN);
          strncpy($$, $1, 63);
      }
    ;

declarations
    : declarations declaration
    | /* vide */
    ;

declaration
    : decl_variable
    | decl_tableau
    | decl_constante
    ;

decl_variable
    : type_simple ':' liste_idf ';'
    ;

decl_tableau
    : type_simple ':' TOK_IDF '[' TOK_ENTIER ']' ';'
      {
          if ($5 <= 0)
              erreur_semantique(line_num, $3, "taille de tableau invalide (> 0 requis)");
          else if (ts_inserer($3, CAT_TAB, $1, $5, line_num) == -1)
              erreur_semantique(line_num, $3, "double declaration");
      }
    ;

decl_constante
    : TOK_CONST TOK_IDF '=' TOK_ENTIER ';'
      {
          if (ts_inserer($2, CAT_CONST, TYPE_INTEGER, 1, line_num) == -1)
              erreur_semantique(line_num, $2, "double declaration");
          else {
              Symbole *s = ts_rechercher($2);
              if (s) { s->valeur.ival = $4; s->est_init = 1; }
          }
      }
    | TOK_CONST TOK_IDF '=' TOK_REEL ';'
      {
          if (ts_inserer($2, CAT_CONST, TYPE_FLOAT, 1, line_num) == -1)
              erreur_semantique(line_num, $2, "double declaration");
          else {
              Symbole *s = ts_rechercher($2);
              if (s) { s->valeur.rval = $4; s->est_init = 1; }
          }
      }
    ;

type_simple
    : TOK_INTEGER  { $$ = TYPE_INTEGER; type_courant = TYPE_INTEGER; }
    | TOK_FLOAT    { $$ = TYPE_FLOAT;   type_courant = TYPE_FLOAT;   }
    ;

liste_idf
    : liste_idf ',' TOK_IDF
      {
          if (ts_inserer($3, CAT_VAR, type_courant, 1, line_num) == -1)
              erreur_semantique(line_num, $3, "double declaration");
      }
    | TOK_IDF
      {
          if (ts_inserer($1, CAT_VAR, type_courant, 1, line_num) == -1)
              erreur_semantique(line_num, $1, "double declaration");
      }
    ;

instructions
    : instructions instruction
    | /* vide */
    ;

instruction
    : affectation
    | condition
    | boucle_for
    | boucle_while
    | instr_write
    | instr_read
    ;

/* ---- Affectation ---- */
affectation
    : TOK_IDF '=' expression ';'
      {
          Symbole *s = verifier_declare($1, line_num);
          if (s) {
              if (s->categorie == CAT_CONST)
                  erreur_semantique(line_num, $1, "constante non modifiable");
              else {
                  ci_emettre(Q_ASGN, $3, "-", $1);
                  s->est_init = 1;
              }
          }
      }
    | TOK_IDF '[' expression ']' '=' expression ';'
      {
          Symbole *s = verifier_declare($1, line_num);
          if (s) {
              if (s->categorie != CAT_TAB)
                  erreur_semantique(line_num, $1, "acces tableau sur scalaire");
              else
                  ci_emettre(Q_TASGN, $1, $3, $6);
          }
      }
    ;

/* ---- Condition IF/ELSE ----
 *
 * On utilise des actions milieu-règle pour émettre les sauts
 * AVANT de connaître la cible (technique du "backpatching").
 *
 * Plan des quadruplets générés :
 *   IFZ  cond  -  L_faux
 *   [bloc vrai]
 *   GOTO  -   -  L_fin
 *   LABEL -   -  L_faux
 *   [bloc faux]
 *   LABEL -   -  L_fin
 */
condition
    : TOK_IF '(' expression ')' mark_ifz '{' instructions '}' partie_else_ci
    ;

/* Action milieu-règle : émet IFZ et retourne l'index du quad pour patcher */
mark_ifz
    : /* vide */
      {
          char *lf = ci_nouveau_label();
          int idx = ci_emettre(Q_IFZ, "", "-", lf);
          /* Copier la cond depuis $<temp>-1 (= $3 du parent) n'est pas
             portable en ANSI Bison. On stocke dans un tableau statique. */
          /* Solution simple : on retransmet label_faux via $$ */
          snprintf($$, 63, "%d|%s", idx, lf);
      }
    ;

partie_else_ci
    : /* vide */
      {
          /* Lire info de mark_ifz = $<temp>5 de la règle condition */
          /* $<temp>-1 dans une règle imbriquée = $<temp>0 en pratique */
          /* On utilise ici la valeur de marque transmise via l'union   */
          char *lf_info = $<temp>-1;   /* valeur de mark_ifz */
          char *colon = strchr(lf_info, '|');
          if (colon) {
              int   idx   = atoi(lf_info);
              char *l_faux = colon + 1;
              /* Patcher l'arg1 du IFZ avec la cond correcte */
              /* (déjà mis au moment de l'émission)           */
              /* Émettre le LABEL faux (pas de ELSE → fin = faux) */
              ci_emettre(Q_LABEL, "-", "-", l_faux);
          }
      }
    | TOK_ELSE
      {
          /* Avant le bloc ELSE : émettre GOTO vers L_fin, puis LABEL L_faux */
          char *lf_info = $<temp>-2;   /* mark_ifz de la règle parente */
          char *colon = strchr(lf_info, '|');
          char *l_fin = ci_nouveau_label();
          snprintf($<temp>$, 63, "%s", l_fin);
          ci_emettre(Q_GOTO, "-", "-", l_fin);
          if (colon) {
              char *l_faux = colon + 1;
              ci_emettre(Q_LABEL, "-", "-", l_faux);
          }
      }
      '{' instructions '}'
      {
          /* Après le bloc ELSE : émettre LABEL L_fin */
          ci_emettre(Q_LABEL, "-", "-", $<temp>2);
      }
    ;

/* ---- Boucle FOR ----
 *
 * FOR (i : debut : pas : fin) { corps }
 *
 * Quadruplets :
 *   ASGN  debut  -    i
 *   LABEL -      -    L_debut
 *   LE    i      fin  T_cond
 *   IFZ   T_cond -    L_fin
 *   [corps]
 *   ADD   i      pas  T_inc
 *   ASGN  T_inc  -    i
 *   GOTO  -      -    L_debut
 *   LABEL -      -    L_fin
 */
boucle_for
    : TOK_FOR '(' TOK_IDF ':' expression ':' expression ':' expression ')'
      {
          /* $3=var  $5=debut  $7=pas  $9=fin */
          Symbole *sv = verifier_declare($3, line_num);
          if (sv) {
              ci_emettre(Q_ASGN, $5, "-", $3);
              char *l_debut = ci_nouveau_label();
              ci_emettre(Q_LABEL, "-", "-", l_debut);
              char *t_cond = ci_nouveau_temp();
              ci_emettre(Q_LE, $3, $9, t_cond);
              char *l_fin = ci_nouveau_label();
              ci_emettre(Q_IFZ, t_cond, "-", l_fin);
              /* Transporter les infos pour l'après-corps */
              snprintf($<temp>$, 63, "%s|%s|%s|%s", l_debut, l_fin, $3, $7);
          } else {
              strncpy($<temp>$, "?|?|?|?", 63);
          }
      }
      '{' instructions '}'
      {
          char info[64]; strncpy(info, $<temp>10, 63);
          char *l_debut = strtok(info, "|");
          char *l_fin   = strtok(NULL, "|");
          char *var_i   = strtok(NULL, "|");
          char *pas_s   = strtok(NULL, "|");
          if (l_debut && l_fin && var_i && pas_s) {
              char *t_inc = ci_nouveau_temp();
              ci_emettre(Q_ADD, var_i, pas_s, t_inc);
              ci_emettre(Q_ASGN, t_inc, "-", var_i);
              ci_emettre(Q_GOTO, "-", "-", l_debut);
              ci_emettre(Q_LABEL, "-", "-", l_fin);
          }
      }
    ;

/* ---- Boucle WHILE ----
 *
 * Quadruplets :
 *   LABEL  -      -    L_debut
 *   [eval cond]
 *   IFZ    cond   -    L_fin
 *   [corps]
 *   GOTO   -      -    L_debut
 *   LABEL  -      -    L_fin
 */
boucle_while
    : TOK_WHILE
      {
          char *l_debut = ci_nouveau_label();
          ci_emettre(Q_LABEL, "-", "-", l_debut);
          strncpy($<temp>$, l_debut, 63);
      }
      '(' expression ')'
      {
          char *l_fin = ci_nouveau_label();
          ci_emettre(Q_IFZ, $4, "-", l_fin);
          snprintf($<temp>$, 63, "%s|%s", $<temp>2, l_fin);
      }
      '{' instructions '}'
      {
          char info[64]; strncpy(info, $<temp>6, 63);
          char *l_debut = strtok(info, "|");
          char *l_fin   = strtok(NULL, "|");
          if (l_debut && l_fin) {
              ci_emettre(Q_GOTO, "-", "-", l_debut);
              ci_emettre(Q_LABEL, "-", "-", l_fin);
          }
      }
    ;

/* ---- WRITE ---- */
instr_write
    : TOK_WRITE '(' expression ')' ';'
      { ci_emettre(Q_WRITE, $3, "-", "-"); }
    ;

/* ---- READ ---- */
instr_read
    : TOK_READ '(' TOK_IDF ')' ';'
      {
          verifier_declare($3, line_num);
          ci_emettre(Q_READ, "-", "-", $3);
      }
    ;

/* ================================================================== */
/*  EXPRESSIONS                                                         */
/* ================================================================== */
expression
    : expression '+' expression
      { char *t = ci_nouveau_temp(); ci_emettre(Q_ADD, $1, $3, t); strncpy($$, t, 63); }
    | expression '-' expression
      { char *t = ci_nouveau_temp(); ci_emettre(Q_SUB, $1, $3, t); strncpy($$, t, 63); }
    | expression '*' expression
      { char *t = ci_nouveau_temp(); ci_emettre(Q_MUL, $1, $3, t); strncpy($$, t, 63); }
    | expression '/' expression
      {
          if (strcmp($3, "0") == 0 || strcmp($3, "0.0") == 0)
              erreur_semantique(line_num, "/", "division par zero (operande constant)");
          char *t = ci_nouveau_temp();
          ci_emettre(Q_DIV, $1, $3, t);
          strncpy($$, t, 63);
      }
    | '-' expression %prec UMINUS
      { char *t = ci_nouveau_temp(); ci_emettre(Q_NEG, $2, "-", t); strncpy($$, t, 63); }
    | '+' expression %prec UMINUS
      { strncpy($$, $2, 63); }
    | expression TOK_AND expression
      { char *t = ci_nouveau_temp(); ci_emettre(Q_MUL, $1, $3, t); strncpy($$, t, 63); }
    | expression TOK_OR expression
      {
          char *t1 = ci_nouveau_temp();
          char *t2 = ci_nouveau_temp();
          ci_emettre(Q_ADD, $1, $3, t1);
          ci_emettre(Q_GT,  t1, "0", t2);
          strncpy($$, t2, 63);
      }
    | TOK_NOT expression
      { char *t = ci_nouveau_temp(); ci_emettre(Q_EQ, $2, "0", t); strncpy($$, t, 63); }
    | expression TOK_GT expression
      { char *t = ci_nouveau_temp(); ci_emettre(Q_GT, $1, $3, t); strncpy($$, t, 63); }
    | expression TOK_GE expression
      { char *t = ci_nouveau_temp(); ci_emettre(Q_GE, $1, $3, t); strncpy($$, t, 63); }
    | expression TOK_LT expression
      { char *t = ci_nouveau_temp(); ci_emettre(Q_LT, $1, $3, t); strncpy($$, t, 63); }
    | expression TOK_LE expression
      { char *t = ci_nouveau_temp(); ci_emettre(Q_LE, $1, $3, t); strncpy($$, t, 63); }
    | expression TOK_EQ expression
      { char *t = ci_nouveau_temp(); ci_emettre(Q_EQ, $1, $3, t); strncpy($$, t, 63); }
    | expression TOK_NE expression
      { char *t = ci_nouveau_temp(); ci_emettre(Q_NE, $1, $3, t); strncpy($$, t, 63); }
    | TOK_IDF
      { verifier_declare($1, line_num); strncpy($$, $1, 63); }
    | TOK_IDF '[' expression ']'
      {
          Symbole *s = verifier_declare($1, line_num);
          if (s && s->categorie != CAT_TAB)
              erreur_semantique(line_num, $1, "acces tableau sur scalaire");
          char *t = ci_nouveau_temp();
          ci_emettre(Q_TLOAD, $1, $3, t);
          strncpy($$, t, 63);
      }
    | TOK_ENTIER
      { snprintf($$, 63, "%d", $1); }
    | TOK_REEL
      { snprintf($$, 63, "%g", $1); }
    | '(' expression ')'
      { strncpy($$, $2, 63); }
    ;

%%

int main(int argc, char *argv[]) {
    if (argc > 1) {
        FILE *f = fopen(argv[1], "r");
        if (!f) { perror(argv[1]); return EXIT_FAILURE; }
        extern FILE *yyin;
        yyin = f;
    }
    ts_init();
    ci_init();
    printf("=== Compilation MiniAlgo : %s ===\n\n",
           (argc > 1) ? argv[1] : "stdin");
    yyparse();
    ts_liberer();
    return (nb_erreurs == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
