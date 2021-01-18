//rectangle.cpp
#include <cstddef>
#include "forme.h"
#include "rectangle.h"


//Initialisation H, L, ptAncrage lors de l'appel du constructeur
Rectangle::Rectangle()
{
   setLargeur(1);
   setHauteur(1);
   setAncrage({0, 0});
}

Rectangle::Rectangle(size_t L, size_t H, Coordonnee ptAncrage)
{
   setLargeur(L);
   setHauteur(H);
   setAncrage(ptAncrage);
}
