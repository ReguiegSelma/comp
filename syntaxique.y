%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ts.h"
#include "quad.h"

extern int nb_lignes;
extern int nb_col;
extern char* yytext;
extern FILE *yyin; 
extern int nb_erreurs;

int fin_if, deb_else;
void yyerror(char *s);
int nb_erreurs = 0;
int yylex();
char type_svg[20];
char tmp_addr[10];
%}

%union {
    int entier;
    float reel;
    char* str;
}

%token <str> IDF <entier> INT_VAL <reel> FLOAT_VAL <entier> ENT_SIGNE <reel> REEL_SIGNE
%token PROGRAM DECL ENDDECL BEGIN_P END INTEGER FLOAT CONST IF ELSE FOR WHILE WRITE
%token PLUS MOINS MULT DIV AFFECT SUP INF EGAL SUPEG INFEG PV DEUXPTS VIRG PARG PARD ACCOLG ACCOLD CROCHG CROCHD
%token AND OR NOT
%type <str> expression terme facteur EXPR_LOG

%left PLUS MOINS
%left MULT DIV
%left OR
%left AND
%right NOT
%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE

%%
PROG: PROGRAM IDF DECL DECLS ENDDECL BEGIN_P INSTS END 
      {      
        if(nb_erreurs == 0){
            printf("Syntaxe Correcte\n");
            YYACCEPT;
            afficher_quads();
        }else{
            printf("\n Compilation echouee : %d erreur(p) detectee(p)\n", nb_erreurs);
        }
      }

DECLS: DEC DECLS 
     | DEC_CONST DECLS
     | /* vide */ 
     ;

DEC: TYPE DEUXPTS LISTE_OBJETS PV ;

TYPE: INTEGER { strcpy(type_svg, "INTEGER"); }
    | FLOAT   { strcpy(type_svg, "FLOAT"); }
    ;

LISTE_OBJETS: OBJET VIRG LISTE_OBJETS 
            | OBJET
            ;

OBJET: IDF { 
        inserer($1, "idf", type_svg, 0, 0); 
     }
     | IDF CROCHG INT_VAL CROCHD { 
        // VERIFICATION : La taille du tableau doit être > 0
        if ($3 <= 0) {
            printf("Erreur Semantique ligne %d: La taille du tableau '%s' doit etre positive (donnee: %d)\n", 
                    nb_lignes, $1, $3);
            nb_erreurs++;
            // On insère quand même pour éviter des erreurs "non déclaré" plus tard, 
            // ou on met une taille par défaut.
            inserer($1, "tab", type_svg, 0, 1); 
        } else {
            inserer($1, "tab", type_svg, 0, $3); 
        }
     }
     ;
DEC_CONST: CONST IDF AFFECT VAL_CONST PV ;        

VAL_CONST: INT_VAL    { inserer($<str>-1, "cst", "INTEGER", (float)$1, 0); }
         | FLOAT_VAL  { inserer($<str>-1, "cst", "FLOAT", $1, 0); }
         | ENT_SIGNE  { inserer($<str>-1, "cst", "INTEGER", (float)$1, 0); }
         | REEL_SIGNE { inserer($<str>-1, "cst", "FLOAT", $1, 0); }

INSTS: INST INSTS | ;
INST: AFF | COND | BOUCLE | WRITE_I | error PV { yyerrok; };
      

AFF: 
    /* --- Cas 1 : Affectation simple (x = expr) --- */
    IDF AFFECT expression PV {
        Symbole* s1 = rechercher($1);
        if (s1 == NULL) {
            printf("Erreur Semantique ligne %d: Variable '%s' non declaree\n", nb_lignes, $1);
            nb_erreurs++;
        } else if (strcmp(s1->code, "cst") == 0) {
            printf("Erreur Semantique ligne %d: Modification de la constante '%s'\n", nb_lignes, $1);
            nb_erreurs++;
        } else {
            // Vérification de type si l'expression est une variable
            Symbole* s3 = rechercher($3);
            if (s3 != NULL) {
                if (strcmp(s1->type, s3->type) != 0) {
                    printf("Erreur Semantique ligne %d: Incompatibilite de type entre %s et %s\n", nb_lignes, $1, $3);
                    nb_erreurs++;
                }
            }
            quad("=", $3, "", $1);
        }
    }
