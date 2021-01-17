//rectangle.h
#include <cstddef>
#include "forme.h"

class Rectangle: public Forme 
{
   public:
     //creation rectangle : (L;H;ptAncrage) **Constructeur**
     //valeurs initiales  : L = 1    H = 1    Ancr = (0;0)
     Rectangle();
     Rectangle(size_t L, size_t H, Coordonnee ptAncrage);
     //Destructeur
     ~Rectangle();
     //Methodes get set
     void setLargeur(size_t l){
	largeur = l;
     }
     void setHauteur(size_t h){
	hauteur = h;
     }
     size_t getLargeur() {
	return largeur;
     }
     size_t getHauteur() {
	return hauteur;
     }
     virtual size_t aire() const {
	return largeur * hauteur;
     }
     void afficher(std::ostream& s) const override{
	s << "Rectangle:\tlargeur = " << getLargeur() << "\tPoint d'ancrage = {";
	ancrage.afficher(s);
	s << "}" << std::endl;
     }
     //getAncrage(); et setAncrage(Coordonnee c); **Methodes heritees**

   private:
     size_t largeur;
     size_t hauteur;
     //Coordonnee ancrage; en protected herite de la classe Forme
};
