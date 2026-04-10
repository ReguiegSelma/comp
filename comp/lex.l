%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "ts.h"     
    #include "syn.tab.h" 


    int col_num = 1;

void lex_error(const char *msg) {
    fprintf(stderr,
            "Erreur lexicale : ligne %d, colonne %d, élément \"%s\" — %s\n",
            yylineno, col_num, yytext, msg);
}
%}

%option noyywrap       
%option yylineno      


LETTRE          [a-zA-Z]
CHIFFRE         [0-9]
UNDERSCORE      _

IDENTIFICATEUR  {LETTRE}({LETTRE}|{CHIFFRE}|{UNDERSCORE})*

ENTIER          {CHIFFRE}+

REEL            {CHIFFRE}+\.{CHIFFRE}+

BLANC           [ \t]+

%%

"//"[^\n]*          {col_num = 1; }
.       { col_num += yyleng; }

"/*"                {
                        int c, prev = 0;
                        col_num += yyleng ;
                        while ((c = input()) != EOF) {
                            if (c == '\n') { line_num++; col_num = 1; }
                            else col_num++;
                            if (prev == '*' && c == '/') break;
                            prev = c;
                        }
                        if (c == EOF)
                            fprintf(stderr, "Erreur Lexicale : commentaire non fermé\n");
                    }

"PROGRAM"           { col_num += yyleng; return TOK_PROGRAM;  }
"DECL"              { col_num += yyleng; return TOK_DECL;     }
"ENDDECL"           { col_num += yyleng; return TOK_ENDDECL;  }
"BEGIN"             { col_num += yyleng; return TOK_BEGIN;     }
"END"               { col_num += yyleng; return TOK_END;       }
"INTEGER"           { col_num += yyleng; return TOK_INTEGER;   }
"FLOAT"             { col_num += yyleng; return TOK_FLOAT;     }
"CONST"             { col_num += yyleng; return TOK_CONST;     }
"IF"                { col_num += yyleng; return TOK_IF;        }
"ELSE"              { col_num += yyleng; return TOK_ELSE;      }
"FOR"               { col_num += yyleng; return TOK_FOR;       }
"WHILE"             { col_num += yyleng; return TOK_WHILE;     }
"WRITE"             { col_num += yyleng; return TOK_WRITE;     }
"READ"              { col_num += yyleng; return TOK_READ;      }

"&&"                { col_num += yyleng; return TOK_AND;  }
"||"                { col_num += yyleng; return TOK_OR;   }
"!"                 { col_num += yyleng; return TOK_NOT;  }


">="                { col_num += yyleng; return TOK_GE;  }
"<="                { col_num += yyleng; return TOK_LE;  }
"=="                { col_num += yyleng; return TOK_EQ;  }
"!="                { col_num += yyleng; return TOK_NE;  }
">"                 { col_num += yyleng; return TOK_GT;  }
"<"                 { col_num += yyleng; return TOK_LT;  }


"+"                 { col_num += yyleng; return '+'; }
"-"                 { col_num += yyleng; return '-'; }
"*"                 { col_num += yyleng; return '*'; }
"/"                 { col_num += yyleng; return '/'; }
"="                 { col_num += yyleng; return '='; }


";"                 { col_num += yyleng; return ';'; }
","                 { col_num += yyleng; return ','; }
":"                 { col_num += yyleng; return ':'; }
"("                 { col_num += yyleng; return '('; }
")"                 { col_num += yyleng; return ')'; }
"{"                 { col_num += yyleng; return '{'; }
"}"                 { col_num += yyleng; return '}'; }
"["                 { col_num += yyleng; return '['; }
"]"                 { col_num += yyleng; return ']'; }


{REEL}              {
                        col_num += yyleng;
                        yylval.rval = atof(yytext);
                        return TOK_REEL;
                    }


{ENTIER}            {
                        col_num += yyleng;
                        int v = atoi(yytext);
                        if (v < -32768 || v > 32767)
                            lex_error("constante entiere hors plage [-32768, 32767]");
                        yylval.ival = v;
                        return TOK_ENTIER;
                    }

{ENTIER}        { col_num += yyleng; yylval.entier = atoi(yytext); return TOK_ENTIER; }
{REEL}          { col_num += yyleng; yylval.reel = atof(yytext); return TOK_REEL; }
{ENTIER_SIGNE}  { 
                    col_num += yyleng;
                    char temp[100];
                    strncpy(temp, yytext+1, strlen(yytext)-2);
                    temp[strlen(yytext)-2] = '\0';
                    yylval.entier = atoi(temp);
                    return TOK_ENTIER;
                }
{REEL_SIGNE}    { 
                    col_num += yyleng;
                    char temp[100];
                    strncpy(temp, yytext+1, strlen(yytext)-2);
                    temp[strlen(yytext)-2] = '\0';
                    yylval.reel = atof(temp);
                    return TOK_REEL;
                }

{IDENTIFICATEUR}    {
                        col_num += yyleng;

                        if (yyleng > 8) {
                            lex_error("identificateur trop long (max 8 caracteres)");
                            yytext[8] = '\0';
                        }

                        strncpy(yylval.sval, yytext, MAX_ID_LEN);
                        yylval.sval[MAX_ID_LEN] = '\0';

                        return TOK_IDF;
                    }


{BLANC}             { col_num += yyleng;    }

\n                  { line_num++; col_num = 1;  }


.                   {
                        col_num += yyleng;
                        lex_error("caractere non reconnu");
                    }

%%