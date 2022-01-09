/**
  * @file grille.cpp
  * @author Cyprien Méjat
  * @brief Contient les déclarations concernant la structure probleme, tels
  * que l'initialisation, l'affichage, la destruction...
  */


#ifndef _PROBLEME_
#define _PROBLEME_


#include "structures.h"


/**
  * @brief Initialise un paramètre à partir des du nombre de ligne, de colonnes,
  * et de mines
  * @param[in] p Le problème à initialiser
  * @pre Le nombre de mines demandé est inférieur ou égal au nombre de cases
  * total
  */
void initialisationProbleme(Probleme &p);


/**
  * @brief Affiche les données d'un problème
  * @param[in] p Problème à afficher
  */
void affichageProbleme(const Probleme &p);


/**
  * @brief Affiche les données d'un problème
  * @param[in] p Problème à afficher
  */
void destructionProbleme(Probleme &p);

#endif