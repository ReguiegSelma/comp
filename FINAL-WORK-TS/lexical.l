%{
#include "syntaxique.tab.h"
#include "ts.h"
#include <string.h>
#include <stdlib.h>

int nb_lignes = 1;
int nb_col = 1;
extern int nb_erreurs;
%}

%option noyywrap

IDF          [a-zA-Z][a-zA-Z0-9_]*
REEL         [0-9]+\.[0-9]+
ENTIER       [0-9]+
ENT_SIGNE    \([+-]{ENTIER}\)
REEL_SIGNE   \([+-]{REEL}\)

%%
"//".* { nb_col += yyleng; }
"/*"([^*]|\*+[^*/])*\*+"/" {  
    for(int i=0; i<yyleng; i++) {
            if(yytext[i] == '\n') {
            nb_lignes++;
            nb_col = 1;
        } else {
            nb_col++;
        }
    } 
}

"PROGRAM" { inserer_kw("PROGRAM", "KW"); nb_col += yyleng; return PROGRAM; }
"DECL"    { inserer_kw("DECL", "KW"); nb_col += yyleng; return DECL; }
"ENDDECL" { inserer_kw("ENDDECL", "KW"); nb_col += yyleng; return ENDDECL; }
"BEGIN"   { inserer_kw("BEGIN", "KW"); nb_col += yyleng; return BEGIN_P; }
"END"     { inserer_kw("END", "KW"); nb_col += yyleng; return END; }
"INTEGER" { inserer_kw("INTEGER", "KW"); nb_col += yyleng; return INTEGER; }
"FLOAT"   { inserer_kw("FLOAT", "KW"); nb_col += yyleng; return FLOAT; }
"CONST"   { inserer_kw("CONST", "KW"); nb_col += yyleng; return CONST; }
"IF"      { inserer_kw("IF", "KW"); nb_col += yyleng; return IF; }
"ELSE"    { inserer_kw("ELSE", "KW"); nb_col += yyleng; return ELSE; }
"FOR"     { inserer_kw("FOR", "KW"); nb_col += yyleng; return FOR; }
"WHILE"   { inserer_kw("WHILE", "KW"); nb_col += yyleng; return WHILE; }
"WRITE"   { inserer_kw("WRITE", "KW"); nb_col += yyleng; return WRITE; }

{IDF} { 
    if(yyleng > 8) { 
        printf("Erreur Lexicale: ligne %d, col %d, IDF trop long '%s'\n", nb_lignes, nb_col, yytext);
        nb_erreurs++;
    }
    yylval.str = strdup(yytext); 
    nb_col += yyleng; 
    return IDF; 
}

{ENTIER} { 
    long val = atol(yytext);
    if (val > 32767) {
        printf("Erreur Lexicale: ligne %d, col %d, Valeur INTEGER hors limite (%s)\n", nb_lignes, nb_col, yytext);
        nb_erreurs++;
    }
    yylval.entier= atoi(yytext);
    nb_col += yyleng; 
    return INT_VAL; 
}                          

{REEL} { 
    yylval.reel = atof(yytext); 
    nb_col += yyleng; 
    return FLOAT_VAL; 
    }

{ENT_SIGNE} {
    char temp[20];
    strncpy(temp, yytext+1, yyleng-2); // enlever () strncpy(destination, source, n) copier n char 
    temp[yyleng-2] = '\0';

    yylval.entier = atoi(temp);
    nb_col += yyleng;
    return ENT_SIGNE;
}

{REEL_SIGNE} {
    char temp[20];
    strncpy(temp, yytext+1, yyleng-2);
    temp[yyleng-2] = '\0';

    yylval.reel = atof(temp);
    nb_col += yyleng;
    return REEL_SIGNE;
}


"+"    { inserer_sep("+", "SEP"); nb_col += yyleng; return PLUS; }
"-"    { inserer_sep("-", "SEP"); nb_col += yyleng; return MOINS; }
"*"    { inserer_sep("*", "SEP"); nb_col += yyleng; return MULT; }
"/"    { inserer_sep("/", "SEP"); nb_col += yyleng; return DIV; }
"="    { inserer_sep("=", "SEP"); nb_col += yyleng; return AFFECT; }
">"    { inserer_sep(">", "SEP"); nb_col += yyleng; return SUP; }
"<"    { inserer_sep("<", "SEP"); nb_col += yyleng; return INF; }
">="   { inserer_sep(">=", "SEP"); nb_col += yyleng; return SUPEG; }
"<="   { inserer_sep("<=", "SEP"); nb_col += yyleng; return INFEG; }
"=="   { inserer_sep("==", "SEP"); nb_col += yyleng; return EGAL; }
"!="   { inserer_sep("!=", "SEP"); nb_col += yyleng; return DIFF; }
";"    { inserer_sep(";", "SEP"); nb_col += yyleng; return PV; }
":"    { inserer_sep(":", "SEP"); nb_col += yyleng; return DEUXPTS; }
","    { inserer_sep(",", "SEP"); nb_col += yyleng; return VIRG; }
"("    { inserer_sep("(", "SEP"); nb_col += yyleng; return PARG; }
")"    { inserer_sep(")", "SEP"); nb_col += yyleng; return PARD; }
"["    { inserer_sep("[", "SEP"); nb_col += yyleng; return CROCHG; }
"]"    { inserer_sep("]", "SEP"); nb_col += yyleng; return CROCHD; }
"{"    { inserer_sep("{", "SEP"); nb_col += yyleng; return ACCOLG; }
"}"    { inserer_sep("}", "SEP"); nb_col += yyleng; return ACCOLD; }
"&&" { inserer_sep("&&","SEP"); nb_col += yyleng; return AND; }
"||" { inserer_sep("||","SEP"); nb_col += yyleng; return OR; }
"!"  { inserer_sep("!","SEP"); nb_col += yyleng; return NOT; }

[ \t\r]+ { nb_col += yyleng; } 
\n       { nb_lignes++; nb_col = 1; }
.        { printf("Erreur Lexicale: ligne %d, col %d, char '%s'\n", nb_lignes, nb_col, yytext); nb_erreurs++; }                     
%%