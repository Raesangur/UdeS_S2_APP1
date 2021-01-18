/********
 * Fichier: coordonnee.h
 * Auteurs: C.-A. Brunet
 * Date: 08 janvier 2018 (creation)
 * Description: Structure pour l'ancrage d'une forme geometrique. Cette
 *    classe et donc de fichier, ne doit pas etre modifie. Ce fichier
 *    fait partie de la distribution de Graphicus.
 ********/

#ifndef COORDONNEE_H
#define COORDONNEE_H
#include <iostream>


struct Coordonnee
{
    int x;
    int y;

    void afficher(std::ostream& s) const
    {
        s << "x=" << x << ", y=" << y << " ,";
    }
};

#endif
