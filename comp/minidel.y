%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "table_symboles.h"
#include "quadruplets.h"

extern int yylex();
extern FILE* yyin;
void yyerror(const char* s);

int nb_ligne = 1;
int nb_colonne = 1;

char* type_courant = NULL;
%}

%union {
    int entier;
    double reel;
    char* string;
}

%token PROGRAMME VAR BEGIN_BLOCK END_BLOCK
%token INTEGER FLOAT CONST
%token IF ELSE FOR WHILE
%token WRITELN READLN
%token LPAR RPAR LBRACE RBRACE LBRACKET RBRACKET
%token SEMICOL COMMA COLON DOT QUOTE
%token ASSIGN

%token <string> IDF
%token <entier> ENTIER
%token <reel> REEL

%left OR
%left AND
%left EQ NEQ
%left LT LE GT GE
%left PLUS MINUS
%left MUL DIV
%right NOT

%type <string> expression condition terme facteur

%%

programme: PROGRAMME IDF {
                printf("\n=== Debut de l'analyse du programme '%s' ===\n", $2);
            } VAR LBRACE declarations RBRACE 
            BEGIN_BLOCK instructions END_BLOCK DOT {
                printf("\n=== Programme '%s' compile avec succes ===\n", $2);
                afficher_table_symboles();
                afficher_quadruplets();
            }
         ;

declarations: declarations declaration
            | declaration
            | /* vide */
            ;

declaration: type_decl liste_variables SEMICOL
           | CONST IDF ASSIGN valeur SEMICOL {
                if (rechercher_symbole($2) != -1) {
                    printf("Erreur semantique, line %d, colonne %d : Variable '%s' deja declaree\n", 
                           nb_ligne, nb_colonne, $2);
                    exit(1);
                }
                inserer_symbole($2, "CONST", NULL);
                printf("Constante '%s' declaree\n", $2);
            }
           ;

type_decl: INTEGER { type_courant = "INTEGER"; }
         | FLOAT { type_courant = "FLOAT"; }
         ;

liste_variables: liste_variables COMMA variable
               | variable
               ;

variable: IDF {
            if (rechercher_symbole($1) != -1) {
                printf("Erreur semantique, line %d, colonne %d : Variable '%s' deja declaree\n", 
                       nb_ligne, nb_colonne, $1);
                exit(1);
            }
            inserer_symbole($1, type_courant, NULL);
            printf("Variable '%s' de type %s declaree\n", $1, type_courant);
        }
        | IDF LBRACKET ENTIER RBRACKET {
            if (rechercher_symbole($1) != -1) {
                printf("Erreur semantique, line %d, colonne %d : Variable '%s' deja declaree\n", 
                       nb_ligne, nb_colonne, $1);
                exit(1);
            }
            char taille[20];
            sprintf(taille, "%d", $3);
            inserer_symbole($1, type_courant, taille);
            printf("Tableau '%s' de type %s de taille %d declare\n", $1, type_courant, $3);
        }
        ;

valeur: ENTIER
      | REEL
      | LPAR ENTIER RPAR
      | LPAR REEL RPAR
      ;

instructions: instructions instruction
            | instruction
            ;

instruction: affectation
           | condition_if
           | boucle_for
           | boucle_while
           | lecture
           | ecriture
           ;

affectation: IDF ASSIGN expression SEMICOL {
                if (rechercher_symbole($1) == -1) {
                    printf("Erreur semantique, line %d, colonne %d : Variable '%s' non declaree\n", 
                           nb_ligne, nb_colonne, $1);
                    exit(1);
                }
                generer_quadruplet("=", $3, "", $1);
            }
           | IDF LBRACKET expression RBRACKET ASSIGN expression SEMICOL {
                if (rechercher_symbole($1) == -1) {
                    printf("Erreur semantique, line %d, colonne %d : Variable '%s' non declaree\n", 
                           nb_ligne, nb_colonne, $1);
                    exit(1);
                }
                char temp[50];
                sprintf(temp, "%s[%s]", $1, $3);
                generer_quadruplet("=", $6, "", temp);
            }
           ;

expression: expression PLUS terme {
                char* temp = creer_temp();
                generer_quadruplet("+", $1, $3, temp);
                $$ = temp;
            }
          | expression MINUS terme {
                char* temp = creer_temp();
                generer_quadruplet("-", $1, $3, temp);
                $$ = temp;
            }
          | terme { $$ = $1; }
          ;

terme: terme MUL facteur {
            char* temp = creer_temp();
            generer_quadruplet("*", $1, $3, temp);
            $$ = temp;
        }
     | terme DIV facteur {
            char* temp = creer_temp();
            generer_quadruplet("/", $1, $3, temp);
            $$ = temp;
        }
     | facteur { $$ = $1; }
     ;

