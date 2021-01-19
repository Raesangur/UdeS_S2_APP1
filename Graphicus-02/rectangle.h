// rectangle.h
#pragma once

#include "forme.h"
#include <cstddef>

class Rectangle : public Forme
{
public:
    // Creation rectangle : (L; H; ptAncrage) **Constructeur**
    Rectangle(double L = 1, double H = 1, Coordonnee ptAncrage = {0, 0});
    Rectangle(const Forme* f);

    // Destructeur
    ~Rectangle() = default;

    // Methodes get set
    void setLargeur(double l);
    void setHauteur(double h);

    double getLargeur() const;
    double getHauteur() const;

    // Methodes virtuelles
    virtual double aire() const override;
    void           afficher(std::ostream& s) const override;
    // getAncrage(); et setAncrage(Coordonnee c); **Methodes heritees**

protected:
    double largeur;
    double hauteur;
    // Coordonnee ancrage; en protected herite de la classe Forme
};
