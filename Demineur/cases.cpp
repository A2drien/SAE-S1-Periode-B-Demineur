/**
  * @file cases.h
  * @author Cyprien M�jat
  * @brief Contient le code qui d�voile et d�masque les cases
  */


#include "cases.h"


/**
  * @brief D�masque toutes les cases autour de la case donn�e en param�tre
  * @param[in,out] g Grille
  * @param[in] nCase Position de la case dont il faut d�masquer les alentours
  */
void devoilerCasesVidesAlentours(Grille& g, unsigned int nCase) {

    // Abscisse et ordonn�e de la case donn� en param�tre
    int x = nCase % g.probl.nbColonnes, y = nCase / g.probl.nbColonnes;

    // Abscisse et ordonn�e maximales de la grille
    int xMax = g.probl.nbColonnes - 1, yMax = g.probl.nbLignes - 1;

    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            /* Si :
             * 1) La case � tester n'est pas celle donn�e en param�tre (i = j = 0)
             * 2) L'abscisse de la case � tester est coh�rente (0 <= x <= xMax)
             * 3) L'ordonn�e de la case � tester est coh�rente (0 <= y <= yMax)
             * 4) La case � tester n'a pas encore �t� d�masqu�e ou marqu�e
             * Alors, d�masquer la case test�e */

            if ((i != 0 || j != 0) && (0 <= i + x && i + x <= xMax) &&
                (0 <= j + y && j + y <= yMax) &&
                g.affCases[(j + y) * g.probl.nbColonnes + (x + i)] == '.') {

                demasquerCase(g, (j + y) * g.probl.nbColonnes + (x + i));
            }
        }
    }
}


/**
  * @brief Demasque la case donn�e en param�tre,
  * @param[in,out] g Grille
  * @param[in] nCase Num�ro de la case � d�masquer
  */
void demasquerCase(Grille& g, unsigned int nCase) {
    unsigned int nbMinesAutour = nbMinesAlentours(g.probl, nCase);

    // S'il n'y a aucune mines autour et que la case n'est pas d�masqu�e ou marqu�e
    if (nbMinesAutour == 0 && g.affCases[nCase] == '.') {
        g.affCases[nCase] = ' '; // La case vide est d�voil�e
        devoilerCasesVidesAlentours(g, nCase); // Les cases autour sont r�v�l�es
    }

    // Sinon, si la case n'est pas d�masqu�e ou marqu�e
    else if (g.affCases[nCase] == '.') {
        g.affCases[nCase] = nbMinesAutour + CONVERSION_CODE_ASCII;
    }
}