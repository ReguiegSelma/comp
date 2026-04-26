%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ts.h"
#include "quad.h"

extern int nb_lignes;
extern int nb_col;
extern char* yytext;
extern FILE *yyin; 
extern int nb_erreurs;

int fin_if, deb_else;
void yyerror(char *s);
int nb_erreurs = 0;
int yylex();
char type_svg[20];
char tmp_addr[10];
%}

%union {
    int entier;
    float reel;
    char* str;
}

%token <str> IDF <entier> INT_VAL <reel> FLOAT_VAL <entier> ENT_SIGNE <reel> REEL_SIGNE
%token PROGRAM DECL ENDDECL BEGIN_P END INTEGER FLOAT CONST IF ELSE FOR WHILE WRITE
%token PLUS MOINS MULT DIV AFFECT SUP INF EGAL SUPEG INFEG DIFF PV DEUXPTS VIRG PARG PARD ACCOLG ACCOLD CROCHG CROCHD
%token AND OR NOT
%type <str> expression terme facteur EXPR_LOG

%left PLUS MOINS
%left MULT DIV
%left OR
%left AND
%right NOT

%%
PROG: PROGRAM IDF DECL DECLS ENDDECL BEGIN_P INSTS END 
      {      
        if(nb_erreurs == 0){
            printf("Syntaxe Correcte\n");
            afficher_quads();
            YYACCEPT;
        }else{
            printf("\n Compilation echouee : %d erreur(s) detectee(s)\n", nb_erreurs);
        }
      }

DECLS: DEC DECLS 
     | DEC_CONST DECLS
     |;

DEC: TYPE DEUXPTS LISTE_OBJETS PV ;

TYPE: INTEGER { strcpy(type_svg, "INTEGER"); }
    | FLOAT   { strcpy(type_svg, "FLOAT"); }
    ;

LISTE_OBJETS: OBJET VIRG LISTE_OBJETS 
            | OBJET
            ;

OBJET: IDF { 
        inserer($1, "idf", type_svg, 0, 0); 
     }
     | IDF CROCHG INT_VAL CROCHD { 
        // taille du tableau doit être > 0
        if ($3 <= 0) {
            printf("Erreur Semantique ligne %d: La taille du tableau '%s' doit etre positive (donnee: %d)\n", 
                    nb_lignes, $1, $3);
            nb_erreurs++; 
        } else {
            inserer($1, "tab", type_svg, 0, $3); 
        }
     }
     ;
DEC_CONST: CONST IDF AFFECT VAL_CONST PV ;

// On récupère le nom de l'IDF via l'indexage négatif ($<str>-1 est l'IDF)
VAL_CONST: INT_VAL    { inserer($<str>-1, "cst", "INTEGER", (float)$1, 0); }
         | FLOAT_VAL  { inserer($<str>-1, "cst", "FLOAT", $1, 0); }
         | ENT_SIGNE  { inserer($<str>-1, "cst", "INTEGER", (float)$1, 0); }
         | REEL_SIGNE { inserer($<str>-1, "cst", "FLOAT", $1, 0); }

INSTS: INST INSTS | ;
INST: AFF| COND | BOUCLE | WRITE_I 
    | error PV { 
        printf("Erreur Syntaxique ligne %d: ';' manquant ou instruction mal formee\n", nb_lignes);
        nb_erreurs++;
      }
    ;
      

