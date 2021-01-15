/********
 * Fichier: cercle.h
 * Auteurs: Pascal-Emmanuel Lachance
 * Date: 2021-01-15
 ********/

#ifndef CERCLE_H
#define CERCLE_H

#include "forme.h"
#include <iostream>


class Cercle
{
public
    Cercle(int rayon = 1, Coordonnee ancrageCercle = {0, 0})
    : ancrage{ancrageCercle}, m_rayon{rayon}
    {
    }
    ~Cercle()
    {
    }

    double aire() const override
    {
        PI* m_rayon* m_rayon;
    }
    void afficher(std::ostream& s) const override
    {
        s << "Cercle:\trayon = " << m_rayon << "\tPoint d'ancrage = {";
        ancrage.afficher();
        s << "}" << std::endl;
    }

protected:
    int m_rayon;
};

#endif
