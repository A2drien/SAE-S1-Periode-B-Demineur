/**
  * @file Sprint1.c
  * Projet Demineur
  * @author Cyprien Méjat
  * @date 20/11/2021
  * @brief Qqch
  */

#include "Sprint1.h"
#include <iostream>
#include <cassert>

/**
  * @brief Produit et affiche un problème
  */
void creationProbleme(){
    Probleme *p;

    p = new Probleme;
    
    initialisationProbleme(*p);
    placementMines(*p);
    affichageProbleme(*p);
    destructionProbleme(*p);
}


/**
  * @brief Initialise un paramètre à partir des du nombre de ligne, de colonnes,
  * et de mines
  * @param[in] p Le problème à initialiser
  * @pre Le nombre de mines demandé est inférieur ou égal au nombre de cases
  * total
  */
void initialisationProbleme(Probleme &p){
    cin >> p.nbLignes >> p.nbColonnes >> p.nbMines;
    assert(p.nbMines <= p.nbCases);

    p.nbCases = p.nbLignes * p.nbColonnes;
    p.dataMines = new bool[p.nbMines];
}

/**
  * @brief Place les mines du problème avec l'algorithme de 
  * @param[in,out] p Le problème dont il faut placer les mines
  * @pre Le nombre de mines demandé est inférieur ou égal au nombre de cases
  * total
  */
void placementMines(Probleme &p){
    assert(p.nbMines <= p.nbCases);

    // Place les mines demandées au début du tableau
    for (unsigned int i=0; i<p.nbMines; ++i){p.dataMines[i] = 1;}

    // Rempli le reste du tableau de cases non minées
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


void destructionProbleme(Probleme &p){
    delete[] p.dataMines;
}