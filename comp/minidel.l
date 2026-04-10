%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "minidel.tab.h"

extern int nb_ligne;
extern int nb_colonne;

void update_position() {
    nb_colonne += yyleng;
}
%}

%option noyywrap

LETTRE [a-zA-Z]
CHIFFRE [0-9]
IDF {LETTRE}({LETTRE}|{CHIFFRE}|_){0,6}
ENTIER {CHIFFRE}+
REEL {CHIFFRE}+\.{CHIFFRE}+
ENTIER_SIGNE \({CHIFFRE}+\)|\(\+{CHIFFRE}+\)|\(\-{CHIFFRE}+\)
REEL_SIGNE \({CHIFFRE}+\.{CHIFFRE}+\)|\(\+{CHIFFRE}+\.{CHIFFRE}+\)|\(\-{CHIFFRE}+\.{CHIFFRE}+\)

%%

"/*"([^*]|\*+[^*/])*\*+"/"  { update_position(); /* Commentaire multi-ligne */ }
"//".*                       { update_position(); /* Commentaire une ligne */ }

"PROGRAMME"     { update_position(); return PROGRAMME; }
"VAR"           { update_position(); return VAR; }
"BEGIN"         { update_position(); return BEGIN_BLOCK; }
"END"           { update_position(); return END_BLOCK; }
"INTEGER"       { update_position(); return INTEGER; }
"FLOAT"         { update_position(); return FLOAT; }
"CONST"         { update_position(); return CONST; }
"IF"            { update_position(); return IF; }
"ELSE"          { update_position(); return ELSE; }
"FOR"           { update_position(); return FOR; }
"WHILE"         { update_position(); return WHILE; }
"writeln"       { update_position(); return WRITELN; }
"readln"        { update_position(); return READLN; }

{IDF}           { 
                    update_position();
                    if (strlen(yytext) > 7) {
                        printf("Erreur lexicale, line %d, colonne %d : Identificateur '%s' trop long (max 7 caracteres)\n", 
                               nb_ligne, nb_colonne - yyleng, yytext);
                        exit(1);
                    }
                    yylval.string = strdup(yytext);
                    return IDF;
                }

{ENTIER}        { update_position(); yylval.entier = atoi(yytext); return ENTIER; }
{REEL}          { update_position(); yylval.reel = atof(yytext); return REEL; }
{ENTIER_SIGNE}  { 
                    update_position();
                    char temp[100];
                    strncpy(temp, yytext+1, strlen(yytext)-2);
                    temp[strlen(yytext)-2] = '\0';
                    yylval.entier = atoi(temp);
                    return ENTIER;
                }
{REEL_SIGNE}    { 
                    update_position();
                    char temp[100];
                    strncpy(temp, yytext+1, strlen(yytext)-2);
                    temp[strlen(yytext)-2] = '\0';
                    yylval.reel = atof(temp);
                    return REEL;
                }

"+"             { update_position(); return PLUS; }
"-"             { update_position(); return MINUS; }
"*"             { update_position(); return MUL; }
"/"             { update_position(); return DIV; }
"="             { update_position(); return ASSIGN; }
"=="            { update_position(); return EQ; }
"!="            { update_position(); return NEQ; }
"<"             { update_position(); return LT; }
"<="            { update_position(); return LE; }
">"             { update_position(); return GT; }
">="            { update_position(); return GE; }
"&&"            { update_position(); return AND; }
"||"            { update_position(); return OR; }
"!"             { update_position(); return NOT; }

"("             { update_position(); return LPAR; }
")"             { update_position(); return RPAR; }
"{"             { update_position(); return LBRACE; }
"}"             { update_position(); return RBRACE; }
"["             { update_position(); return LBRACKET; }
"]"             { update_position(); return RBRACKET; }
";"             { update_position(); return SEMICOL; }
","             { update_position(); return COMMA; }
":"             { update_position(); return COLON; }
"."             { update_position(); return DOT; }
"'"             { update_position(); return QUOTE; }

[ \t]           { update_position(); }
\n              { nb_ligne++; nb_colonne = 1; }

.               { 
                    printf("Erreur lexicale, line %d, colonne %d : Caractere non reconnu '%s'\n", 
                           nb_ligne, nb_colonne, yytext);
                    exit(1);
                }

%%
