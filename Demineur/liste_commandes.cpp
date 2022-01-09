/**
  * @file liste_commandes.cpp
  * @author Cyprien Méjat
  * @brief Contient le code des 5 commandes principales
  */


#include "liste_commandes.h"


/**
  * @brief Code commende 1 : Produit et affiche un problème
  */
void creationProbleme(){
    Probleme *p;

    p = new Probleme;
    
    initialisationProbleme(*p);
    placementMinesAleatoire(*p);
    affichageProbleme(*p);
    destructionProbleme(*p);
}


/**
  * @brief Code commande 2 : affiche une grille à partir d'un problème et d'un
  * historique
  */
void ordreAfficherGrille(){
    Grille *g;
    g = new Grille;

    initialisationGrille(*g);

    if (partieFinie(*g) == 1) {
        devoilerMines(*g);
    }

    afficherGrille(*g);
    destructionGrille(*g);
}


/**
  * @brief Code commande 3 : affiche "game won" si la partie est gagné,
  * "game not won" sinon.
  */
void verificationPartieGagnee() {
    Grille* g;
    g = new Grille;

    initialisationGrille(*g);

    if (partieGagne(*g))
        cout << "game won" << endl;

    else
        cout << "game not won" << endl;

    destructionGrille(*g);
}


/**
  * @brief Code commande 4 : affiche "game lost" si la partie est perdue,
  * "game not lost" sinon.
  */
void verificationPartiePerdue() {
    Grille* g;
    g = new Grille;

    initialisationGrille(*g);

    if (partiePerdue(*g))
        cout << "game lost" << endl;

    else
        cout << "game not lost" << endl;

    destructionGrille(*g);
}


/**
  * @brief Code commande 5 : Donne un coup que pourrait jouer l'ordinateur
  */
void coupOrdinateur() {
    Grille* g;
    g = new Grille;

    bool* listeCoupsPossibles;
    listeCoupsPossibles = new bool;

    unsigned int nbCoupsPossibles = enregistrementGrilleClavier(*g);

    selectionnerCoupAleatoire(*g, nbCoupsPossibles);
}