AFF: 
    /* --- Cas 1 : Affectation simple (x = expr) --- */
    IDF AFFECT expression PV {
        Symbole* s1 = rechercher($1);
        if (s1 == NULL) {
            printf("Erreur Semantique ligne %d: Variable '%s' non declaree\n", nb_lignes, $1);
            nb_erreurs++;
        } else if (strcmp(s1->code, "cst") == 0) {
            printf("Erreur Semantique ligne %d: Modification de la constante '%s' interdite\n", nb_lignes, $1);
            nb_erreurs++;
        } else {
            Symbole* s3 = rechercher($3);
            char* type_src;
            float val_src;

            // 1. On détermine le type et la valeur de ce qui arrive ($3)
            if (s3 != NULL) {
                type_src = s3->type;
                val_src = s3->val;
            } else {
                // Si c'est un chiffre direct (ex: 5 ou 5.5), on détecte son type
                type_src = (strchr($3, '.')) ? "FLOAT" : "INTEGER";
                val_src = atof($3);
            }

            // 2. Vérification de compatibilité avec promotion (INT -> FLOAT)
            int compatible = 0;
            if (strcmp(s1->type, type_src) == 0) {
                compatible = 1; // Même type (INT=INT ou FLOAT=FLOAT)
            } else if (strcmp(s1->type, "FLOAT") == 0 && strcmp(type_src, "INTEGER") == 0) {
                compatible = 1; // Promotion : FLOAT = INTEGER (OK)
            }

            if (!compatible) {
                printf("Erreur Semantique ligne %d: Incompatibilite de type entre %s (%s) et %s (%s)\n", 
                        nb_lignes, $1, s1->type, $3, type_src);
                nb_erreurs++;
            }

            // 3. Mise à jour de la valeur et génération du Quad
            mettre_a_jour_val($1, val_src);
            quad("=", $3, "", $1);
        }
    }
/* --- Cas 2 : Erreur sur l'expression simple --- 
| IDF AFFECT error PV {
        printf("Erreur Syntaxique: ligne %d, col %d expression invalide\n", nb_lignes, nb_col);
        nb_erreurs++;
        yyerrok;
    } */     

/* --- Cas 3 : Affectation Tableau (t[i] = expr) --- */
    | IDF CROCHG expression CROCHD AFFECT expression PV { 
        Symbole* p = rechercher($1);     // Recherche du tableau
        Symbole* p_idx = rechercher($3); // Recherche si l'indice est une variable
        Symbole* p_src = rechercher($6); // Recherche si la source est une variable

        if(p == NULL) {
            printf("Erreur Semantique ligne %d: tableau '%s' non declare\n", nb_lignes, $1);
            nb_erreurs++;
        } 
        else {
            // 1. Vérifier si c'est bien un tableau
            if(strcmp(p->code, "tab") != 0) {
                printf("Erreur Semantique ligne %d: '%s' n'est pas un tableau\n", nb_lignes, $1);
                nb_erreurs++;
            } 
            
            // 2. Vérification de la borne (si l'indice est un nombre constant)(Indice statique ou dynamique calculé)
            // On convertit le texte de l'indice en entier pour comparer
            float v_idx = (p_idx) ? p_idx->val : atof($3);
            if (v_idx >= p->taille || v_idx < 0) {
                printf("Erreur Semantique ligne %d: index %.0f hors limites pour '%s' (taille %d)\n", 
                        nb_lignes, v_idx, $1, p->taille);
                nb_erreurs++;
            }

            //didnt do this 
            // 3. Vérification des types (AMÉLIORÉE avec promotion)
            char* type_source;
            if (p_src != NULL) {
                type_source = p_src->type;
            } else {
                // Détecter le type si c'est une valeur brute (chiffre)
                type_source = (strchr($6, '.')) ? "FLOAT" : "INTEGER";
            }

            int compatible = 0;
            if (strcmp(p->type, type_source) == 0) {
                compatible = 1; // Types identiques
            } else if (strcmp(p->type, "FLOAT") == 0 && strcmp(type_source, "INTEGER") == 0) {
                compatible = 1; // Promotion : Tableau FLOAT accepte INTEGER
            }

            if (!compatible) {
                printf("Erreur Semantique ligne %d: incompatibilite de type entre le tableau %s (%s) et %s (%s)\n", 
                        nb_lignes, $1, p->type, $6, type_source);
                nb_erreurs++;
            }

            // 4. Génération du quadruplet
            // Note : Pour les tableaux, on ne met pas à jour 'val' car la TS 
            // ne stocke qu'une valeur simple, pas tout le contenu du tableau.
            char res[40];
            sprintf(res, "%s[%s]", $1, $3);
            quad("=", $6, "", res);
        }
    }

    /* --- Cas 4 : Erreurs de rattrapage Tableau --- */
   | IDF CROCHG error CROCHD AFFECT expression PV {
        printf("Erreur Syntaxique: ligne %d , col %d index invalide \n", nb_lignes, nb_col);
        nb_erreurs++;
        yyerrok;
     }
   | IDF CROCHG expression CROCHD AFFECT error PV {
        printf("Erreur Syntaxique: ligne %d , col %d expression invalide \n", nb_lignes, nb_col);
        nb_erreurs++;
        yyerrok;
     }


