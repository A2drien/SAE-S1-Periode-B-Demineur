#ifndef _GRILLE_

#define _GRILLE_

#include "probleme.h"
#define CONVERSION_CODE_ASCII 48;      // Convertit un chiffre en ASCII; 


// Structure contenant le type de coup et la case consernée
struct Coup {
    char typeCoup;                     // Type du coup (marquer/démasquer)
    unsigned int nCase;                // Numéro de la case du coup
};


// Structure contenant l'historique des coups joués
struct Historique {
    unsigned int nbCoupsJoues;          // Nombre de coups joués
    Coup* histCoups;                    // Historique des coups joués
};


// Structure contenant la grille
struct Grille {
    Historique hist;                    // Historique des coups de la grille
    Probleme probl;                     // Lignes, colonnes, mines de la grille
    char* affCases;                     // Ce qu'affiche chaque case
};


/**
  * @brief Initialise une grille
  * @param[in] g Grille
  */
void initialisationGrille(Grille &g);


/**
  * @brief Enregistre les positions des mines du problème
  * @param[in,out] p Problème de la grille
  */
void enregistrementMinesProblemeGrille(Probleme &p);

/**
  * @brief Initialise l'historique de la grille
  * @param[in,out] g Grille
  */
void initialisationHistorique(Grille &g);


/**
  * @brief Démasque toutes les cases autour de la case donnée en paramètre
  * @param[in,out] g Grille
  * @param[in] nCase Position de la case dont il faut démasquer les alentours
  */
void devoilerCasesVidesAlentours(Grille &g, unsigned int nCase);


/**
  * @brief Enregistre un coup fourni dans l'historique
  * @param[in,out] g Grille
  * @param[in] nCoup Numéro du coup dans l'historique
  */
void enregistrementCoupHistorique(Grille &g, unsigned int nCoup);


/**
  * @brief Demasque la case donnée en paramètre, 
  * @param[in,out] g Grille
  * @param[in] nCase Numéro de la case à démasquer
  */
void demasquerCase(Grille &g, unsigned int nCase);


/**
  * @brief Renvoie le nombre de mines autour de la case fournie en paramètres
  * @param[in] p Problème de la grille
  * @param[in] nCase Numéro de la case à inspecter aux alentours
  * @return Nombre de mines autour de la case donnée
  */
unsigned int nbMinesAlentours(const Probleme &p, unsigned int nCase);


/**
  * @brief Affiche la grille ainsi que le nombre de lignes et de colonnes
  * @param[in] g Grille à afficher
  */
void afficherGrille(const Grille &g);


/**
  * @brief Détruit l'historique de la grille
  * @param[out] h Historique à détuire
  */
void destuctionHistorique(Historique &h);


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