/* --- Cas 2 : Erreur sur l'expression simple --- */
    | IDF AFFECT error PV {
        printf("Erreur Syntaxique: ligne %d, col %d expression invalide\n", nb_lignes, nb_col);
        nb_erreurs++;
        yyerrok;
    }

/* --- Cas 3 : Affectation Tableau (t[i] = expr) --- */
    | IDF CROCHG expression CROCHD AFFECT expression PV { 
        Symbole* p = rechercher($1);     // Recherche du tableau
        Symbole* p_idx = rechercher($3); // Recherche si l'indice est une variable
        Symbole* p_src = rechercher($6); // Recherche si la source est une variable

        if(p == NULL) {
            printf("Erreur Semantique ligne %d: tableau '%s' non declare\n", nb_lignes, $1);
            nb_erreurs++;
        } 
        else {
            // 1. Vérifier si c'est bien un tableau
            if(strcmp(p->code, "tab") != 0) {
                printf("Erreur Semantique ligne %d: '%s' n'est pas un tableau\n", nb_lignes, $1);
                nb_erreurs++;
            } 
            
            // 2. Vérification de la borne (si l'indice est un nombre constant)
            // On convertit le texte de l'indice en entier pour comparer
            int val_index = atoi($3); 
            if (p_idx == NULL && (val_index >= p->taille || val_index < 0)) {
                printf("Erreur Semantique ligne %d: index %d hors limites pour '%s' (taille %d)\n", 
                        nb_lignes, val_index, $1, p->taille);
                nb_erreurs++;
            }

            // 3. Vérification des types
            if (p_src != NULL) {
                if (strcmp(p->type, p_src->type) != 0) {
                    printf("Erreur Semantique ligne %d: incompatibilite de type entre le tableau %s et %s\n", 
                            nb_lignes, $1, $6);
                    nb_erreurs++;
                }
            }

            // 4. Génération du quadruplet
            char res[40];
            sprintf(res, "%s[%s]", $1, $3);
            quad("=", $6, "", res);
        }
    }

    /* --- Cas 4 : Erreurs de rattrapage Tableau --- */
   | IDF CROCHG error CROCHD AFFECT expression PV {
        printf("Erreur Syntaxique: ligne %d , col %d index invalide \n", nb_lignes, nb_col);
        nb_erreurs++;
        yyerrok;
     }
   | IDF CROCHG expression CROCHD AFFECT error PV {
        printf("Erreur Syntaxique: ligne %d , col %d expression invalide \n", nb_lignes, nb_col);
        nb_erreurs++;
        yyerrok;
     }


expression: expression PLUS terme { 
                if(strcmp($1, "empty") == 0 || strcmp($3, "empty") == 0) {
                    $$ = strdup("empty");
                } else {
                    $$ = new_temp(); 
                    quad("+", $1, $3, $$); 
                }
            }
          | expression MOINS terme { 
                if(strcmp($1, "empty") == 0 || strcmp($3, "empty") == 0) {
                    $$ = strdup("empty");
                } else {
                    $$ = new_temp(); 
                    quad("-", $1, $3, $$); 
                }
            }
| terme { $$ = $1; }
;

terme: terme MULT facteur { 
            if(strcmp($1, "empty") == 0 || strcmp($3, "empty") == 0) {
                $$ = strdup("empty");
            } else {
                $$ = new_temp(); 
                quad("*", $1, $3, $$); 
            }
        }
| terme DIV facteur { 
            if(strcmp($1, "empty") == 0 || strcmp($3, "empty") == 0) {
                $$ = strdup("empty");
            } else {
                // Ta vérification de division par zéro
                if (strcmp($3, "0") == 0 || strcmp($3, "0.00") == 0) {
                    printf("Erreur Semantique ligne %d: Division par zero !\n", nb_lignes);
                    nb_erreurs++;
                    $$ = strdup("empty");
                } else {
                    $$ = new_temp(); 
                    quad("/", $1, $3, $$); 
                }
            }
        }
     | facteur { $$ = $1; };

