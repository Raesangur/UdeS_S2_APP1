// carre.h
#pragma once

#include "forme.h"
#include "rectangle.h"
#include <cstddef>

class Carre : public Rectangle
{
public:
    Carre(double cote = 1, Coordonnee ancrage = {0, 0});
    ~Carre() = default;

    void   setCote(double valCote);
    double getCote() const;

    double aire() const override;
    void   afficher(std::ostream& s) const override;

private:
    double cote;
};
