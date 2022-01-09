/**
  * @file mines.h
  * @author Cyprien M�jat
  * @brief Contient les d�clarations concernant le placement, le d�voilement,
  * etc des mines.
  */


#ifndef _MINES_
#define _MINES_


#include "structures.h"


#define CONVERSION_CODE_ASCII 48;      // Convertit un chiffre en ASCII;


/**
  * @brief Place les mines du probl�me avec l'algorithme de
  * @param[in,out] p Le probl�me dont il faut placer les mines
  * @pre Le nombre de mines demand� est inf�rieur ou �gal au nombre de cases
  * total
  */
void placementMinesAleatoire(Probleme& p);


/**
  * @brief Enregistre les positions des mines du probl�me
  * @param[in,out] p Probl�me de la grille
  */
void enregistrementMinesProblemeGrille(Probleme& p);


/**
  * @brief Renvoie le nombre de mines autour de la case fournie en param�tres
  * @param[in] p Probl�me de la grille
  * @param[in] nCase Num�ro de la case � inspecter aux alentours
  * @return Nombre de mines autour de la case donn�e
  */
unsigned int nbMinesAlentours(const Probleme& p, unsigned int nCase);


/**
  * @brief Fait appara�tre toutes les mines
  * @param[in,out] g Grille
  */
void devoilerMines(Grille& g);


#endif