facteur: 
    /* --- Identifiant simple (avec vérification si c'est un tableau) --- */
    IDF { 
        Symbole* s = rechercher($1);
        if (s == NULL) {
            printf("Erreur Semantique: variable '%s' non declaree ligne %d\n", $1, nb_lignes);
            nb_erreurs++;
            $$ = strdup("empty");
        } else {
            if (strcmp(s->code, "tab") == 0) {
                printf("Erreur Semantique: '%s' est un tableau, index requis ligne %d\n", $1, nb_lignes);
                nb_erreurs++;
                $$ = strdup("empty");
            } else {
                $$ = strdup($1);
            }
        }
    }
/* --- Accès Tableau (avec vérification de borne et type) --- */
    | IDF CROCHG expression CROCHD { 
        Symbole* s = rechercher($1);
        if (s == NULL) {
            printf("Erreur Semantique: ligne %d: tableau '%s' non declare\n", nb_lignes, $1);
            nb_erreurs++; 
            $$ = strdup("empty");
        } else {
            if (strcmp(s->code, "tab") != 0) {
                printf("Erreur Semantique: ligne %d: '%s' n'est pas un tableau\n", nb_lignes, $1);
                nb_erreurs++;
                $$ = strdup("empty");
            } else {
                // Si l'index est valide (pas empty), on vérifie la borne statiquement
                if (strcmp($3, "empty") != 0) {
                    // Si l'expression d'index est un nombre direct (pas une variable)
                    if (rechercher($3) == NULL) {
                        int val_index = atoi($3);
                        if (val_index >= s->taille || val_index < 0) {
                            printf("Erreur Semantique: ligne %d: index %d hors limites pour '%s' (taille %d)\n", 
                                    nb_lignes, val_index, $1, s->taille);
                            nb_erreurs++;
                        }
                    }
                }
                char* t = malloc(50);
                sprintf(t, "%s[%s]", $1, $3);
                $$ = t; 
            }
        }
    }
/* --- Rattrapage d'erreur sur l'index du tableau --- */
    | IDF CROCHG error CROCHD {
        printf("Erreur Syntaxique: ligne %d , col %d index invalide \n", nb_lignes, nb_col);
        nb_erreurs++;
        yyerrok;
        $$ = strdup("empty");
    }
    | INT_VAL { 
        char b[20]; sprintf(b, "%d", $1); $$ = strdup(b); 
    }
    | FLOAT_VAL { 
        char b[20]; sprintf(b, "%.2f", $1); $$ = strdup(b); 
    }

    | ENT_SIGNE { 
        char b[20]; sprintf(b, "%d", $1); $$ = strdup(b); 
    }
    | REEL_SIGNE { 
        char b[20]; sprintf(b, "%.2f", $1); $$ = strdup(b); 
    }

/* --- Expressions entre parenthèses --- */
    | PARG expression PARD { $$ = $2; }

    /* --- Rattrapage d'erreur sur parenthèses --- */
    | PARG error PARD {
        printf("Erreur Syntaxique: ligne %d , col %d expression invalide \n", nb_lignes, nb_col);
        nb_erreurs++;
        yyerrok;
        $$ = strdup("empty");
    }
    ;

COND: IF PARG EXPR_LOG PARD 
      { 
        fin_if = prochain_quad(); 
        quad("BZ", "", $3, ""); 
      }
      ACCOLG INSTS ACCOLD ELSE_PART {
          // On patche le BZ du début vers ici si la condition était fausse
          sprintf(tmp_addr, "%d", prochain_quad());
          modifier_quad(fin_if, 3, tmp_addr);
      }
| IF PARG error PARD
      {
        printf("Erreur Syntaxique: ligne %d , col %d condition invalide \n", nb_lignes, nb_col);
        nb_erreurs++;
        yyerrok;
      }
      ACCOLG INSTS ACCOLD ELSE_PART
    ;

