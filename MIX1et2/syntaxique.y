%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ts.h"
#include "quad.h"

extern int nb_lignes;
extern int nb_erreurs;
extern char* yytext;
extern FILE *yyin;

int yylex();
void yyerror(const char* s);

char type_svg[20];
char save_type[20];

// Variables pour les quadruplets
int fin_if = 0;
int deb_else = 0;
int loop_start = 0;
int loop_cond = 0;
char tmp_addr[10];
%}

%union { 
    char* str;
    int integer;
    float float_val;
}

%token <str> IDF
%token <integer> INT_VAL
%token <float_val> FLOAT_VAL

%token PROGRAM DECL ENDDECL BEGIN_P END INTEGER FLOAT CONST IF ELSE FOR WHILE WRITE
%token PLUS MOINS MULT DIV AFFECT SUP INF EGAL PV DEUXPTS VIRG PARG PARD ACCOLG ACCOLD CROCHG CROCHD
%token AND OR NOT

%type <str> expression terme facteur EXPR_LOG
%type <float_val> VAL_CONST

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
            printf("\nCompilation echouee : %d erreur(s)\n", nb_erreurs);
        }
      }

DECLS: DEC DECLS | ;

DEC: TYPE DEUXPTS LISTE_OBJETS PV 
   | CONST IDF AFFECT VAL_CONST PV 
     { 
        insert_idf_cst($2, "CONST", type_svg, $4, 0, 0, 1);
     }
   | error PV
      {
          printf("Erreur Syntaxique: ligne %d\n", nb_lignes);
          nb_erreurs++;
          yyerrok;
      }
   ;

LISTE_OBJETS: OBJET VIRG LISTE_OBJETS | OBJET ;

OBJET: IDF { insert_idf_cst($1, "VAR", type_svg, 0, 0, 0, 0); }
     | IDF CROCHG INT_VAL CROCHD { insert_idf_cst($1, "TAB", type_svg, 0, 1, $3, 0); }
     ;

VAL_CONST: INT_VAL { $$ = (float)$1; } 
         | FLOAT_VAL { $$ = $1; }
         ;

TYPE: INTEGER { strcpy(type_svg, "INTEGER"); } 
    | FLOAT { strcpy(type_svg, "FLOAT"); }
    ;

INSTS: INST INSTS | ;

INST: AFF PV 
    | COND 
    | BOUCLE 
    | WRITE_I PV
    | error PV
      {
          printf("Erreur Syntaxique: ligne %d\n", nb_lignes);
          nb_erreurs++;
          yyerrok;
      }
    ;

AFF: IDF AFFECT expression { 
    int idx = search_idf_cst($1);
    if(idx == -1) {
        printf("Erreur Semantique: ligne %d '%s' non declare\n", nb_lignes, $1);
        nb_erreurs++;
    } else if(ts_idf_cst[idx].estConstante) {
        printf("Erreur Semantique: ligne %d, Modif constante '%s'\n", nb_lignes, $1);
        nb_erreurs++;
    } else {
        quad("=", $3, "", $1);
    }
}
   | IDF CROCHG expression CROCHD AFFECT expression {
    int idx = search_idf_cst($1);
    if(idx == -1) {
        printf("Erreur Semantique: ligne %d: tableau '%s' non declare\n", nb_lignes, $1);
        nb_erreurs++;
    } else if(!ts_idf_cst[idx].estTableau) {
        printf("Erreur Semantique: ligne %d: '%s' n'est pas un tableau\n", nb_lignes, $1);
        nb_erreurs++;
    } else {
        char res[30]; 
        sprintf(res, "%s[%s]", $1, $3);
        quad("=", $6, "", res);
    }
   }
   ;

expression: expression PLUS terme { $$ = new_temp(); quad("+", $1, $3, $$); }
          | expression MOINS terme { $$ = new_temp(); quad("-", $1, $3, $$); }
          | terme { $$ = $1; }
          ;

terme: terme MULT facteur { $$ = new_temp(); quad("*", $1, $3, $$); }
     | terme DIV facteur { 
        $$ = new_temp(); 
        quad("/", $1, $3, $$);
       }
     | facteur { $$ = $1; }
     ;

