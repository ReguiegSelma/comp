#ifndef TS_H
#define TS_H

typedef struct {
    char name[20];
    char type[20];
    int estConstante; // 1 si c'est une CONST, 0 sinon
    int estTableau;   // 1 si c'est un tableau, 0 sinon
    int taille;       // Taille du tableau
} Symbole;

extern Symbole table[1000]; // La table des symboles

void inserer(char* name, char* type, int isConst, int isTab, int size);
int rechercher(char* name);
void afficher_ts();

#endif