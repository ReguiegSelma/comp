#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "opti.h"
#include "quad.h"

// Sauvegarde de l'etat precedent pour detecter les changements
static quad_struct etat_precedent[1000];
static int qc_precedent = 0;

void sauvegarder_etat()
{
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
            return 0; // Difference detectee
        }
    }
    return 1; // Aucun changement
}

int est_constante(char *operande)
{
    if (operande == NULL || strlen(operande) == 0)
        return 0;

    int i = 0;
    // Gestion du signe
    if (operande[0] == '+' || operande[0] == '-')
        i = 1;

    int has_digit = 0;
    int has_dot = 0;

    while (operande[i] != '\0')
    {
        if (isdigit(operande[i]))
        {
            has_digit = 1;
        }
        else if (operande[i] == '.' && !has_dot)
        {
            has_dot = 1;
        }
        else
        {
            return 0; // Caractère non numerique
        }
        i++;
    }

    return has_digit; // Au moins un chiffre trouve
}
int est_utilise(char *var, int debut)
{
    for (int i = debut + 1; i < qc; i++)
    {
        // Verifier si la variable apparaît comme operande
        if (strcmp(quad_table[i].op1, var) == 0 ||
            strcmp(quad_table[i].op2, var) == 0)
        {
            return 1;
        }

        // Verifier dans les sauts conditionnels
        if ((strcmp(quad_table[i].op, "BZ") == 0 ||
             strcmp(quad_table[i].op, "BNZ") == 0) &&
            strcmp(quad_table[i].op2, var) == 0)
        {
            return 1;
        }

        // Verifier dans WRITE
        if (strcmp(quad_table[i].op, "WRITE") == 0 &&
            strcmp(quad_table[i].op1, var) == 0)
        {
            return 1;
        }
    }
    return 0;
}
int est_saut(char *op)
{
    return strcmp(op, "BR") == 0 ||
           strcmp(op, "BZ") == 0 ||
           strcmp(op, "BNZ") == 0 ||
           strcmp(op, "BG") == 0;
}
void mettre_a_jour_adresses_sauts(int index_supprime) {
    for (int i = 0; i < qc; i++) {
        if (est_saut(quad_table[i].op)) {
            int cible = atoi(quad_table[i].res);
            if (cible > index_supprime) {
                char nouvelle_cible[10];
                sprintf(nouvelle_cible, "%d", cible - 1);
                free(quad_table[i].res);
                quad_table[i].res = strdup(nouvelle_cible);
            }
        }
    }
}

void elimination_expressions_communes()
{
    printf("\netape 1: elimination des expressions communes\n");
    int nb_optimisations = 0;

    // Parcourir tous les quadruplets
    for (int i = 0; i < qc; i++)
    {
        // On s'interesse aux operations arithmetiques et logiques
        if (strcmp(quad_table[i].op, "+") == 0 ||
            strcmp(quad_table[i].op, "-") == 0 ||
            strcmp(quad_table[i].op, "*") == 0 ||
            strcmp(quad_table[i].op, "/") == 0 ||
            strcmp(quad_table[i].op, "AND") == 0 ||
            strcmp(quad_table[i].op, "OR") == 0)
        {

            // Chercher une expression identique avant ce quadruplet
            for (int j = 0; j < i; j++)
            {
                // Même operation ?
                if (strcmp(quad_table[i].op, quad_table[j].op) == 0)
                {
                    // Mêmes operandes ?
                    if (strcmp(quad_table[i].op1, quad_table[j].op1) == 0 &&
                        strcmp(quad_table[i].op2, quad_table[j].op2) == 0)
                    {

                        // Verifier que le resultat de j n'a pas ete modifie entre j et i
                        int modifie = 0;
                        for (int k = j + 1; k < i; k++)
                        {
                            if (strcmp(quad_table[k].res, quad_table[j].res) == 0)
                            {
                                modifie = 1;
                                break;
                            }
                        }

                        if (!modifie)
                        {
                            // Remplacer l'operation par une simple copie
                            printf("Quad %d: %s = %s %s %s remplace par %s = %s\n",
                                   i, quad_table[i].res, quad_table[i].op1,
                                   quad_table[i].op, quad_table[i].op2,
                                   quad_table[i].res, quad_table[j].res);

                            strcpy(quad_table[i].op, "=");
                            strcpy(quad_table[i].op1, quad_table[j].res);
                            strcpy(quad_table[i].op2, "");
                            nb_optimisations++;
                            break; // On a trouve, pas besoin de continuer
                        }
                    }
                }
            }
        }
    }

    printf("  => %d expressions communes eliminees\n", nb_optimisations);
}

