%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ts.h"
#include "quad.h"

int contient_point_decimal(char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '.') return 1;
    }
    return 0;
}

// Fonction pour vérifier si une chaîne est un entier non signe
int est_un_entier(char* s) {
    if (s == NULL || *s == '\0' || strcmp(s, "ID_ERR") == 0) return 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] < '0' || s[i] > '9') return 0;
    }
    return 1;
}

char tmp_addr[10];
int fin_if, deb_else;

#define LOOP_STACK_MAX 128
int loop_start[LOOP_STACK_MAX];
int loop_cond[LOOP_STACK_MAX];
int loop_top = -1;

void push_loop_start(int start) {
    if (loop_top + 1 >= LOOP_STACK_MAX) {
        printf("Erreur interne: pile de boucles pleine\n");
        return;
    }
    loop_top++;
    loop_start[loop_top] = start;
    loop_cond[loop_top] = -1;
}

void set_loop_cond(int cond) {
    if (loop_top < 0) return;
    loop_cond[loop_top] = cond;
}

int pop_loop_start() {
    if (loop_top < 0) return -1;
    return loop_start[loop_top];
}

int pop_loop_cond() {
    if (loop_top < 0) return -1;
    return loop_cond[loop_top--];
}

extern int nb_lignes;
extern int nb_col;
extern char* yytext;
extern FILE *yyin; 
extern int nb_erreurs;

int nb_erreurs = 0;
int yylex();
void yyerror(const char* s);
char type_svg[20];
%}

%union { 
    char* str;
    int ent; 
    float flt;
}

%token <str> IDF INT_VAL FLOAT_VAL
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
            afficher_quads();
        }else{
            printf("\nCompilation echouee : %d erreur(s) detectee(s)\n", nb_erreurs);
        }
      }

DECLS: DEC DECLS | ;

DEC: TYPE DEUXPTS LISTE_OBJETS PV 
   | CONST IDF AFFECT VAL_CONST PV { inserer($2, "CONST", 1, 0, 0); }
   | error PV
      {
          printf("Erreur Syntaxique: ligne %d de declaration\n", nb_lignes);
          nb_erreurs++;
          yyerrok;
      }
   ;

LISTE_OBJETS: OBJET VIRG LISTE_OBJETS 
            | OBJET
            ;

OBJET: IDF { 
         inserer($1, type_svg, 0, 0, 0); 
       }
     | IDF CROCHG INT_VAL CROCHD { 
         int t = atoi($3);
         if(t <= 0) {
            printf("Erreur Semantique: ligne %d: taille de tableau invalide pour '%s'\n", nb_lignes, $1);
            nb_erreurs++;
         } else inserer($1, type_svg, 0, 1, t); 
       }
     ;

VAL_CONST: INT_VAL | FLOAT_VAL | PARG MOINS INT_VAL PARD | PARG MOINS FLOAT_VAL PARD | PARG PLUS INT_VAL PARD | PARG PLUS FLOAT_VAL PARD ;

TYPE: INTEGER { strcpy(type_svg, "INTEGER"); } 
    | FLOAT { strcpy(type_svg, "FLOAT"); }

INSTS: INST INSTS | ;
INST: AFF | COND | BOUCLE | WRITE_I 
      | error PV
      {
          printf("Erreur Syntaxique: ligne %d , col %d instruction fausse \n", nb_lignes, nb_col);
          nb_erreurs++;
          yyerrok;
      }
    ;

