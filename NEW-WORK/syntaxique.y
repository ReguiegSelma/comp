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
int cpt_t = 1;

char* cree_temp() {
    char* t = malloc(10);
    sprintf(t, "T%d", cpt_t++);
    return t;
}
%}

%union {
    int entier;
    float reel;
    char* str;
}

%token kw_program kw_decl kw_enddecl kw_begin kw_end kw_integer kw_float kw_const kw_if kw_for kw_while
%token <str>idf <entier>cst_int <reel>cst_float
%token comp_egal

%type <str> EXPR

%left '+' '-'
%left '*' '/'

%%
S: kw_program idf kw_decl LIST_DEC kw_enddecl kw_begin LIST_INST kw_end { YYACCEPT; }

LIST_DEC: DEC LIST_DEC | ;

DEC: TYPE ':' LIST_IDF ';' 
   | kw_const idf '=' VAL_CST ';' {
        if(rechercher($2)!=-1) printf("Erreur Semantique: ligne %d, col %d, element %s (Double declaration)\n", nb_line, col, $2);
        else inserer($2, "CONST", save_type, 0, 0);
     }
;

TYPE: kw_integer { strcpy(save_type, "INTEGER"); }
    | kw_float   { strcpy(save_type, "FLOAT"); }
;

LIST_IDF: OBJET ',' LIST_IDF | OBJET ;

OBJET: idf {
        if(rechercher($1)!=-1) printf("Erreur Semantique: ligne %d, col %d, element %s (Double declaration)\n", nb_line, col, $1);
        else inserer($1, "IDF", save_type, 0, 0);
     }
     | idf '[' cst_int ']' {
        if(rechercher($1)!=-1) printf("Erreur Semantique: ligne %d, col %d, element %s (Double declaration)\n", nb_line, col, $1);
        else inserer($1, "TAB", save_type, 0, $3);
     }
;

VAL_CST: cst_int | cst_float ;

LIST_INST: INST LIST_INST | ;

INST: AFF | COND | BOUCLE_FOR | BOUCLE_WHILE ;

AFF: idf '=' EXPR ';' {
        int p = rechercher($1);
        if(p==-1) printf("Erreur Semantique: ligne %d, col %d, element %s (Variable non declaree)\n", nb_line, col, $1);
        else if(strcmp(tab[p].code, "CONST")==0) printf("Erreur Semantique: ligne %d, col %d, element %s (Modification constante interdite)\n", nb_line, col, $1);
        else quadr("=", $3, "", $1);
     }
     | idf '[' cst_int ']' '=' EXPR ';' {
        int p = rechercher($1);
        if(p!=-1 && $3 >= tab[p].taille) printf("Erreur Semantique: ligne %d, Index hors limites pour %s\n", nb_line, $1);
        char dest[20]; sprintf(dest, "%s[%d]", $1, $3);
        quadr("=", $6, "", dest);
     }
;

EXPR: EXPR '+' EXPR { $$ = cree_temp(); quadr("+", $1, $3, $$); }
    | EXPR '*' EXPR { $$ = cree_temp(); quadr("*", $1, $3, $$); }
    | EXPR '/' EXPR { 
        if(strcmp($3,"0")==0) printf("Erreur Semantique: ligne %d, Division par zero\n", nb_line);
        $$ = cree_temp(); quadr("/", $1, $3, $$); 
    }
    | idf { 
        if(rechercher($1)==-1) printf("Erreur Semantique: ligne %d, element %s (Non declaree)\n", nb_line, $1);
        $$ = $1; 
    }
    | cst_int { char s[15]; sprintf(s, "%d", $1); $$ = strdup(s); }
    | cst_float { char s[15]; sprintf(s, "%.2f", $1); $$ = strdup(s); }
    | '(' EXPR ')' { $$ = $2; }
;

COND: kw_if '(' EXPR '>' EXPR ')' '{' LIST_INST '}' ;

BOUCLE_FOR: kw_for '(' idf ':' cst_int ':' cst_int ':' cst_int ')' '{' LIST_INST '}' ;

BOUCLE_WHILE: kw_while '(' EXPR '<' EXPR ')' '{' LIST_INST '}' ;

%%
void yyerror(char* msg) {
    printf("Erreur Syntaxique: ligne %d, col %d\n", nb_line, col);
}

int main() {
    yyparse();
    afficher_ts();
    afficher_quads();
    return 0;
}