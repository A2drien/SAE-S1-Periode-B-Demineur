#include "Sprint1.cpp"
#include "Sprint2.cpp"

#include <iostream>

using namespace std;

int main(){
    unsigned int typeCommande;
    while (1){
        std::cin >> typeCommande;
        switch(typeCommande){
            case 1: creationProbleme(); break;
            case 2: break;
            case 3: break;
            case 4: break;
            case 5: break;
        }
    }
}