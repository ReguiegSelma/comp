#ifndef OPTIMISEUR_H
#define OPTIMISEUR_H

#include "quad.h"

// Fonction principale d'optimisation
// Applique les 4 étapes jusqu'à convergence (plus de changement)
void optimiser_code();

// Étape 1: Élimination des expressions communes
// Détecte et élimine les calculs redondants
// Ex: T1 = a + b; T2 = a + b; => T1 = a + b; T2 = T1;
void elimination_expressions_communes();

// Étape 2: Propagation des constantes
// Remplace les variables par leurs valeurs constantes connues
// Ex: x = 5; y = x + 3; => x = 5; y = 8;
void propagation_constantes();

// Étape 3: Suppression du code mort/inutile
// Élimine les affectations à des variables jamais utilisées
// Ex: T1 = a + b; x = 5; (si T1 non utilisé) => x = 5;
void suppression_code_mort();

// Étape 4: Optimisation des boucles
// Déplace les calculs invariants hors des boucles
// Ex: while(...) { t = 5 * 2; x = t + i; } => t = 10; while(...) { x = t + i; }
void optimisation_boucles();

// Fonctions utilitaires
int comparer_quads(); // Compare l'état actuel avec l'état précédent
void sauvegarder_etat(); // Sauvegarde l'état des quadruplets
int est_constante(char *operande); // Vérifie si une opérande est une constante
int est_utilise(char *var, int debut); // Vérifie si une variable est utilisée après

#endif