expression: expression PLUS terme { 
                if(strcmp($1, "empty") == 0 || strcmp($3, "empty") == 0) {
                    $$ = strdup("empty");
                } else {
                    Symbole* s1 = rechercher($1);
                    Symbole* s3 = rechercher($3);
                    float v1 = (s1) ? obtenir_val($1) : atof($1);
                    float v3 = (s3) ? obtenir_val($3) : atof($3);

                    // Détermination du type du temporaire
                    char* type_res = "INTEGER";
                    if ((s1 && strcmp(s1->type, "FLOAT") == 0) || (s3 && strcmp(s3->type, "FLOAT") == 0)) 
                        type_res = "FLOAT";

                    $$ = new_temp(); 
                    quad("+", $1, $3, $$); 
                    inserer($$, "temp", type_res, v1 + v3, 0); 
                }
            }
          | expression MOINS terme { 
                if(strcmp($1, "empty") == 0 || strcmp($3, "empty") == 0) {
                    $$ = strdup("empty");
                } else {
                    Symbole* s1 = rechercher($1);
                    Symbole* s3 = rechercher($3);
                    float v1 = (s1) ? obtenir_val($1) : atof($1);
                    float v3 = (s3) ? obtenir_val($3) : atof($3);

                    char* type_res = "INTEGER";
                    if ((s1 && strcmp(s1->type, "FLOAT") == 0) || (s3 && strcmp(s3->type, "FLOAT") == 0)) 
                        type_res = "FLOAT";

                    $$ = new_temp(); 
                    quad("-", $1, $3, $$); 
                    inserer($$, "temp", type_res, v1 - v3, 0);
                }
            }
          | terme { $$ = $1; }
          ;

terme: terme MULT facteur { 
            if(strcmp($1, "empty") == 0 || strcmp($3, "empty") == 0) {
                $$ = strdup("empty");
            } else {
                Symbole* s1 = rechercher($1);
                Symbole* s3 = rechercher($3);
                float v1 = (s1) ? obtenir_val($1) : atof($1);
                float v3 = (s3) ? obtenir_val($3) : atof($3);

                char* type_res = "INTEGER";
                if ((s1 && strcmp(s1->type, "FLOAT") == 0) || (s3 && strcmp(s3->type, "FLOAT") == 0)) 
                    type_res = "FLOAT";

                $$ = new_temp(); 
                quad("*", $1, $3, $$); 
                inserer($$, "temp", type_res, v1 * v3, 0);
            }
        }
| terme DIV facteur { 
            if(strcmp($1, "empty") == 0 || strcmp($3, "empty") == 0) {
                $$ = strdup("empty");
            } else {
                Symbole* s1 = rechercher($1);
                Symbole* s3 = rechercher($3);
                float v1 = (s1) ? obtenir_val($1) : atof($1);
                float v3 = (s3) ? obtenir_val($3) : atof($3);

                if (v3 == 0) {
                    printf("Erreur Semantique ligne %d: Division par zero detectee !\n", nb_lignes);
                    nb_erreurs++;
                    $$ = strdup("empty");
                } else {
                    // Pour la division, on peut décider qu'elle donne toujours un FLOAT
                    // ou suivre la règle des entiers. Ici, on suit la règle mixte :
                    char* type_res = "INTEGER";
                    if ((s1 && strcmp(s1->type, "FLOAT") == 0) || (s3 && strcmp(s3->type, "FLOAT") == 0)) 
                        type_res = "FLOAT";

                    $$ = new_temp(); 
                    quad("/", $1, $3, $$); 
                    inserer($$, "temp", type_res, v1 / v3, 0);
                }
            }
        }
     | facteur { $$ = $1; }
     ;

