/**
  * @file cases.h
  * @author Cyprien M�jat
  * @brief Contient les d�clarations qui d�voilent et d�masquent les cases
  */


#ifndef _CASES_
#define _CASES_


#include "mines.h"


/**
  * @brief D�masque toutes les cases autour de la case donn�e en param�tre
  * @param[in,out] g Grille
  * @param[in] nCase Position de la case dont il faut d�masquer les alentours
  */
void devoilerCasesVidesAlentours(Grille& g, unsigned int nCase);


/**
  * @brief Demasque la case donn�e en param�tre,
  * @param[in,out] g Grille
  * @param[in] nCase Num�ro de la case � d�masquer
  */
void demasquerCase(Grille& g, unsigned int nCase);


#endif