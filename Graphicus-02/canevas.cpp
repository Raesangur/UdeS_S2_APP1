/********
 * Fichier: canevas.cpp
 * Auteurs: C.-A. Brunet
 * Date: 08 janvier 2018 (creation)
 * Description: Implementation des methodes des classes decrites dans
 *    canevas.h. Ce fichier fait partie de la distribution de Graphicus.
 ********/

#include "canevas.h"

Canevas::Canevas()
{
}

Canevas::~Canevas()
{
}

bool Canevas::reinitialiser()
{
    m_index = 0;
    m_couches.clear();
    return true;
}

bool Canevas::activerCouche(int index)
{
    if(index > m_couches.size())
    {
        return false;
    }

    m_couches[m_index].SetEtat(Couche::Etat::Inactive);
    m_couches[m_index = index].SetEtat(Couche::Etat::Active);
    return true;
}

bool Canevas::cacherCouche(int index)
{
    if(index > m_couches.size())
    {
        return false;
    }
    m_couches[index].SetEtat(Couche::Etat::Cachee);
    return true;
}

bool Canevas::ajouterForme(Forme* p_forme)
{
    return m_couches[m_index].AjouterForme(p_forme);
}

bool Canevas::retirerForme(int index)
{
    return m_couches[m_index].RetirerForme(index);
}

double Canevas::aire()
{
    double aireTotale;
    for(const Couche& c : m_couches)
    {
        if(c.GetEtat() != Couche::Etat::Cachee)
        {
        }
        else
        {
            aireTotale += c.Aire();
        }
    }

    return aireTotale;
}

bool Canevas::translater(int deltaX, int deltaY)
{
    Couche& c = m_couches[m_index];
    if(c.GetEtat() == Couche::Etat::Active)
    {
        return c.Translater(deltaX, deltaY);
    }
    return true;
}

void Canevas::afficher(std::ostream& s)
{
   for (const Couche& c : m_couches)
   {
       c.afficher(s);
       s << std::endl;
   }
}
