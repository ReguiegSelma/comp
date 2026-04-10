#ifndef TABLE_SYMBOLES_H
#define TABLE_SYMBOLES_H

#define TAILLE_TABLE 100

typedef struct {
    char nom[8];
    char type[20];
    char taille[20];  // Pour les tableaux
    int utilise;
} Symbole;

extern Symbole table_symboles[TAILLE_TABLE];
extern int nb_symboles;

void initialiser_table_symboles();
int hash_function(const char* nom);
int rechercher_symbole(const char* nom);
void inserer_symbole(const char* nom, const char* type, const char* taille);
void afficher_table_symboles();

#endif
