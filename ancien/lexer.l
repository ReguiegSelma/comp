

%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symtable.h"     
#include "parser.tab.h"     

int line_num = 1;
int col_num  = 1;

#define ADVANCE_COL  col_num += yyleng

void lex_error(const char *msg) {
    fprintf(stderr, "Erreur Lexicale : ligne %d , colonne %d , element \"%s\" — %s\n",
            line_num, col_num, yytext, msg);
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

"//"[^\n]*          { ADVANCE_COL;    }

"/*"                {
                        int c, prev = 0;
                        ADVANCE_COL;
                        while ((c = input()) != EOF) {
                            if (c == '\n') { line_num++; col_num = 1; }
                            else col_num++;
                            if (prev == '*' && c == '/') break;
                            prev = c;
                        }
                        if (c == EOF)
                            fprintf(stderr, "Erreur Lexicale : commentaire non fermé\n");
                    }


"PROGRAM"           { ADVANCE_COL; return TOK_PROGRAM;  }
"DECL"              { ADVANCE_COL; return TOK_DECL;     }
"ENDDECL"           { ADVANCE_COL; return TOK_ENDDECL;  }
"BEGIN"             { ADVANCE_COL; return TOK_BEGIN;     }
"END"               { ADVANCE_COL; return TOK_END;       }
"INTEGER"           { ADVANCE_COL; return TOK_INTEGER;   }
"FLOAT"             { ADVANCE_COL; return TOK_FLOAT;     }
"CONST"             { ADVANCE_COL; return TOK_CONST;     }
"IF"                { ADVANCE_COL; return TOK_IF;        }
"ELSE"              { ADVANCE_COL; return TOK_ELSE;      }
"FOR"               { ADVANCE_COL; return TOK_FOR;       }
"WHILE"             { ADVANCE_COL; return TOK_WHILE;     }
"WRITE"             { ADVANCE_COL; return TOK_WRITE;     }
"READ"              { ADVANCE_COL; return TOK_READ;      }


"&&"                { ADVANCE_COL; return TOK_AND;  }
"||"                { ADVANCE_COL; return TOK_OR;   }
"!"                 { ADVANCE_COL; return TOK_NOT;  }


">="                { ADVANCE_COL; return TOK_GE;  }
"<="                { ADVANCE_COL; return TOK_LE;  }
"=="                { ADVANCE_COL; return TOK_EQ;  }
"!="                { ADVANCE_COL; return TOK_NE;  }
">"                 { ADVANCE_COL; return TOK_GT;  }
"<"                 { ADVANCE_COL; return TOK_LT;  }


"+"                 { ADVANCE_COL; return '+'; }
"-"                 { ADVANCE_COL; return '-'; }
"*"                 { ADVANCE_COL; return '*'; }
"/"                 { ADVANCE_COL; return '/'; }
"="                 { ADVANCE_COL; return '='; }


";"                 { ADVANCE_COL; return ';'; }
","                 { ADVANCE_COL; return ','; }
":"                 { ADVANCE_COL; return ':'; }
"("                 { ADVANCE_COL; return '('; }
")"                 { ADVANCE_COL; return ')'; }
"{"                 { ADVANCE_COL; return '{'; }
"}"                 { ADVANCE_COL; return '}'; }
"["                 { ADVANCE_COL; return '['; }
"]"                 { ADVANCE_COL; return ']'; }


{REEL}              {
                        ADVANCE_COL;
                        yylval.rval = atof(yytext);
                        return TOK_REEL;
                    }


{ENTIER}            {
                        ADVANCE_COL;
                        int v = atoi(yytext);
                        if (v < -32768 || v > 32767)
                            lex_error("constante entiere hors plage [-32768, 32767]");
                        yylval.ival = v;
                        return TOK_ENTIER;
                    }


{IDENTIFICATEUR}    {
                        ADVANCE_COL;

                        if (yyleng > 8) {
                            lex_error("identificateur trop long (max 8 caracteres)");
                            yytext[8] = '\0';
                        }

                        strncpy(yylval.sval, yytext, MAX_ID_LEN);
                        yylval.sval[MAX_ID_LEN] = '\0';

                        return TOK_IDF;
                    }


{BLANC}             { ADVANCE_COL;    }

\n                  { line_num++; col_num = 1;  }


.                   {
                        ADVANCE_COL;
                        lex_error("caractere non reconnu");
                    }

%%
