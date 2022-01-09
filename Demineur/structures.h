/**
  * @file structures.h
  * @author Cyprien Méjat
  * @brief Contient les structures et dépendances.
  */


#ifndef _STRUCTURES_
#define _STRUCTURES_


#include <iostream>
#include <cassert>


using namespace std;


// Structure contenant le type de coup et la case consernée
struct Coup {
    char typeCoup;                     // Type du coup (marquer/démasquer)
    unsigned int nCase;                // Numéro de la case du coup
};


// Structure contenant l'historique des coups joués
struct Historique {
    unsigned int nbCoupsJoues;          // Nombre de coups joués
    Coup* histCoups;                    // Historique des coups joués
};


// Structure contenant les données du problème fourni
struct Probleme {
    unsigned int nbLignes;              // Nombre de lignes dans la grille
    unsigned int nbColonnes;            // Nombre de colonnes dans la grille
    unsigned int nbCases;               // Nombre de cases dans la grille
    unsigned int nbMines;               // Nombre de mines dans la grille
    bool* dataMines;                    // Indique si la case n est minée
};


// Structure contenant la grille
struct Grille {
    Historique hist;                    // Historique des coups de la grille
    Probleme probl;                     // Lignes, colonnes, mines de la grille
    char* affCases;                     // Ce qu'affiche chaque case
};

#endif