AFF: IDF AFFECT expression PV { 
    Symbole* s = rechercher($1);
    if(s != NULL) {
        int ok = 1;
        if (strcmp($3, "ID_ERR") == 0) { ok = 0; }
        if(strcmp(s->type, "INTEGER") == 0 && contient_point_decimal($3)) {
            printf("Erreur Semantique: ligne %d: incompatibilite de type, '%s' est INTEGER\n", nb_lignes, $1);
            nb_erreurs++;
            ok = 0;
        }
        if(s->estConstante) {
            printf("Erreur Semantique: ligne %d, Modif constante '%s'\n", nb_lignes, $1);
            nb_erreurs++;
            ok = 0;
        }
        if (ok) {
            // Mémorisation de la valeur pour la propagation de constante
            if (est_un_entier($3)) {
                s->valeur = atof($3);
                s->a_une_valeur = 1;
            } else {
                Symbole* rhs = rechercher($3);
                if (rhs != NULL && rhs->a_une_valeur) {
                    s->valeur = rhs->valeur;
                    s->a_une_valeur = 1;
                } else {
                    s->a_une_valeur = 0; // valeur inconnue
                }
            }
            quad("=", $3, "", $1); 
        }
    } else {
        printf("Erreur Semantique: ligne %d '%s' non declare\n", nb_lignes, $1);
        nb_erreurs++;
    }
}
   | IDF AFFECT error PV {
        printf("Erreur Syntaxique: ligne %d , col %d expression invalide \n", nb_lignes, nb_col);
        nb_erreurs++;
        yyerrok;
     }
   | IDF CROCHG expression CROCHD AFFECT expression PV { 
    Symbole* s = rechercher($1);
    if(s == NULL) {
        printf("Erreur Semantique: ligne %d: tableau '%s' non declare\n", nb_lignes, $1);
        nb_erreurs++;
    } else if (strcmp($3, "ID_ERR") == 0 || strcmp($6, "ID_ERR") == 0) {}
    else {
        // Détection débordement tableau
        if (est_un_entier($3)) {
            int idx = atoi($3);
            if (idx >= s->taille || idx < 0) {
                printf("Erreur Semantique: ligne %d: index %d hors limites pour '%s' (taille %d)\n", nb_lignes, idx, $1, s->taille);
                nb_erreurs++;
            }
        }
        
        if(!s->estTableau) {
            printf("Erreur Semantique: ligne %d: '%s' n'est pas un tableau\n", nb_lignes, $1);
            nb_erreurs++;
        }
        if(s->estConstante) {
            printf("Erreur Semantique: ligne %d: '%s' est une constante\n", nb_lignes, $1);
            nb_erreurs++;
        }
        if(s->estTableau && !s->estConstante) {
            Symbole* s_val = rechercher($6);
            int est_float = (s_val != NULL) ? (strcmp(s_val->type, "FLOAT") == 0) : contient_point_decimal($6);

            if(strcmp(s->type, "INTEGER") == 0 && est_float) {
                printf("Erreur Semantique: ligne %d: incompatibilite de type sur '%s'\n", nb_lignes, $1);
                nb_erreurs++;
            } else {
                char res[30]; sprintf(res, "%s[%s]", $1, $3);
                quad("=", $6, "", res); 
                if (est_un_entier($6)) {
                    s->valeur = atof($6);
                    s->a_une_valeur = 1;
                } else {
                    Symbole* rhs = rechercher($6);
                    if (rhs != NULL && rhs->a_une_valeur) {
                        s->valeur = rhs->valeur;
                        s->a_une_valeur = 1;
                    } else {
                        s->a_une_valeur = 0;
                    }
                }
            }
        }
    }
}
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
            if(strcmp($1, "ID_ERR") == 0 || strcmp($3, "ID_ERR") == 0) $$ = "ID_ERR";
            else { $$ = new_temp(); quad("+", $1, $3, $$); }
          }
          | expression MOINS terme { 
            if(strcmp($1, "ID_ERR") == 0 || strcmp($3, "ID_ERR") == 0) $$ = "ID_ERR";
            else { $$ = new_temp(); quad("-", $1, $3, $$); }
          }
          | terme { $$ = $1; }

terme: terme MULT facteur { 
            if(strcmp($1, "ID_ERR") == 0 || strcmp($3, "ID_ERR") == 0) $$ = "ID_ERR";
            else { $$ = new_temp(); quad("*", $1, $3, $$); }
          }
     | terme DIV facteur { 
            int div_nulle = 0;
            if(strcmp($3, "0") == 0 || strcmp($3, "0.0") == 0) div_nulle = 1;
            else {
                Symbole* s_div = rechercher($3);
                if (s_div != NULL && s_div->a_une_valeur && s_div->valeur == 0) div_nulle = 1;
            }

            if(div_nulle) {
                printf("Erreur Semantique: ligne %d, Division par zero !\n", nb_lignes);
                nb_erreurs++; $$ = "ID_ERR"; 
            } else {
                $$ = new_temp(); quad("/", $1, $3, $$); 
            }
       }
     | facteur { $$ = $1; }

