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
    for(Couche& c : m_couches)
    {
        c = Couche();    // Assigne un objet bien réinitialisé
    }

    m_couches[0].SetEtat(Couche::Etat::Active);
}

Canevas::~Canevas()
{
}

bool Canevas::reinitialiser()
{
    m_index = 0;
    m_couches.clear();
    bool status = m_couches.push_back(Couche(), DEFAULT_COUCHES_NBR);
    return status;
}

bool Canevas::activerCouche(size_t index)
{
    if(index > m_couches.size())
    {
        return false;
    }
    if(m_couches[m_index].GetEtat() == Couche::Etat::Active)
    {
        m_couches[m_index].SetEtat(Couche::Etat::Inactive);
    }

    m_index = index;
    m_couches[m_index].SetEtat(Couche::Etat::Active);
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
        m_couches.push_back(couche);
        return true;
    }
    catch(const std::bad_alloc& ex)    // Operator new throw une std::bad_alloc en cas d'échec (ne
                                       // retourne pas nullptr);
    {
        std::cout << "Erreur d'allocation en rajoutant une nouvelle couche" << std::endl;
        return false;
    }
}
bool Canevas::enleverCouche(size_t index)
{
    if(nombreCouche() == 1)
    {
        // Il doit au minimum y avoir une couche!
        m_couches[0].Reinitialiser();
        return false;
    }

    if(index < nombreCouche())
    {
        m_couches.remove(index);
        if(m_index == nombreCouche())
        {
            m_index--;
        }
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

const Couche& Canevas::getCouche(size_t index) const
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
    return m_couches[m_index].RetirerForme(index) == nullptr ? false : true;
}

double Canevas::aire()
{
    double aireTotale = 0.0;
    for(const Couche& c : m_couches)
    {
        // On skip les couches cachées (dans la méthode Aire de la couche en tant que telle)
        aireTotale += c.Aire();
    }

    return aireTotale;
}

bool Canevas::translater(int deltaX, int deltaY)
{
    Couche& c = m_couches[m_index];

    // Il y a vérification de l'état actif dans translater
    return c.Translater(deltaX, deltaY);
}

void Canevas::afficher(std::ostream& s)
{
    for(size_t i = 0; i < m_couches.size(); i++)
    {
        s << "----- Couche " << i << std::endl;
        m_couches[i].afficher(s);
    }
}
