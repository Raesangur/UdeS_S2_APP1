// carre.cpp
#include "carre.h"
#include "forme.h"
#include "rectangle.h"
#include <cstddef>

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
