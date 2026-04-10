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

// Pour la gestion des sauts
char tmp_addr[10];
int fin_if, deb_else, deb_while, cond_while;

extern int nb_lignes;
extern int nb_col;
extern char* yytext;
extern FILE *yyin; 

int nb_erreurs = 0;
int yylex();
void yyerror(const char* s);
char type_svg[20];
%}

%union { 
    char* str;
    int inter; // Pour stocker les positions des quads
}

%expect 2
%token <str> IDF INT_VAL FLOAT_VAL
%token PROGRAM DECL ENDDECL BEGIN_P END INTEGER FLOAT CONST IF ELSE FOR WHILE WRITE
%token PLUS MOINS MULT DIV AFFECT SUP INF EGAL PV DEUXPTS VIRG PARG PARD ACCOLG ACCOLD CROCHG CROCHD
%type <str> expression terme facteur EXPR_LOG
%left PLUS MOINS
%left MULT DIV
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
         if(t <= 0) {printf("Erreur Semantique: ligne %d: taille de tableau invalide pour '%s'\n", nb_lignes, $1);
                        nb_erreurs++;
         }else inserer($1, type_svg, 0, 1, t); 
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
    int p = rechercher($1);
    if(p != -1) {
        if (strcmp($3, "ID_ERR") == 0) {}
        else if(strcmp(table[p].type, "INTEGER") == 0 && contient_point_decimal($3)) {
            printf("Erreur Semantique: ligne %d: incompatibilite de type, '%s' est INTEGER\n", nb_lignes, $1);
            nb_erreurs++;
        }
        else if(table[p].estConstante) {
            printf("Erreur Semantique: ligne %d, Modif constante '%s'\n", nb_lignes, $1);
            nb_erreurs++;
        }
        else {
            quad("=", $3, "", $1); 
        }
    } else {
        printf("Erreur Semantique: ligne %d '%s' non declare\n", nb_lignes, $1);
        nb_erreurs++;
    }
}
   | IDF CROCHG expression CROCHD AFFECT expression PV { 
    int p = rechercher($1);
    if(p == -1) {
        printf("Erreur Semantique: ligne %d: tableau '%s' non declare\n", nb_lignes, $1);
        nb_erreurs++;
    } else if (strcmp($3, "ID_ERR") == 0 || strcmp($6, "ID_ERR") == 0) {}
    else if(!table[p].estTableau) {
        printf("Erreur Semantique: ligne %d: '%s' n'est pas un tableau\n", nb_lignes, $1);
        nb_erreurs++;
    }
    else if(table[p].estConstante) {
        printf("Erreur Semantique: ligne %d: '%s' est une constante, pas un tableau\n", nb_lignes, $1);
        nb_erreurs++;
    } else {
        // --- DEBUT AJOUT VERIFICATION TYPE ---
        int p_val = rechercher($6);
        int est_float = 0;
        
        // Si c'est une variable, on check son type dans la TS
        if(p_val != -1) {
            if(strcmp(table[p_val].type, "FLOAT") == 0) est_float = 1;
        } 
        // Si c'est une valeur directe (constante), on check le point decimal
        else if(contient_point_decimal($6)) {
            est_float = 1;
        }

        if(strcmp(table[p].type, "INTEGER") == 0 && est_float) {
            printf("Erreur Semantique: ligne %d: incompatibilite de type, '%s' est INTEGER\n", nb_lignes, $1);
            nb_erreurs++;
        }else {
        char res[30]; 
        sprintf(res, "%s[%s]", $1, $3);
        quad("=", $6, "", res); 
    }
}
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
            if(strcmp($1, "ID_ERR") == 0 || strcmp($3, "ID_ERR") == 0) $$ = "ID_ERR";
            else if(strcmp($3, "0") == 0 || strcmp($3, "0.0") == 0) {
                printf("Erreur Semantique: ligne %d, Division par zero !\n", nb_lignes);
                nb_erreurs++;
                $$ = "ID_ERR"; 
            } else {
                $$ = new_temp(); quad("/", $1, $3, $$); 
            }
       }
     | facteur { $$ = $1; }

