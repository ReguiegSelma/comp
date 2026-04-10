%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symtable.h"
#include "quadruplets.h"

extern int  yylex(void);
extern int  yylineno;
extern int  col_num;
extern char *yytext;

int nb_erreurs = 0;

void erreur_syntaxique(const char *msg) {
    fprintf(stderr, "Erreur Syntaxique : ligne %d , colonne %d , element \"%s\" -- %s\n",
            yylineno, col_num, yytext, msg);
    nb_erreurs++;
}