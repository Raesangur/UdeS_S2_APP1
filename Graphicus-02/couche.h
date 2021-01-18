/********
 * Fichier: couche.h
 * Auteurs: Pascal-Emmanuel Lachance
 * Date: 2021-01-15
 * Description: Declaration de la classe pour une couche dans un
 *    canevas. La classe Couche gere un vecteur de pointeur de formes
 *    geometriques en accord avec les specifications de Graphicus.
 *    Ce fichier fait partie de la distribution de Graphicus.
 ********/

#ifndef COUCHE_H
#define COUCHE_H
#include "cercle.h"
#include "forme.h"
#include "vector.h"

class Couche
{
public:
    enum Etat
    {
        Init,
        Active,
        Inactive,
        Cachee
    };

private:
    vector<Forme*> m_formes;
    Etat           m_etat = Etat::Init;

public:
    Couche()  = default;
    ~Couche() = default;

    bool AjouterForme(Forme* pforme)
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
                return false;
            }
        }
        else
        {
            return false;
        }
    }

    Forme* RetirerForme(size_t index)
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
    Forme* GetForme(size_t index) const
    {
        return m_formes[index];
    }

    double Aire() const
    {
        if(m_etat == Etat::Cachee)
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

    bool Translater(int x, int y)
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

    bool Reinitialiser()
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

    void SetEtat(Etat nouvelEtat)
    {
        if(m_etat != Etat::Init)
        {
            m_etat = nouvelEtat;
        }
    }
    Etat GetEtat() const
    {
        return m_etat;
    }


    void afficher(std::ostream& s) const
    {
        m_formes.afficher(s);
    }
};

#endif