facteur: IDF {
            if (rechercher_symbole($1) == -1) {
                printf("Erreur semantique, line %d, colonne %d : Variable '%s' non declaree\n", 
                       nb_ligne, nb_colonne, $1);
                exit(1);
            }
            $$ = $1;
        }
       | ENTIER {
            char* val = malloc(20);
            sprintf(val, "%d", $1);
            $$ = val;
        }
       | REEL {
            char* val = malloc(20);
            sprintf(val, "%f", $1);
            $$ = val;
        }
       | IDF LBRACKET expression RBRACKET {
            if (rechercher_symbole($1) == -1) {
                printf("Erreur semantique, line %d, colonne %d : Variable '%s' non declaree\n", 
                       nb_ligne, nb_colonne, $1);
                exit(1);
            }
            char* temp = malloc(50);
            sprintf(temp, "%s[%s]", $1, $3);
            $$ = temp;
        }
       | LPAR expression RPAR { $$ = $2; }
       ;

condition: expression EQ expression {
                char* temp = creer_temp();
                generer_quadruplet("==", $1, $3, temp);
                $$ = temp;
            }
         | expression NEQ expression {
                char* temp = creer_temp();
                generer_quadruplet("!=", $1, $3, temp);
                $$ = temp;
            }
         | expression LT expression {
                char* temp = creer_temp();
                generer_quadruplet("<", $1, $3, temp);
                $$ = temp;
            }
         | expression LE expression {
                char* temp = creer_temp();
                generer_quadruplet("<=", $1, $3, temp);
                $$ = temp;
            }
         | expression GT expression {
                char* temp = creer_temp();
                generer_quadruplet(">", $1, $3, temp);
                $$ = temp;
            }
         | expression GE expression {
                char* temp = creer_temp();
                generer_quadruplet(">=", $1, $3, temp);
                $$ = temp;
            }
         | condition AND condition {
                char* temp = creer_temp();
                generer_quadruplet("&&", $1, $3, temp);
                $$ = temp;
            }
         | condition OR condition {
                char* temp = creer_temp();
                generer_quadruplet("||", $1, $3, temp);
                $$ = temp;
            }
         | NOT condition {
                char* temp = creer_temp();
                generer_quadruplet("!", $2, "", temp);
                $$ = temp;
            }
         | LPAR condition RPAR { $$ = $2; }
         ;

condition_if: IF LPAR condition RPAR LBRACE {
                    int etiq = creer_etiquette();
                    generer_quadruplet("BZ", $3, "", creer_etiq_str(etiq));
                } 
                instructions RBRACE suite_if
            ;

suite_if: ELSE LBRACE {
                int etiq_fin = creer_etiquette();
                generer_quadruplet("BR", "", "", creer_etiq_str(etiq_fin));
            }
            instructions RBRACE
        | /* vide */
        ;

boucle_for: FOR LPAR IDF COLON expression COLON expression COLON expression RPAR LBRACE {
                generer_quadruplet("=", $5, "", $3);
                int etiq_debut = creer_etiquette();
                generer_etiquette(etiq_debut);
            }
            instructions RBRACE {
                char* temp = creer_temp();
                generer_quadruplet("+", $3, $7, temp);
                generer_quadruplet("=", temp, "", $3);
                char* cond_temp = creer_temp();
                generer_quadruplet("<=", $3, $9, cond_temp);
                generer_quadruplet("BNZ", cond_temp, "", creer_etiq_str(nb_quad - 3));
            }
          ;

boucle_while: WHILE {
                int etiq_debut = creer_etiquette();
                generer_etiquette(etiq_debut);
            }
            LPAR condition RPAR LBRACE {
                int etiq_fin = creer_etiquette();
                generer_quadruplet("BZ", $4, "", creer_etiq_str(etiq_fin));
            }
            instructions RBRACE {
                generer_quadruplet("BR", "", "", creer_etiq_str(nb_quad - 6));
            }
            ;

ecriture: WRITELN LPAR QUOTE IDF QUOTE RPAR SEMICOL {
                generer_quadruplet("WRITE", $4, "", "");
            }
        | WRITELN LPAR IDF RPAR SEMICOL {
                if (rechercher_symbole($3) == -1) {
                    printf("Erreur semantique, line %d, colonne %d : Variable '%s' non declaree\n", 
                           nb_ligne, nb_colonne, $3);
                    exit(1);
                }
                generer_quadruplet("WRITE", $3, "", "");
            }
        ;

lecture: READLN LPAR IDF RPAR SEMICOL {
            if (rechercher_symbole($1) == -1) {
                printf("Erreur semantique, line %d, colonne %d : Variable '%s' non declaree\n", 
                       nb_ligne, nb_colonne, $1);
                exit(1);
            }
            generer_quadruplet("READ", "", "", $3);
        }
       ;

%%

void yyerror(const char* s) {
    printf("Erreur syntaxique, line %d, colonne %d : %s\n", nb_ligne, nb_colonne, s);
    exit(1);
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <fichier_source.mdl>\n", argv[0]);
        return 1;
    }

    yyin = fopen(argv[1], "r");
    if (!yyin) {
        printf("Erreur: Impossible d'ouvrir le fichier '%s'\n", argv[1]);
        return 1;
    }

    initialiser_table_symboles();
    initialiser_quadruplets();

    printf("\n=== Compilation du fichier: %s ===\n", argv[1]);
    yyparse();

    fclose(yyin);
    return 0;
}
