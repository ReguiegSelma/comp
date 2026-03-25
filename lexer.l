/*
 * ============================================================
 *  ANALYSEUR LEXICAL — MiniAlgo
 *  Outil : Flex
 *  Rôle  : découper le code source en tokens (unités lexicales)
 *          et remplir la table des symboles
 * ============================================================
 */

%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symtable.h"       /* table des symboles partagée  */
#include "parser.tab.h"     /* tokens générés par Bison     */

/* Compteurs de position pour les messages d'erreur */
int line_num = 1;
int col_num  = 1;

/* Macro utilitaire : avance le compteur de colonnes */
#define ADVANCE_COL  col_num += yyleng

/* Affiche une erreur lexicale formatée */
void lex_error(const char *msg) {
    fprintf(stderr, "Erreur Lexicale : ligne %d , colonne %d , element \"%s\" — %s\n",
            line_num, col_num, yytext, msg);
}
%}

/* ---- Options Flex ---- */
%option noyywrap       /* pas de fichier supplémentaire à analyser  */
%option yylineno       /* flex maintient yylineno automatiquement   */

/* ------------------------------------------------------------------ */
/*  DÉFINITIONS DES EXPRESSIONS RÉGULIÈRES (abréviations réutilisables) */
/* ------------------------------------------------------------------ */

LETTRE          [a-zA-Z]
CHIFFRE         [0-9]
UNDERSCORE      _

/* Identificateur : commence par une lettre, suivi de lettres/chiffres/_ */
/* La longueur max (8 car.) est vérifiée dans l'action, pas ici          */
IDENTIFICATEUR  {LETTRE}({LETTRE}|{CHIFFRE}|{UNDERSCORE})*

/* Entier non signé (le signe se gère avec les parenthèses dans la grammaire) */
ENTIER          {CHIFFRE}+

/* Réel non signé */
REEL            {CHIFFRE}+\.{CHIFFRE}+

/* Espaces blancs (espaces, tabulations) */
BLANC           [ \t]+

%%

/* ================================================================== */
/*  RÈGLES LEXICALES                                                   */
/*  Ordre important : les règles les plus spécifiques d'abord          */
/* ================================================================== */

/* --- Commentaires ------------------------------------------------- */

"//"[^\n]*          { ADVANCE_COL; /* ignorer commentaire ligne */    }

"/*"                {
                        /* Commentaire multi-lignes : on avance jusqu'à */ 
                        /* la prochaine séquence  */
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

/* --- Mots-clés ----------------------------------------------------- */
/* Note : ils doivent apparaître AVANT la règle IDENTIFICATEUR         */

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

/* --- Opérateurs logiques ------------------------------------------ */

"&&"                { ADVANCE_COL; return TOK_AND;  }
"||"                { ADVANCE_COL; return TOK_OR;   }
"!"                 { ADVANCE_COL; return TOK_NOT;  }

/* --- Opérateurs de comparaison ------------------------------------ */

">="                { ADVANCE_COL; return TOK_GE;  }
"<="                { ADVANCE_COL; return TOK_LE;  }
"=="                { ADVANCE_COL; return TOK_EQ;  }
"!="                { ADVANCE_COL; return TOK_NE;  }
">"                 { ADVANCE_COL; return TOK_GT;  }
"<"                 { ADVANCE_COL; return TOK_LT;  }

/* --- Opérateurs arithmétiques ------------------------------------- */

"+"                 { ADVANCE_COL; return '+'; }
"-"                 { ADVANCE_COL; return '-'; }
"*"                 { ADVANCE_COL; return '*'; }
"/"                 { ADVANCE_COL; return '/'; }
"="                 { ADVANCE_COL; return '='; }

/* --- Délimiteurs -------------------------------------------------- */

";"                 { ADVANCE_COL; return ';'; }
","                 { ADVANCE_COL; return ','; }
":"                 { ADVANCE_COL; return ':'; }
"("                 { ADVANCE_COL; return '('; }
")"                 { ADVANCE_COL; return ')'; }
"{"                 { ADVANCE_COL; return '{'; }
"}"                 { ADVANCE_COL; return '}'; }
"["                 { ADVANCE_COL; return '['; }
"]"                 { ADVANCE_COL; return ']'; }

/* --- Constante réelle --------------------------------------------- */

{REEL}              {
                        ADVANCE_COL;
                        yylval.rval = atof(yytext);
                        return TOK_REEL;
                    }

/* --- Constante entière -------------------------------------------- */

{ENTIER}            {
                        ADVANCE_COL;
                        int v = atoi(yytext);
                        /* Vérification de la plage INTEGER */
                        if (v < -32768 || v > 32767)
                            lex_error("constante entiere hors plage [-32768, 32767]");
                        yylval.ival = v;
                        return TOK_ENTIER;
                    }

/* --- Identificateur ----------------------------------------------- */

{IDENTIFICATEUR}    {
                        ADVANCE_COL;

                        /* Règle : longueur maximale 8 caractères */
                        if (yyleng > 8) {
                            lex_error("identificateur trop long (max 8 caracteres)");
                            /* On tronque silencieusement pour continuer l'analyse */
                            yytext[8] = '\0';
                        }

                        /* Copier le lexème dans yylval */
                        strncpy(yylval.sval, yytext, MAX_ID_LEN);
                        yylval.sval[MAX_ID_LEN] = '\0';

                        return TOK_IDF;
                    }

/* --- Caractères ignorés ------------------------------------------ */

{BLANC}             { ADVANCE_COL; /* ignorer espaces */    }

\n                  { line_num++; col_num = 1; /* nouvelle ligne */ }

/* --- Caractère non reconnu --------------------------------------- */

.                   {
                        ADVANCE_COL;
                        lex_error("caractere non reconnu");
                    }

%%
