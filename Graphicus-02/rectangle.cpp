// rectangle.cpp
#include "rectangle.h"
#include "forme.h"
#include <cstddef>

Rectangle::Rectangle(double L, double H, Coordonnee ptAncrage)
{
    setLargeur(L);
    setHauteur(H);
    setAncrage(ptAncrage);
}

void Rectangle::setLargeur(double l)
{
    largeur = l;
}
void Rectangle::setHauteur(double h)
{
    hauteur = h;
}

double Rectangle::getLargeur() const
{
    return largeur;
}
double Rectangle::getHauteur() const
{
    return hauteur;
}

double Rectangle::aire() const
{
    return largeur * hauteur;
}
void Rectangle::afficher(std::ostream& s) const
{
    s << "Rectangle(";
    ancrage.afficher(s);
    s << "l=" << getLargeur() << ", h=" << getHauteur() << ", aire=" << aire() << ")" << std::endl;
}
