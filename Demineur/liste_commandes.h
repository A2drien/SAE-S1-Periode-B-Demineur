#ifndef _LISTE_COMMANDES_
#define _LISTE_COMMANDES_

#include "etat_partie.h"

/**
  * @brief Code commende 1 : Produit et affiche un problème
  */
void creationProbleme();


/**
  * @brief Code commande 2 : affiche une grille à partir d'un problème et d'un
  * historique
  */
void ordreAfficherGrille();


/**
  * @brief Code commande 3 : affiche "game lost" si la partie est perdue,
  * "game in progress" sinon.
  */
void verificationPartieGagnee();


/**
  * @brief Code commande 4 : affiche "game lost" si la partie est perdue,
  * "game in progress" sinon.
  */
void verificationPartiePerdue();


/**
  * @brief Code commande 5 : Donne un coup que pourrait jouer l'ordinateur
  */
void coupOrdinateur();
#endif