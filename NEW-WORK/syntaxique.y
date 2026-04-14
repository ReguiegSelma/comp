%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ts.h"
#include "quad.h"

extern int nb_line;
extern int col;
int yylex();
void yyerror(char* msg);

char save_type[20];
int cpt_t = 1;
int div_zero_flag = 0; 

char* cree_temp() {
    char* t = malloc(15);
    sprintf(t, "T%d", cpt_t++);
    return t;
}

void verif_type(char* idf_dest, char* type_expr) {
    if (div_zero_flag) return; 
    int p = rechercher(idf_dest);
    if(p != -1) {
        if(strcmp(tab[p].type, "INTEGER") == 0 && strcmp(type_expr, "FLOAT") == 0) {
            printf("Erreur Semantique: ligne %d, Incompatibilite de type sur %s\n", nb_line, idf_dest);
        }
    }
}
%}

%union {
    int entier;
    float reel;
    char* str;
    struct {
       char* nom;
       char* type;
    } exp;
}

%token <str>idf <entier>cst_int <reel>cst_float
%token kw_program kw_decl kw_enddecl kw_begin kw_end kw_integer kw_float kw_const kw_if kw_else kw_for kw_while comp_egal
%type <exp> EXPR
%type <entier> INDEX

%left '+' '-'
%left '*' '/'

%%
S: kw_program idf kw_decl LIST_DEC kw_enddecl kw_begin LIST_INST kw_end ;

LIST_DEC: DEC LIST_DEC | ;
DEC: TYPE ':' LIST_IDF ';' | kw_const idf '=' cst_int ';' { inserer($2, "CONST", "INTEGER", (float)$4, 0); } ;

TYPE: kw_integer { strcpy(save_type, "INTEGER"); } | kw_float { strcpy(save_type, "FLOAT"); } ;

LIST_IDF: OBJET ',' LIST_IDF | OBJET ;
OBJET: idf { inserer($1, "IDF", save_type, 0, 0); } 
     | idf '[' cst_int ']' { inserer($1, "TAB", save_type, 0, $3); } ;

LIST_INST: INST LIST_INST | ;
INST: AFF | COND | BOUCLE_FOR | BOUCLE_WHILE | error ';' ;

AFF: idf '=' EXPR ';' {
        div_zero_flag = 0; 
        int p = rechercher($1);
        if(p == -1) printf("Erreur Semantique: ligne %d, %s non declaree\n", nb_line, $1);
        else {
            if(strcmp(tab[p].code, "CONST") == 0) printf("Erreur Semantique: ligne %d, %s est une CONSTANTE\n", nb_line, $1);
            else {
                verif_type($1, $3.type);
                tab[p].val = atof($3.nom);
                quadr("=", $3.nom, "", $1);
            }
        }
     }
     /* CORRECTION ICI : Utilisation de INDEX au lieu de cst_int */
     | idf '[' INDEX ']' '=' EXPR ';' {
        int p = rechercher($1);
        if(p != -1) {
            if(strcmp(tab[p].code, "TAB") != 0) {
                printf("Erreur Semantique: ligne %d, %s n'est pas un tableau\n", nb_line, $1);
            } else {
                if($3 < 0) printf("Erreur Semantique: ligne %d, Indice negatif (%d) interdit pour %s\n", nb_line, $3, $1);
                else if($3 >= tab[p].taille) printf("Erreur Semantique: ligne %d, Depassement des bornes sur %s\n", nb_line, $1);
                
                verif_type($1, $6.type);
                char dest[30]; sprintf(dest, "%s[%d]", $1, $3);
                quadr("=", $6.nom, "", dest);
            }
        }
     }
;

INDEX: cst_int { $$ = $1; } | '-' cst_int { $$ = -$2; } ;

EXPR: EXPR '+' EXPR { 
        $$.nom = cree_temp(); 
        $$.type = (strcmp($1.type, "FLOAT") == 0 || strcmp($3.type, "FLOAT") == 0) ? "FLOAT" : "INTEGER";
        quadr("+", $1.nom, $3.nom, $$.nom); 
    }
    | EXPR '/' EXPR { 
        if(strcmp($3.nom, "0") == 0) { printf("Erreur Semantique: ligne %d, Division par zero\n", nb_line); div_zero_flag = 1; }
        int p = rechercher($3.nom);
        if(p != -1 && tab[p].val == 0) { printf("Erreur Semantique: ligne %d, Division par zero (variable %s nulle)\n", nb_line, $3.nom); div_zero_flag = 1; }
        $$.nom = cree_temp(); $$.type = "FLOAT"; 
        quadr("/", $1.nom, $3.nom, $$.nom); 
    }
    | idf { 
        int p = rechercher($1);
        if(p == -1) { printf("Erreur Semantique: ligne %d, %s non declaree\n", nb_line, $1); $$.type = "UNKNOWN"; }
        else $$.type = tab[p].type;
        $$.nom = $1; 
    }
    | cst_int { char s[12]; sprintf(s, "%d", $1); $$.nom = strdup(s); $$.type = "INTEGER"; }
    | cst_float { char s[12]; sprintf(s, "%.2f", $1); $$.nom = strdup(s); $$.type = "FLOAT"; }
;

COND: kw_if '(' EXPR '>' EXPR ')' '{' LIST_INST '}' ;
BOUCLE_FOR: kw_for '(' idf ':' cst_int ':' cst_int ':' cst_int ')' '{' LIST_INST '}' ;
BOUCLE_WHILE: kw_while '(' EXPR '<' EXPR ')' '{' LIST_INST '}' ;

%%
void yyerror(char* msg) { printf("Erreur Syntaxique: ligne %d, col %d\n", nb_line, col); }
int main() { yyparse(); afficher_ts(); afficher_quads(); return 0; }