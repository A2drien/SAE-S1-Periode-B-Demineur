/**
 * @file main.cpp
 * @author Cyprien Méjat
 * @brief Charge le programme final
 */


#include "liste_commandes.h"


int main(){
    srand(time(NULL));

    unsigned int typeCommande;
        
    cin >> typeCommande;
        
    switch(typeCommande){
        case 1: creationProbleme();         break;
        case 2: ordreAfficherGrille();      break;
        case 3: verificationPartieGagnee(); break;
        case 4: verificationPartiePerdue(); break;
        case 5: coupOrdinateur();           break;
    }

    return 0;
}