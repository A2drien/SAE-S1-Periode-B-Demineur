#include "structures.h"
#include "define.h"

#include <iostream>
#include <cassert>

using namespace std;

void creationProbleme();

void initialisationProbleme(Probleme &p);

void placementMines(Probleme &p);

void affichageProbleme(const Probleme &p);

void destructionProbleme(Probleme &p);
