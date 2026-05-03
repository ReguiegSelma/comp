#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "quad.h"
#include "ts.h"

// Remarque : Assurez-vous que votre ts.h permet de parcourir les symboles
extern void ecrire_ds(FILE* f); 

void generer_assembleur(const char* nom_fichier) {
    FILE* f = fopen(nom_fichier, "w");
    if (!f) return;

    // 1. En-tête et Segment de données
    fprintf(f, "TITLE %s\n", nom_fichier);
    fprintf(f, "DATA SEGMENT\n");
    fprintf(f, "  ; --- Variables issues de la TS ---\n");
    
    // IMPORTANT : Vous devez appeler une fonction de votre ts.c 
    // qui fait : fprintf(f, "  %s DW ?\n", element->name);
    ecrire_ds(f); 

    fprintf(f, "DATA ENDS\n\n");

    // 2. Segment de Pile
    fprintf(f, "STACK SEGMENT\n  DW 128 DUP(0)\nSTACK ENDS\n\n");

    // 3. Segment de Code
    fprintf(f, "CODE SEGMENT\n  ASSUME CS:CODE, DS:DATA, SS:STACK\n\nSTART:\n");
    fprintf(f, "  MOV AX, DATA\n  MOV DS, AX\n\n");

    // 4. Traduction des Quadruplets
    for (int i = 0; i < qc; i++) {
        fprintf(f, "L%d: ", i); 

        // --- AFFECTATION (=) ---
        if (strcmp(quad_table[i].op, "=") == 0) {
            // Gestion des réels : on ignore la partie après le point pour le 8086 standard
            char val[20];
            strcpy(val, quad_table[i].op1);
            char *dot = strchr(val, '.');
            if (dot) *dot = '\0'; 

            fprintf(f, "MOV AX, %s\n", val);
            fprintf(f, "  MOV %s, AX\n", quad_table[i].res);
        }
        // --- ADDITION (+) ---
        else if (strcmp(quad_table[i].op, "+") == 0) {
            fprintf(f, "MOV AX, %s\n", quad_table[i].op1);
            fprintf(f, "  ADD AX, %s\n", quad_table[i].op2);
            fprintf(f, "  MOV %s, AX\n", quad_table[i].res);
        }
        // --- MULTIPLICATION (*) ---
        else if (strcmp(quad_table[i].op, "*") == 0) {
            fprintf(f, "MOV AX, %s\n", quad_table[i].op1);
            fprintf(f, "  MOV BX, %s\n", quad_table[i].op2);
            fprintf(f, "  MUL BX\n"); // Résultat dans AX
            fprintf(f, "  MOV %s, AX\n", quad_table[i].res);
        }
        // --- COMPARAISONS (INF, SUP, etc.) ---
        else if (strcmp(quad_table[i].op, "INF") == 0) {
            fprintf(f, "MOV AX, %s\n", quad_table[i].op1);
            fprintf(f, "  CMP AX, %s\n", quad_table[i].op2);
            fprintf(f, "  JL VRAI_%d\n", i);  // Jump if Less
            fprintf(f, "  MOV %s, 0\n", quad_table[i].res);
            fprintf(f, "  JMP FIN_CMP_%d\n", i);
            fprintf(f, "VRAI_%d: MOV %s, 1\n", i, quad_table[i].res);
            fprintf(f, "FIN_CMP_%d: NOP\n", i);
        }
        // --- BRANCHEMENTS (BR, BZ) ---
        else if (strcmp(quad_table[i].op, "BR") == 0) {
            fprintf(f, "JMP L%s\n", quad_table[i].res);
        }
        else if (strcmp(quad_table[i].op, "BZ") == 0) {
            fprintf(f, "MOV AX, %s\n", quad_table[i].op2);
            fprintf(f, "  CMP AX, 0\n");
            fprintf(f, "  JE L%s\n", quad_table[i].res);
        }
        // --- AFFICHAGE (WRITE) ---
        else if (strcmp(quad_table[i].op, "WRITE") == 0) {
            fprintf(f, "  ; Appel affichage pour %s\n", quad_table[i].op1);
            // Ici, l'affichage nécessite une routine complexe en assembleur.
        }
    }

    // 5. Fin du programme
    fprintf(f, "\n  MOV AH, 4Ch\n  INT 21h\nCODE ENDS\nEND START\n");
    fclose(f);
}