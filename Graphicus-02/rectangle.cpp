// rectangle.cpp
#include "rectangle.h"
#include "forme.h"
#include <cstddef>

Rectangle::Rectangle(double L, double H, Coordonnee ptAncrage) : Forme(ptAncrage.x, ptAncrage.y)
{
    setLargeur(L);
    setHauteur(H);
}
Rectangle::Rectangle(const Forme* f) : Forme(f->getAncrage().x, f->getAncrage().y)
{
    try
    {
        const Rectangle& r = *dynamic_cast<const Rectangle*>(f);
        setLargeur(r.getLargeur());
        setHauteur(r.getHauteur());
    }
    catch(const std::bad_cast& ex)
    {
        setLargeur(1);
        setHauteur(1);
    }
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
