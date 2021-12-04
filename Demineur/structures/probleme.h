// Structure contenant les données du problème fourni
struct Probleme {
    unsigned int nbLignes;              // Nombre de lignes dans la grille
    unsigned int nbColonnes;            // Nombre de colonnes dans la grille
    unsigned int nbCases;               // Nombre de cases dans la grille
    unsigned int nbMines;               // Nombre de mines
    unsigned int *dataMines;            // Liste de la position des mines
};