facteur: 
    /* --- Identifiant simple (avec vérification si c'est un tableau) --- */
    IDF { 
        Symbole* s = rechercher($1);
        if (s == NULL) {
            printf("Erreur Semantique: variable '%s' non declaree ligne %d\n", $1, nb_lignes);
            nb_erreurs++;
            $$ = strdup("empty");
        } else {
            if (strcmp(s->code, "tab") == 0) {
                printf("Erreur Semantique: '%s' est un tableau, index requis ligne %d\n", $1, nb_lignes);
                nb_erreurs++;
                $$ = strdup("empty");
            } else {
                $$ = strdup($1);
            }
        }
    }
/* --- Accès Tableau (avec vérification de borne et type) --- */
    | IDF CROCHG expression CROCHD { 
        Symbole* s = rechercher($1);
        if (s == NULL) {
            printf("Erreur Semantique: ligne %d: tableau '%s' non declare\n", nb_lignes, $1);
            nb_erreurs++; 
            $$ = strdup("empty");
        } else {
            // 2. Vérification de la nature de l'objet
            if (strcmp(s->code, "tab") != 0) {
                printf("Erreur Semantique: ligne %d: '%s' n'est pas un tableau\n", nb_lignes, $1);
                nb_erreurs++;
                $$ = strdup("empty");
            } else {
                // Si l'index est valide (pas empty), on vérifie la borne statiquement
                if (strcmp($3, "empty") != 0) {
                    // On récupère la valeur numérique de l'index (soit le chiffre, soit la valeur de la variable)
                    float v_idx = (rechercher($3)) ? obtenir_val($3) : atof($3);
                    
                    if (v_idx >= s->taille || v_idx < 0) {
                        printf("Erreur Semantique ligne %d: index %.0f hors limites pour '%s' (taille %d)\n", 
                                nb_lignes, v_idx, $1, s->taille);
                        nb_erreurs++;
                        yyerrok;
                    }
                }

                // 4. Construction du nom pour le quadruplet (ex: T[2] ou T[i])
                char* t = malloc(50);
                sprintf(t, "%s[%s]", $1, $3);
                $$ = t; 
            }
        }
    }
/* --- Rattrapage d'erreur sur l'index du tableau --- */
    | IDF CROCHG error CROCHD {
        printf("Erreur Syntaxique: ligne %d , col %d index invalide \n", nb_lignes, nb_col);
        nb_erreurs++;
        yyerrok;
        $$ = strdup("empty");
    }
    
    | INT_VAL { 
        char b[20]; sprintf(b, "%d", $1); $$ = strdup(b); 
        // Important : on enregistre la constante pour que rechercher() la trouve avec son type
        if (!rechercher(b)) inserer(b, "cst", "INTEGER", (float)$1, 0);
    }
    | FLOAT_VAL { 
        char b[20]; sprintf(b, "%.2f", $1); $$ = strdup(b); 
        if (!rechercher(b)) inserer(b, "cst", "FLOAT", $1, 0);
    }
    | ENT_SIGNE { 
        char b[20]; sprintf(b, "%d", $1); $$ = strdup(b); 
        if (!rechercher(b)) inserer(b, "cst", "INTEGER", (float)$1, 0);
    }
    | REEL_SIGNE { 
        char b[20]; sprintf(b, "%.2f", $1); $$ = strdup(b); 
        if (!rechercher(b)) inserer(b, "cst", "FLOAT", $1, 0);
    }

/* --- Expressions entre parenthèses --- */
    | PARG expression PARD { $$ = $2; }

    /* --- Rattrapage d'erreur sur parenthèses --- */
    | PARG error PARD {
        printf("Erreur Syntaxique: ligne %d , col %d expression invalide \n", nb_lignes, nb_col);
        nb_erreurs++;
        yyerrok;
        $$ = strdup("empty");
    }
    ;
