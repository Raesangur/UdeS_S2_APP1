/********
 * Fichier: canevas.h
 * Auteurs: C.-A. Brunet
 * Date: 08 janvier 2018 (creation)
 * Description: Declaration de la classe Canevas. La classe gere un
 *    tableau de couches en accord avec les specifications de Graphicus.
 *    Ce fichier fait partie de la distribution de Graphicus.
 ********/

#ifndef DESSIN_H
#define DESSIN_H
#include "couche.h"
#include "forme.h"
#include "vector.h"
#include <iostream>

class Canevas
{
public:
    Canevas();
    ~Canevas();

    bool reinitialiser();

    bool   activerCouche(size_t index);
    bool   cacherCouche(size_t index);
    bool   ajouterCouche(Couche* couche);
    bool   enleverCouche(size_t index);
    size_t nombreCouche() const;

    bool ajouterForme(Forme* p_forme);
    bool retirerForme(size_t index);

    double aire();
    bool   translater(int deltaX, int deltaY);
    void   afficher(std::ostream& s);

private:
    vector<Couche> m_couches{5};
    size_t         m_index = 0;
};

#endif
