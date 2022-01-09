/**
  * @file mines.cpp
  * @author Cyprien M�jat
  * @brief Contient le code concernant le placement, le d�voilement, etc des mines.
  */


#include "mines.h"


/**
  * @brief Place les mines du probl�me avec l'algorithme de
  * @param[in,out] p Le probl�me dont il faut placer les mines
  * @pre Le nombre de mines demand� est inf�rieur ou �gal au nombre de cases
  * total
  */
void placementMinesAleatoire(Probleme& p) {
    assert(p.nbMines <= p.nbCases);

    // Place les mines demand�es au d�but du tableau
    for (unsigned int i = 0; i < p.nbMines; ++i) { p.dataMines[i] = 1; }

    // Remplit le reste du tableau de cases non min�es
    for (unsigned int i = p.nbMines; i < p.nbCases; ++i) { p.dataMines[i] = 0; }

    // M�lange de Knuth, disperse al�atoirement les mines
    for (unsigned int i = p.nbCases - 1; i > 0; --i) {
        unsigned int j = rand() % (i + 1);
        bool tmp = p.dataMines[j];
        p.dataMines[j] = p.dataMines[i];
        p.dataMines[i] = tmp;
    }
}


/**
  * @brief Enregistre les positions des mines du probl�me
  * @param[in,out] p Probl�me de la grille
  */
void enregistrementMinesProblemeGrille(Probleme& p) {

    // Aucune case n'est de base min�e
    for (unsigned int i = 0; i < p.nbCases; ++i) {
        p.dataMines[i] = 0;
    }

    unsigned int positionMine; // Position de la mine

    // Les cases min�es consern�es sont chang�es une � une
    for (unsigned int i = 0; i < p.nbMines; ++i) {
        cin >> positionMine;
        p.dataMines[positionMine] = 1;
    }
}


/**
  * @brief Renvoie le nombre de mines autour de la case fournie en param�tres
  * @param[in] p Probl�me de la grille
  * @param[in] nCase Num�ro de la case � inspecter aux alentours
  * @return Nombre de mines autour de la case donn�e
  */
unsigned int nbMinesAlentours(const Probleme& p, unsigned int nCase) {

    // Abscisse et ordonn�e de la case donn�e en param�tre
    int x = nCase % p.nbColonnes, y = nCase / p.nbColonnes;

    // Abscisse et ordonn�e maximales de la grille
    int xMax = p.nbColonnes - 1, yMax = p.nbLignes - 1;

    unsigned int nbMines = 0; // Nombre de mines autour de la case donn�e

    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            /* Si :
             * 1) La case � tester n'est pas celle donn�e en param�tre
             * 2) L'abscisse de la case � tester est coh�rente (0 <= x <= xMax)
             * 3) L'ordonn�e de la case � tester est coh�rente (0 <= y <= yMax)
             * Alors, ajoute 1 si la case test�e est min�e */
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
  * @brief Fait appara�tre toutes les mines
  * @param[in] g Grille
  */
void devoilerMines(Grille& g) {
    for (unsigned int i = 0; i < g.probl.nbCases; ++i) {
        if (g.probl.dataMines[i] == 1) {
            g.affCases[i] = 'm';
        }
    }
}