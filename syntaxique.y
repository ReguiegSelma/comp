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

%token <str> IDF <entier> INT_VAL <reel> FLOAT_VAL ENT_SIGNE REEL_SIGNE
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

DECLS: DEC DECLS | ;

DEC: TYPE DEUXPTS LISTE_OBJETS PV 
   | error PV
      {
          printf("Erreur Syntaxique: ligne %d de declaration\n", nb_lignes);
          nb_erreurs++;
          yyerrok;
      }
   ;

TYPE: INTEGER { strcpy(type_svg, "INTEGER"); }
    | FLOAT { strcpy(type_svg, "FLOAT"); }
    ;

LISTE_OBJETS: OBJET VIRG LISTE_OBJETS 
            | OBJET
            ;

OBJET: IDF { 
        if (rechercher($1) != -1) {printf("Erreur Semantique: Double declaration de %s ligne %d\n", $1, nb_lignes);
            nb_erreurs++;}
        else inserer($1, "IDF", type_svg, 0, 0); 
     }
     | IDF CROCHG INT_VAL CROCHD { 
         if($3 <= 0) {
            printf("Erreur Semantique: ligne %d: taille de tableau invalide pour '%s'\n", nb_lignes, $1);
            nb_erreurs++;
            yyerrok;
         } else if (rechercher($1) != -1){ printf("Erreur Semantique: Double declaration ligne %d\n", nb_lignes);
            nb_erreurs++;
            yyerrok;}
        else inserer($1, "TAB", type_svg, 0, $3);
       }
     | CONST IDF AFFECT VAL_CONST PV { 
        if (rechercher($2) != -1){ printf("Erreur Semantique: Double declaration ligne %d\n", nb_lignes);
        nb_erreurs++;
        yyerrok;
        }
        else inserer($2, "CONST", type_svg, 0, 0); }
     ;

VAL_CONST: INT_VAL | FLOAT_VAL | ENT_SIGNE | REEL_SIGNE

INSTS: INST INSTS | ;
INST: AFF | COND | BOUCLE | WRITE_I 
      | error PV
      {
          printf("Erreur Syntaxique: ligne %d , col %d instruction fausse \n", nb_lignes, nb_col);
          nb_erreurs++;
          yyerrok;
      }
    ;

