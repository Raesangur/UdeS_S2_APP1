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
    ~Cercle()
    {
    }

    double getRayon() const
    {
        return m_rayon;
    }
    void setRayon(double ray)
    {
        m_rayon = ray;
    }

    double aire() const override
    {
        return 3.14159265358979323846264 * getRayon() * getRayon();
    }
    void afficher(std::ostream& s) const override
    {
        s << "Cercle:\trayon = " << getRayon() << "\tPoint d'ancrage = {";
        ancrage.afficher(s);
        s << "}" << std::endl;
    }

private:
    double m_rayon;
};

#endif

