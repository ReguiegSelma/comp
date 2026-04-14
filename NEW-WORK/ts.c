#include <stdio.h>
#include <string.h>
#include "ts.h"

Element tab[1000];
int cp = 0;

int rechercher(char name[]) {
    for (int i = 0; i < cp; i++) {
        if (strcmp(tab[i].name, name) == 0) return i;
    }
    return -1;
}

void inserer(char name[], char code[], char type[], float val, int taille) {
    if (rechercher(name) == -1) {
        strcpy(tab[cp].name, name);
        strcpy(tab[cp].code, code);
        strcpy(tab[cp].type, type);
        tab[cp].val = val;
        tab[cp].taille = taille;
        cp++;
    }
}

void afficher_ts() {
    printf("\n/******** Table des Symboles *********/\n");
    printf("Nom\tCode\tType\tTaille\tValeur\n");
    for (int i = 0; i < cp; i++) {
        printf("%s\t%s\t%s\t%d\t%.2f\n", tab[i].name, tab[i].code, tab[i].type, tab[i].taille, tab[i].val);
    }
}