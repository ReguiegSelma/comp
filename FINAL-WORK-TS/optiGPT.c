#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "opti.h"
#include "quad.h"

static quad_struct etat_precedent[1000];
static int qc_precedent = 0;

/* ================= UTILITAIRES ================= */

int est_saut(char *op)
{
    return strcmp(op, "BR") == 0 ||
           strcmp(op, "BZ") == 0 ||
           strcmp(op, "BNZ") == 0 ||
           strcmp(op, "BG") == 0;
}

int est_operateur(char *op)
{
    return strcmp(op, "+") == 0 ||
           strcmp(op, "-") == 0 ||
           strcmp(op, "*") == 0 ||
           strcmp(op, "/") == 0 ||
           strcmp(op, "AND") == 0 ||
           strcmp(op, "OR") == 0;
}

/* Vérifie si index est dans une boucle */
int est_dans_boucle(int index)
{
    for (int i = 0; i < qc; i++)
    {
        if (strcmp(quad_table[i].op, "BR") == 0 && strlen(quad_table[i].res) > 0)
        {
            int cible = atoi(quad_table[i].res);

            /* Ignore faux BR 0 si trop global */
            if (cible > 0 && cible < i)
            {
                if (index >= cible && index <= i)
                    return 1;
            }
        }
    }
    return 0;
}

/* Variable redéfinie entre start et end ? */
int variable_modifiee_entre(char *var, int start, int end)
{
    for (int i = start + 1; i < end; i++)
    {
        if (strcmp(quad_table[i].res, var) == 0)
            return 1;
    }
    return 0;
}

void sauvegarder_etat()
{
    for (int i = 0; i < qc_precedent; i++)
    {
        free(etat_precedent[i].op);
        free(etat_precedent[i].op1);
        free(etat_precedent[i].op2);
        free(etat_precedent[i].res);
    }

    for (int i = 0; i < qc; i++)
    {
        etat_precedent[i].op = strdup(quad_table[i].op);
        etat_precedent[i].op1 = strdup(quad_table[i].op1);
        etat_precedent[i].op2 = strdup(quad_table[i].op2);
        etat_precedent[i].res = strdup(quad_table[i].res);
    }

    qc_precedent = qc;
}

int comparer_quads()
{
    if (qc != qc_precedent)
        return 0;

    for (int i = 0; i < qc; i++)
    {
        if (strcmp(quad_table[i].op, etat_precedent[i].op) != 0 ||
            strcmp(quad_table[i].op1, etat_precedent[i].op1) != 0 ||
            strcmp(quad_table[i].op2, etat_precedent[i].op2) != 0 ||
            strcmp(quad_table[i].res, etat_precedent[i].res) != 0)
        {
            return 0;
        }
    }
    return 1;
}

int est_constante(char *operande)
{
    if (!operande || strlen(operande) == 0)
        return 0;

    int i = 0;
    if (operande[0] == '+' || operande[0] == '-')
        i++;

    int has_digit = 0;
    int has_dot = 0;

    while (operande[i])
    {
        if (isdigit(operande[i]))
            has_digit = 1;
        else if (operande[i] == '.' && !has_dot)
            has_dot = 1;
        else
            return 0;
        i++;
    }

    return has_digit;
}

int est_utilise(char *var, int debut)
{
    for (int i = debut + 1; i < qc; i++)
    {
        if (strcmp(quad_table[i].op1, var) == 0 ||
            strcmp(quad_table[i].op2, var) == 0)
            return 1;

        if (strcmp(quad_table[i].op, "WRITE") == 0 &&
            strcmp(quad_table[i].op1, var) == 0)
            return 1;

        /* Stop si réécriture avant usage */
        if (strcmp(quad_table[i].res, var) == 0)
            return 0;
    }
    return 0;
}

/* ================= ETAPE 1 ================= */

void elimination_expressions_communes()
{
    printf("\n=== ETAPE 1: Elimination expressions communes ===\n");
    int nb = 0;

    for (int i = 0; i < qc; i++)
    {
        if (!est_operateur(quad_table[i].op))
            continue;

        for (int j = 0; j < i; j++)
        {
            if (!est_operateur(quad_table[j].op))
                continue;

            if (strcmp(quad_table[i].op, quad_table[j].op) == 0 &&
                strcmp(quad_table[i].op1, quad_table[j].op1) == 0 &&
                strcmp(quad_table[i].op2, quad_table[j].op2) == 0)
            {
                /* Vérifier que les opérandes n’ont pas changé */
                if (variable_modifiee_entre(quad_table[i].op1, j, i) ||
                    variable_modifiee_entre(quad_table[i].op2, j, i))
                    continue;

                free(quad_table[i].op);
                free(quad_table[i].op1);
                free(quad_table[i].op2);

                quad_table[i].op = strdup("=");
                quad_table[i].op1 = strdup(quad_table[j].res);
                quad_table[i].op2 = strdup("");

                printf("Quad %d optimisé par réutilisation de %s\n",
                       i, quad_table[j].res);

                nb++;
                break;
            }
        }
    }

    printf("=> %d expressions communes éliminées\n", nb);
}

/* ================= ETAPE 2 ================= */

