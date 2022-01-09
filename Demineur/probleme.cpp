/**
  * @file probleme.cpp
  * @author Cyprien Méjat
  * @brief Contient le code concernant la structure probleme, tels
  * que l'initialisation, l'affichage, la destruction...
  */


#include "probleme.h"


/**
  * @brief Initialise un paramètre à partir des du nombre de ligne, de colonnes,
  * et de mines
  * @param[in] p Le problème à initialiser
  * @pre Le nombre de mines demandé est inférieur ou égal au nombre de cases
  * total
  */
void initialisationProbleme(Probleme &p){
    cin >> p.nbLignes >> p.nbColonnes >> p.nbMines;
    p.nbCases = p.nbLignes * p.nbColonnes;
    assert(p.nbMines <= p.nbCases);

    p.dataMines = new bool[p.nbCases];
}

/**
  * @brief Affiche les données d'un problème
  * @param[in] p Problème à afficher
  */
void affichageProbleme(const Probleme &p){
    cout << p.nbLignes << " " << p.nbColonnes << " " << p.nbMines;

    for (unsigned int i=0; i<p.nbCases; ++i){
        if (p.dataMines[i] == 1)
            cout << " " << i;
    }

    cout << endl;
}


/**
  * @brief Affiche les données d'un problème
  * @param[out] p Problème à afficher
  */
void destructionProbleme(Probleme &p){
    p.nbLignes = NULL;
    p.nbColonnes = NULL;
    p.nbCases = NULL;
    p.nbMines = NULL;
    
    delete[] p.dataMines;
}