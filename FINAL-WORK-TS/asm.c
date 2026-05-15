#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "quad.h"
#include "ts.h"


extern void ecrire_ds(FILE* f); 

void generer_assembleur(const char* nom_fichier) {
    FILE* f = fopen(nom_fichier, "w");
    if (!f) return;

    fprintf(f, "TITLE %s\n", nom_fichier);
    fprintf(f, "DATA SEGMENT\n");
    fprintf(f, "  ; --- Variables  de la TS ---\n");
    
    ecrire_ds(f); 

    fprintf(f, "DATA ENDS\n\n");

    fprintf(f, "STACK SEGMENT\n  DW 64 DUP(0)\nSTACK ENDS\n\n");

    fprintf(f, "CODE SEGMENT\n  ASSUME CS:CODE, DS:DATA, SS:STACK\n\nSTART:\n");
    fprintf(f, "  MOV AX, DATA\n  MOV DS, AX\n\n");

    for (int i = 0; i < qc; i++) {
        fprintf(f, "L%d: ", i); 

        if (strcmp(quad_table[i].op, "=") == 0) {
            char val[20];
            strcpy(val, quad_table[i].op1);
            char *dot = strchr(val, '.');
            if (dot) *dot = '\0'; 

            fprintf(f, "MOV AX, %s\n", val);
            fprintf(f, "  MOV %s, AX\n", quad_table[i].res);
        }

        else if (strcmp(quad_table[i].op, "+") == 0) {
            fprintf(f, "MOV AX, %s\n", quad_table[i].op1);
            fprintf(f, "  ADD AX, %s\n", quad_table[i].op2);
            fprintf(f, "  MOV %s, AX\n", quad_table[i].res);
        }

        else if (strcmp(quad_table[i].op, "*") == 0) {
            fprintf(f, "MOV AX, %s\n", quad_table[i].op1);
            fprintf(f, "  MOV BX, %s\n", quad_table[i].op2);
            fprintf(f, "  MUL BX\n"); // Résultat dans AX
            fprintf(f, "  MOV %s, AX\n", quad_table[i].res);
        }
       else if (strcmp(quad_table[i].op, "INF") == 0) {
            fprintf(f, "MOV AX, %s\n", quad_table[i].op1);
            fprintf(f, "  CMP AX, %s\n", quad_table[i].op2);
            fprintf(f, "  JL VRAI_%d\n", i);
            fprintf(f, "  MOV %s, 0\n", quad_table[i].res);
            fprintf(f, "  JMP FIN_CMP_%d\n", i);
            fprintf(f, "VRAI_%d: MOV %s, 1\n", i, quad_table[i].res);
            fprintf(f, "FIN_CMP_%d: NOP\n", i);
        }
        else if (strcmp(quad_table[i].op, "SUP") == 0) {
            fprintf(f, "MOV AX, %s\n", quad_table[i].op1);
            fprintf(f, "  CMP AX, %s\n", quad_table[i].op2);
            fprintf(f, "  JG VRAI_%d\n", i);       // Jump if Greater
            fprintf(f, "  MOV %s, 0\n", quad_table[i].res);
            fprintf(f, "  JMP FIN_CMP_%d\n", i);
            fprintf(f, "VRAI_%d: MOV %s, 1\n", i, quad_table[i].res);
            fprintf(f, "FIN_CMP_%d: NOP\n", i);
        }
        else if (strcmp(quad_table[i].op, "INFEQ") == 0) {
            fprintf(f, "MOV AX, %s\n", quad_table[i].op1);
            fprintf(f, "  CMP AX, %s\n", quad_table[i].op2);
            fprintf(f, "  JLE VRAI_%d\n", i);      // Jump if Less or Equal
            fprintf(f, "  MOV %s, 0\n", quad_table[i].res);
            fprintf(f, "  JMP FIN_CMP_%d\n", i);
            fprintf(f, "VRAI_%d: MOV %s, 1\n", i, quad_table[i].res);
            fprintf(f, "FIN_CMP_%d: NOP\n", i);
        }
        else if (strcmp(quad_table[i].op, "SUPEQ") == 0) {
            fprintf(f, "MOV AX, %s\n", quad_table[i].op1);
            fprintf(f, "  CMP AX, %s\n", quad_table[i].op2);
            fprintf(f, "  JGE VRAI_%d\n", i);      // Jump if Greater or Equal
            fprintf(f, "  MOV %s, 0\n", quad_table[i].res);
            fprintf(f, "  JMP FIN_CMP_%d\n", i);
            fprintf(f, "VRAI_%d: MOV %s, 1\n", i, quad_table[i].res);
            fprintf(f, "FIN_CMP_%d: NOP\n", i);
        }
        else if (strcmp(quad_table[i].op, "EQ") == 0) {
            fprintf(f, "MOV AX, %s\n", quad_table[i].op1);
            fprintf(f, "  CMP AX, %s\n", quad_table[i].op2);
            fprintf(f, "  JE VRAI_%d\n", i);       // Jump if Equal
            fprintf(f, "  MOV %s, 0\n", quad_table[i].res);
            fprintf(f, "  JMP FIN_CMP_%d\n", i);
            fprintf(f, "VRAI_%d: MOV %s, 1\n", i, quad_table[i].res);
            fprintf(f, "FIN_CMP_%d: NOP\n", i);
        }
        else if (strcmp(quad_table[i].op, "NEQ") == 0) {
            fprintf(f, "MOV AX, %s\n", quad_table[i].op1);
            fprintf(f, "  CMP AX, %s\n", quad_table[i].op2);
            fprintf(f, "  JNE VRAI_%d\n", i);      // Jump if Not Equal
            fprintf(f, "  MOV %s, 0\n", quad_table[i].res);
            fprintf(f, "  JMP FIN_CMP_%d\n", i);
            fprintf(f, "VRAI_%d: MOV %s, 1\n", i, quad_table[i].res);
            fprintf(f, "FIN_CMP_%d: NOP\n", i);
        }
        else if (strcmp(quad_table[i].op, "BR") == 0) {
            fprintf(f, "JMP L%s\n", quad_table[i].res);
        }
        else if (strcmp(quad_table[i].op, "BZ") == 0) {
            fprintf(f, "MOV AX, %s\n", quad_table[i].op2);
            fprintf(f, "  CMP AX, 0\n");
            fprintf(f, "  JE L%s\n", quad_table[i].res);
        }
         
    }

    // 5. Fin du programme
    fprintf(f, "\n  MOV AH, 4Ch\n  INT 21h\nCODE ENDS\nEND START\n");
    fclose(f);
}