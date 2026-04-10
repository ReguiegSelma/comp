%{
#include "syntaxique.tab.h"
#include <string.h>
int nb_lignes = 1;
int nb_col = 1;
%}

%option noyywrap

IDF [a-zA-Z][a-zA-Z0-9_]*
REEL [0-9]+\.[0-9]+
ENTIER [0-9]+

%%
"//".* { nb_col += yyleng; }
"/*"([^*]|\*+[^*/])*\*+"/" { /* ignore */ }

"PROGRAM"               { nb_col += yyleng; return PROGRAM; }
"DECL"                  { nb_col += yyleng; return DECL; }
"ENDDECL"               { nb_col += yyleng; return ENDDECL; }
"BEGIN"                 { nb_col += yyleng; return BEGIN_P; }
"END"                   { nb_col += yyleng; return END; }
"INTEGER"               { nb_col += yyleng; return INTEGER; }
"FLOAT"                 { nb_col += yyleng; return FLOAT; }
"CONST"                 { nb_col += yyleng; return CONST; }
"IF"                    { nb_col += yyleng; return IF; }
"ELSE"                  { nb_col += yyleng; return ELSE; }
"FOR"                   { nb_col += yyleng; return FOR; }
"WHILE"                 { nb_col += yyleng; return WHILE; }
"WRITE"                 { nb_col += yyleng; return WRITE; }

{IDF}                   { 
                          if(yyleng > 8) printf("Erreur Lexicale:  ligne %d, col %d, IDF trop long '%s'\n",nb_lignes, nb_col, yytext);
                          yylval.str = strdup(yytext); nb_col += yyleng; return IDF; 
                        }
{ENTIER} { 
    long val = atol(yytext);
    if (val > 32767) {
        printf("Erreur Lexicale: ligne %d, col %d, Valeur INTEGER hors limite (%s)\n",nb_lignes, nb_col, yytext);
    }
    yylval.str = strdup(yytext); 
    nb_col += yyleng; 
    return INT_VAL; 
}                          
{REEL}                  { yylval.str = strdup(yytext); nb_col += yyleng; return FLOAT_VAL; }

"+" { nb_col++; return PLUS; }
"-" { nb_col++; return MOINS; }
"*" { nb_col++; return MULT; }
"/" { nb_col++; return DIV; }
"=" { nb_col++; return AFFECT; }
">" { nb_col++; return SUP; }
"<" { nb_col++; return INF; }
";" { nb_col++; return PV; }
":" { nb_col++; return DEUXPTS; }
"," { nb_col++; return VIRG; }
"(" { nb_col++; return PARG; }
")" { nb_col++; return PARD; }
"[" { return CROCHG; }
"]" { return CROCHD; }
"{" { nb_col++; return ACCOLG; }
"}" { nb_col++; return ACCOLD; }
"=="       {nb_col++; return EGAL;}

[ \t\r]+                { nb_col += yyleng; } 
\n                      { nb_lignes++; nb_col = 1; }
.                       { printf("Erreur Lexicale: ligne %d, col %d, char '%s'\n", nb_lignes, nb_col, yytext); }                     
%%