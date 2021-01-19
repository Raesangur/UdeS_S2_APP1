/********
 * Fichier: forme.h
 * Auteurs: C.-A. Brunet
 * Date: 08 janvier 2018 (creation)
 * Description: Declaration des classes de formes geometriques. La
 *    classe Forme ne doit pas etre modifiee. Ce fichier fait partie de
 *    la distribution de Graphicus.
 ********/

#ifndef FORME_H
#define FORME_H

// Disclaimer : Certaines méthodes ont étés modifiées en y ajoutant le mot-clé "const".
// Ce changement permettent uniquement de rendre la classe utilisable dans plus de contextes, et
// ne modifient en rien les fonctionalités de celle-ci.

#include "coordonnee.h"
#include <iostream>

class Forme
{
public:
    Forme(int x = 0, int y = 0);
    virtual ~Forme();
    void           translater(int deltaX, int deltaY);
    Coordonnee     getAncrage() const;
    void           setAncrage(Coordonnee c);
    virtual double aire() const                    = 0;
    virtual void   afficher(std::ostream& s) const = 0;

protected:
    Coordonnee ancrage;
};

#endif
