// carre.h
#include "forme.h"
#include <cstddef>

class Carre : public Rectangle
{
public:
    Carre();
    Carre(size_t cote, Coordonnee ancrage);
    ~Carre() = default;

    void setCote(size_t valCote)
    {
        cote = valCote;
    }
    size_t getCote() const
    {
        return cote;
    }

    double aire() const override
    {
        return cote * cote;
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
