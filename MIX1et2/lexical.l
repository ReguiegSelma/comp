%{
#include "syntaxique.tab.h"
#include "ts.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int nb_lignes = 1;
int nb_erreurs = 0;
extern YYSTYPE yylval;
%}

%option noyywrap

lettre [a-zA-Z]
chiffre [0-9]

idf {lettre}({lettre}|{chiffre}|_)*
entier {chiffre}+
reel {chiffre}+\.{chiffre}+

entier_signe \([+-]{entier}\)
reel_signe \([+-]{reel}\)

commentaire_simple "//".*
commentaire_multi "/*"([^*]|\*+[^*/])*\*+"/"

%%

{commentaire_simple} { /* ignorer */ }
{commentaire_multi}   { /* ignorer */ }

"&&"        { return AND; }
"||"        { return OR; }
"!"         { return NOT; }
"=="        { return EGAL; }

"PROGRAM"   { return PROGRAM; }
"DECL"      { return DECL; }
"ENDDECL"   { return ENDDECL; }
"BEGIN"     { return BEGIN_P; }
"END"       { return END; }
"INTEGER"   { return INTEGER; }
"FLOAT"     { return FLOAT; }
"CONST"     { return CONST; }
"IF"        { return IF; }
"ELSE"      { return ELSE; }
"FOR"       { return FOR; }
"WHILE"     { return WHILE; }
"WRITE"     { return WRITE; }

{idf}       { 
                if(yyleng > 8) { 
                    printf("Erreur Lexicale: ligne %d, IDF trop long '%s'\n", nb_lignes, yytext);
                    nb_erreurs++;
                }
                yylval.str = strdup(yytext); 
                return IDF; 
            }

{entier_signe}  { 
    yylval.integer = atoi(yytext+1); 
    return INT_VAL; 
}

{reel_signe}    { 
    yylval.float_val = atof(yytext+1);
    return FLOAT_VAL; 
}

{entier}    { 
    long val = atol(yytext);
    if (val > 32767 || val < -32768) {
        printf("Erreur Lexicale: ligne %d, Valeur INTEGER hors limite (%s)\n", nb_lignes, yytext);
        nb_erreurs++;
    }
    yylval.integer = atoi(yytext);
    return INT_VAL; 
}

{reel}      { 
    yylval.float_val = atof(yytext);
    return FLOAT_VAL; 
}

"+"         { return PLUS; }
"-"         { return MOINS; }
"*"         { return MULT; }
"/"         { return DIV; }
"="         { return AFFECT; }
">"         { return SUP; }
"<"         { return INF; }
";"         { return PV; }
":"         { return DEUXPTS; }
","         { return VIRG; }
"("         { return PARG; }
")"         { return PARD; }
"["         { return CROCHG; }
"]"         { return CROCHD; }
"{"         { return ACCOLG; }
"}"         { return ACCOLD; }

[ \t\r]+    { /* espaces */ }
\n          { nb_lignes++; }
.           { printf("Erreur Lexicale: ligne %d, char '%s'\n", nb_lignes, yytext); nb_erreurs++; }

%%