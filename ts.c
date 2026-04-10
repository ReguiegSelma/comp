#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ts.h"

extern int nb_lignes;
extern int nb_erreurs;

Symbole table[1000];
int cp_ts = 0; // Compteur d'elements dans la table

// Fonction pour inserer un symbole
void inserer(char *name, char *type, int isConst, int isTab, int size)
{
    if (rechercher(name) == -1)
    {
        if (cp_ts < 1000)
        {
            strcpy(table[cp_ts].name, name);
            strcpy(table[cp_ts].type, type);
            table[cp_ts].estConstante = isConst;
            table[cp_ts].estTableau = isTab;
            table[cp_ts].taille = size;
            cp_ts++;
        }
        else
        {
            printf("Erreur: Table des symboles pleine !\n");
        }
    }
    else
    {
        printf("Erreur Semantique: ligne %d, Double declaration de '%s'\n", nb_lignes, name);
        nb_erreurs++;
    }
}

// Fonction pour rechercher un symbole (retourne l'indice ou -1)
int rechercher(char *name)
{
    for (int i = 0; i < cp_ts; i++)
    {
        if (strcmp(table[i].name, name) == 0)
        {
            return i;
        }
    }
    return -1;
}

// Pour debugger : affiche le contenu de la table
void afficher_ts()
{
    printf("\n--- TABLE DES SYMBOLES ---\n");
    printf("Nom\t| Type\t\t| Const\t| Tab\t| Taille\n");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < cp_ts; i++)
    {
        printf("%s\t| %s\t| %d\t| %d\t| %d\n",
               table[i].name, table[i].type,
               table[i].estConstante, table[i].estTableau, table[i].taille);
    }
}