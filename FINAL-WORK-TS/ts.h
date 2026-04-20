#ifndef TS_H
#define TS_H

// Structure elt_idf_cst pour Identifiants, Tableaux et Constantes
typedef struct Symbole {
    char name[20];      
    char code[20];      // "idf", "tab", "cst,temp"
    char type[20];      // "INTEGER", "FLOAT"
    float val;          // Valeur réelle pour les calculs/constantes
    int taille;         // Taille si c'est un tableau
    struct Symbole *next;
} Symbole;

// Structure pour Mots-clés et Séparateurs
typedef struct StrEntry {
    char name[20];
    char code[20];
    struct StrEntry *next;
} StrEntry;

// Prototypes
void inserer(const char *name, const char *code, const char *type, float val, int taille);
Symbole* rechercher(const char *name);
void inserer_kw(const char *name, const char *code);
void inserer_sep(const char *name, const char *code);
void afficher_ts_ids();
void afficher_ts_kw();
void afficher_ts_sep();

// Fonctions de mise à jour (Crucial pour la propagation)
void mettre_a_jour_val(const char *name, float v);
float obtenir_val(const char *name);

// Fonctions pour la pile des boucles (Gestion de l'imbrication)
void push_loop_start(int addr);
int pop_loop_start();
void push_loop_cond(int addr);
int pop_loop_cond();

#endif