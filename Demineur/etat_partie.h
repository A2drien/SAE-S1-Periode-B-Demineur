/**
  * @file etat_partie.h
  * @author Cyprien M�jat
  * @brief Contient les d�clarations concernant les �tats de la partie
  * (gagn�e, perdue, en cours)
  */


#ifndef _ETAT_PARTIE_
#define _ETAT_PARTIE_


#include "structures.h"


/**
  * @brief Retourne 1 si la partie est gagn�e, 0 sinon
  * @param[in] g Grille
  */
bool partieGagne(const Grille& g);


/**
  * @brief Retourne 1 si la partie est perdue, 0 sinon
  * @param[in] g Grille
  */
bool partiePerdue(const Grille& g);


/**
  * @brief Retourne 1 si la partie est finie (gagn�e ou perdue)
  * @param[in] g Grille
  */
bool partieFinie(const Grille& g);


#endif