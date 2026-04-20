#ifndef QUAD_H
#define QUAD_H

typedef struct
{
    char *op;
    char *op1;
    char *op2;
    char *res;
} quad_struct;

// Fonctions principales
void quad(char *op, char *op1, char *op2, char *res);
void afficher_quads();
int prochain_quad();                                // Retourne l'indice du prochain quad
void modifier_quad(int indice, int col, char *val); // Pour les sauts
char *new_temp();                                   // Pour generer T1, T2, T3...

#endif