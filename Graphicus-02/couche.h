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

    bool   AjouterForme(Forme* pforme);
    Forme* RetirerForme(size_t index);
    Forme* GetForme(size_t index) const;

    double Aire() const;
    bool   Translater(int x, int y);
    bool   Reinitialiser();

    void SetEtat(Etat nouvelEtat);
    Etat GetEtat() const;

    void afficher(std::ostream& s) const;
};

#endif
