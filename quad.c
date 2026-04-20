#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "quad.h"

quad_struct quad_table[1000];
int qc = 0;     // Compteur de quadruplets
int temp_c = 1; // Compteur de temporaires T1, T2...

void quad(char *op, char *op1, char *op2, char *res)
{
    quad_table[qc].op = strdup(op);
    quad_table[qc].op1 = strdup(op1);
    quad_table[qc].op2 = strdup(op2);
    quad_table[qc].res = strdup(res);
    qc++;
}

int prochain_quad()
{
    return qc;
}

void modifier_quad(int indice, int col, char *val)
{
    // col 1: op1, col 2: op2, col 3: res
    if (col == 1)
        quad_table[indice].op1 = strdup(val);
    else if (col == 2)
        quad_table[indice].op2 = strdup(val);
    else if (col == 3)
        quad_table[indice].res = strdup(val);
}

char *new_temp()
{
    char *t = malloc(10);
    sprintf(t, "T%d", temp_c++);
    return t;
}

void afficher_quads()
{
    printf("\n--- QUADRUPLETS GENERES ---\n");
    for (int i = 0; i < qc; i++)
    {
        printf("%d - ( %s, %s, %s, %s )\n", i,
               quad_table[i].op,
               quad_table[i].op1,
               quad_table[i].op2,
               quad_table[i].res);
    }
}