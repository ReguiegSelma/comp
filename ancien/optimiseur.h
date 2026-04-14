#ifndef OPTIMISEUR_H
#define OPTIMISEUR_H

#include "quadruplets.h"



void opt_pliage_constantes(void);

void opt_propagation_copies(void);

void opt_code_mort(void);

void opt_sauts_inutiles(void);

void opt_simplification_algebrique(void);

void opt_optimiser(void);

#endif