%{
#include "syntaxique.tab.h"
#include <string.h>
#include <stdlib.h>
int nb_line = 1;
int col = 1;
%}
%option noyywrap
%%
"PROGRAM" { col+=7; return kw_program; }
"DECL"    { col+=4; return kw_decl; }
"ENDDECL" { col+=7; return kw_enddecl; }
"BEGIN"   { col+=5; return kw_begin; }
"END"     { col+=3; return kw_end; }
"INTEGER" { col+=7; return kw_integer; }
"FLOAT"   { col+=5; return kw_float; }
"CONST"   { col+=5; return kw_const; }
"IF"      { col+=2; return kw_if; }
"FOR"     { col+=3; return kw_for; }
"WHILE"   { col+=5; return kw_while; }

[a-zA-Z][a-zA-Z0-9]* { yylval.str = strdup(yytext); col+=yyleng; return idf; }
[0-9]+               { yylval.entier = atoi(yytext); col+=yyleng; return cst_int; }
[0-9]+\.[0-9]+       { yylval.reel = atof(yytext); col+=yyleng; return cst_float; }

"==" { col+=2; return comp_egal; }
">"  { col+=1; return '>'; }
"<"  { col+=1; return '<'; }
"+"  { col+=1; return '+'; }
"-"  { col+=1; return '-'; }
"*"  { col+=1; return '*'; }
"/"  { col+=1; return '/'; }
"="  { col+=1; return '='; }
":"  { col+=1; return ':'; }
";"  { col+=1; return ';'; }
","  { col+=1; return ','; }
"("  { col+=1; return '('; }
")"  { col+=1; return ')'; }
"["  { col+=1; return '['; }
"]"  { col+=1; return ']'; }
"{"  { col+=1; return '{'; }
"}"  { col+=1; return '}'; }

[ \t\r] { col++; }
\n      { nb_line++; col=1; }
.       { printf("Erreur Lexicale: ligne %d, col %d, element %s\n", nb_line, col, yytext); col++; }
%%