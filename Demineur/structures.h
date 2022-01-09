/**
  * @file structures.h
  * @author Cyprien M�jat
  * @brief Contient les structures et d�pendances.
  */


#ifndef _STRUCTURES_
#define _STRUCTURES_


#include <iostream>
#include <cassert>


using namespace std;


// Structure contenant le type de coup et la case consern�e
struct Coup {
    char typeCoup;                     // Type du coup (marquer/d�masquer)
    unsigned int nCase;                // Num�ro de la case du coup
};


// Structure contenant l'historique des coups jou�s
struct Historique {
    unsigned int nbCoupsJoues;          // Nombre de coups jou�s
    Coup* histCoups;                    // Historique des coups jou�s
};


// Structure contenant les donn�es du probl�me fourni
struct Probleme {
    unsigned int nbLignes;              // Nombre de lignes dans la grille
    unsigned int nbColonnes;            // Nombre de colonnes dans la grille
    unsigned int nbCases;               // Nombre de cases dans la grille
    unsigned int nbMines;               // Nombre de mines dans la grille
    bool* dataMines;                    // Indique si la case n est min�e
};


// Structure contenant la grille
struct Grille {
    Historique hist;                    // Historique des coups de la grille
    Probleme probl;                     // Lignes, colonnes, mines de la grille
    char* affCases;                     // Ce qu'affiche chaque case
};

#endif