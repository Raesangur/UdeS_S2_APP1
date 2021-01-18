// rectangle.h
#pragma once

#include "forme.h"
#include <cstddef>

class Rectangle : public Forme
{
public:
    // creation rectangle : (L;H;ptAncrage) **Constructeur**
    Rectangle(double L = 1, double H = 1, Coordonnee ptAncrage = {0, 0});
    // Destructeur
    ~Rectangle() = default;
    // Methodes get set

    void setLargeur(double l)
    {
        largeur = l;
    }
    void setHauteur(double h)
    {
        hauteur = h;
    }

    double getLargeur() const
    {
        return largeur;
    }
    double getHauteur() const
    {
        return hauteur;
    }

    virtual double aire() const override
    {
        return largeur * hauteur;
    }
    void afficher(std::ostream& s) const override
    {
        s << "Rectangle(";
        ancrage.afficher(s);
        s << "l=" << getLargeur() << ", h=" << getHauteur() << ", aire=" << aire() << ")" << std::endl;
    }
    // getAncrage(); et setAncrage(Coordonnee c); **Methodes heritees**

private:
    double largeur;
    double hauteur;
    // Coordonnee ancrage; en protected herite de la classe Forme
};

