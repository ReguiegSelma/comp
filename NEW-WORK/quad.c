#include <stdio.h>
#include <string.h>
#include "quad.h"

qdr quad[1000];
int qc = 0;

void quadr(char op[], char arg1[], char arg2[], char res[]) {
    strcpy(quad[qc].op, op);
    strcpy(quad[qc].arg1, arg1);
    strcpy(quad[qc].arg2, arg2);
    strcpy(quad[qc].res, res);
    qc++;
}

void update_quad(int num_quad, int col_quad, char val[]) {
    if (col_quad == 1) strcpy(quad[num_quad].arg1, val);
    else if (col_quad == 2) strcpy(quad[num_quad].arg2, val);
    else if (col_quad == 3) strcpy(quad[num_quad].res, val);
}

void afficher_quads() {
    printf("\n/ Liste des Quadruplets /\n");
    for (int i = 0; i < qc; i++) {
        printf("%d - (%s, %s, %s, %s)\n", i, quad[i].op, quad[i].arg1, quad[i].arg2, quad[i].res);
    }
}