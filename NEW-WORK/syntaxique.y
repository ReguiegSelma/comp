%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ts.h"
#include "quad.h"

extern int nb_line;
extern int col;
extern FILE *yyin;

int yylex();
void yyerror(char* msg);

char save_type[20];
int temp_cpt = 1;

char* new_temp(){
    char* t = malloc(10);
    sprintf(t,"T%d",temp_cpt++);
    return t;
}

extern int qc;
%}

%union {
    int entier;
    float reel;
    char* str;
}

/* tokens */
%token kw_program kw_decl kw_enddecl kw_begin kw_end
%token kw_integer kw_float kw_const kw_if kw_else kw_while kw_for
%token comp_egal

%token <str> idf
%token <entier> cst_int
%token <reel> cst_float

%token plus moins mult divi aff sup inf
%token sc dp vg po pf crochg crochd accol_g accol_d

%type <str> EXPR

%left plus moins
%left mult divi

%%

S:
    kw_program idf kw_decl LIST_DEC kw_enddecl kw_begin LIST_INST kw_end
    { printf("Compilation terminee.\n"); }
;

/* declarations */
LIST_DEC:
    DEC LIST_DEC
    | 
;

DEC:
    TYPE dp LIST_OBJETS sc
    | kw_const idf aff VAL_CST sc   /* FIX CONST */
;

TYPE:
    kw_integer { strcpy(save_type,"INTEGER"); }
    | kw_float { strcpy(save_type,"FLOAT"); }
;

LIST_OBJETS:
    OBJET vg LIST_OBJETS
    | OBJET
;

OBJET:
    idf
    | idf crochg cst_int crochd
;

VAL_CST:
    cst_int
    | cst_float
;

/* instructions */
LIST_INST:
    INST LIST_INST
    |
;

INST:
    AFF
    | COND
    | BOUCLE
;

/* affectation */
AFF:
    idf aff EXPR sc
    | idf crochg cst_int crochd aff EXPR sc
;

/* expressions */
EXPR:
    EXPR plus EXPR   { $$ = new_temp(); }
    | EXPR mult EXPR { $$ = new_temp(); }
    | EXPR divi EXPR { $$ = new_temp(); }
    | idf            { $$ = $1; }
    | cst_int {
        char* s = malloc(10);
        sprintf(s,"%d",$1);
        $$ = s;
    }
    | cst_float {
        char* s = malloc(10);
        sprintf(s,"%f",$1);
        $$ = s;
    }
;

/* condition */
COND:
    kw_if po EXPR sup EXPR pf accol_g LIST_INST accol_d
;

/* boucles */
BOUCLE:
    kw_while po EXPR sup EXPR pf accol_g LIST_INST accol_d
    | kw_for po idf dp EXPR dp EXPR dp EXPR pf accol_g LIST_INST accol_d
;

%%

void yyerror(char* msg){
    printf("Erreur Syntaxique: ligne %d, col %d\n", nb_line, col);
}

int main(int argc, char *argv[]){
    if(argc > 1){
        FILE *f = fopen(argv[1],"r");
        if(f) yyin = f;
        else { printf("Erreur ouverture fichier\n"); return 1; }
    }
    yyparse();
    return 0;
}