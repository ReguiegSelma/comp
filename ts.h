#ifndef TS_H
#define TS_H

typedef struct Symbole {
    char name[20];
    char type[20];
    int estConstante;
    int estTableau;
    int taille;
    float valeur;
    int a_une_valeur;
    struct Symbole* next;
} Symbole;

void inserer(const char* name, const char* type, int isConst, int isTab, int size);
Symbole* rechercher(const char* name);

void inserer_kw(const char* lexeme);
void inserer_sep(const char* lexeme);

void afficher_ts_ids();
void afficher_ts_kw();
void afficher_ts_sep();

#endif
