/********
 * Fichier: couche.h
 * Auteurs: Pascal-Emmanuel Lachance
 * Date: 2021-01-15
 * Description: Declaration de la classe pour une couche dans un
 *    canevas. La classe Couche gere un vecteur de pointeur de formes
 *    geometriques en accord avec les specifications de Graphicus.
 *    Ce fichier fait partie de la distribution de Graphicus.
 ********/

#ifndef COUCHE_H
#define COUCHE_H
#include "vector.h"
#include "forme.h"
#include "cercle.h"

class Couche
{
private:
    vector<Forme*> formes;

public:

};

#endif
