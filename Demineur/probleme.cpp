/**
  * @file Sprint1.c
  * Projet Demineur
  * @author Cyprien Méjat
  * @date 20/11/2021
  * @brief Qqch
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
  * @brief Place les mines du problème avec l'algorithme de 
  * @param[in,out] p Le problème dont il faut placer les mines
  * @pre Le nombre de mines demandé est inférieur ou égal au nombre de cases
  * total
  */
void placementMinesAleatoire(Probleme &p){
    assert(p.nbMines <= p.nbCases);

    // Place les mines demandées au début du tableau
    for (unsigned int i=0; i<p.nbMines; ++i){p.dataMines[i] = 1;}

    // Remplit le reste du tableau de cases non minées
    for (unsigned int i=p.nbMines; i<p.nbCases; ++i){p.dataMines[i] = 0;}

    // Mélange de Knuth, disperse aléatoirement les mines
    for (unsigned int i=p.nbCases-1; i>0; --i){
        unsigned int j = rand()%(i+1);
        bool tmp = p.dataMines[j];
        p.dataMines[j] = p.dataMines[i];
        p.dataMines[i] = tmp;
    }
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
  * @param[in] p Problème à afficher
  */
void destructionProbleme(Probleme &p){
    p.nbLignes = NULL;
    p.nbColonnes = NULL;
    p.nbCases = NULL;
    p.nbMines = NULL;
    
    delete[] p.dataMines;
}