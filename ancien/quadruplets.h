#ifndef QUADRUPLETS_H
#define QUADRUPLETS_H



#define MAX_QUADS   1000
#define MAX_TEMPS   200
#define MAX_LABELS  200

typedef struct {
    char nom[32];
} Operande;


typedef enum {
    Q_ADD,
    Q_SUB,
    Q_MUL,
    Q_DIV,
    Q_NEG,
    Q_ASGN,
    Q_TASGN,
    Q_TLOAD,
    Q_GT,
    Q_GE,
    Q_LT,
    Q_LE,
    Q_EQ,
    Q_NE,
    Q_IFZ,
    Q_GOTO,
    Q_LABEL,
    Q_WRITE,
    Q_READ,
    Q_HALT
} OpCode;


typedef struct {
    OpCode op;
    Operande arg1;
    Operande arg2;
    Operande res;
} Quad;


void ci_init(void);

char *ci_nouveau_temp(void);
char *ci_nouveau_label(void);

int ci_emettre(OpCode op,
               const char *arg1,
               const char *arg2,
               const char *res);

void ci_patcher(int idx, const char *nouvelle_res);

int ci_prochain(void);

Quad *ci_get_quads(void);
int   ci_get_nb(void);

void ci_afficher(void);

void ci_set_nb(int n);

#endif