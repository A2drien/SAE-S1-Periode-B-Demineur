#include <iostream>
#include <cassert>

/**
 * @file Sprint2.c
 * Projet Demineur
 * @author Cyprien Méjat 
 * @version 1 20/11/2021
 * @date date description
 * @brief Deuxième partie de la résolution du problème de la SAE 1.02 (Démineur)
 * Produire une grille à partir d'un problème et d'un historique
 */

#define NB_LIGNES_MAX 16                // Nombre maximum de lignes acceptés
#define NB_COLONNES_MAX 16              // Nombre maximum de colonnes acceptés
#define NB_CASES_MAX NB_LIGNES_MAX*NB_COLONNES_MAX // Nombre maximum de cases
#define LG_MOT_MAX 5                    // Longueur maximale d'un "mot"
#define CONVERSION_CODE_ASCII 48        // Convertit un chiffre en ASCII

#pragma warning (disable:4996)

using std::cout;
using std::cin;
using std::endl;


// Structure contenant l'historique des coups joués
struct Historique {
    unsigned int nbCoupsJoues = 0;      // Nombre de coups joués
    char typeCoup[NB_CASES_MAX];        // Type du coup (marquer/démasquer)
};

// Structure contenant les données du problème fourni
struct Probleme {
    unsigned int nbLignes = 0;          // Nombre de lignes dans la grille
    unsigned int nbColonnes = 0;        // Nombre de colonnes dans la grille
    unsigned int nbMines = 0;           // Nombre de mines
    bool dataMines[NB_CASES_MAX];       // Indique si la case possède une mine
};

// Structure contenant la grille
struct Grille {
    Historique hist;                    // Historique des coups de la grille
    Probleme probl;                     // Lignes, colonnes, mines de la grille
	char affCases[NB_CASES_MAX];        // Ce qu'affiche chaque case
};

void enregistrementProbleme(Probleme &p);

void enregistrementHistorique(Historique &h);

unsigned int nbMinesAlentours(const Probleme &p, unsigned int nCase);

void ajoutCasesMarquees(Grille &g);

void initialisationGrille(Grille &g);

void afficherGrille(const Grille &g);


/**
 * @brief Enregistre les données du problème
 * @param[inout] p Problème à enregistrer
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