/********
 * Fichier: cercle.h
 * Auteurs: Pascal-Emmanuel Lachance
 * Date: 2021-01-15
 ********/

#ifndef CERCLE_H
#define CERCLE_H

#include "forme.h"
#include <iostream>


class Cercle : public Forme
{
public:
    Cercle(double ray = 1, Coordonnee a = {0, 0}) : Forme{a.x, a.y}, m_rayon{ray}
    {
    }
    ~Cercle() = default;

    double getRayon() const;
    void   setRayon(double ray);

    double aire() const override;
    void   afficher(std::ostream& s) const override;

private:
    double m_rayon;
};

#endif
