// carre.h
#pragma once

#include "forme.h"
#include "rectangle.h"
#include <cstddef>

class Carre : public Rectangle
{
public:
    Carre(double c = 1, Coordonnee ancrage = {0, 0});
    ~Carre() = default;

    void   setCote(double valCote);
    double getCote() const;

    void   setLargeur(double l);
    void   setHauteur(double h);
    size_t getLargeur() const;
    size_t getHauteur() const;

    double aire() const override;
    void   afficher(std::ostream& s) const override;
};
