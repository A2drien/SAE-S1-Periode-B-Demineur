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
    
    delete& p;
}


/**
  * @brief Code commande 2 : affiche une grille à partir d'un problème et d'un
  * historique
  */
void ordreAfficherGrille(){
    Grille *g;

    g = new Grille;

    initialisationGrille(*g);
    enregistrementMinesProblemeGrille(g->probl);
    afficherGrille(*g);
    destructionGrille(*g);

    delete& g;
}


/**
  * @brief Code commande 3 : affiche "game win" si la partie est gagné,
  * "game in progress" sinon.
  */
void verificationPartieGagnee() {
    Grille* g;

    g = new Grille;

    initialisationGrille(*g);
    enregistrementMinesProblemeGrille(g->probl);

    if (partieGagne(*g))
        cout << "game win" << endl;

    else
        cout << "game in progress" << endl;

    destructionGrille(*g);

    delete& g;
}


/**
  * @brief Code commande 4 : affiche "game lost" si la partie est perdue,
  * "game in progress" sinon.
  */
void verificationPartiePerdue() {
    Grille* g;

    g = new Grille;

    initialisationGrille(*g);
    enregistrementMinesProblemeGrille(g->probl);

    if (partiePerdue(*g))
        cout << "game lost" << endl;

    else
        cout << "game in progress" << endl;

    destructionGrille(*g);

    delete& g;
}


/**
  * @brief Code commande 5 : Donne un coup que pourrait jouer l'ordinateur
  */
void coupOrdinateur() {
    Grille* g;

    g = new Grille;

    enregistrementGrilleClavier(*g);

    Coup coup;

    coupAleatoire(*g, coup);
}