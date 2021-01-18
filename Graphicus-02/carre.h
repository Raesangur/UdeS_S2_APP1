// carre.h
#include "forme.h"
#include <cstddef>

classe Carre : public Rectangle
{
public:
    Carre(double cote = 1, Coordonnee ancrage = {0, 0});
    ~Carre();

    void setCote(double valCote)
    {
        cote = valCote;
    }
    double getCote() const
    {
        return cote;
    }

    double aire() const override
    {
        double aire = cote * cote;
    }

    void afficher(std::ostream & s) const override
    {
    	s << "Carre(";
        ancrage.afficher(s);
        s << "c=" << getCote() << ", aire=" << aire() << ")" << std::endl;
    }

private:
    double cote;
};
