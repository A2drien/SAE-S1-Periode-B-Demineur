/**
 * @file main.c
 * Projet Demineur
 * @author Cyprien Méjat 
 * @version 1 20/11/2021
 * @date date description
 * @brief Deuxième partie de la résolution du problème de la SAE 1.02 (Démineur)
 * Produire une grille à partir d'un problème et d'un historique
 */


#include "structures/grille.h"
#include "define.h"

#include <iostream>
#include <cassert>

using std::cout;
using std::cin;
using std::endl;


void creationProbleme(Probleme &p);

void affichageProbleme(const Probleme &p);

void enregistrementProbleme(Probleme &p);

void enregistrementHistorique(Historique &h);

unsigned int nbMinesAlentours(const Probleme &p, unsigned int nCase);

void ajoutCasesMarquees(Grille &g);

void initialisationGrille(Grille &g);

void afficherGrille(const Grille &g);

void creationGrille(Grille &g){};

void testPartieGagne(const Grille &g){}

void testPartiePerdue(const Grille &g){}

void etatPartie();

void nouveauCoup(Grille &g){}


/**
 * @brief Produit un problème
 * @param[in] p Problème à produire
 */
void creationProbleme(Probleme &p){
    cin >> p.nbLignes >> p.nbColonnes >> p.nbMines;
    assert(p.nbMines <= p.nbCases);

    p.nbCases = p.nbLignes * p.nbColonnes;
    p.dataMines = new unsigned int[p.nbMines];

    bool positionUtilise;               // Indique si la case est déjà minée
    unsigned int nCase;                 // Numéro de la case minée

    for (unsigned int i=0; i<p.nbMines; i++){
        do{
            positionUtilise = false;
            nCase = rand()%(p.nbLignes*p.nbColonnes);

            for (unsigned int j=0; j<i; j++){
                if (nCase == p.dataMines[j])
                    positionUtilise = true;
            }
        }
        while (positionUtilise);

        p.dataMines[i] = nCase;
    }
}


/**
 * @brief Affiche un problème
 * @param[in] p Problème à afficher
 */
void affichageProbleme(const Probleme &p){
    cout << p.nbLignes << " " << p.nbColonnes << " " << p.nbMines;

    for (unsigned int i=0; i<p.nbMines; i++){
        cout << " " << p.dataMines[i];
    }

    cout << endl;
}


/**
 * @brief Enregistre les données du problème
 * @param[in] p Problème à enregistrer
 */
void enregistrementProbleme(Probleme &p){
    cin >> p.nbLignes >> p.nbColonnes >> p.nbMines;

    for (unsigned int i=0; i<p.nbColonnes*p.nbLignes; i++){
        p.dataMines[i] = 0;
    }

    unsigned int position;

    for (unsigned int i=0; i<p.nbMines; i++){
        cin >> position;
        p.dataMines[position] = 1;
    }
}


/**
 * @brief Enregistre les données de l'historique
 * @param[inout] h Historique des coups
 */
void enregistrementHistorique(Historique &h){
    cin >> h.nbCoupsJoues;
    unsigned int position;
    char typeAction;
    for (unsigned int i=0; i<h.nbCoupsJoues; i++){
        cin >> typeAction >> position;
        h.typeCoup[position] = typeAction;
    }
}

/**
 * @brief Renvoie le nombre de mines autour de la case fournie en paramètres
 * @param[in] p Problème de la grille
 * @param[in] nCase Numéro de la case à inspecter aux alentours
 * @return Le nombre de mines autour de la case donnée
 */
unsigned int nbMinesAlentours(const Probleme &p, unsigned int nCase){
    unsigned int x = nCase%p.nbColonnes, y = nCase/p.nbColonnes;
    unsigned int xMax = p.nbColonnes-1, yMax = p.nbLignes-1;
    unsigned int nbMines = 0;

    // Si la case actuelle n'est PAS tout en haut
    if (y != 0){
        nbMines += p.dataMines[nCase - p.nbColonnes];
        
        // Si la case actuelle n'est PAS tout en haut à gauche
        if (x != 0){nbMines += p.dataMines[nCase - p.nbColonnes - 1];}
        
        // Si la case actuelle n'est PAS tout en haut à droite
        if (x != xMax){nbMines += p.dataMines[nCase - p.nbColonnes + 1];}
    }
    
    // Si la case actuelle n'est PAS tout à gauche
    if (x != 0){nbMines += p.dataMines[nCase - 1];}
    
    // Si la case actuelle n'est PAS tout à droite
    if (xMax != 0){nbMines += p.dataMines[nCase + 1];}

    // Si la case actuelle n'est PAS tout en bas
    if (y != yMax){
        nbMines += p.dataMines[nCase + p.nbColonnes];
        
        // Si la case actuelle n'est PAS tout en haut à gauche
        if (x != 0){nbMines += p.dataMines[nCase + p.nbColonnes - 1];}

        // Si la case actuelle n'est PAS tout en haut à gauche
        if (x != xMax){nbMines += p.dataMines[nCase + p.nbColonnes + 1];}
    }
    return nbMines;
}

/**
 * @brief Ajoute à la grille les indications de marquages tels que '.', 'x'...
 * @param[inout] g Grille à completer
 */
void ajoutCasesMarquees(Grille &g){
    for (unsigned int i=0; i<g.probl.nbColonnes*g.probl.nbLignes; i++){
        if (g.hist.typeCoup[i] == 'M')
            g.affCases[i] = 'x';
        
        else if (g.hist.typeCoup[i] == 'D'){
            unsigned int nbMinesAutours = nbMinesAlentours(g.probl, i);
            if (nbMinesAutours == 0)
                g.affCases[i] = ' ';
            
            else
                g.affCases[i] = nbMinesAutours + CONVERSION_CODE_ASCII;
        }
    }
}

/**
 * @brief Produit une grille à partir d’un problème et d’un historique de coups
 * @param[inout] g Grille à produire
 */
void initialisationGrille(Grille &g){
    enregistrementProbleme(g.probl);
    enregistrementHistorique(g.hist);
    for (unsigned int i=0; i<g.probl.nbColonnes*g.probl.nbLignes; i++){
        g.affCases[i] = '.';   // Les cases sont de base masquées
    }
    ajoutCasesMarquees(g);
}


/**
 * @brief Affiche la grille ainsi que le nombre de lignes et de colonnes
 * @param[in] g Grille à afficher
 */
void afficherGrille(const Grille &g){
    unsigned int nbLignes = g.probl.nbLignes;
    unsigned int nbColonnes = g.probl.nbColonnes;

    cout << nbLignes << " " << nbColonnes << endl;

    for (unsigned int i=0; i<nbLignes; i++){
        for (unsigned int j=0; j<nbColonnes; j++){
            cout << " ___";
        }
        cout << endl;

        for (unsigned int j=0; j<nbColonnes; j++){
            cout << "| " << g.affCases[i*nbLignes+j] << " ";
        }
        cout << "|" << endl;
    }
    
    for (unsigned int i=0; i<nbColonnes; i++){
        cout << " ___";
    }
    cout << endl;
}


int main(){
    srand(time(NULL));
    
    Grille grille;                      // Grille à manipuler
    unsigned int operation = 0;         // Numéro de l'opération à effectuer

    while(1){
        cin >> operation;

        switch (operation){
            case 2:
                initialisationGrille(grille);
                afficherGrille(grille);
        }
    }
}