void propagation_constantes()
{
    printf("\n=== etape 2: Propagation des constantes ===\n");
    int nb_optimisations = 0;

    // Parcourir tous les quadruplets
for (int i = 0; i < qc; i++) {
        if (strcmp(quad_table[i].op, "=") == 0 && est_constante(quad_table[i].op1)) {
            char *var = quad_table[i].res;
            char *valeur = quad_table[i].op1;

            for (int j = i + 1; j < qc; j++) {
                // Si on rencontre un saut arrière (boucle), on stoppe par sécurité 
                // sans analyse de flux complète.
                if (est_saut(quad_table[j].op) && atoi(quad_table[j].res) <= j) break;
                
                // Si la variable est modifiée, on arrête la propagation
                if (strcmp(quad_table[j].res, var) == 0) break;

                if (strcmp(quad_table[j].op1, var) == 0) strcpy(quad_table[j].op1, valeur);
                if (strcmp(quad_table[j].op2, var) == 0) strcpy(quad_table[j].op2, valeur);
            }
        }

        // evaluer les operations entre constantes
        if ((strcmp(quad_table[i].op, "+") == 0 ||
             strcmp(quad_table[i].op, "-") == 0 ||
             strcmp(quad_table[i].op, "*") == 0 ||
             strcmp(quad_table[i].op, "/") == 0) &&
            est_constante(quad_table[i].op1) &&
            est_constante(quad_table[i].op2))
        {

            float v1 = atof(quad_table[i].op1);
            float v2 = atof(quad_table[i].op2);
            float resultat = 0;

            // Calculer le resultat selon l'operateur
            if (strcmp(quad_table[i].op, "+") == 0)
                resultat = v1 + v2;
            else if (strcmp(quad_table[i].op, "-") == 0)
                resultat = v1 - v2;
            else if (strcmp(quad_table[i].op, "*") == 0)
                resultat = v1 * v2;
            else if (strcmp(quad_table[i].op, "/") == 0)
            {
                if (v2 != 0)
                    resultat = v1 / v2;
                else
                    continue; // eviter division par zero
            }

            printf("  Quad %d: evaluer %s %s %s = %.2f\n",
                   i, quad_table[i].op1, quad_table[i].op,
                   quad_table[i].op2, resultat);

            // Remplacer par le resultat constant
            strcpy(quad_table[i].op, "=");
            sprintf(quad_table[i].op1, "%.2f", resultat);
            strcpy(quad_table[i].op2, "");
            nb_optimisations++;
        }
    }

    printf("  => %d constantes propagees\n", nb_optimisations);
}

void suppression_code_mort() {
    printf("\n=== etape 3: Suppression du code mort ===\n");
    int nb_suppressions = 0;

    for (int i = 0; i < qc; i++) {
        // Condition de suppression : Ti non utilisé et pas d'effet de bord
        if (strlen(quad_table[i].res) > 0 && quad_table[i].res[0] == 'T') {
            if (!est_utilise(quad_table[i].res, i)) {
                
                printf("  Quad %d: Suppression de %s (inutile)\n", i, quad_table[i].res);
                
                // Mettre à jour tous les sauts qui pointent plus loin que i
                mettre_a_jour_adresses_sauts(i);

                // Décalage physique
                for (int k = i; k < qc - 1; k++) {
                    quad_table[k] = quad_table[k + 1];
                }
                qc--;
                i--; // Re-vérifier l'index actuel
                nb_suppressions++;
            }
        }
    }
    printf("  => %d quadruplets supprimes\n", nb_suppressions);
}


void optimisation_boucles()
{
    printf("\n=== etape 4: Optimisation des boucles ===\n");
    int nb_optimisations = 0;

    // Identifier les boucles (BR qui sautent vers l'arrière)
    for (int i = 0; i < qc; i++)
    {
        if (strcmp(quad_table[i].op, "BR") == 0 &&
            strlen(quad_table[i].res) > 0)
        {

            int cible = atoi(quad_table[i].res);

            // Verifier que c'est un saut vers l'arrière (boucle)
            if (cible > 0 && cible < i)
            {
                printf("  Boucle detectee: quad %d -> %d\n", cible, i);

                // Analyser le corps de la boucle [cible, i]
                for (int j = cible; j < i; j++)
                {
                    // Chercher les calculs invariants
                    if ((strcmp(quad_table[j].op, "+") == 0 ||
                         strcmp(quad_table[j].op, "-") == 0 ||
                         strcmp(quad_table[j].op, "*") == 0 ||
                         strcmp(quad_table[j].op, "/") == 0) &&
                        est_constante(quad_table[j].op1) &&
                        est_constante(quad_table[j].op2))
                    {

                        // Ce calcul est invariant (opère sur des constantes)
                        printf("    Quad %d: Calcul invariant %s %s %s detecte\n",
                               j, quad_table[j].op1, quad_table[j].op,
                               quad_table[j].op2);

                        // On pourrait le deplacer avant la boucle
                        // Pour simplifier, on le signale ici
                        // Une implementation complète le deplacerait reellement
                        nb_optimisations++;
                    }
                }
            }
        }
    }

    printf("  => %d opportunites d'optimisation de boucles detectees\n",
           nb_optimisations);
}

void optimiser_code()
{
    printf("\n");
    printf("          OPTIMISATION DU CODE INTERMEDIAIRE               \n");

    int iteration = 0;
    int changements = 1; // Flag pour detecter les modifications

    // Boucle principale: continuer tant qu'il y a des changements
    while (changements)
    {
        iteration++;
        printf("  PASSE D'OPTIMISATION #%d                            \n", iteration);

        // Sauvegarder l'etat avant optimisation
        sauvegarder_etat();

        // Appliquer les 4 etapes d'optimisation
        elimination_expressions_communes();
        propagation_constantes();
        suppression_code_mort();
        optimisation_boucles();

        // Verifier s'il y a eu des changements
        changements = !comparer_quads();

        if (changements)
        {
            printf("\n Des changements ont ete detectes, nouvelle passe...\n");
        }
        else
        {
            printf("\n  Aucun changement detecte, convergence atteinte!\n");
        }
    }

    printf("\n");
    printf("  OPTIMISATION TERMINeE EN %d PASSE(S)                  \n", iteration);

    // Afficher le code optimise final
    printf("\n--- CODE OPTIMISe FINAL ---\n");
    afficher_quads();
}