facteur: IDF { 
            Symbole* s = rechercher($1);
            if (s == NULL) {
                printf("Erreur Semantique: ligne %d: variable '%s' non declaree\n", nb_lignes, $1);
                nb_erreurs++; $$ = "ID_ERR"; 
            } else {
                if(s->estTableau) {
                    printf("Erreur Semantique: ligne %d: '%s' est un tableau, index requis\n", nb_lignes, $1);
                    nb_erreurs++;
                }
                $$ = $1; 
            }
         }
       | IDF CROCHG expression CROCHD { 
            Symbole* s = rechercher($1);
            if (s == NULL) {
                printf("Erreur Semantique: ligne %d: tableau '%s' non declare\n", nb_lignes, $1);
                nb_erreurs++; $$ = "ID_ERR"; 
            } else {
                if(!s->estTableau) {
                    printf("Erreur Semantique: ligne %d: '%s' n'est pas un tableau\n", nb_lignes, $1);
                    nb_erreurs++;
                }
                if (est_un_entier($3)) {
                    int idx = atoi($3);
                    if (idx >= s->taille || idx < 0) {
                        printf("Erreur Semantique: ligne %d: index %d hors limites pour '%s'\n", nb_lignes, idx, $1);
                        nb_erreurs++;
                    }
                }
                char* t = malloc(30); sprintf(t, "%s[%s]", $1, $3); $$ = t; 
            }
         }
       | IDF CROCHG error CROCHD {
            printf("Erreur Syntaxique: ligne %d , col %d index invalide \n", nb_lignes, nb_col);
            nb_erreurs++;
            yyerrok;
            $$ = "ID_ERR";
         }
       | INT_VAL { $$ = $1; }
       | FLOAT_VAL { $$ = $1; }
       | PARG expression PARD { $$ = $2; }
       | PARG error PARD {
            printf("Erreur Syntaxique: ligne %d , col %d expression invalide \n", nb_lignes, nb_col);
            nb_erreurs++;
            yyerrok;
            $$ = "ID_ERR";
         }
       | PARG MOINS INT_VAL PARD { char* t=malloc(25); sprintf(t,"-%s",$3); $$=t; }
       | PARG PLUS INT_VAL PARD { char* r=malloc(20); sprintf(r,"+%s",$3); $$=r; }  
       | PARG MOINS FLOAT_VAL PARD { char* temp = malloc(30); sprintf(temp, "-%s", $3); $$= temp; }
       | PARG PLUS FLOAT_VAL PARD { char* temp = malloc(30); sprintf(temp, "+%s", $3); $$ = temp; }
       ;





COND: IF PARG EXPR_LOG PARD 
      { 
        fin_if = prochain_quad(); 
        quad("BZ", "", $3, ""); 
      }
      ACCOLG INSTS ACCOLD ELSE_PART {
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

ELSE_PART: ELSE 
           {
             deb_else = prochain_quad();
             quad("BR", "", "", "");
             sprintf(tmp_addr, "%d", prochain_quad());
             modifier_quad(fin_if, 3, tmp_addr);
             fin_if = deb_else;
           }
           ACCOLG INSTS ACCOLD
         | %prec LOWER_THAN_ELSE 
         ;

BOUCLE: WHILE { push_loop_start(prochain_quad()); }
        PARG EXPR_LOG PARD 
        {
           set_loop_cond(prochain_quad());
           quad("BZ", "", $4, "");
        }
        ACCOLG INSTS ACCOLD
        {
           int cond = pop_loop_cond();
           int start = pop_loop_start();
           sprintf(tmp_addr, "%d", start);
           quad("BR", "", "", tmp_addr);
           sprintf(tmp_addr, "%d", prochain_quad());
           modifier_quad(cond, 3, tmp_addr);
        }
      | FOR PARG IDF DEUXPTS INT_VAL DEUXPTS INT_VAL DEUXPTS INT_VAL PARD 
        {
            quad("=", $5, "", $3);
            push_loop_start(prochain_quad()); 
            char* t = new_temp();
            quad("BG", $3, $7, t); 
            set_loop_cond(prochain_quad());
            quad("BZ", "", t, ""); 
        }
        ACCOLG INSTS ACCOLD
        {
            char* t2 = new_temp();
            quad("+", $3, $9, t2);
            quad("=", t2, "", $3);
            int cond = pop_loop_cond();
            int start = pop_loop_start();
            sprintf(tmp_addr, "%d", start);
            quad("BR", "", "", tmp_addr);
            sprintf(tmp_addr, "%d", prochain_quad());
            modifier_quad(cond, 3, tmp_addr);
        }

EXPR_LOG: EXPR_LOG OR EXPR_LOG { $$ = new_temp(); quad("OR", $1, $3, $$); }
        | EXPR_LOG AND EXPR_LOG { $$ = new_temp(); quad("AND", $1, $3, $$); }
        | NOT EXPR_LOG { $$ = new_temp(); quad("NOT", $2, "", $$); }
        | expression SUP expression { $$ = new_temp(); quad("SUP", $1, $3, $$); }
        | expression INF expression { $$ = new_temp(); quad("INF", $1, $3, $$); }
        | expression EGAL expression { $$ = new_temp(); quad("EGAL", $1, $3, $$); }
        | PARG EXPR_LOG PARD { $$ = $2; }
        ;



WRITE_I: WRITE PARG IDF PARD PV { 
    if(rechercher($3) == NULL) {printf("Erreur Semantique: ligne %d, variable '%s' non declaree\n",nb_lignes, $3);nb_erreurs++;}
}




%%
void yyerror(const char* s) { 
    printf("Erreur Syntaxique: ligne %d, col %d, pres de '%s'\n", nb_lignes, nb_col, yytext);nb_erreurs++; 
    }
int main(int argc, char *argv[]) {
    if (argc > 1) {
        FILE *f = fopen(argv[1], "r");
        if (f){ yyin = f;}
        else {
            printf("Can't open!\n");
            exit(1);
        }
    }
    yyparse();
    afficher_ts_ids();
    afficher_ts_kw();
    afficher_ts_sep();
    return 0;
}
