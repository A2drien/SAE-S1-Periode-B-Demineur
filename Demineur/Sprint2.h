#include "structures.h"
#include "define.h"



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









// Serviront pour d'autres Sprints
void testPartieGagne(const Grille &g);

void testPartiePerdue(const Grille &g);

void etatPartie();

void nouveauCoup(Grille &g);