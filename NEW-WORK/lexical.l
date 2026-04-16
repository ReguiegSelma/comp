%{
#include "syntaxique.tab.h"
#include <string.h>
#include <stdlib.h>
#include "ts.h"
#include "quad.h"
int nb_line = 1;
int col = 1;
%}

%option noyywrap

%%

"//".*                         { col += yyleng; }

"/*"([^*]|\*+[^*/])*\*+"/"    {
                                for(int i=0;i<yyleng;i++){
                                    if(yytext[i]=='\n'){ nb_line++; col=1; }
                                    else col++;
                                }
                              }


"PROGRAM"  { col+=7; return kw_program; }
"DECL"     { col+=4; return kw_decl; }
"ENDDECL"  { col+=7; return kw_enddecl; }
"BEGIN"    { col+=5; return kw_begin; }
"END"      { col+=3; return kw_end; }
"INTEGER"  { col+=7; return kw_integer; }
"FLOAT"    { col+=5; return kw_float; }
"CONST"    { col+=5; return kw_const; }
"IF"       { col+=2; return kw_if; }
"ELSE"     { col+=4; return kw_else; }
"FOR"      { col+=3; return kw_for; }
"WHILE"    { col+=5; return kw_while; }


[a-zA-Z][a-zA-Z0-9]* {
    yylval.str = strdup(yytext);
    col += yyleng;
    return idf;
}


[0-9]+\.[0-9]+ {
    yylval.reel = atof(yytext);
    col += yyleng;
    return cst_float;
}

[0-9]+ {
    yylval.entier = atoi(yytext);
    col += yyleng;
    return cst_int;
}

"==" { col+=2; return comp_egal; }
"+"  { col++; return plus; }
"-"  { col++; return moins; }
"*"  { col++; return mult; }
"/"  { col++; return divi; }
"="  { col++; return aff; }
">"  { col++; return sup; }
"<"  { col++; return inf; }

";"  { col++; return sc; }
":"  { col++; return dp; }
","  { col++; return vg; }
"("  { col++; return po; }
")"  { col++; return pf; }
"["  { col++; return crochg; }
"]"  { col++; return crochd; }
"{"  { col++; return accol_g; }
"}"  { col++; return accol_d; }

[ \t\r]+ { col += yyleng; }
\n       { nb_line++; col=1; }


. {
    printf("Erreur Lexicale: ligne %d, col %d, element %s\n", nb_line, col, yytext);
    col++;
}

%%