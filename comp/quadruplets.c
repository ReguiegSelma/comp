#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "quadruplets.h"

Quadruplet quadruplets[MAX_QUAD];
int nb_quad = 0;
int nb_temp = 0;
int nb_etiq = 0;

void initialiser_quadruplets() {
    nb_quad = 0;
    nb_temp = 0;
    nb_etiq = 0;
}

void generer_quadruplet(const char* op, const char* arg1, const char* arg2, const char* res) {
    if (nb_quad >= MAX_QUAD) {
        printf("Erreur: Nombre maximum de quadruplets atteint\n");
        exit(1);
    }
    
    strcpy(quadruplets[nb_quad].operateur, op);
    strcpy(quadruplets[nb_quad].operande1, arg1);
    strcpy(quadruplets[nb_quad].operande2, arg2);
    strcpy(quadruplets[nb_quad].resultat, res);
    nb_quad++;
}

void afficher_quadruplets() {
    printf("\n=== CODE INTERMEDIAIRE (QUADRUPLETS) ===\n");
    printf("%-5s %-10s %-15s %-15s %-15s\n", "NUM", "OPER", "ARG1", "ARG2", "RES");
    printf("----------------------------------------------------------------\n");
    
    for (int i = 0; i < nb_quad; i++) {
        printf("%-5d %-10s %-15s %-15s %-15s\n", 
               i, 
               quadruplets[i].operateur,
               quadruplets[i].operande1,
               quadruplets[i].operande2,
               quadruplets[i].resultat);
    }
    printf("Total: %d quadruplets generes\n", nb_quad);
    printf("========================================\n\n");
}

char* creer_temp() {
    char* temp = malloc(20);
    sprintf(temp, "T%d", nb_temp++);
    return temp;
}

int creer_etiquette() {
    return nb_etiq++;
}

char* creer_etiq_str(int num) {
    char* etiq = malloc(20);
    sprintf(etiq, "E%d", num);
    return etiq;
}

void generer_etiquette(int num) {
    char etiq[20];
    sprintf(etiq, "E%d", num);
    generer_quadruplet("LABEL", etiq, "", "");
}
