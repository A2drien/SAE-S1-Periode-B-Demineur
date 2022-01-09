/**
  * @file historique.h
  * @author Cyprien Méjat
  * @brief Contient les déclarations concernant la structure historique, tels
  * que l'initialisation, l'affichage, la destruction...
  */


#ifndef _HISTORIQUE_
#define _HISTORIQUE_


#include "cases.h"


/**
  * @brief Enregistre un coup fourni dans l'historique
  * @param[in,out] g Grille
  * @param[in] nCoup Numéro du coup dans l'historique
  */
void enregistrementCoupHistorique(Grille& g, unsigned int nCoup);


/**
  * @brief Initialise l'historique de la grille
  * @param[in,out] g Grille
  */
void initialisationHistorique(Grille& g);


/**
  * @brief Détruit l'historique de la grille
  * @param[out] h Historique à détuire
  */
void destuctionHistorique(Historique &h);

#endif