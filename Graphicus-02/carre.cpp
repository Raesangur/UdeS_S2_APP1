// carre.cpp
#include "carre.h"
#include "forme.h"
#include "rectangle.h"
#include <cstddef>

Carre::Carre(double cote, Coordonnee ptAncrage)
{
    setCote(cote);
    setAncrage(ptAncrage);
}

void Carre::setCote(double valCote)
{
    cote = valCote;
}
double Carre::getCote() const
{
    return cote;
}

double Carre::aire() const
{
    return cote * cote;
}

void Carre::afficher(std::ostream& s) const
{
    s << "Carre(";
    ancrage.afficher(s);
    s << "c=" << getCote() << ", aire=" << aire() << ")" << std::endl;
}
