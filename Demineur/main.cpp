#include "liste_commandes.h"


int main(){

    unsigned int typeCommande;
    
    while (1){
        
        cin >> typeCommande;
        
        switch(typeCommande){
            case 1: creationProbleme();         break;
            case 2: ordreAfficherGrille();      break;
            case 3: verificationPartieGagnee(); break;
            case 4: verificationPartiePerdue(); break;
            case 5: coupOrdinateur();           break;
        }
    }
    return 0;
}