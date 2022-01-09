/**
  * @file mines.h
  * @author Cyprien Méjat
  * @brief Contient les déclarations concernant le placement, le dévoilement,
  * etc des mines.
  */


#ifndef _MINES_
#define _MINES_


#include "structures.h"


#define CONVERSION_CODE_ASCII 48;      // Convertit un chiffre en ASCII;


/**
  * @brief Place les mines du problème avec l'algorithme de
  * @param[in,out] p Le problème dont il faut placer les mines
  * @pre Le nombre de mines demandé est inférieur ou égal au nombre de cases
  * total
  */
void placementMinesAleatoire(Probleme& p);


/**
  * @brief Enregistre les positions des mines du problème
  * @param[in,out] p Problème de la grille
  */
void enregistrementMinesProblemeGrille(Probleme& p);


/**
  * @brief Renvoie le nombre de mines autour de la case fournie en paramètres
  * @param[in] p Problème de la grille
  * @param[in] nCase Numéro de la case à inspecter aux alentours
  * @return Nombre de mines autour de la case donnée
  */
unsigned int nbMinesAlentours(const Probleme& p, unsigned int nCase);


/**
  * @brief Fait apparaître toutes les mines
  * @param[in,out] g Grille
  */
void devoilerMines(Grille& g);


#endif