AFF: IDF AFFECT expression PV  {
    int pos1 = rechercher($1);

    if (pos1 == -1) {
        printf("Erreur Semantique: %s non declare ligne %d\n", $1, nb_lignes);
        nb_erreurs++;
    } 
    else if (tab[pos1].cst == 1) {
        printf("Erreur Semantique: Modification d'une constante '%s'\n", $1);
        nb_erreurs++;
    } 
    else {
        int pos2 = rechercher($3);
        if (pos2 != -1) {
            if (strcmp(tab[pos1].type, tab[pos2].type) != 0) {
                printf("Erreur Semantique: incompatibilite de type ligne %d\n", nb_lignes);
                nb_erreurs++;
            }
        }
        quad("=", $3, "", $1);
    }
}
   | IDF AFFECT error PV {
        printf("Erreur Syntaxique: ligne %d , col %d expression invalide \n", nb_lignes, nb_col);
        nb_erreurs++;
        yyerrok;
     }
   | IDF CROCHG expression CROCHD AFFECT expression PV { 
    int p = rechercher($1);
    int p2 = rechercher($6);
    if(p == -1) {
        printf("Erreur Semantique: ligne %d: tableau '%s' non declare\n", nb_lignes, $1);
        nb_erreurs++;
        yyerrok;
    } else if ($3 <=tab[p].taille || $3 < 0) {
                printf("Erreur Semantique: ligne %d: index %d hors limites pour '%s' (taille %d)\n", nb_lignes, $3, $1, tab[p].taille);
                nb_erreurs++;
                yyerrok;
            }
        
        if(tab[p].tab == 0) {
            printf("Erreur Semantique: ligne %d: '%s' n'est pas un tableau\n", nb_lignes, $1);
            nb_erreurs++;
        } else if ( tab[p].cst == 0) {
        printf("Erreur Semantique: ligne %d: '%s' est une constante\n", nb_lignes, $1);
        nb_erreurs++;
        yyerrok;
        } else if (p2==-1 ){
        if (strcmp(tab[p].type, "INTEGER") == 0 && strcmp(tab[p2].type, "FLOAT") == 0) {
            printf("Erreur Semantique: ligne %d: incompatibilite de type sur '%s'\n", nb_lignes, $1);
            nb_erreurs++;
            yyerrok;
        }}
        else {
            char res[30];
            sprintf(res, "%s[%s]", $1, $3);
            quad("=", $6, "", res);

            if (p2 != -1) {
                tab[p].valeur = tab[p2].valeur;
            } else {
                tab[p].valeur = atof($6);
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
    if(strcmp($1, "empty")==0 || strcmp($3, "empty")==0)
        $$ = strdup("empty");
    else {
        $$ = new_temp();
        quad("+", $1, $3, $$);
    }
}
| expression MOINS terme {
    if(strcmp($1, "empty")==0 || strcmp($3, "empty")==0)
        $$ = strdup("empty");
    else {
        $$ = new_temp();
        quad("-", $1, $3, $$);
    }
}
| terme { $$ = $1; }
;

terme: terme MULT facteur {
    if(strcmp($1,"empty")==0 || strcmp($3,"empty")==0)
        $$ = strdup("empty");
    else {
        $$ = new_temp();
        quad("*", $1, $3, $$);
    }}
| terme DIV facteur {
    if(strcmp($3,"0")==0 || strcmp($3,"0.0")==0) {
        printf("Erreur Semantique: Division par zero ligne %d\n", nb_lignes);
        nb_erreurs++;
        $$ = strdup("empty");
    } else if(strcmp($1,"empty")==0 || strcmp($3,"empty")==0) {
        $$ = strdup("empty");
    } else {
        $$ = new_temp();
        quad("/", $1, $3, $$);
    }
}
| facteur { $$ = $1; }
;

facteur: IDF { 
            int p = rechercher($1);
            if (p == -1) {
             printf("Erreur Semantique: variable '%s' non declaree ligne %d\n", $1, nb_lignes);
             nb_erreurs++;
             $$ = strdup("empty");
            } 
            else {
                //tableau utilisé sans index
             if (tab[p].tab != 0) {
                 printf("Erreur Semantique: '%s' est un tableau, index requis ligne %d\n", $1, nb_lignes);
                 nb_erreurs++;
                }
             $$ = strdup($1);
            }
        }
       | IDF CROCHG expression CROCHD { 
            int p = rechercher($1);
            if (p== -1) {
                printf("Erreur Semantique: ligne %d: tableau '%s' non declare\n", nb_lignes, $1);
                nb_erreurs++; $$=strdup("empty");
            } else {
                if(tab[p].tab != 0) {
                    printf("Erreur Semantique: ligne %d: '%s' n'est pas un tableau\n", nb_lignes, $1);
                    nb_erreurs++;
                }
                if (strcmp(tab[p].type, "INTEGER") == 0){
                    if ($3 >= taille || $3 < 0) {
                        printf("Erreur Semantique: ligne %d: index %d hors limites pour '%s'\n", nb_lignes, $3, $1);
                        nb_erreurs++;
                    }
                }
                char* t = malloc(30);
                 sprintf(t, "%s[%s]", $1, $3);
                 $$ = t; 
            }
         }
       | IDF CROCHG error CROCHD {
            printf("Erreur Syntaxique: ligne %d , col %d index invalide \n", nb_lignes, nb_col);
            nb_erreurs++;
            yyerrok;
            $$ = strdup("empty");
         }
       | INT_VAL { $$ = $1; }
       | FLOAT_VAL { $$ = $1; }
       | PARG expression PARD { $$ = $2; }
       | PARG error PARD {
            printf("Erreur Syntaxique: ligne %d , col %d expression invalide \n", nb_lignes, nb_col);
            nb_erreurs++;
            yyerrok;
            $$ =strdup("empty");
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
           prochain_quad();
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
            prochain_quad(); 
            char* t = new_temp();
            quad("BG", $3, $7, t); 
            prochain_quad();
            quad("BZ", "", t, ""); 
        }
        ACCOLG INSTS ACCOLD
        {
            char* t2 = new_temp();
            quad("+", $3, $9, t2);
            quad("=", t2, "", $3);
            int cond = 0;
            int start = 0;
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
    if(rechercher($3) ==-1){ printf("Erreur Semantique: ligne %d, variable '%s' non declaree\n",nb_lignes, $3);nb_erreurs++;}
}




%%
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