//didnt do this read it 
COND:
    IF PARG EXPR_LOG PARD ACCOLG INSTS ACCOLD ELSE ACCOLG INSTS ACCOLD
    {
        /* IF + ELSE avec blocs obligatoires */

        int br_index = prochain_quad();

        // saut après IF (skip ELSE)
        quad("BR", "", "", "");

        // patch du BZ → début ELSE
        sprintf(tmp_addr, "%d", br_index + 1);
        modifier_quad(fin_if, 3, tmp_addr);

        // patch du BR → fin ELSE
        sprintf(tmp_addr, "%d", prochain_quad());
        modifier_quad(br_index, 3, tmp_addr);
    }

  | IF PARG EXPR_LOG PARD ACCOLG INSTS ACCOLD
    {
        /* IF sans ELSE */

        sprintf(tmp_addr, "%d", prochain_quad());
        modifier_quad(fin_if, 3, tmp_addr);
    }
;

BOUCLE: WHILE { push_loop_start(prochain_quad()); }
        PARG EXPR_LOG PARD 
        {
           int q_bz = prochain_quad();
           quad("BZ", "", $4, ""); 
           push_loop_cond(q_bz); // On mémorise l'adresse du BZ pour le patcher
        }
        ACCOLG INSTS ACCOLD
        {
           int cond = pop_loop_cond();
           int start = pop_loop_start();
           
           sprintf(tmp_addr, "%d", start);
           quad("BR", "", "", tmp_addr); // Retour au test de condition
           
           sprintf(tmp_addr, "%d", prochain_quad());
           modifier_quad(cond, 3, tmp_addr); // Sortie de boucle
        }
        | FOR PARG IDF DEUXPTS INT_VAL DEUXPTS INT_VAL DEUXPTS INT_VAL PARD 
        {
           // Initialisation : i = start_val
        // 1. Initialisation dans la TS pour la propagation
            mettre_a_jour_val($3, (float)$5);

            // 2. Génération du quad d'initialisation (i = debut)
            char val_init[20]; sprintf(val_init, "%d", $5);
            quad("=", val_init, "", $3);
            
            // 3. Mémoriser le début du test de borne
            push_loop_start(prochain_quad()); 
            
            // 4. Test de sortie : si i > limite, on crée un drapeau t
            char* t = new_temp();
            char val_limit[20]; sprintf(val_limit, "%d", $7);
            quad("BG", $3, val_limit, t); 
            
            // 5. Saut si i > limite
            int q_bz = prochain_quad();
            quad("BZ", "", t, ""); 
            push_loop_cond(q_bz);
        }
        ACCOLG INSTS ACCOLD
        {
            // 6. Mise à jour de la valeur de l'index dans la TS (i = i + step)
            float v_current = obtenir_val($3);
            mettre_a_jour_val($3, v_current + $9);

            // 7. Génération du quad d'incrémentation
            char* t2 = new_temp();
            char val_step[20]; sprintf(val_step, "%d", $9);
            quad("+", $3, val_step, t2);
            quad("=", t2, "", $3);
            
            // 8. On récupère les adresses
            int cond_to_patch = pop_loop_cond();
            int loop_start = pop_loop_start();
            
            // 9. Bouclage
            sprintf(tmp_addr, "%d", loop_start);
            quad("BR", "", "", tmp_addr);
            
            // 10. Sortie définitive
            sprintf(tmp_addr, "%d", prochain_quad());
            modifier_quad(cond_to_patch, 3, tmp_addr);
        }

