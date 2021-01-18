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
