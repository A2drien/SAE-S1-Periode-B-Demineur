#include "Sprint2.cpp"


/**
  * @brief Enregistre les données de la grille fournie au clavier
  * @param g Grille
  */
void enregistrementCoup(Grille &g){
    cin >> g.probl.nbLignes >> g.probl.nbColonnes;

    char caractereGrille;

    for (unsigned int x=0; x<g.probl.nbLignes; ++x){
        // Efface la grille du côté haut
        for (unsigned int i=0; i<g.probl.nbLignes*4; ++i){
            cin >> caractereGrille;
        }
        
        for (unsigned int y=0; y<g.probl.nbColonnes; ++y){
            cin >> g.affCases[x*g.probl.nbLignes+y];
        }
    }

    for (unsigned int i=0; i<0;++i){
        
    }
}