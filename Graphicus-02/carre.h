//carre.h
#include <cstddef>
#include "forme.h"

classe Carre:public Rectangle
{
   public:
	Carre();
	Carre(size_t cote, Coordonnee ancrage);
	~Carre();
	void setCote(size_t valCote){
		cote = valCote;
	}
	size_t getCote() const{
		return cote;
	}
	size_t aire() const{
		size_t aire = cote * cote;
	}
	void afficher(std::ostream& s) const override{
		s << "Carre:\tlargeur = " << getCote() << "\tPoint d'ancrage = {";
		ancrage.afficher(s);
		s << "}" << std::endl;
	}
   private:
	size_t cote;
};
