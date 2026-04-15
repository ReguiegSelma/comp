#ifndef QUAD_H
#define QUAD_H

typedef struct {
    char* op;
    char* op1;
    char* op2;
    char* res;
} quad_struct;

extern quad_struct quad_table[1000];
extern int qc;
extern int temp_c;

void quad(char *op, char *op1, char *op2, char *res);
int prochain_quad();
void modifier_quad(int indice, int col, char *val);
char *new_temp();
void afficher_quads();

#endif