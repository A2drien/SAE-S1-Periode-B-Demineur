/**
  * @file historique.cpp
  * @author Cyprien Méjat
  * @brief Contient le code concernant la structure historique, tels
  * que l'initialisation, l'affichage, la destruction...
  */


#include "historique.h"
  

/**
  * @brief Enregistre un coup fourni dans l'historique
  * @param[in,out] g Grille
  * @param[in] nCoup Index du coup dans l'historique
  */
void enregistrementCoupHistorique(Grille& g, unsigned int nCoup) {
    char typeCoup; // Type du coup (marquer/démasquer)
    unsigned int nCase; // Numéro de la case du coup

    cin >> typeCoup >> nCase;

    g.hist.histCoups[nCoup].typeCoup = typeCoup;
    g.hist.histCoups[nCoup].nCase = nCase;

    if (typeCoup == 'M') { // Si le joueur marque une case
        g.affCases[nCase] = 'x';
    }

    else if (typeCoup == 'D') { // Si le joueur démasque une case
        demasquerCase(g, nCase);
    }
}


/**
  * @brief Initialise l'historique de la grille
  * @param[in,out] g Grille
  */
void initialisationHistorique(Grille& g) {
    cin >> g.hist.nbCoupsJoues;

    g.hist.histCoups = new Coup[g.hist.nbCoupsJoues];

    // Chaque coup est enregistré dans l'historique
    for (unsigned int i = 0; i < g.hist.nbCoupsJoues; ++i) {
        enregistrementCoupHistorique(g, i);
    }
}


/**
  * @brief Détruit l'historique de la grille
  * @param[in] h Historique à détuire
  */
void destuctionHistorique(Historique& h) {
    for (unsigned int i=0; i<h.nbCoupsJoues; ++i){
        h.histCoups->typeCoup = NULL;
        h.histCoups->nCase = NULL;
    }

    h.nbCoupsJoues = NULL;
    delete[] h.histCoups;
}