facteur: IDF { 
            if (rechercher($1) == -1) {
                printf("Erreur Semantique: ligne %d: variable '%s' non declaree\n", nb_lignes, $1);
                nb_erreurs++;
                $$ = "ID_ERR"; 
            } else {
                int p = rechercher($1);
                if(p != -1 && table[p].estTableau) 
                    printf("Erreur Semantique: '%s' est un tableau, index requis\n", $1);
                $$ = $1; 
            }
         }
       | IDF CROCHG expression CROCHD { 
            if (rechercher($1) == -1) {
                printf("Erreur Semantique: ligne %d: tableau '%s' non declare\n", nb_lignes, $1);
                nb_erreurs++;
                $$ = "ID_ERR"; 
            } else if (strcmp($3, "ID_ERR") == 0) {
                $$ = "ID_ERR";
            } else {
                int p = rechercher($1);
                if(p != -1 && !table[p].estTableau) 
                    printf("Erreur Semantique: ligne %d, '%s' n'est pas un tableau\n", nb_lignes, $1);
                    nb_erreurs++;
                char* t = malloc(30); sprintf(t, "%s[%s]", $1, $3); $$ = t; 
            }
         }
       | INT_VAL { $$ = $1; }
       | FLOAT_VAL { $$ = $1; }
       | PARG expression PARD { $$ = $2; }
       | PARG MOINS INT_VAL PARD { char* t=malloc(25); sprintf(t,"-%s",$3); $$=t; }
       | PARG PLUS INT_VAL PARD { char* r=malloc(20); sprintf(r,"+%s",$3); $$=r; }  
       | PARG MOINS FLOAT_VAL PARD { char* temp = malloc(30); sprintf(temp, "-%s", $3); $$= temp; }
       | PARG PLUS FLOAT_VAL PARD {  char* temp = malloc(30); sprintf(temp, "+%s", $3);$$ = temp;  }
       | MOINS INT_VAL { printf("Erreur Synt: ligne %d: parentheses manquantes\n", nb_lignes);nb_erreurs++; $$="ID_ERR"; }
       | PLUS INT_VAL { printf("Erreur Synt: ligne %d: parentheses manquantes\n", nb_lignes);nb_erreurs++; $$=$2; } 
       ;

/* --- GESTION DES CONDITIONS IF / ELSE --- */
COND: IF PARG EXPR_LOG PARD 
      { 
        fin_if = prochain_quad(); 
        quad("BZ", "", $3, ""); 
      }
      ACCOLG INSTS ACCOLD ELSE_PART {
          sprintf(tmp_addr, "%d", prochain_quad());
          modifier_quad(fin_if, 3, tmp_addr);
      }

ELSE_PART: ELSE 
           {
             deb_else = prochain_quad();
             quad("BR", "", "", "");
             sprintf(tmp_addr, "%d", prochain_quad());
             modifier_quad(fin_if, 3, tmp_addr);
             fin_if = deb_else; // On re-utilise fin_if pour le saut du else
           }
           ACCOLG INSTS ACCOLD
         | %prec LOWER_THAN_ELSE 
         ;

/* --- GESTION DES BOUCLES --- */
BOUCLE: WHILE { deb_while = prochain_quad(); }
        PARG EXPR_LOG PARD 
        {
           cond_while = prochain_quad();
           quad("BZ", "", $4, "");
        }
        ACCOLG INSTS ACCOLD
        {
           sprintf(tmp_addr, "%d", deb_while);
           quad("BR", "", "", tmp_addr);
           sprintf(tmp_addr, "%d", prochain_quad());
           modifier_quad(cond_while, 3, tmp_addr);
        }
      | FOR PARG IDF DEUXPTS INT_VAL DEUXPTS INT_VAL DEUXPTS INT_VAL PARD 
        {
            // Initialisation i = debut
            quad("=", $5, "", $3);
            deb_while = prochain_quad(); // Debut du test
            char* t = new_temp();
            quad("BG", $3, $7, t); // i > fin ?
            cond_while = prochain_quad();
            quad("BZ", "", t, ""); 
        }
        ACCOLG INSTS ACCOLD
        {
            // i = i + pas
            char* t2 = new_temp();
            quad("+", $3, $9, t2);
            quad("=", t2, "", $3);
            sprintf(tmp_addr, "%d", deb_while);
            quad("BR", "", "", tmp_addr);
            sprintf(tmp_addr, "%d", prochain_quad());
            modifier_quad(cond_while, 3, tmp_addr);
        }

EXPR_LOG: expression SUP expression { $$ = new_temp(); quad("SUP", $1, $3, $$); }
        | expression INF expression { $$ = new_temp(); quad("INF", $1, $3, $$); }
        | expression EGAL expression { $$ = new_temp(); quad("EGAL", $1, $3, $$); }
        ;

WRITE_I: WRITE PARG IDF PARD PV { 
    if(rechercher($3) == -1) {printf("Erreur Semantique: ligne %d, col %d, variable '%s' non declaree\n",nb_lignes, nb_col, $3);nb_erreurs++;}
}

%%
void yyerror(const char* s) { printf("Erreur Syntaxique: ligne %d, col %d, pres de '%s'\n", nb_lignes, nb_col, yytext);nb_erreurs++; }
int main(int argc, char *argv[]) {
    if (argc > 1) {
        FILE *f = fopen(argv[1], "r");
        if (f == NULL) {
            printf("impossible d'ouvrir %s\n", argv[1]);
            return 1;
        }
        yyin = f;
    }

    yyparse();
    return 0;
}