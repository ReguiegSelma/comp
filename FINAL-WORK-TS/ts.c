#include <stdio.h>    // Pour l'affichage (printf)
#include <stdlib.h>   // Pour la mémoire (malloc/free)
#include <string.h>   // Pour manipuler les chaînes (strcmp/strcpy)
#include "ts.h"       // Ton plan de construction

extern int nb_erreurs;
extern int nb_lignes;

/* Structures pour les différentes tables */
typedef struct {
    Symbole **buckets; // Un tableau de pointeurs , pointeur vers tableau de pointeurs
    size_t capacity;   // Le nombre total de tiroirs
} TS_Table;

static TS_Table ts_id = {NULL, 0}; // pas encore alloue, aucune case 
static TS_Table ts_kw = {NULL, 0};
static TS_Table ts_sep = {NULL, 0};

/* Gestion de la pile pour WHILE/FOR */
static int loop_start_stack[100], loop_cond_stack[100], top = -1; 
//  taille fixe = 100 , pile vide 
// stocke l’adresse de début de boucle.
// stocke l’adresse du quadruplet conditionnel.


unsigned long hash_str(const char *s) {
    unsigned long h = 5381; // 5381 = valeur celebre (algorithme DJB2)
    int c;
    while ((c = *s++)) h = ((h << 5) + h) + c; // parcourt chaque caractère
    return h;
}

/* Fonction générique d'insertion pour éviter la duplication de code */
void inserer_dans_table(TS_Table *table, const char *name, const char *code, const char *type, float val, int taille) {
    if (table->capacity == 0) { // vide première insertion.  Donc créer table.
        table->capacity = 53; // Nombre premier pour limiter les collisions
        table->buckets = calloc(table->capacity, sizeof(Symbole *)); // calloc(nombre, taille)
    }
    unsigned long h = hash_str(name) % table->capacity;
    
    // Vérification de double déclaration (uniquement pour les IDs)
    for (Symbole *cur = table->buckets[h]; cur; cur = cur->next) {
        if (strcmp(cur->name, name) == 0) {
            if (table == &ts_id && strcmp(code, "temp") != 0) { 
                // On ne signale pas d'erreur pour les temporaires réutilisés
                printf("Erreur Semantique: Double declaration de '%s' ligne %d\n", name, nb_lignes);
                nb_erreurs++;
            }
            return;
        }
    }

    Symbole *s = malloc(sizeof(Symbole));
    // On copie maximum 19 caractères pour laisser de la place au \0 final
    strncpy(s->name, name, 19); 
    s->name[19] = '\0'; 
    
    strncpy(s->code, code, 19);
    s->code[19] = '\0';
    
    strncpy(s->type, type, 19);
    s->type[19] = '\0';

    s->val = val; 
    s->taille = taille;
    s->next = table->buckets[h];
    table->buckets[h] = s;
}
// inserer dans ts 
void inserer(const char *name, const char *code, const char *type, float val, int taille) {
    inserer_dans_table(&ts_id, name, code, type, val, taille);
}

void inserer_kw(const char *name, const char *code) {
    inserer_dans_table(&ts_kw, name, code, "KEYWORD", 0, 0);
}

void inserer_sep(const char *name, const char *code) {
    inserer_dans_table(&ts_sep, name, code, "SEPARATOR", 0, 0);
}

Symbole* rechercher(const char *name) {
    if (ts_id.capacity == 0) return NULL;
    unsigned long h = hash_str(name) % ts_id.capacity;
    for (Symbole *cur = ts_id.buckets[h]; cur; cur = cur->next) {
        if (strcmp(cur->name, name) == 0) return cur;
    }
    return NULL;
}


/*--- LOGIQUE DE MISE À JOUR (Propagation) ---*/

void mettre_a_jour_val(const char *name, float v) {
    Symbole *s = rechercher(name);
    if (s) {
        s->val = v;
    }
}

float obtenir_val(const char *name) {
    Symbole *s = rechercher(name);
    if (s) return s->val;
    return 0;
}


/* Gestion de la pile */
void push_loop_start(int addr) { loop_start_stack[++top] = addr; }
int pop_loop_start() { return loop_start_stack[top]; }
void push_loop_cond(int addr) { loop_cond_stack[top] = addr; }
int pop_loop_cond() { return loop_cond_stack[top--]; }

/* Fonctions d'affichage */
void afficher_ts_ids() {
    printf("\n/*************** TABLE DES SYMBOLES (IDFS) ***************/\n");
    printf("%-15s | %-10s | %-10s | %-8s | %-6s\n", "Nom", "Code", "Type", "Valeur", "Taille");
    for (int i=0; i<ts_id.capacity; i++) {
        for (Symbole *s = ts_id.buckets[i]; s; s=s->next)
            printf("%-15s | %-10s | %-10s | %-8.2f | %-6d\n", s->name, s->code, s->type, s->val, s->taille);
    }
}

void afficher_ts_kw() {
    printf("\n/*************** TABLE DES MOTS-CLES ***************/\n");
    printf("%-15s | %-10s\n", "Nom", "Code");
    if (ts_kw.capacity == 0) return;
    for (int i=0; i<ts_kw.capacity; i++) {
        for (Symbole *s = ts_kw.buckets[i]; s; s=s->next)
            printf("%-15s | %-10s\n", s->name, s->code);
    }
}

void afficher_ts_sep() {
    printf("\n/*************** TABLE DES SEPARATEURS ***************/\n");
    printf("%-15s | %-10s\n", "Nom", "Code");
    if (ts_sep.capacity == 0) return;
    for (int i=0; i<ts_sep.capacity; i++) {
        for (Symbole *s = ts_sep.buckets[i]; s; s=s->next)
            printf("%-15s | %-10s\n", s->name, s->code);
    }
}