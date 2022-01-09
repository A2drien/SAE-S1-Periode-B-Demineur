/**
  * @file etat_partie.cpp
  * @author Cyprien Méjat
  * @brief Contient le code concernant les états de la partie (gagnée, perdue,
  * en cours)
  */


#include "etat_partie.h"


/**
  * @brief Retourne 1 si la partie est gagnée, 0 sinon
  * @param[in] g Grille
  */
bool partieGagne(const Grille& g) {

    // Vérification de toutes les cases
    for (unsigned int i = 0; i < g.probl.nbCases; ++i) {

        // Si au moins une case non minée n'a pas été démasquée...
        if  (g.probl.dataMines[i] == 0 &&
            (g.affCases[i] == '.' || g.affCases[i] == 'x')){
              return 0; // La partie n'est pas encore gagnée
        }
    }
    return 1; // Sinon, la partie est gagnée
}


/**
  * @brief Retourne 1 si la partie est perdue, 0 sinon
  * @param[in] g Grille
  */
bool partiePerdue(const Grille& g) {

    // Vérification de tous les coups joués
    for (unsigned int i = 0; i < g.hist.nbCoupsJoues; ++i) {
        char typeCoup = g.hist.histCoups[i].typeCoup;
        unsigned int nCase = g.hist.histCoups[i].nCase;

        /** Si le coup est de marquer une case non minée ou de démasquer une
            case minée, alors la partie est perdue */
        if ((typeCoup == 'D' && g.probl.dataMines[nCase] == 1) ||
            (typeCoup == 'M' && g.probl.dataMines[nCase] == 0))
            return 1;
    }
    return 0; // Sinon, la partie n'est pas perdue
}


/**
  * @brief Retourne 1 si la partie est finie (gagnée ou perdue)
  * @param[in] g Grille
  */
bool partieFinie(const Grille& g) {
    return (partieGagne(g) || partiePerdue(g));
}