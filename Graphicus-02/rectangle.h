// rectangle.h
#include "forme.h"
#include <cstddef>

class Rectangle : public Forme
{
public:
    // creation rectangle : (L;H;ptAncrage) **Constructeur**
    // valeurs initiales  : L = 1    H = 1    Ancr = (0;0)
    Rectangle();
    Rectangle(size_t L, size_t H, Coordonnee ptAncrage);
    // Destructeur
    ~Rectangle() = default;
    // Methodes get set

    void setLargeur(size_t l)
    {
        largeur = l;
    }
    void setHauteur(size_t h)
    {
        hauteur = h;
    }
    size_t getLargeur() const
    {
        return largeur;
    }
    size_t getHauteur() const
    {
        return hauteur;
    }
    double aire() const override
    {
        return largeur * hauteur;
    }
    void afficher(std::ostream& s) const override
    {
        s << "Rectangle(";
        ancrage.afficher(s);
        s << "l=" << getLargeur() << ", h=" << getHauteur() << ", aire=" << aire() << ")" << std::endl;
    }
    // getAncrage(); et setAncrage(Coordonnee c); **Methodes heritees**

private:
    size_t largeur;
    size_t hauteur;
    // Coordonnee ancrage; en protected herite de la classe Forme
};

