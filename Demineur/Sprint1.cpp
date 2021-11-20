#include <iostream>
#include <cassert>

/**
 * @file Sprint1.c
 * Projet Demineur
 * @author Cyprien Méjat 
 * @version 1 20/11/2021
 * @date date description
 * @brief Fonctions de tri par ordre croissant de tableaux d'entiers  
 * Structures de donn�es et algorithmes - DUT1 Paris 5
 */

#define NB_LIGNES_MAX 16
#define NB_COLONNES_MAX 16
#define NB_CASES_MAX NB_LIGNES_MAX*NB_COLONNES_MAX

#pragma warning (disable:4996)

using std::cout;
using std::cin;
using std::endl;

int srand(time(NULL));


unsigned int initialisationMines(unsigned int nbLignes, unsigned int nbColonnes,
                                 unsigned int nbMines, unsigned int &dataMines);

void creationProbleme();


/**
 * @brief Définie la position des mines sur la grille
 * @param[in] nbLignes Nombre de lignes de la grille
 * @param[in] nbColonnes Nombre de colonnes de la grille
 * @param[in] nbMines Nombre de mines dans la grille
 * @param[inout] dataMines Liste de toutes les positions des mines
 */
unsigned int initialisationMines(unsigned int nbLignes, unsigned int nbColonnes,
                                 unsigned int nbMines, unsigned int &dataMines){
    bool positionNonUtilise = 1;
    for (unsigned int i=0; i<nbMines; i++){
        bool positionNonUtilise = true;
        do{
            unsigned int position = rand()%(nbLignes*nbColonnes);
            for (unsigned int j=0; j<i; j++){
                positionNonUtilise *= position != dataMines[j];
            }
        }
        while(positionNonUtilise == false);
    }
}


/**
 * @brief Produit et affiche un problème
 */
void creationProbleme(){
    unsigned int nbLignes, nbColonnes, nbMines, dataMines[NB_CASES_MAX];

    cin >> nbLignes >> nbColonnes >> nbMines;

    assert(nbLignes <= NB_LIGNES_MAX && nbColonnes <= NB_COLONNES_MAX);
    assert(nbMines <= nbLignes*nbColonnes);

    initialisationMines(nbLignes, nbColonnes, nbMines, dataMines);

    cout << nbLignes << " " << nbColonnes << " " << nbMines;

    for (unsigned int i=0; i<nbMines; i++){
        cout << " " << dataMines[i];
    }

    cout << endl;
}

int main(){

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