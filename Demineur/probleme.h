/**
  * @file grille.cpp
  * @author Cyprien M�jat
  * @brief Contient les d�clarations concernant la structure probleme, tels
  * que l'initialisation, l'affichage, la destruction...
  */


#ifndef _PROBLEME_
#define _PROBLEME_


#include "structures.h"


/**
  * @brief Initialise un param�tre � partir des du nombre de ligne, de colonnes,
  * et de mines
  * @param[in] p Le probl�me � initialiser
  * @pre Le nombre de mines demand� est inf�rieur ou �gal au nombre de cases
  * total
  */
void initialisationProbleme(Probleme &p);


/**
  * @brief Affiche les donn�es d'un probl�me
  * @param[in] p Probl�me � afficher
  */
void affichageProbleme(const Probleme &p);


/**
  * @brief Affiche les donn�es d'un probl�me
  * @param[out] p Probl�me � afficher
  */
void destructionProbleme(Probleme &p);


#endif