//carre.cpp
#include <cstddef>
#include "forme.h"
#include "rectangle.h"
#include "carre.h"

Carre::Carre()
{
   setCote(1);
   setAncrage{0, 0};
}

Carre::Carre(size_t cote, Coordonnee ptAncrage)
{
   setCote(cote);
   setAncrage(ptAncrage);
}
