#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "table_symboles.h"

Symbole table_symboles[TAILLE_TABLE];
int nb_symboles = 0;

void initialiser_table_symboles() {
    for (int i = 0; i < TAILLE_TABLE; i++) {
        table_symboles[i].utilise = 0;
        strcpy(table_symboles[i].nom, "");
        strcpy(table_symboles[i].type, "");
        strcpy(table_symboles[i].taille, "");
    }
    nb_symboles = 0;
}

int hash_function(const char* nom) {
    int hash = 0;
    for (int i = 0; nom[i] != '\0'; i++) {
        hash = (hash * 31 + nom[i]) % TAILLE_TABLE;
    }
    return hash;
}

int rechercher_symbole(const char* nom) {
    int index = hash_function(nom);
    int compteur = 0;
    
    while (compteur < TAILLE_TABLE) {
        if (table_symboles[index].utilise && strcmp(table_symboles[index].nom, nom) == 0) {
            return index;
        }
        if (!table_symboles[index].utilise) {
            return -1;
        }
        index = (index + 1) % TAILLE_TABLE;
        compteur++;
    }
    return -1;
}

void inserer_symbole(const char* nom, const char* type, const char* taille) {
    int index = hash_function(nom);
    
    while (table_symboles[index].utilise) {
        index = (index + 1) % TAILLE_TABLE;
    }
    
    strcpy(table_symboles[index].nom, nom);
    strcpy(table_symboles[index].type, type);
    if (taille != NULL) {
        strcpy(table_symboles[index].taille, taille);
    } else {
        strcpy(table_symboles[index].taille, "");
    }
    table_symboles[index].utilise = 1;
    nb_symboles++;
}

void afficher_table_symboles() {
    printf("\n=== TABLE DES SYMBOLES ===\n");
    printf("%-15s %-15s %-10s\n", "NOM", "TYPE", "TAILLE");
    printf("----------------------------------------------\n");
    
    for (int i = 0; i < TAILLE_TABLE; i++) {
        if (table_symboles[i].utilise) {
            printf("%-15s %-15s %-10s\n", 
                   table_symboles[i].nom, 
                   table_symboles[i].type,
                   table_symboles[i].taille[0] ? table_symboles[i].taille : "-");
        }
    }
    printf("Total: %d symboles\n", nb_symboles);
    printf("=========================\n\n");
}
