#include "cercle.h"

Cercle::Cercle(double ray, Coordonnee a) : Forme{a.x, a.y}, m_rayon{ray}
{
}
Cercle::Cercle(const Forme* f) : Forme(f->getAncrage().x, f->getAncrage().y)
{
    try
    {
        const Cercle& c = *dynamic_cast<const Cercle*>(f);
        setRayon(c.getRayon());
    }
    catch(const std::bad_cast& ex)
    {
        setRayon(1);
        return;
    }
}

double Cercle::getRayon() const
{
    return m_rayon;
}
void Cercle::setRayon(double ray)
{
    m_rayon = ray;
}

double Cercle::aire() const
{
    return 3.14159265358979323846264 * getRayon() * getRayon();
}
void Cercle::afficher(std::ostream& s) const
{
    s << "Cercle(";
    ancrage.afficher(s);
    s << "r=" << getRayon() << ", aire=" << aire() << ")" << std::endl;
}
