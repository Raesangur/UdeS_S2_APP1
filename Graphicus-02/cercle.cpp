#include "cercle.h"

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
