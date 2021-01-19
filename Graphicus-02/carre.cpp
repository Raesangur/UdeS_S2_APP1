// carre.cpp
#include "carre.h"
#include "forme.h"
#include "rectangle.h"
#include <cstddef>

Carre::Carre(double c, Coordonnee ptAncrage) : Rectangle(c, c, ptAncrage)
{
}
Carre::Carre(const Forme* f)
{
    try
    {
        const Carre& c = *dynamic_cast<const Carre*>(f);
        setCote(c.getCote());
        setAncrage(c.getAncrage());
    }
    catch(const std::bad_cast& ex)
    {
        setCote(1);
    }
}

void Carre::setCote(double valCote)
{
    largeur = valCote;
    hauteur = valCote;
}
double Carre::getCote() const
{
    return largeur;
}

void Carre::setLargeur(double l)
{
    setCote(l);
}
void Carre ::setHauteur(double h)
{
    setCote(h);
}

size_t Carre::getLargeur() const
{
    return getCote();
}
size_t Carre ::getHauteur() const
{
    return getCote();
}

double Carre::aire() const
{
    return hauteur * largeur;
}

void Carre::afficher(std::ostream& s) const
{
    s << "Carre(";
    ancrage.afficher(s);
    s << "c=" << getCote() << ", aire=" << aire() << ")" << std::endl;
}
