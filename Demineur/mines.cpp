/**
  * @file mines.cpp
  * @author Cyprien Méjat
  * @brief Contient le code concernant le placement, le dévoilement, etc des mines.
  */


#include "mines.h"


/**
  * @brief Place les mines du problème avec l'algorithme de
  * @param[in,out] p Le problème dont il faut placer les mines
  * @pre Le nombre de mines demandé est inférieur ou égal au nombre de cases
  * total
  */
void placementMinesAleatoire(Probleme& p) {
    assert(p.nbMines <= p.nbCases);

    // Place les mines demandées au début du tableau
    for (unsigned int i = 0; i < p.nbMines; ++i) { p.dataMines[i] = 1; }

    // Remplit le reste du tableau de cases non minées
    for (unsigned int i = p.nbMines; i < p.nbCases; ++i) { p.dataMines[i] = 0; }

    // Mélange de Knuth, disperse aléatoirement les mines
    for (unsigned int i = p.nbCases - 1; i > 0; --i) {
        unsigned int j = rand() % (i + 1);
        bool tmp = p.dataMines[j];
        p.dataMines[j] = p.dataMines[i];
        p.dataMines[i] = tmp;
    }
}


/**
  * @brief Enregistre les positions des mines du problème
  * @param[in,out] p Problème de la grille
  */
void enregistrementMinesProblemeGrille(Probleme& p) {

    // Aucune case n'est de base minée
    for (unsigned int i = 0; i < p.nbCases; ++i) {
        p.dataMines[i] = 0;
    }

    unsigned int positionMine; // Position de la mine

    // Les cases minées consernées sont changées une à une
    for (unsigned int i = 0; i < p.nbMines; ++i) {
        cin >> positionMine;
        p.dataMines[positionMine] = 1;
    }
}


/**
  * @brief Renvoie le nombre de mines autour de la case fournie en paramètres
  * @param[in] p Problème de la grille
  * @param[in] nCase Numéro de la case à inspecter aux alentours
  * @return Nombre de mines autour de la case donnée
  */
unsigned int nbMinesAlentours(const Probleme& p, unsigned int nCase) {

    // Abscisse et ordonnée de la case donnée en paramètre
    int x = nCase % p.nbColonnes, y = nCase / p.nbColonnes;

    // Abscisse et ordonnée maximales de la grille
    int xMax = p.nbColonnes - 1, yMax = p.nbLignes - 1;

    unsigned int nbMines = 0; // Nombre de mines autour de la case donnée

    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            /* Si :
             * 1) La case à tester n'est pas celle donnée en paramètre
             * 2) L'abscisse de la case à tester est cohérente (0 <= x <= xMax)
             * 3) L'ordonnée de la case à tester est cohérente (0 <= y <= yMax)
             * Alors, ajoute 1 si la case testée est minée */
            if ((i != 0 || j != 0) && (0 <= i + x && i + x <= xMax) && (0 <= j + y &&
                j + y <= yMax)) {
                nbMines += p.dataMines[(j + y) * p.nbColonnes + (x + i)];
            }
            //cout << "Case al : " << (j + y) * p.nbColonnes + (x + i) << endl;
            //cout << "0 <= " << i + x << " <= " << xMax << " et 0 <= " << j + y << " <= " << yMax << " et mines = " << p.dataMines[nCase] << endl;
        }
    }
    return nbMines;
}


/** 
  * @brief Fait apparaître toutes les mines
  * @param[in] g Grille
  */
void devoilerMines(Grille& g) {
    for (unsigned int i = 0; i < g.probl.nbCases; ++i) {
        if (g.probl.dataMines[i] == 1) {
            g.affCases[i] = 'm';
        }
    }
}