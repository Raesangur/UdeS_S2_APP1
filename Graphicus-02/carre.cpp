// carre.cpp
#include "carre.h"
#include "forme.h"
#include "rectangle.h"
#include <cstddef>

Carre::Carre(double c, Coordonnee ptAncrage) : Rectangle(c, c, ptAncrage)
{
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
