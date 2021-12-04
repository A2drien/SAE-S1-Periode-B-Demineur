#ifndef _HISTORIQUE_
#define _HISTORIQUE_

// Structure contenant l'historique des coups joués
struct Historique {
    unsigned int nbCoupsJoues;          // Nombre de coups joués
    char *typeCoup;                     // Type du coup (marquer/démasquer)
    unsigned int *nCase;                // Numéro de la case du coup
};

#endif