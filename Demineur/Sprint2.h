#include "Structures.h"
#include "Define.h"


void creationGrille(Grille &g);

// ???
void initialisationGrille(Grille &g);

void enregistrementMinesProblemeGrille(Probleme &p);

void enregistrementHistorique(Historique &h);

void enregistrementCoupHistorique(Grille &g, unsigned int nCoup);

void demasquerCase(Grille &g, unsigned int nCase);

unsigned int nbMinesAlentours(const Probleme &p, unsigned int nCase);

void afficherGrille(const Grille &g);












void testPartieGagne(const Grille &g);

void testPartiePerdue(const Grille &g);

void etatPartie();

void nouveauCoup(Grille &g);