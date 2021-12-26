/**
  * @file main.c
  * Projet Demineur
  * @author Cyprien Méjat 
  * @version 1 20/11/2021
  * @date date description
  * @brief Deuxième partie de la résolution du problème de la SAE 1.02 (Démineur)
  * Produire une grille à partir d'un problème et d'un historique
  */

#include <iostream>
#include <cassert>

#include "Sprint1.cpp"
#include "Sprint2.h"

using namespace std;


/**
  * @brief Initialise une grille
  * @param[in] g Grille
  */
void initialisationGrille(Grille &g){
    initialisationHistorique(g);
    initialisationProbleme(g.probl);

    g.affCases = new char[g.probl.nbCases];

    enregistrementHistorique(g.hist);
    
    for (unsigned int i=0; i<g.probl.nbColonnes*g.probl.nbLignes; ++i){
        g.affCases[i] = '.';   // Les cases sont de base masquées
    }
}


/**
  * @brief Enregistre les positions des mines du problème
  * @param[in,out] p Problème de la grille
  */
void enregistrementMinesProblemeGrille(Probleme &p){
    for (unsigned int i=0; i<p.nbCases; ++i){
        p.dataMines[i] = 0;
    }
    
    unsigned int positionMine; // Position de la mine
    
    for (unsigned int i=0; i<p.nbMines; ++i){
        cin >> positionMine;
        p.dataMines[positionMine] = 1;
    }
}


/**
  * @brief Initialise l'historique de la grille
  * @param[in,out] g Grille
  */
void initialisationHistorique(Grille &g){
    cin >> g.hist.nbCoupsJoues;
    g.hist.histCoups = new Coup[g.hist.nbCoupsJoues];
    
    for (unsigned int i=0; i<g.hist.nbCoupsJoues; ++i){
        enregistrementCoupHistorique(g, i);
    }
}


/**
  * @brief Démasque toutes les cases autour de la case donnée en paramètre
  * @param[in,out] g Grille
  * @param[in] nCase Position de la case dont il faut démasquer les alentours
  */
void devoilerCasesVidesAlentours(Grille &g, unsigned int nCase){
    // Abscisse et ordonnée de la case donné en paramètre
    unsigned int x = nCase%g.probl.nbColonnes, y = nCase/g.probl.nbColonnes;
    
    // Abscisse et ordonnée maximales de la grille
    unsigned int xMax = g.probl.nbColonnes-1, yMax = g.probl.nbLignes-1;
    
    for (int i=-1; i<=1; ++i){
        for (int j=-1; j<=-1; ++j){
            /* Si : 
             * 1) La case à tester n'est pas celle donnée en paramètre
             * 2) L'abscisse de la case à tester est cohérente (0 <= x <= xMax)
             * 3) L'ordonnée de la case à tester est cohérente (0 <= y <= yMax)
             * Alors, démasquer la case testée */
            if ((i != 0 && j != 0) && (0 <= i+x && i+x <= xMax) && (0 <= j+y &&
                j+y <= yMax)){
                demasquerCase(g, nCase);
            }
        }
    }
}


/**
  * @brief Enregistre un coup fourni dans l'historique
  * @param[in,out] g Grille
  * @param[in] nCoup Numéro du coup dans l'historique
  */
void enregistrementCoupHistorique(Grille &g, unsigned int nCoup){
    char typeCoup; // Type du coup (marquer/démasquer)
    unsigned int nCase; // Numéro de la case du coup

    cin >> typeCoup >> nCase;

    g.hist.histCoups[nCoup].typeCoup = typeCoup;
    g.hist.histCoups[nCoup].nCase = nCase;

    if (typeCoup == 'M') // Si le joueur marque une case
        g.affCases[nCoup] = 'x';
    
    else if (typeCoup == 'D'){ // Si le joueur démasque une case
        demasquerCase(g, nCase);
    }
}


/**
  * @brief Demasque la case donnée en paramètre, 
  * @param[in,out] g Grille
  * @param[in] nCase Numéro de la case à démasquer
  */
void demasquerCase(Grille &g, unsigned int nCase){
    unsigned int nbMinesAutours = nbMinesAlentours(g.probl, nCase);
        
    if (nbMinesAutours == 0){
        g.affCases[nCase] = ' ';
        devoilerCasesVidesAlentours(g, nCase);
    }
    
    else{
        g.affCases[nCase] = nbMinesAutours + CONVERSION_CODE_ASCII;
    }
}


/**
  * @brief Enregistre les données de l'historique
  * @param[in,out] h Historique des coups
  */
void enregistrementHistorique(Historique &h){
    cin >> h.nbCoupsJoues;
    unsigned int position;
    char typeAction;
    for (unsigned int i=0; i<h.nbCoupsJoues; ++i){
        cin >> typeAction >> position;
        h.histCoups[position].typeCoup = typeAction;
    }
}


/**
  * @brief Renvoie le nombre de mines autour de la case fournie en paramètres
  * @param[in] p Problème de la grille
  * @param[in] nCase Numéro de la case à inspecter aux alentours
  * @return Nombre de mines autour de la case donnée
  */
unsigned int nbMinesAlentours(const Probleme &p, unsigned int nCase){
    // Abscisse et ordonnée de la case donnée en paramètre
    unsigned int x = nCase%p.nbColonnes, y = nCase/p.nbColonnes;
    
    // Abscisse et ordonnée maximales de la grille
    unsigned int xMax = p.nbColonnes-1, yMax = p.nbLignes-1;
    
    unsigned int nbMines = 0; // Nombre de mines autour de la case donnée

    for (int i=-1; i<=1; ++i){
        for (int j=-1; j<=-1; ++j){
            /* Si : 
             * 1) La case à tester n'est pas celle donnée en paramètre
             * 2) L'abscisse de la case à tester est cohérente (0 <= x <= xMax)
             * 3) L'ordonnée de la case à tester est cohérente (0 <= y <= yMax)
             * Alors, ajoute 1 si la case testée est minée */
            if ((i != 0 && j != 0) && (0 <= i+x && i+x <= xMax) && (0 <= j+y &&
                j+y <= yMax)){
                nbMines += p.dataMines[nCase];
            }
        }
    }
    return nbMines;
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
            cout << "| " << g.affCases[i*nbLignes+j] << " ";
        }
        cout << "|" << endl;
    }
    
    for (unsigned int i=0; i<nbColonnes; ++i){
        cout << " ___";
    }
    cout << endl;
}


/**
  * @brief Détruit l'historique de la grille
  * @param[out] h Historique à détuire
  */
void destuctionHistorique(Historique &h){
    delete[] h.histCoups;
}


/**
 * @brief Détruit la grille
 * @param g Grille à détruire
 */
void destructionGrille(Grille &g){
    destructionProbleme(g.probl);
    destuctionHistorique(g.hist);
    delete[] g.affCases;
}