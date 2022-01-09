/**
  * @file grille.cpp
  * @author Cyprien Méjat 
  * @brief Contient le code concernant la structure grille, tels
  * que l'initialisation, l'affichage, la destruction...
  */


#include "grille.h"


  /**
  * @brief Initialise une grille
  * @param[in] g Grille
  */
void initialisationGrille(Grille &g){
    initialisationProbleme(g.probl);
    enregistrementMinesProblemeGrille(g.probl);

    g.affCases = new char[g.probl.nbCases];
    
    // L'intégralité des cases sont de base masquées
    for (unsigned int i=0; i<g.probl.nbCases; ++i){
        g.affCases[i] = '.';
    }

    initialisationHistorique(g);
}

/**
  * @brief Affiche la grille ainsi que le nombre de lignes et de colonnes
  * @param[in] g Grille à afficher
  */
void afficherGrille(const Grille &g){
    unsigned int nbLignes = g.probl.nbLignes;
    unsigned int nbColonnes = g.probl.nbColonnes;

    cout << nbLignes << " " << nbColonnes << endl;

    for (unsigned int i=0; i<nbLignes; ++i){
        for (unsigned int j=0; j<nbColonnes; j++){
            cout << " ___";
        }
        cout << endl;

        for (unsigned int j=0; j<nbColonnes; j++){
            cout << "| " << g.affCases[i*nbColonnes+j] << " ";
        }
        cout << "|" << endl;
    }
    
    for (unsigned int i=0; i<nbColonnes; ++i){
        cout << " ___";
    }
    cout << endl;
}


/**
 * @brief Détruit la grille
 * @param g Grille à détruire
 */
void destructionGrille(Grille &g){
    unsigned int nbCases = g.probl.nbCases;

    destructionProbleme(g.probl);
    
    destuctionHistorique(g.hist);
    delete& g.hist;

    //delete[] &g.affCases; // Provoque un crash
    
}


/**
  * @brief Enregistre la grille fournie au clavier
  * @param[out] g Grille
  */
void enregistrementGrilleClavier(Grille& g) {
    cin >> g.probl.nbLignes >> g.probl.nbColonnes;

    char caractereGrille;

    for (unsigned int x = 0; x < g.probl.nbLignes; ++x) {
        // Efface la grille du côté haut
        for (unsigned int i = 0; i < g.probl.nbLignes * 4; ++i) {
            cin >> caractereGrille;
        }

        for (unsigned int y = 0; y < g.probl.nbColonnes; ++y) {
            cin >> g.affCases[x * g.probl.nbLignes + y];
        }
    }
}


void coupAleatoire(Grille& g, Coup& c) {

}