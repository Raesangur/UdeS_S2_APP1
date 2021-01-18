// carre.h
#include "forme.h"
#include <cstddef>

classe Carre : public Rectangle
{
public:
    Carre();
    Carre(size_t cote, Coordonnee ancrage);
    ~Carre();

    void setCote(size_t valCote)
    {
        cote = valCote;
    }
    size_t getCote() const
    {
        return cote;
    }

    size_t aire() const override
    {
        size_t aire = cote * cote;
    }

    void afficher(std::ostream & s) const override
    {
    	s << "Carre(";
        ancrage.afficher(s);
        s << "c=" << getCote() << ", aire=" << aire() << ")" << std::endl;
    }

private:
    size_t cote;
};
