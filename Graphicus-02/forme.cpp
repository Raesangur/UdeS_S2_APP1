/********
 * Fichier: forme.cpp
 * Auteurs: C.-A. Brunet
 * Date: 08 janvier 2018 (creation)
 * Description: Implementation des methodes des classes decrites dans
 *    forme.h. Les methodes de la classe Forme ne doivent pas etre
 *    modifiees. Ce fichier fait partie de la distribution de Graphicus.
 ********/

#include "forme.h"

int conteurForme = 0;

Forme::Forme()
{
    conteurForme++;
}

Forme::Forme(int x1, int y1)
{
    ancrage.x = x1;
    ancrage.y = y1;
    conteurForme++;
}

Forme::~Forme()
{
    conteurForme--;
}

void Forme::translater(int deltaX, int deltaY)
{
    ancrage.x += deltaX;
    ancrage.y += deltaY;
}

Coordonnee Forme::getAncrage()
{
    return ancrage;
}

void Forme::setAncrage(Coordonnee c)
{
    ancrage = c;
}
