/********
 * Fichier: couche.cpp
 * Auteurs: C.-A. Brunet
 * Date: 08 janvier 2018 (creation)
 * Description: Implementation des methodes des classes decrites dans
 *    couche.h. Ce fichier fait partie de la distribution de Graphicus.
 ********/

#include "couche.h"


// Copy assignment operator
Couche& Couche::operator=(const Couche& other)
{
    m_etat   = other.m_etat;
    m_formes = other.m_formes;

    return *this;
}

bool Couche::AjouterForme(Forme* pforme)
{
    if(m_etat == Etat::Active)
    {
        try
        {
            m_formes.push_back(pforme);
            return true;
        }
        catch(std::bad_alloc& ex)
        {
            std::cout << "erreur lors de l'ajout d'une forme à la couche" << std::endl;
            return false;
        }
    }
    else
    {
        return false;
    }
}

Forme* Couche::RetirerForme(size_t index)
{
    if(m_etat == Etat::Active)
    {
        return m_formes.remove(index);
    }
    else
    {
        return nullptr;
    }
}
Forme* Couche::GetForme(size_t index) const
{
    // Le vecteur retourne nullptr pour un index invalide; pas besoin de vérifier ici
    return m_formes[index];
}

size_t Couche::NombreForme() const
{
    return m_formes.size();
}

double Couche::Aire() const
{
    if(m_etat == Etat::Cachee || m_etat == Etat::Init)
    {
        return 0.0;
    }
    else
    {
        double total = 0.0;
        for(const Forme* f : m_formes)
        {
            total += f->aire();
        }
        return total;
    }
}

bool Couche::Translater(int x, int y)
{
    if(m_etat != Etat::Active)
    {
        return false;
    }

    if(m_formes.empty() == true)
    {
        return false;
    }
    for(Forme* f : m_formes)
    {
        f->translater(x, y);
    }
    return true;
}

bool Couche::Reinitialiser()
{
    m_etat = Etat::Init;
    if(m_formes.empty() == true)
    {
        return false;
    }
    else
    {
        m_formes.clear();
        return true;
    }
}

void Couche::SetEtat(Etat nouvelEtat)
{
    if(nouvelEtat != Etat::Init)
    {
        m_etat = nouvelEtat;
    }
}
Couche::Etat Couche::GetEtat() const
{
    return m_etat;
}

void Couche::afficher(std::ostream& s) const
{
    if(m_etat == Etat::Init)
    {
        s << "Couche initialisee" << std::endl;
        return;
    }
    if(m_etat == Etat::Cachee)
    {
        s << "Couche cachee" << std::endl;
        return;
    }
    if(m_formes.size() == 0)
    {
        s << "Couche vide" << std::endl;
        return;
    }

    // Opérateur de left-shift overload pour le vecteur pour faire l'affichage.
    s << m_formes;
}
