%{
#include "syntaxique.tab.h"
#include "ts.h"
#include <string.h>
int nb_lignes = 1;
int nb_col = 1;
extern int nb_erreurs;
%}

%option noyywrap

IDF [a-zA-Z][a-zA-Z0-9_]*
REEL [0-9]+\.[0-9]+
ENTIER [0-9]+

%%
"//".* { nb_col += yyleng; }
"/*"([^*]|\*+[^*/])*\*+"/" { /* ignore */ }

"&&" { inserer_sep("&&"); nb_col += yyleng; return AND; }
"||" { inserer_sep("||"); nb_col += yyleng; return OR; }
"!"  { inserer_sep("!"); nb_col += yyleng; return NOT; }
"PROGRAM"               { inserer_kw("PROGRAM"); nb_col += yyleng; return PROGRAM; }
"DECL"                  { inserer_kw("DECL"); nb_col += yyleng; return DECL; }
"ENDDECL"               { inserer_kw("ENDDECL"); nb_col += yyleng; return ENDDECL; }
"BEGIN"                 { inserer_kw("BEGIN"); nb_col += yyleng; return BEGIN_P; }
"END"                   { inserer_kw("END"); nb_col += yyleng; return END; }
"INTEGER"               { inserer_kw("INTEGER"); nb_col += yyleng; return INTEGER; }
"FLOAT"                 { inserer_kw("FLOAT"); nb_col += yyleng; return FLOAT; }
"CONST"                 { inserer_kw("CONST"); nb_col += yyleng; return CONST; }
"IF"                    { inserer_kw("IF"); nb_col += yyleng; return IF; }
"ELSE"                  { inserer_kw("ELSE"); nb_col += yyleng; return ELSE; }
"FOR"                   { inserer_kw("FOR"); nb_col += yyleng; return FOR; }
"WHILE"                 { inserer_kw("WHILE"); nb_col += yyleng; return WHILE; }
"WRITE"                 { inserer_kw("WRITE"); nb_col += yyleng; return WRITE; }

{IDF}                   { 
                          if(yyleng > 8) { 
                            printf("Erreur Lexicale:  ligne %d, col %d, IDF trop long '%s'\n",nb_lignes, nb_col, yytext);
                            nb_erreurs++;
                          }
                          yylval.str = strdup(yytext); nb_col += yyleng; return IDF; 
                        }
{ENTIER} { 
    long val = atol(yytext);
    if (val > 32767) {
        printf("Erreur Lexicale: ligne %d, col %d, Valeur INTEGER hors limite (%s)\n",nb_lignes, nb_col, yytext);
        nb_erreurs++;
    }
    yylval.str = strdup(yytext); 
    nb_col += yyleng; 
    return INT_VAL; 
}                          
{REEL}                  { yylval.str = strdup(yytext); nb_col += yyleng; return FLOAT_VAL; }

"+" { inserer_sep("+"); nb_col++; return PLUS; }
"-" { inserer_sep("-"); nb_col++; return MOINS; }
"*" { inserer_sep("*"); nb_col++; return MULT; }
"/" { inserer_sep("/"); nb_col++; return DIV; }
"=" { inserer_sep("="); nb_col++; return AFFECT; }
">" { inserer_sep(">"); nb_col++; return SUP; }
"<" { inserer_sep("<"); nb_col++; return INF; }
";" { inserer_sep(";"); nb_col++; return PV; }
":" { inserer_sep(":"); nb_col++; return DEUXPTS; }
"," { inserer_sep(","); nb_col++; return VIRG; }
"(" { inserer_sep("("); nb_col++; return PARG; }
")" { inserer_sep(")"); nb_col++; return PARD; }
"[" { inserer_sep("["); nb_col++; return CROCHG; }
"]" { inserer_sep("]"); nb_col++; return CROCHD; }
"{" { inserer_sep("{"); nb_col++; return ACCOLG; }
"}" { inserer_sep("}"); nb_col++; return ACCOLD; }
"=="       { inserer_sep("=="); nb_col++; return EGAL;}

[ \t\r]+                { nb_col += yyleng; } 
\n                      { nb_lignes++; nb_col = 1; }
.                       { printf("Erreur Lexicale: ligne %d, col %d, char '%s'\n", nb_lignes, nb_col, yytext); nb_erreurs++; }                     
%%
