/**
  * @file grille.h
  * @author Cyprien Méjat
  * @brief Contient les déclarations concernant la structure grille, tels
  * que l'initialisation, l'affichage, la destruction...
  */


#ifndef _GRILLE_
#define _GRILLE_


#include "probleme.h"
#include "historique.h"
#include "etat_partie.h"


/**
  * @brief Initialise une grille
  * @param[in] g Grille
  */
void initialisationGrille(Grille &g);


/**
  * @brief Affiche la grille ainsi que le nombre de lignes et de colonnes
  * @param[in] g Grille à afficher
  */
void afficherGrille(const Grille &g);


/**
 * @brief Détruit la grille
 * @param g Grille à détruire
 */
void destructionGrille(Grille &g);


/**
  * @brief Enregistre la grille fournie au clavier
  * @param[out] g Grille
  */
void enregistrementGrilleClavier(Grille& g);


void coupAleatoire(Grille &g, Coup &c);
#endif
