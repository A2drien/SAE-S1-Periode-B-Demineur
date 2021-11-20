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


struct Liste {
	unsigned int tab[NB_CASES_MAX];	// Conteneur primaire (tableau statique)
	unsigned int nbItems = 0; 	    // Nombre d'items stockés
};


unsigned int initialisationMines(unsigned int nbLignes, unsigned int nbColonnes,
                                 unsigned int nbMines, Liste &dataMines);

void creationProbleme();


/**
 * @brief Définie la position des mines sur la grille
 * @param[in] nbLignes Nombre de lignes de la grille
 * @param[in] nbColonnes Nombre de colonnes de la grille
 * @param[in] nbMines Nombre de mines dans la grille
 * @param[inout] dataMines Liste de toutes les positions des mines
 */
unsigned int initialisationMines(unsigned int nbLignes, unsigned int nbColonnes,
                                 unsigned int nbMines, Liste &dataMines){
    bool positionNonUtilise = 1;
    unsigned int position;
    for (unsigned int i=0; i<nbMines; i++){
        do{
            bool positionNonUtilise = true;
            position = rand()%(nbLignes*nbColonnes);
            for (unsigned int j=0; j<i; j++){
                positionNonUtilise *= position != dataMines.tab[j];
            }
        }
        while(positionNonUtilise == false);
        dataMines.tab[i] = position;
        dataMines.nbItems++;
    }
}


/**
 * @brief Produit et affiche un problème
 */
void creationProbleme(){
    unsigned int nbLignes, nbColonnes, nbMines;
    Liste dataMines;

    cin >> nbLignes >> nbColonnes >> nbMines;

    assert(nbLignes <= NB_LIGNES_MAX && nbColonnes <= NB_COLONNES_MAX);
    assert(nbMines <= nbLignes*nbColonnes);

    initialisationMines(nbLignes, nbColonnes, nbMines, dataMines);

    cout << nbLignes << " " << nbColonnes << " " << nbMines;

    for (unsigned int i=0; i<nbMines; i++){
        cout << " " << dataMines.tab[i];
    }

    cout << endl;
}

int main(){
    srand(time(NULL));

    unsigned int operation;

    while (1){
        cin >> operation;

        switch (operation){
            case 1:
                creationProbleme();
                break;
        }
    }
}