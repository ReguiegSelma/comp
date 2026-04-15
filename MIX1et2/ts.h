#ifndef TS_H
#define TS_H

#define MAX_IDF_CST 1000
#define MAX_KW 50
#define MAX_SEP 50

// Structure pour les identifiants et constantes
typedef struct {
    char name[20];
    char code[20];
    char type[20];
    float value;
    int estTableau;
    int taille;
    int estConstante;
    int a_une_valeur;
} elt_idf_cst;

// Structure pour les mots-clés
typedef struct {
    char name[20];
    char code[20];
} elt_kw;

// Structure pour les séparateurs
typedef struct {
    char name[20];
    char code[20];
} elt_sep;

// Tables de symboles globales
extern elt_idf_cst ts_idf_cst[MAX_IDF_CST];
extern elt_kw ts_kw[MAX_KW];
extern elt_sep ts_sep[MAX_SEP];

extern int count_idf_cst;
extern int count_kw;
extern int count_sep;

// Prototypes
int search_idf_cst(char entity[]);
int search_kw(char entity[]);
int search_sep(char entity[]);
void insert_idf_cst(char entity[], char code[], char type[], float value, int isTab, int size, int isConst);
void insert_kw(char entity[], char code[]);
void insert_sep(char entity[], char code[]);
void afficher_ts_ids();
void afficher_ts_kw();
void afficher_ts_sep();

#endif