facteur: IDF { 
            int idx = search_idf_cst($1);
            if(idx == -1) {
                printf("Erreur Semantique: ligne %d: variable '%s' non declaree\n", nb_lignes, $1);
                nb_erreurs++;
            }
            $$ = $1; 
         }
       | IDF CROCHG expression CROCHD { 
            char* t = malloc(30); 
            sprintf(t, "%s[%s]", $1, $3); 
            $$ = t; 
         }
       | INT_VAL { char* t=malloc(20); sprintf(t,"%d",$1); $$=t; }
       | FLOAT_VAL { char* t=malloc(20); sprintf(t,"%f",$1); $$=t; }
       | PARG expression PARD { $$ = $2; }
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
    ;

ELSE_PART: ELSE 
           {
             deb_else = prochain_quad();
             quad("BR", "", "", "");
             sprintf(tmp_addr, "%d", prochain_quad());
             modifier_quad(fin_if, 3, tmp_addr);
           }
           ACCOLG INSTS ACCOLD
         | %prec LOWER_THAN_ELSE 
         ;

BOUCLE: WHILE 
        { 
            loop_start = prochain_quad(); 
        }
        PARG EXPR_LOG PARD 
        {
            loop_cond = prochain_quad();
            quad("BZ", "", $4, "");
        }
        ACCOLG INSTS ACCOLD
        {
            sprintf(tmp_addr, "%d", loop_start);
            quad("BR", "", "", tmp_addr);
            sprintf(tmp_addr, "%d", prochain_quad());
            modifier_quad(loop_cond, 3, tmp_addr);
        }
      | FOR PARG IDF DEUXPTS INT_VAL DEUXPTS INT_VAL DEUXPTS INT_VAL PARD
        {
            // Initialisation: $3 = variable, $5 = debut, $7 = pas, $9 = fin
            char* start_val = malloc(20);
            char* step_val = malloc(20);
            char* end_val = malloc(20);
            sprintf(start_val, "%d", $5);
            sprintf(step_val, "%d", $7);
            sprintf(end_val, "%d", $9);
            
            quad("=", start_val, "", $3);
            loop_start = prochain_quad();
            char* temp_cond = new_temp();
            quad("SUP", $3, end_val, temp_cond);
            loop_cond = prochain_quad();
            quad("BZ", "", temp_cond, "");
        }
        ACCOLG INSTS ACCOLD
        {
            char* temp_step = new_temp();
            char* step_val = malloc(20);
            sprintf(step_val, "%d", $7);
            quad("+", $3, step_val, temp_step);
            quad("=", temp_step, "", $3);
            sprintf(tmp_addr, "%d", loop_start);
            quad("BR", "", "", tmp_addr);
            sprintf(tmp_addr, "%d", prochain_quad());
            modifier_quad(loop_cond, 3, tmp_addr);
        }
      ;

EXPR_LOG: EXPR_LOG OR EXPR_LOG { $$ = new_temp(); quad("OR", $1, $3, $$); }
        | EXPR_LOG AND EXPR_LOG { $$ = new_temp(); quad("AND", $1, $3, $$); }
        | NOT EXPR_LOG { $$ = new_temp(); quad("NOT", $2, "", $$); }
        | expression SUP expression { $$ = new_temp(); quad("SUP", $1, $3, $$); }
        | expression INF expression { $$ = new_temp(); quad("INF", $1, $3, $$); }
        | expression EGAL expression { $$ = new_temp(); quad("EGAL", $1, $3, $$); }
        | PARG EXPR_LOG PARD { $$ = $2; }
        ;

WRITE_I: WRITE PARG IDF PARD {
    int idx = search_idf_cst($3);
    if(idx == -1) {
        printf("Erreur Semantique: ligne %d, variable '%s' non declaree\n", nb_lignes, $3);
        nb_erreurs++;
    }
}
;

%%

void yyerror(const char* s) { 
    printf("Erreur Syntaxique: ligne %d, pres de '%s'\n", nb_lignes, yytext);
    nb_erreurs++; 
}

int main(int argc, char *argv[]) {
    if (argc > 1) {
        FILE *f = fopen(argv[1], "r");
        if (f) yyin = f;
        else {
            printf("Can't open file!\n");
            return 1;
        }
    }
    yyparse();
    afficher_ts_ids();
    afficher_ts_kw();
    afficher_ts_sep();
    return 0;
}