/*
 * ============================================================
 *  TABLE DES SYMBOLES — MiniAlgo
 *  Fichier : symtable.c
 *  Implémentation : table de hachage à chaînage externe
 * ============================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symtable.h"

/* Tableau de seaux (buckets) */
static Symbole *table[HASH_SIZE];

/* Compteur d'adresses (offset mémoire cumulé) */
static int adresse_courante = 0;

/* ------------------------------------------------------------------ */
/*  Fonction de hachage djb2                                           */
/*  Distribue bien les chaînes courtes (noms d'identifiants)          */
/* ------------------------------------------------------------------ */
unsigned int ts_hash(const char *nom) {
    unsigned long h = 5381;
    int c;
    while ((c = (unsigned char)*nom++))
        h = ((h << 5) + h) + c;   /* h * 33 + c */
    return (unsigned int)(h % HASH_SIZE);
}

/* ------------------------------------------------------------------ */
/*  Initialisation : vider tous les seaux                              */
/* ------------------------------------------------------------------ */
void ts_init(void) {
    for (int i = 0; i < HASH_SIZE; i++)
        table[i] = NULL;
    adresse_courante = 0;
}

/* ------------------------------------------------------------------ */
/*  Insertion d'un nouveau symbole                                     */
/*  Retourne  0 : succès                                               */
/*            -1 : symbole déjà déclaré (double déclaration)           */
/* ------------------------------------------------------------------ */
int ts_inserer(const char *nom, Categorie cat, TypeDonnee type,
               int taille, int ligne) {

    /* Vérifier si déjà présent */
    if (ts_rechercher(nom) != NULL)
        return -1;   /* double déclaration détectée */

    unsigned int idx = ts_hash(nom);

    /* Allouer et remplir la nouvelle entrée */
    Symbole *s = (Symbole *)malloc(sizeof(Symbole));
    if (!s) { perror("malloc symtable"); exit(EXIT_FAILURE); }

    strncpy(s->nom, nom, MAX_ID_LEN);
    s->nom[MAX_ID_LEN] = '\0';
    s->categorie  = cat;
    s->type       = type;
    s->taille     = (taille > 0) ? taille : 1;
    s->adresse    = adresse_courante;
    s->est_init   = 0;
    s->ligne_decl = ligne;
    s->valeur.ival = 0;

    /* Calculer l'adresse de la prochaine variable
       INTEGER = 2 octets, FLOAT = 4 octets (convention 8086) */
    int taille_elem = (type == TYPE_FLOAT) ? 4 : 2;
    adresse_courante += s->taille * taille_elem;

    /* Insérer en tête de liste chaînée du seau */
    s->suivant = table[idx];
    table[idx] = s;

    return 0;
}

/* ------------------------------------------------------------------ */
/*  Recherche d'un symbole par son nom                                 */
/*  Retourne le pointeur sur l'entrée, NULL si absent                 */
/* ------------------------------------------------------------------ */
Symbole *ts_rechercher(const char *nom) {
    unsigned int idx = ts_hash(nom);
    Symbole *p = table[idx];
    while (p) {
        if (strcmp(p->nom, nom) == 0)
            return p;
        p = p->suivant;
    }
    return NULL;
}

/* ------------------------------------------------------------------ */
/*  Affichage de la table (utile pour le débogage / rapport)          */
/* ------------------------------------------------------------------ */
void ts_afficher(void) {
    printf("\n===== TABLE DES SYMBOLES =====\n");
    printf("%-10s %-8s %-8s %-7s %-8s %s\n",
           "Nom", "Categ.", "Type", "Taille", "Adresse", "Ligne");
    printf("----------------------------------------------\n");

    for (int i = 0; i < HASH_SIZE; i++) {
        Symbole *p = table[i];
        while (p) {
            const char *cat_str  = (p->categorie == CAT_VAR)   ? "VAR"
                                 : (p->categorie == CAT_TAB)   ? "TABLEAU"
                                 :                               "CONST";
            const char *type_str = (p->type == TYPE_INTEGER)   ? "INTEGER"
                                 : (p->type == TYPE_FLOAT)     ? "FLOAT"
                                 :                               "?";
            printf("%-10s %-8s %-8s %-7d %-8d %d\n",
                   p->nom, cat_str, type_str, p->taille,
                   p->adresse, p->ligne_decl);
            p = p->suivant;
        }
    }
    printf("==============================\n\n");
}

/* ------------------------------------------------------------------ */
/*  Libération mémoire                                                 */
/* ------------------------------------------------------------------ */
void ts_liberer(void) {
    for (int i = 0; i < HASH_SIZE; i++) {
        Symbole *p = table[i];
        while (p) {
            Symbole *tmp = p->suivant;
            free(p);
            p = tmp;
        }
        table[i] = NULL;
    }
}

/* Accès externe au seau i (utilisé par le générateur 8086) */
Symbole *ts_get_bucket(int idx) {
    if (idx < 0 || idx >= HASH_SIZE) return NULL;
    return table[idx];
}