ELSE_PART: ELSE 
           {
             deb_else = prochain_quad();
             quad("BR", "", "", ""); // Saut pour sauter le bloc ELSE si le IF était vrai
             
             // On patche le BZ du IF pour qu'il vienne ICI (début du else)
             sprintf(tmp_addr, "%d", prochain_quad());
             modifier_quad(fin_if, 3, tmp_addr);
             
             fin_if = deb_else; // Maintenant, fin_if pointe sur le BR pour le patcher plus tard
           }
           ACCOLG INSTS ACCOLD
         | %prec LOWER_THAN_ELSE 
         ;

BOUCLE: WHILE { push_loop_start(prochain_quad()); }
        PARG EXPR_LOG PARD 
        {
           int q_bz = prochain_quad();
           quad("BZ", "", $4, ""); 
           push_loop_cond(q_bz); // On mémorise l'adresse du BZ pour le patcher
        }
        ACCOLG INSTS ACCOLD
        {
           int cond = pop_loop_cond();
           int start = pop_loop_start();
           
           sprintf(tmp_addr, "%d", start);
           quad("BR", "", "", tmp_addr); // Retour au test de condition
           
           sprintf(tmp_addr, "%d", prochain_quad());
           modifier_quad(cond, 3, tmp_addr); // Sortie de boucle
        }
        | FOR PARG IDF DEUXPTS INT_VAL DEUXPTS INT_VAL DEUXPTS INT_VAL PARD 
        {
           // Initialisation : i = start_val
           char val_init[20]; sprintf(val_init, "%d", $5);
           quad("=", val_init, "", $3);
           
           push_loop_start(prochain_quad()); // Adresse du test de sortie
           
           char* t = new_temp();
           char val_limit[20]; sprintf(val_limit, "%d", $7);
           quad("BG", $3, val_limit, t); // Si i > limite
           
           int q_bz = prochain_quad();
           quad("BZ", "", t, ""); // Si BG est vrai (t=1), on sort
           push_loop_cond(q_bz);
        }
        ACCOLG INSTS ACCOLD
        {
           // Incrémentation : i = i + step
           char* t2 = new_temp();
           char val_step[20]; sprintf(val_step, "%d", $9);
           quad("+", $3, val_step, t2);
           quad("=", t2, "", $3);
           
           int cond = pop_loop_cond();
           int start = pop_loop_start();
           
           sprintf(tmp_addr, "%d", start);
           quad("BR", "", "", tmp_addr);
           
           sprintf(tmp_addr, "%d", prochain_quad());
           modifier_quad(cond, 3, tmp_addr);
        }

EXPR_LOG: EXPR_LOG OR EXPR_LOG  { $$ = new_temp(); quad("OR", $1, $3, $$); }
        | EXPR_LOG AND EXPR_LOG { $$ = new_temp(); quad("AND", $1, $3, $$); }
        | NOT EXPR_LOG          { $$ = new_temp(); quad("NOT", $2, "", $$); }
        | expression SUP expression   { $$ = new_temp(); quad("SUP", $1, $3, $$); }
        | expression INF expression   { $$ = new_temp(); quad("INF", $1, $3, $$); }
        | expression SUPEG expression { $$ = new_temp(); quad("SUPEG", $1, $3, $$); }
        | expression INFEG expression { $$ = new_temp(); quad("INFEG", $1, $3, $$); }
        | expression EGAL expression  { $$ = new_temp(); quad("EGAL", $1, $3, $$); }
        | PARG EXPR_LOG PARD    { $$ = $2; }
        ;


WRITE_I: WRITE PARG IDF PARD PV { 
    if(rechercher($3) == NULL) { 
        printf("Erreur Semantique ligne %d: variable '%s' non declaree\n", nb_lignes, $3);
        nb_erreurs++;
    }
}



%%

void yyerror(char *s) {
    printf("Erreur Syntaxique ligne %d, col %d : %s (proche de '%s')\n", 
            nb_lignes, nb_col, s, yytext);
}


int main(int argc, char *argv[]) {
    if (argc > 1) {
        FILE *f = fopen(argv[1], "r");
        if (f) { yyin = f; }
        else {
            printf("Impossible d'ouvrir le fichier !\n");
            exit(1);
        }
    }
    
    yyparse();

    afficher_ts_ids();
    afficher_ts_kw();
    afficher_ts_sep();
    
    return 0;
}
