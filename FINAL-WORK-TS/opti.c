#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "opti.h"
#include "quad.h"

static quad_struct etat_precedent[1000];
static int qc_precedent = 0;

void sauvegarder_etat()
{
    for (int i = 0; i < qc_precedent; i++) {
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
    if (qc != qc_precedent) return 0;

    for (int i = 0; i < qc; i++)
    {
        if (strcmp(quad_table[i].op, etat_precedent[i].op) != 0 ||
            strcmp(quad_table[i].op1, etat_precedent[i].op1) != 0 ||
            strcmp(quad_table[i].op2, etat_precedent[i].op2) != 0 ||
            strcmp(quad_table[i].res, etat_precedent[i].res) != 0)
            return 0;
    }
    return 1;
}

int est_constante(char *operande)
{
    if (operande == NULL || strlen(operande) == 0) return 0;

    int i = 0;
    if (operande[0] == '+' || operande[0] == '-') i = 1;

    int has_digit = 0, has_dot = 0;

    while (operande[i] != '\0')
    {
        if (isdigit(operande[i])) has_digit = 1;
        else if (operande[i] == '.' && !has_dot) has_dot = 1;
        else return 0;
        i++;
    }
    return has_digit;
}

int est_saut(char *op)
{
    return strcmp(op, "BR") == 0 || strcmp(op, "BZ") == 0 ||
           strcmp(op, "BNZ") == 0 || strcmp(op, "BG") == 0;
}

int est_vivante(char* var, int index_actuel) {
    for (int j = index_actuel + 1; j < qc; j++) {
        // Utilisation
        if (strcmp(quad_table[j].op1, var) == 0 || 
            strcmp(quad_table[j].op2, var) == 0) {
            return 1; 
        }
        // Réaffectation (écrasement)
        if (strcmp(quad_table[j].res, var) == 0) {
            return 0; 
        }
        // Ne plus s'arrêter sur un saut
    }
    return 0;
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
    int nb_optimisations = 0;

    for (int i = 0; i < qc; i++)
    {
        if (strcmp(quad_table[i].op, "+") == 0 || strcmp(quad_table[i].op, "-") == 0 ||
            strcmp(quad_table[i].op, "*") == 0 || strcmp(quad_table[i].op, "/") == 0)
        {
            for (int j = 0; j < i; j++)
            {
                if (strcmp(quad_table[i].op, quad_table[j].op) == 0 &&
                    strcmp(quad_table[i].op1, quad_table[j].op1) == 0 &&
                    strcmp(quad_table[i].op2, quad_table[j].op2) == 0)
                {
                    int modifie = 0;
                    for (int k = j + 1; k < i; k++)
                    {
                        if (strcmp(quad_table[k].res, quad_table[j].op1) == 0 ||
                            strcmp(quad_table[k].res, quad_table[j].op2) == 0 ||
                            strcmp(quad_table[k].res, quad_table[j].res) == 0)
                        { modifie = 1; break; }
                    }

                    if (!modifie)
                    {
                        free(quad_table[i].op);
                        quad_table[i].op = strdup("=");
                        free(quad_table[i].op1);
                        quad_table[i].op1 = strdup(quad_table[j].res);
                        free(quad_table[i].op2);
                        quad_table[i].op2 = strdup("");
                        nb_optimisations++;
                        break;
                    }
                }
            }
        }
    }
}

// Vérifie si un index est la cible d'un saut (BR, BZ, BN...)
int est_cible_de_saut(int index) {
    for (int i = 0; i < qc; i++) {
        if (est_saut(quad_table[i].op) && atoi(quad_table[i].res) == index)
            return 1;
    }
    return 0;
}

void propagation_constantes()
{
    int nb_optimisations = 0;
    int changement = 1;

    while (changement) {
        changement = 0;

        for (int i = 0; i < qc; i++) {
            // ---- Constant folding ----
            if ((strcmp(quad_table[i].op, "+") == 0 || strcmp(quad_table[i].op, "-") == 0 ||
                 strcmp(quad_table[i].op, "*") == 0 || strcmp(quad_table[i].op, "/") == 0) &&
                est_constante(quad_table[i].op1) && est_constante(quad_table[i].op2))
            {
                float v1 = atof(quad_table[i].op1);
                float v2 = atof(quad_table[i].op2);
                float res_val = 0;

                if (strcmp(quad_table[i].op, "+") == 0) res_val = v1 + v2;
                else if (strcmp(quad_table[i].op, "-") == 0) res_val = v1 - v2;
                else if (strcmp(quad_table[i].op, "*") == 0) res_val = v1 * v2;
                else if (strcmp(quad_table[i].op, "/") == 0 && v2 != 0) res_val = v1 / v2;

                

                free(quad_table[i].op);
                quad_table[i].op = strdup("=");
                char temp[32];
                if (res_val == (int)res_val)
                 sprintf(temp, "%d", (int)res_val);
                else
                sprintf(temp, "%.2f", res_val);
                free(quad_table[i].op1);
                quad_table[i].op1 = strdup(temp);
                free(quad_table[i].op2);
                quad_table[i].op2 = strdup("");
                nb_optimisations++;
                changement = 1;
                continue;
            }

            // ---- Propagation de constante ----
            if (strcmp(quad_table[i].op, "=") == 0 && est_constante(quad_table[i].op1) && strlen(quad_table[i].op2) == 0)
            {
                char *var = quad_table[i].res;
                char *valeur = quad_table[i].op1;

                for (int j = i + 1; j < qc; j++) {
                    if (strcmp(quad_table[j].res, var) == 0) break;

                    // ** Arrêt obligatoire avant une cible de saut (point de fusion) **
                    if (est_cible_de_saut(j)) break;

                    if (strcmp(quad_table[j].op1, var) == 0) {
                        free(quad_table[j].op1);
                        quad_table[j].op1 = strdup(valeur);
                        nb_optimisations++;
                        changement = 1;
                    }
                    if (strcmp(quad_table[j].op2, var) == 0) {
                        free(quad_table[j].op2);
                        quad_table[j].op2 = strdup(valeur);
                        nb_optimisations++;
                        changement = 1;
                    }
                }
            }
        }
    }
}


void suppression_code_mort() {
    int nb_suppressions = 0;
    int changement = 1;

    while (changement) {
        changement = 0;

        for (int i = qc - 1; i >= 0; i--) {
            char *var_dest = quad_table[i].res;

            if (strlen(var_dest) == 0 || est_saut(quad_table[i].op) || 
                strcmp(quad_table[i].op, "WRITE") == 0) continue;

            int est_utilisee = 0;
            int skip_until = -1;   // indice de sortie de la région "autre branche"

            for (int j = i + 1; j < qc; j++) {
                // Sortie de la région protégée
                if (skip_until != -1 && j >= skip_until)
                    skip_until = -1;

                // Saut inconditionnel : démarre une région jusqu'à sa cible
                if (strcmp(quad_table[j].op, "BR") == 0) {
                    int cible = atoi(quad_table[j].res);
                    if (cible > j) {
                        skip_until = cible;
                    } else if (cible <= i) {
                        // Saut arrière (boucle) => variable vivante
                        est_utilisee = 1;
                        break;
                    }
                }

                // Utilisation → vivante
                if (strcmp(quad_table[j].op1, var_dest) == 0 ||
                    strcmp(quad_table[j].op2, var_dest) == 0) {
                    est_utilisee = 1;
                    break;
                }

                // Réaffectation de la même variable
                if (strcmp(quad_table[j].res, var_dest) == 0) {
                    if (skip_until != -1 && j < skip_until) {
                        // Dans l'autre branche, on ignore cette réaffectation
                        continue;
                    } else {
                        // Même chemin → écrasement avant usage → morte
                        break;
                    }
                }
            }

            // Suppression si morte et pas cible d'un saut
            if (!est_utilisee && !est_cible_de_saut(i)) {
                mettre_a_jour_adresses_sauts(i);
                free(quad_table[i].op);
                free(quad_table[i].op1);
                free(quad_table[i].op2);
                free(quad_table[i].res);
                for (int k = i; k < qc - 1; k++)
                    quad_table[k] = quad_table[k + 1];
                qc--;
                nb_suppressions++;
                changement = 1;
            }
        }
    }
}


void optimisation_boucles()
{
    int nb_deplacements = 0;
    int modifie = 1;

    while (modifie) {
        modifie = 0;
        for (int i = 0; i < qc; i++) {
            if (strcmp(quad_table[i].op, "BR") == 0 && strlen(quad_table[i].res) > 0) {
                int cible = atoi(quad_table[i].res);
                if (cible > 0 && cible < i) {

                    // Détection itérative des invariants (y compris les copies d'invariants)
                    int *a_deplacer = malloc((i - cible) * sizeof(int));
                    int nb = 0;
                    int ajout = 1;
                    char **inv_res = malloc((i - cible) * sizeof(char *));
                    int nb_inv = 0;

                    while (ajout) {
                        ajout = 0;
                        for (int j = cible; j < i; j++) {
                            int deja_pris = 0;
                            for (int k = 0; k < nb; k++)
                                if (a_deplacer[k] == j) { deja_pris = 1; break; }
                            if (deja_pris) continue;

                            int est_invariant = 0;
                            if (strcmp(quad_table[j].op, "=") == 0 &&
                                est_constante(quad_table[j].op1) &&
                                strlen(quad_table[j].op2) == 0)
                                est_invariant = 1;
                            else if ((strcmp(quad_table[j].op, "+") == 0 ||
                                      strcmp(quad_table[j].op, "-") == 0 ||
                                      strcmp(quad_table[j].op, "*") == 0 ||
                                      strcmp(quad_table[j].op, "/") == 0) &&
                                     est_constante(quad_table[j].op1) &&
                                     est_constante(quad_table[j].op2))
                                est_invariant = 1;
                            else if (strcmp(quad_table[j].op, "=") == 0 &&
                                     strlen(quad_table[j].op2) == 0) {
                                for (int r = 0; r < nb_inv; r++)
                                    if (strcmp(quad_table[j].op1, inv_res[r]) == 0) {
                                        est_invariant = 1;
                                        break;
                                    }
                            }

                            if (est_invariant && !est_cible_de_saut(j)) {
                                a_deplacer[nb++] = j;
                                inv_res[nb_inv++] = strdup(quad_table[j].res);
                                ajout = 1;
                            }
                        }
                    }
                    for (int r = 0; r < nb_inv; r++) free(inv_res[r]);
                    free(inv_res);

                    if (nb > 0) {
                        // Construction d'un nouveau tableau
                        quad_struct *nouveau = malloc((qc + nb) * sizeof(quad_struct));
                        int pos = 0;

                        // Avant la boucle
                        for (int j = 0; j < cible; j++)
                            nouveau[pos++] = quad_table[j];

                        // Invariants
                        for (int j = 0; j < nb; j++)
                            nouveau[pos++] = quad_table[a_deplacer[j]];

                        // Corps restant
                        for (int j = cible; j < i; j++) {
                            int sauter = 0;
                            for (int k = 0; k < nb; k++)
                                if (a_deplacer[k] == j) { sauter = 1; break; }
                            if (!sauter) nouveau[pos++] = quad_table[j];
                        }

                        // Fin (à partir du BR)
                        for (int j = i; j < qc; j++)
                            nouveau[pos++] = quad_table[j];

                        int nv_qc = pos;

                        // Table de correspondance ancien indice -> nouvel indice
                        int *corresp = malloc(qc * sizeof(int));
                        for (int anc = 0; anc < qc; anc++) {
                            corresp[anc] = -1;
                            for (int k = 0; k < nv_qc; k++) {
                                if (quad_table[anc].op == nouveau[k].op &&
                                    strcmp(quad_table[anc].op1, nouveau[k].op1) == 0 &&
                                    strcmp(quad_table[anc].op2, nouveau[k].op2) == 0 &&
                                    strcmp(quad_table[anc].res, nouveau[k].res) == 0) {
                                    corresp[anc] = k;
                                    break;
                                }
                            }
                        }

                        // Mise à jour des sauts
                        for (int k = 0; k < nv_qc; k++) {
                            if (est_saut(nouveau[k].op) && strlen(nouveau[k].res) > 0) {
                                int anc = atoi(nouveau[k].res);
                                if (anc >= 0 && anc < qc && corresp[anc] != -1) {
                                    char temp[16];
                                    sprintf(temp, "%d", corresp[anc]);
                                    free(nouveau[k].res);
                                    nouveau[k].res = strdup(temp);
                                }
                            }
                        }

                        // Recopie dans quad_table
                        for (int k = 0; k < nv_qc; k++)
                            quad_table[k] = nouveau[k];
                        qc = nv_qc;

                        free(nouveau);
                        free(corresp);
                        nb_deplacements += nb;
                        modifie = 1;
                    }
                    free(a_deplacer);
                }
            }
        }
    }
}

void optimiser_code()
{

    int iteration = 0;
    int changements = 1;

    while (changements)
    {
        iteration++;
        sauvegarder_etat();

        elimination_expressions_communes();
        propagation_constantes();
        suppression_code_mort();
        optimisation_boucles();

        changements = !comparer_quads();
    }

    printf("  \n   OPTIMISATION TERMINEE EN %d PASSE(S)                  \n", iteration);

    printf("\n--- CODE OPTIMISE FINAL ---\n");
    afficher_quads();
}