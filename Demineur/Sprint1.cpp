#include <iostream>
#include <cassert>
#include <time.h>
#include <stdlib.h>

/**
 * @file Sprint1.c
 * Projet Demineur
 * @author Cyprien Méjat 
 * @version 1 20/11/2021
 * @date date description
 * @brief Deuxième partie de la résolution du problème de la SAE 1.02 (Démineur)
 * Produire une grille à partir d'un problème et d'un historique
 */

#define NB_LIGNES_MAX 16
#define NB_COLONNES_MAX 16
#define NB_CASES_MAX NB_LIGNES_MAX*NB_COLONNES_MAX

#pragma warning (disable:4996)

using std::cout;
using std::cin;
using std::endl;


// Structure contenant les données du problème fourni
struct Probleme {
    unsigned int nbLignes = 0;              // Nombre de lignes dans la grille
    unsigned int nbColonnes = 0;            // Nombre de colonnes dans la grille
    unsigned int nbMines = 0;               // Nombre de mines
    unsigned int dataMines[NB_CASES_MAX];   // Liste de la position des mines
};


void creationProbleme(Probleme &p);

void affichageProbleme(const Probleme &p);


/**
 * @brief Produit un problème
 * @param[inout] p Problème à produire
 */
void creationProbleme(Probleme &p){
    cin >> p.nbLignes >> p.nbColonnes >> p.nbMines;

    assert(p.nbLignes <= NB_LIGNES_MAX && p.nbColonnes <= NB_COLONNES_MAX);

    bool positionUtilise;                   // Indique si la case est déjà minée
    unsigned int nCase;                     // Numéro de la case minée

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


int main(){
    srand(time(NULL));

    unsigned int operation;

    Probleme p;

    while (1){
        cin >> operation;

        switch (operation){
            case 1:
                creationProbleme(p);
                affichageProbleme(p);
                break;
        }
    }
}