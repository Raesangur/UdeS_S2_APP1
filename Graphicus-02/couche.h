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
    Etat           m_etat;

public:
    Couche()  = default;
    ~Couche() = default;

    bool AjouterForme(Forme* pforme)
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

    Forme* RetirerForme(size_t index)
    {
        return m_formes.remove(index);
    }
    Forme* GetForme(size_t index) const
    {
        return m_formes[index];
    }

    double Aire() const
    {
        double total = 0.0;
        for(const Forme* f : m_formes)
        {
            total += f->aire();
        }
        return total;
    }

    bool Translater(int x, int y)
    {
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
        m_etat = nouvelEtat;
    }
    Etat GetEtat()
    {
        return m_etat;
    }


    void afficher(std::ostream& s) const
    {
        m_formes.afficher(s);
    }
};

#endif
