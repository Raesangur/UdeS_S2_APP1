// carre.h
#pragma once

#include "forme.h"
#include "rectangle.h"
#include <cstddef>

class Carre : public Rectangle
{
public:
    Carre(double c = 1, Coordonnee ancrage = {0, 0});
    Carre(const Forme* f);
    ~Carre() = default;

    void   setCote(double valCote);
    double getCote() const;


    double aire() const override;
    void   afficher(std::ostream& s) const override;

private:
    // Modification de la déclaration d'accessibilité des méthodes héritées de rectangle
    using Rectangle::setLargeur;
    using Rectangle::setHauteur;
    using Rectangle::getLargeur;
    using Rectangle::getHauteur;
};
