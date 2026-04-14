#ifndef SYMTABLE_H
#define SYMTABLE_H

#define HASH_SIZE 101
#define MAX_ID_LEN 8

typedef enum {
    TYPE_INTEGER,
    TYPE_FLOAT,
    TYPE_INCONNU
} TypeDonnee;

typedef enum {
    CAT_VAR,
    CAT_CONST,
    CAT_TAB
} Categorie;

typedef struct Symbole {
    char nom[MAX_ID_LEN + 1];
    Categorie categorie;
    TypeDonnee type;
    int taille;
    int adresse;
    int est_init;
    int ligne_decl;

    union {
        int ival;
        float rval;
    } valeur;

    struct Symbole *suivant;
} Symbole;

/* Fonctions */
unsigned int ts_hash(const char *nom);
void ts_init(void);

int ts_inserer(const char *nom, Categorie cat, TypeDonnee type,
               int taille, int ligne);

Symbole *ts_rechercher(const char *nom);

void ts_afficher(void);
void ts_liberer(void);

Symbole *ts_get_bucket(int idx);

#endif