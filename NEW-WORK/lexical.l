%{
#include "syntaxique.tab.h"
#include <string.h>
#include <stdlib.h>
int nb_line = 1;
int col = 1;
%}

%option noyywrap

%%
"//".* { col += yyleng; }
"/*"([^*]|\*+[^*/])*(\*+"/") { 
    for(int i=0; i<yyleng; i++) {
        if(yytext[i]=='\n') { nb_line++; col=1; }
        else col++;
    }
}

"PROGRAM" { col+=yyleng; return kw_program; }
"DECL"    { col+=yyleng; return kw_decl; }
"ENDDECL" { col+=yyleng; return kw_enddecl; }
"BEGIN"   { col+=yyleng; return kw_begin; }
"END"     { col+=yyleng; return kw_end; }
"INTEGER" { col+=yyleng; return kw_integer; }
"FLOAT"   { col+=yyleng; return kw_float; }
"CONST"   { col+=yyleng; return kw_const; }
"IF"      { col+=yyleng; return kw_if; }
"ELSE"    { col+=yyleng; return kw_else; }
"WHILE"   { col+=yyleng; return kw_while; }

[a-zA-Z][a-zA-Z0-9]* { 
    yylval.str = strdup(yytext); 
    col+=yyleng; return idf; 
}
[0-9]+ { 
    yylval.entier = atoi(yytext); 
    col+=yyleng; return cst_int; 
}
[0-9]+\.[0-9]+ { 
    yylval.reel = atof(yytext); 
    col+=yyleng; return cst_float; 
}

"+" { col++; return plus; }
"-" { col++; return moins; }
"*" { col++; return mult; }
"/" { col++; return divi; }
"=" { col++; return aff; }
">" { col++; return sup; }
"<" { col++; return inf; }
";" { col++; return sc; }
":" { col++; return dp; }
"," { col++; return vg; }
"(" { col++; return po; }
")" { col++; return pf; }
"[" { col++; return crochg; }
"]" { col++; return crochd; }
"{" { col++; return accol_g; }
"}" { col++; return accol_d; }

[ \t] { col++; }
\n    { nb_line++; col=1; }
.     { printf("Erreur Lexicale ligne %d : %s\n", nb_line, yytext); }
%%