/**
  * @file etat_partie.h
  * @author Cyprien Méjat
  * @brief Contient les déclarations concernant les états de la partie (gagnée, perdue, en cours)
  */


#ifndef _ETAT_PARTIE_
#define _ETAT_PARTIE_


#include "structures.h"


/**
  * @brief Retourne 1 si la partie est gagnée, 0 sinon
  * @param[in] g Grille
  */
bool partieGagne(const Grille& g);


/**
  * @brief Retourne 1 si la partie est perdue, 0 sinon
  * @param[in] g Grille
  */
bool partiePerdue(const Grille& g);


/**
  * @brief Retourne 1 si la partie est finie (gagnée ou perdue)
  * @param[in] g Grille
  */
bool partieFinie(const Grille& g);

#endif