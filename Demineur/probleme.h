#ifndef _PROBLEME_
#define _PROBLEME_

#include <iostream>
#include <cassert>

using namespace std;


// Structure contenant les données du problème fourni
struct Probleme {
    unsigned int nbLignes;              // Nombre de lignes dans la grille
    unsigned int nbColonnes;            // Nombre de colonnes dans la grille
    unsigned int nbCases;               // Nombre de cases dans la grille
    unsigned int nbMines;               // Nombre de mines dans la grille
    bool* dataMines;                    // Indique si la case n est minée
};


void creationProbleme();

void initialisationProbleme(Probleme &p);

void placementMinesAleatoire(Probleme &p);

void affichageProbleme(const Probleme &p);

void destructionProbleme(Probleme &p);

#endif