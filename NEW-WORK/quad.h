#ifndef QUAD_H
#define QUAD_H

typedef struct {
    char op[10];
    char arg1[10];
    char arg2[10];
    char res[10];
} qdr;

extern qdr quad[1000];
extern int qc;

void quadr(char op[], char arg1[], char arg2[], char res[]);
void update_quad(int num_quad, int col_quad, char val[]);
void afficher_quads();

#endif