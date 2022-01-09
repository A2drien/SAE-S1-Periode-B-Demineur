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
  * @param[in] g Grille
  * @return nbCoupsPossibles nombres de coups possibles dans la liste
  */
unsigned int enregistrementGrilleClavier(Grille& g) {
    cin >> g.probl.nbLignes >> g.probl.nbColonnes;
    g.probl.nbCases = g.probl.nbColonnes * g.probl.nbLignes;

    g.affCases = new char[g.probl.nbCases];

    char caractereGrille;
    unsigned int nbCoupsPossibles = 0;

    for (unsigned int x = 0; x < g.probl.nbLignes; ++x) {

        // Efface la grille du côté haut
        for (unsigned int i = 0; i < g.probl.nbColonnes * NB_CARACTERE_CASE; ++i) {
            cin >> caractereGrille;
        }

        cin >> caractereGrille; // Enlève le | de gauche

        // Enregistre le contenu des cases
        for (unsigned int y = 0; y < g.probl.nbColonnes; ++y) {
            cin >> caractereGrille;

            // S'il trouve le symbole '|', c'est qu'il devait prendre un espace
            if (caractereGrille == '|') {
                g.affCases[x * g.probl.nbColonnes + y] = ' ';
            }

            // Sinon, c'est le bon caractère
            else {
                g.affCases[x * g.probl.nbColonnes + y] = caractereGrille;
                cin >> caractereGrille; // Enlève le | à droite

                if (g.affCases[x * g.probl.nbColonnes + y] == '.') {
                    nbCoupsPossibles++;
                }
            }
        }
    }

    // Efface la grille du côté bas
    for (unsigned int i = 0; i < g.probl.nbColonnes * NB_CARACTERE_CASE; ++i) {
        cin >> caractereGrille;
    }

    return nbCoupsPossibles;
}


/**
 * @brief Sélectionne et affiche un coup aléatoire
 * @param g Grille
 * @param nbCoupsPossibles Nombre de cases libres 
 */
void selectionnerCoupAleatoire(const Grille& g, unsigned int nbCoupsPossibles) {
    // Afficher le type de coup (il y en a 2, donc une chance sur 2) :
    if (rand() % 2 == 0)
        cout << "D";

    else
        cout << "M";


    // Afficher la case à marquer/démasquer : 
    unsigned int nCase = rand() % nbCoupsPossibles;
    unsigned int idxCase = 0;

    for (unsigned int i = 0; i < g.probl.nbCases; ++i) {
        if (g.affCases[i] == '.' && idxCase == nCase) {
            cout << i;
            break;
        }

        else if (g.affCases[i] == '.'){
            idxCase++;
        }
    }
}