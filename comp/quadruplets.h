#ifndef QUADRUPLETS_H
#define QUADRUPLETS_H

#define MAX_QUAD 1000

typedef struct {
    char operateur[10];
    char operande1[50];
    char operande2[50];
    char resultat[50];
} Quadruplet;

extern Quadruplet quadruplets[MAX_QUAD];
extern int nb_quad;
extern int nb_temp;
extern int nb_etiq;

void initialiser_quadruplets();
void generer_quadruplet(const char* op, const char* arg1, const char* arg2, const char* res);
void afficher_quadruplets();
char* creer_temp();
int creer_etiquette();
char* creer_etiq_str(int num);
void generer_etiquette(int num);

#endif
