#include "cases.h"


/**
  * @brief Démasque toutes les cases autour de la case donnée en paramètre
  * @param[in,out] g Grille
  * @param[in] nCase Position de la case dont il faut démasquer les alentours
  */
void devoilerCasesVidesAlentours(Grille& g, unsigned int nCase) {

    // Abscisse et ordonnée de la case donné en paramètre
    int x = nCase % g.probl.nbColonnes, y = nCase / g.probl.nbColonnes;

    // Abscisse et ordonnée maximales de la grille
    int xMax = g.probl.nbColonnes - 1, yMax = g.probl.nbLignes - 1;

    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            /* Si :
             * 1) La case à tester n'est pas celle donnée en paramètre (i = j = 0)
             * 2) L'abscisse de la case à tester est cohérente (0 <= x <= xMax)
             * 3) L'ordonnée de la case à tester est cohérente (0 <= y <= yMax)
             * 4) La case à tester n'a pas encore été démasquée ou marquée
             * Alors, démasquer la case testée */

            if ((i != 0 || j != 0) && (0 <= i + x && i + x <= xMax) && (0 <= j + y &&
                j + y <= yMax) && g.affCases[(j + y) * g.probl.nbColonnes + (x + i)] == '.') {

                demasquerCase(g, (j + y) * g.probl.nbColonnes + (x + i));
            }
        }
    }
}


/**
  * @brief Demasque la case donnée en paramètre,
  * @param[in,out] g Grille
  * @param[in] nCase Numéro de la case à démasquer
  */
void demasquerCase(Grille& g, unsigned int nCase) {
    unsigned int nbMinesAutour = nbMinesAlentours(g.probl, nCase);

    // S'il n'y a aucune mines autour et que la case n'est pas démasquée ou marquée
    if (nbMinesAutour == 0 && g.affCases[nCase] == '.') {
        g.affCases[nCase] = ' '; // La case vide est dévoilée
        devoilerCasesVidesAlentours(g, nCase); // Les cases autour sont révélées
    }

    // Sinon, si la case n'est pas démasquée ou marquée
    else if (g.affCases[nCase] == '.') {
        g.affCases[nCase] = nbMinesAutour + CONVERSION_CODE_ASCII;
    }
}