void propagation_constantes()
{
    printf("\n=== ETAPE 2: Propagation constantes ===\n");
    int nb = 0;

    for (int i = 0; i < qc; i++)
    {
        if (strcmp(quad_table[i].op, "=") == 0 &&
            est_constante(quad_table[i].op1) &&
            strlen(quad_table[i].op2) == 0)
        {
            char *var = quad_table[i].res;
            char *val = quad_table[i].op1;

            for (int j = i + 1; j < qc; j++)
            {
                /* Stop sur réaffectation */
                if (strcmp(quad_table[j].res, var) == 0)
                    break;

                /* Stop si boucle */
                if (est_dans_boucle(j) && est_dans_boucle(i) != est_dans_boucle(j))
                    break;

                if (strcmp(quad_table[j].op1, var) == 0)
                {
                    free(quad_table[j].op1);
                    quad_table[j].op1 = strdup(val);
                    nb++;
                }

                if (strcmp(quad_table[j].op2, var) == 0)
                {
                    free(quad_table[j].op2);
                    quad_table[j].op2 = strdup(val);
                    nb++;
                }
            }
        }

        /* Constant folding */
        if (est_operateur(quad_table[i].op) &&
            est_constante(quad_table[i].op1) &&
            est_constante(quad_table[i].op2))
        {
            float v1 = atof(quad_table[i].op1);
            float v2 = atof(quad_table[i].op2);
            float r = 0;

            if (strcmp(quad_table[i].op, "+") == 0) r = v1 + v2;
            else if (strcmp(quad_table[i].op, "-") == 0) r = v1 - v2;
            else if (strcmp(quad_table[i].op, "*") == 0) r = v1 * v2;
            else if (strcmp(quad_table[i].op, "/") == 0 && v2 != 0) r = v1 / v2;
            else continue;

            char buffer[50];
            sprintf(buffer, "%.2f", r);

            free(quad_table[i].op);
            free(quad_table[i].op1);
            free(quad_table[i].op2);

            quad_table[i].op = strdup("=");
            quad_table[i].op1 = strdup(buffer);
            quad_table[i].op2 = strdup("");

            nb++;
        }
    }

    printf("=> %d optimisations de constantes\n", nb);
}

/* ================= ETAPE 3 ================= */

void suppression_code_mort()
{
    printf("\n=== ETAPE 3: Suppression code mort ===\n");

    int sup[1000] = {0};
    int nb = 0;

    for (int i = 0; i < qc; i++)
    {
        if (est_saut(quad_table[i].op) ||
            strcmp(quad_table[i].op, "WRITE") == 0)
            continue;

        /* x=x */
        if (strcmp(quad_table[i].op, "=") == 0 &&
            strcmp(quad_table[i].op1, quad_table[i].res) == 0)
        {
            sup[i] = 1;
            nb++;
            continue;
        }

        /* Toute variable jamais relue */
        if (strlen(quad_table[i].res) > 0 &&
            !est_utilise(quad_table[i].res, i))
        {
            sup[i] = 1;
            nb++;
        }
    }

    int j = 0;
    for (int i = 0; i < qc; i++)
    {
        if (!sup[i])
        {
            quad_table[j++] = quad_table[i];
        }
    }

    qc = j;

    printf("=> %d suppressions\n", nb);
}

/* ================= ETAPE 4 ================= */

void optimisation_boucles()
{
    printf("\n=== ETAPE 4: Optimisation boucles ===\n");

    int nb = 0;

    for (int i = 0; i < qc; i++)
    {
        if (strcmp(quad_table[i].op, "BR") == 0)
        {
            int cible = atoi(quad_table[i].res);

            /* Ignore BR 0 */
            if (cible <= 0 || cible >= i)
                continue;

            printf("Boucle réelle détectée : %d -> %d\n", cible, i);

            for (int j = cible; j < i; j++)
            {
                if (est_operateur(quad_table[j].op) &&
                    est_constante(quad_table[j].op1) &&
                    est_constante(quad_table[j].op2))
                {
                    printf("Invariant détecté au quad %d\n", j);
                    nb++;
                }
            }
        }
    }

    printf("=> %d invariants détectés\n", nb);
}

void optimiser_code() { 
    printf("\n"); printf(" OPTIMISATION DU CODE INTERMEDIAIRE \n"); 
    int iteration = 0; 
    int changements = 1; // Flag pour detecter les modifications
     // Boucle principale: continuer tant qu'il y a des changements 
     while (changements) { 
        iteration++; 
        printf(" PASSE D'OPTIMISATION #%d \n", iteration);
     // Sauvegarder l'etat avant optimisation 
     sauvegarder_etat(); 
     // Appliquer les 4 etapes d'optimisation 
     elimination_expressions_communes(); 
     propagation_constantes(); 
     suppression_code_mort(); 
     optimisation_boucles(); 
     // Verifier s'il y a eu des changements 
     changements = !comparer_quads(); 
     
    if (changements) { 
        printf("\n Des changements ont ete detectes, nouvelle passe...\n"); 
    } else { 
        printf("\n Aucun changement detecte, convergence atteinte!\n"); 
    } 
}
     printf("\n"); 
     printf(" OPTIMISATION TERMINeE EN %d PASSE(S) \n", iteration);
     // Afficher le code optimise final 
     printf("\n--- CODE OPTIMISe FINAL ---\n"); 
     afficher_quads(); }