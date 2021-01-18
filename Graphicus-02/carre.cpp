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
