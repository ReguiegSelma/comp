#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ts.h"

// Tables de symboles
elt_idf_cst ts_idf_cst[MAX_IDF_CST];
elt_kw ts_kw[MAX_KW];
elt_sep ts_sep[MAX_SEP];

int count_idf_cst = 0;
int count_kw = 0;
int count_sep = 0;

extern int nb_lignes;
extern int nb_erreurs;

int search_idf_cst(char entity[]) {
    for (int i = 0; i < count_idf_cst; i++) {
        if (strcmp(entity, ts_idf_cst[i].name) == 0)
            return i;
    }
    return -1;
}

int search_kw(char entity[]) {
    for (int i = 0; i < count_kw; i++) {
        if (strcmp(entity, ts_kw[i].name) == 0)
            return i;
    }
    return -1;
}

int search_sep(char entity[]) {
    for (int i = 0; i < count_sep; i++) {
        if (strcmp(entity, ts_sep[i].name) == 0)
            return i;
    }
    return -1;
}

void insert_idf_cst(char entity[], char code[], char type[], float value, int isTab, int size, int isConst) {
    if (search_idf_cst(entity) == -1) {
        strcpy(ts_idf_cst[count_idf_cst].name, entity);
        strcpy(ts_idf_cst[count_idf_cst].code, code);
        strcpy(ts_idf_cst[count_idf_cst].type, type);
        ts_idf_cst[count_idf_cst].value = value;
        ts_idf_cst[count_idf_cst].estTableau = isTab;
        ts_idf_cst[count_idf_cst].taille = size;
        ts_idf_cst[count_idf_cst].estConstante = isConst;
        ts_idf_cst[count_idf_cst].a_une_valeur = (value != 0);
        count_idf_cst++;
    } else {
        printf("Erreur Semantique: ligne %d, Double declaration de '%s'\n", nb_lignes, entity);
        nb_erreurs++;
    }
}

void insert_kw(char entity[], char code[]) {
    if (search_kw(entity) == -1) {
        strcpy(ts_kw[count_kw].name, entity);
        strcpy(ts_kw[count_kw].code, code);
        count_kw++;
    }
}

void insert_sep(char entity[], char code[]) {
    if (search_sep(entity) == -1) {
        strcpy(ts_sep[count_sep].name, entity);
        strcpy(ts_sep[count_sep].code, code);
        count_sep++;
    }
}

void afficher_ts_ids() {
    printf("\n--- TS IDENTIFIANTS ET CONSTANTES ---\n");
    if (count_idf_cst == 0) {
        printf("(vide)\n");
        return;
    }
    printf("%-15s | %-10s | %-10s | %-10s | %-8s | %-6s\n", 
           "Nom", "Code", "Type", "Valeur", "Tableau", "Const");
    printf("---------------------------------------------------------------\n");
    for (int i = 0; i < count_idf_cst; i++) {
        printf("%-15s | %-10s | %-10s | %-10.2f | %-8d | %-6d\n",
               ts_idf_cst[i].name,
               ts_idf_cst[i].code,
               ts_idf_cst[i].type,
               ts_idf_cst[i].value,
               ts_idf_cst[i].estTableau,
               ts_idf_cst[i].estConstante);
    }
}

void afficher_ts_kw() {
    printf("\n--- TS MOTS-CLES ---\n");
    if (count_kw == 0) {
        printf("(vide)\n");
        return;
    }
    for (int i = 0; i < count_kw; i++) {
        printf("%s\n", ts_kw[i].name);
    }
}

void afficher_ts_sep() {
    printf("\n--- TS SEPARATEURS ---\n");
    if (count_sep == 0) {
        printf("(vide)\n");
        return;
    }
    for (int i = 0; i < count_sep; i++) {
        printf("%s\n", ts_sep[i].name);
    }
}