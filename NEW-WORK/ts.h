#ifndef TS_H
#define TS_H

typedef struct {
    char name[20];
    char code[20];  // IDF, CONST, TAB
    char type[20];  // INTEGER, FLOAT
    float val;
    int taille;
} Element;

extern Element tab[1000];
extern int cp;

int rechercher(char name[]);
void inserer(char name[], char code[], char type[], float val, int taille);
void afficher_ts();

#endif