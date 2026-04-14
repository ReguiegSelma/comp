/*
 * ============================================================
 *  CODE INTERMÉDIAIRE — MiniAlgo
 *  Fichier : quadruplets.c
 *  Implémentation de la liste de quadruplets et des utilitaires
 * ============================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "quadruplets.h"

/* ---- Tableau global de quadruplets ---- */
static Quad quads[MAX_QUADS];
static int  nb_quads = 0;

/* ---- Compteurs de nommage automatique ---- */
static int compteur_temp  = 0;   /* T0, T1, T2, … */
static int compteur_label = 0;   /* L0, L1, L2, … */

/* Buffers statiques cycliques pour ci_nouveau_temp / ci_nouveau_label */
static char buf_temp [MAX_TEMPS][16];
static char buf_label[MAX_LABELS][16];

/* ------------------------------------------------------------------ */
void ci_init(void) {
    nb_quads       = 0;
    compteur_temp  = 0;
    compteur_label = 0;
}

/* ------------------------------------------------------------------ */
char *ci_nouveau_temp(void) {
    if (compteur_temp >= MAX_TEMPS) {
        fprintf(stderr, "Erreur interne : trop de temporaires\n");
        exit(EXIT_FAILURE);
    }
    snprintf(buf_temp[compteur_temp], 16, "T%d", compteur_temp);
    return buf_temp[compteur_temp++];
}

/* ------------------------------------------------------------------ */
char *ci_nouveau_label(void) {
    if (compteur_label >= MAX_LABELS) {
        fprintf(stderr, "Erreur interne : trop d'etiquettes\n");
        exit(EXIT_FAILURE);
    }
    snprintf(buf_label[compteur_label], 16, "L%d", compteur_label);
    return buf_label[compteur_label++];
}

/* ------------------------------------------------------------------ */
int ci_emettre(OpCode op,
               const char *arg1,
               const char *arg2,
               const char *res) {
    if (nb_quads >= MAX_QUADS) {
        fprintf(stderr, "Erreur interne : depassement de la liste de quadruplets\n");
        exit(EXIT_FAILURE);
    }
    int idx = nb_quads;
    quads[idx].op = op;
    strncpy(quads[idx].arg1.nom, arg1 ? arg1 : "-", 31);
    strncpy(quads[idx].arg2.nom, arg2 ? arg2 : "-", 31);
    strncpy(quads[idx].res.nom,  res  ? res  : "-", 31);
    nb_quads++;
    return idx;
}

/* ------------------------------------------------------------------ */
void ci_patcher(int idx, const char *nouvelle_res) {
    if (idx < 0 || idx >= nb_quads) return;
    strncpy(quads[idx].res.nom, nouvelle_res, 31);
}

/* ------------------------------------------------------------------ */
int ci_prochain(void) {
    return nb_quads;
}

/* ------------------------------------------------------------------ */
Quad *ci_get_quads(void) { return quads; }
int   ci_get_nb(void)    { return nb_quads; }

/* ------------------------------------------------------------------ */
/*  Nom lisible d'un opcode (pour l'affichage)                         */
/* ------------------------------------------------------------------ */
static const char *opcode_nom(OpCode op) {
    switch (op) {
        case Q_ADD:   return "ADD";
        case Q_SUB:   return "SUB";
        case Q_MUL:   return "MUL";
        case Q_DIV:   return "DIV";
        case Q_NEG:   return "NEG";
        case Q_ASGN:  return "ASGN";
        case Q_TASGN: return "TASGN";
        case Q_TLOAD: return "TLOAD";
        case Q_GT:    return "GT";
        case Q_GE:    return "GE";
        case Q_LT:    return "LT";
        case Q_LE:    return "LE";
        case Q_EQ:    return "EQ";
        case Q_NE:    return "NE";
        case Q_IFZ:   return "IFZ";
        case Q_GOTO:  return "GOTO";
        case Q_LABEL: return "LABEL";
        case Q_WRITE: return "WRITE";
        case Q_READ:  return "READ";
        case Q_HALT:  return "HALT";
        default:      return "???";
    }
}

/* ------------------------------------------------------------------ */
void ci_afficher(void) {
    printf("\n===== CODE INTERMÉDIAIRE (quadruplets) =====\n");
    printf("%-4s  %-6s  %-10s  %-10s  %-10s\n",
           "Idx", "Op", "Arg1", "Arg2", "Res");
    printf("--------------------------------------------\n");
    for (int i = 0; i < nb_quads; i++) {
        printf("%-4d  %-6s  %-10s  %-10s  %-10s\n",
               i,
               opcode_nom(quads[i].op),
               quads[i].arg1.nom,
               quads[i].arg2.nom,
               quads[i].res.nom);
    }
    printf("============================================\n\n");
}

/* Setter pour nb_quads (utilisé par l'optimiseur après compactage) */
void ci_set_nb(int n) { nb_quads = n; }
