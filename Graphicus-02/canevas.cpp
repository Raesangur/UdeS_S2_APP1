/********
 * Fichier: canevas.cpp
 * Auteurs: C.-A. Brunet
 * Date: 08 janvier 2018 (creation)
 * Description: Implementation des methodes des classes decrites dans
 *    canevas.h. Ce fichier fait partie de la distribution de Graphicus.
 ********/

#include "canevas.h"
#include <exception>

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

bool Canevas::activerCouche(size_t index)
{
    if(index > m_couches.size())
    {
        return false;
    }

    m_couches[m_index].SetEtat(Couche::Etat::Inactive);
    m_couches[m_index = index].SetEtat(Couche::Etat::Active);
    return true;
}

bool Canevas::cacherCouche(size_t index)
{
    if(index > m_couches.size())
    {
        return false;
    }
    m_couches[index].SetEtat(Couche::Etat::Cachee);
    return true;
}

bool Canevas::ajouterCouche(const Couche& couche)
{
    try
    {
        m_couches.push_back(Couche(couche));
        return true;
    }
    catch(std::bad_alloc ex)    // Operator new throw une std::bad_alloc en cas d'échec (ne retourne
                                // pas nullptr);
    {
        return false;
    }
}
bool Canevas::enleverCouche(size_t index)
{
    if(index < nombreCouche())
    {
        m_couches.remove(index);
        return true;
    }
    else
    {
        return false;
    }
}

size_t Canevas::nombreCouche() const
{
    return m_couches.size();
}

Couche& getCouche(size_t index) const
{
    // Retourne la couche en cours
    if(index == (size_t)-1)
    {
         return m_couches[m_index];
    }
    else
    {
        return m_couches[index];
    }
}

bool Canevas::ajouterForme(Forme* p_forme)
{
    return m_couches[m_index].AjouterForme(p_forme);
}

bool Canevas::retirerForme(size_t index)
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
    for(size_t i = 0; i < m_couches.size(); i++)
    {
        s << "----- Couche " << i << std::endl;
        m_couches[i].afficher(s);
    }
}
