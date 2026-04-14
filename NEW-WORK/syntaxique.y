%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ts.h"
#include "quad.h"

extern int nb_line;
extern int col;
int yylex();
void yyerror(char* msg);

char save_type[20];
int temp_cpt = 1;

char* new_temp() {
    char* t = malloc(15);
    sprintf(t, "T%d", temp_cpt++);
    return t;
}

int fin_if, deb_while, cond_while;
%}

%union {
    int entier;
    float reel;
    char* str;
}

%token kw_program kw_decl kw_enddecl kw_begin kw_end kw_integer kw_float kw_const kw_if kw_else kw_while
%token <str>idf <entier>cst_int <reel>cst_float
%token plus moins mult divi aff sup inf sc dp vg po pf crochg crochd accol_g accol_d

%type <str> EXPR

%left plus moins
%left mult divi

%%
S: kw_program idf kw_decl LIST_DEC kw_enddecl kw_begin LIST_INST kw_end 
   { printf("Compilation terminee.\n"); YYACCEPT; }

LIST_DEC: DEC LIST_DEC | ;
DEC: TYPE dp LIST_OBJETS sc ;
TYPE: kw_integer { strcpy(save_type, "INTEGER"); }
    | kw_float { strcpy(save_type, "FLOAT"); }
    ;

LIST_OBJETS: OBJET vg LIST_OBJETS | OBJET ;
OBJET: idf { 
        if (rechercher($1) != -1) printf("Erreur Semantique: Double declaration de %s ligne %d\n", $1, nb_line);
        else inserer($1, "IDF", save_type, 0, 0); 
     }
     | idf crochg cst_int crochd { 
        if ($3 <= 0) printf("Erreur Semantique: Taille tableau invalide ligne %d\n", nb_line);
        else if (rechercher($1) != -1) printf("Erreur Semantique: Double declaration ligne %d\n", nb_line);
        else inserer($1, "TAB", save_type, 0, $3);
     }
     | kw_const idf aff VAL_CST { 
        if (rechercher($2) != -1) printf("Erreur Semantique: Double declaration ligne %d\n", nb_line);
        else inserer($2, "CONST", save_type, 0, 0); 
     }
     ;

VAL_CST: cst_int | cst_float ;

LIST_INST: INST LIST_INST | ;
INST: AFF | COND | BOUCLE ;

AFF: idf aff EXPR sc {
    int p = rechercher($1);
    if (p == -1) printf("Erreur Semantique: %s non declare ligne %d\n", $1, nb_line);
    else if (strcmp(tab[p].code, "CONST") == 0) printf("Erreur Semantique: Modif constante ligne %d\n", nb_line);
    else quadr("=", $3, "", $1);
}
| idf crochg cst_int crochd aff EXPR sc {
    int p = rechercher($1);
    if (p != -1 && ($3 >= tab[p].taille || $3 < 0)) printf("Erreur Semantique: Index hors limites ligne %d\n", nb_line);
    char res[20]; sprintf(res, "%s[%d]", $1, $3);
    quadr("=", $6, "", res);
}

EXPR: EXPR plus EXPR  { $$ = new_temp(); quadr("+", $1, $3, $$); }
    | EXPR mult EXPR  { $$ = new_temp(); quadr("*", $1, $3, $$); }
    | EXPR divi EXPR  { 
        if (strcmp($3, "0") == 0 || strcmp($3, "0.0") == 0) printf("Erreur Semantique: Division par zero ligne %d\n", nb_line);
        $$ = new_temp(); quadr("/", $1, $3, $$); 
    }
    | idf { 
        if (rechercher($1) == -1) printf("Erreur Semantique: %s non declare ligne %d\n", $1, nb_line);
        $$ = $1; 
    }
    | cst_int { char* s = malloc(15); sprintf(s, "%d", $1); $$ = s; }
    ;

COND: kw_if po EXPR sup EXPR pf {
        quadr("BGE", $3, $5, ""); // On saute si NOT (>) donc si <=
        fin_if = qc - 1;
    } 
    accol_g LIST_INST accol_d {
        char s[15]; sprintf(s, "%d", qc);
        update_quad(fin_if, 3, s);
    }
    ;

BOUCLE: kw_while { deb_while = qc; } 
        po EXPR sup EXPR pf {
            quadr("BGE", $4, $6, ""); 
            cond_while = qc - 1;
        }
        accol_g LIST_INST accol_d {
            char s[15]; sprintf(s, "%d", deb_while);
            quadr("BR", s, "", "");
            sprintf(s, "%d", qc);
            update_quad(cond_while, 3, s);
        }
        ;

%%
void yyerror(char* msg) { printf("Erreur Syntaxique: ligne %d, col %d\n", nb_line, col); }

int main() {
    yyparse();
    afficher_ts();
    afficher_quads();
    return 0;
}