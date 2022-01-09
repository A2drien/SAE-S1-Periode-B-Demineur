/**
  * @file cases.h
  * @author Cyprien Méjat
  * @brief Contient les déclarations qui dévoilent et démasquent les cases
  */


#ifndef _CASES_
#define _CASES_


#include "mines.h"


/**
  * @brief Démasque toutes les cases autour de la case donnée en paramètre
  * @param[in,out] g Grille
  * @param[in] nCase Position de la case dont il faut démasquer les alentours
  */
void devoilerCasesVidesAlentours(Grille& g, unsigned int nCase);


/**
  * @brief Demasque la case donnée en paramètre,
  * @param[in,out] g Grille
  * @param[in] nCase Numéro de la case à démasquer
  */
void demasquerCase(Grille& g, unsigned int nCase);


#endif