EXPR_LOG: EXPR_LOG OR EXPR_LOG  { 
            float v1 = (rechercher($1)) ? obtenir_val($1) : 0;
            float v3 = (rechercher($3)) ? obtenir_val($3) : 0;
            $$ = new_temp(); 
            quad("OR", $1, $3, $$); 
            inserer($$, "temp", "INTEGER", (v1 || v3) ? 1.0 : 0.0, 0);
        }
        | EXPR_LOG AND EXPR_LOG { 
            float v1 = (rechercher($1)) ? obtenir_val($1) : 0;
            float v3 = (rechercher($3)) ? obtenir_val($3) : 0;
            $$ = new_temp(); 
            quad("AND", $1, $3, $$); 
            inserer($$, "temp", "INTEGER", (v1 && v3) ? 1.0 : 0.0, 0);
        }
        | NOT EXPR_LOG { 
            float v2 = (rechercher($2)) ? obtenir_val($2) : 0;
            $$ = new_temp(); 
            quad("NOT", $2, "", $$); 
            inserer($$, "temp", "INTEGER", (!v2) ? 1.0 : 0.0, 0);
        }
        | expression SUP expression   { 
            float v1 = (rechercher($1)) ? obtenir_val($1) : atof($1);
            float v3 = (rechercher($3)) ? obtenir_val($3) : atof($3);
            $$ = new_temp(); 
            quad("SUP", $1, $3, $$); 
            inserer($$, "temp", "INTEGER", (v1 > v3) ? 1.0 : 0.0, 0);
        }
        | expression INF expression   { 
            float v1 = (rechercher($1)) ? obtenir_val($1) : atof($1);
            float v3 = (rechercher($3)) ? obtenir_val($3) : atof($3);
            $$ = new_temp(); 
            quad("INF", $1, $3, $$); 
            inserer($$, "temp", "INTEGER", (v1 < v3) ? 1.0 : 0.0, 0);
        }
        | expression SUPEG expression { 
            float v1 = (rechercher($1)) ? obtenir_val($1) : atof($1);
            float v3 = (rechercher($3)) ? obtenir_val($3) : atof($3);
            $$ = new_temp(); 
            quad("SUPEG", $1, $3, $$); 
            inserer($$, "temp", "INTEGER", (v1 >= v3) ? 1.0 : 0.0, 0);
        }
        | expression INFEG expression { 
            float v1 = (rechercher($1)) ? obtenir_val($1) : atof($1);
            float v3 = (rechercher($3)) ? obtenir_val($3) : atof($3);
            $$ = new_temp(); 
            quad("INFEG", $1, $3, $$); 
            inserer($$, "temp", "INTEGER", (v1 <= v3) ? 1.0 : 0.0, 0);
        }
        | expression DIFF expression  { 
            float v1 = (rechercher($1)) ? obtenir_val($1) : atof($1);
            float v3 = (rechercher($3)) ? obtenir_val($3) : atof($3);
            $$ = new_temp(); 
            quad("DIFF", $1, $3, $$); 
            inserer($$, "temp", "INTEGER", (v1 != v3) ? 1.0 : 0.0, 0);
        }
        | expression EGAL expression  { 
            float v1 = (rechercher($1)) ? obtenir_val($1) : atof($1);
            float v3 = (rechercher($3)) ? obtenir_val($3) : atof($3);
            $$ = new_temp(); 
            quad("EGAL", $1, $3, $$); 
            inserer($$, "temp", "INTEGER", (v1 == v3) ? 1.0 : 0.0, 0);
        }
        | PARG EXPR_LOG PARD    { $$ = $2; }
        ;

WRITE_I: WRITE PARG IDF PARD PV { 
    Symbole* s = rechercher($3);
    if(s == NULL) { 
        printf("Erreur Semantique ligne %d: variable '%s' non declaree\n", nb_lignes, $3);
        nb_erreurs++;
    } else {
        // Affiche le nom ET la valeur stockée dans la TS au moment de la compilation
        printf(" Variable %s = %.2f\n", s->name, s->val);
    }
}



%%

void yyerror(char *s) {}


int main(int argc, char *argv[]) {
    if (argc > 1) {
        FILE *f = fopen(argv[1], "r");
        if (f) { yyin = f; }
        else {
            printf("Impossible d'ouvrir le fichier !\n");
            exit(1);
        }
    }
    
    yyparse();

    afficher_ts_ids();
    afficher_ts_kw();
    afficher_ts_sep();
    
    return 0;
}
