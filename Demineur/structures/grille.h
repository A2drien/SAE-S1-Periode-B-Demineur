#include "historique.h"
#include "probleme.h"

#ifndef _GRILLE_
#define _GRILLE_

// Structure contenant la grille
struct Grille {
    Historique hist;                    // Historique des coups de la grille
    Probleme probl;                     // Lignes, colonnes, mines de la grille
	char *affCases;                     // Ce qu'affiche chaque case
};

#endif