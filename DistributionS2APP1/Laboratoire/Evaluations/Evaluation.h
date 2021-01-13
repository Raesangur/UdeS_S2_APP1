#ifndef EVALUATION_H
#define EVALUATION_H
#include <iostream>
#include <iomanip>

class Evaluation
{
protected:
   double resultat; 
public:
   Evaluation() // Constucteur par defaut
      { resultat = 0.0; }

   Evaluation(double res)
      { resultat = res; }

   void setResultat(double res) 
      { resultat = res; }
   
   double getResultat() const
      { return resultat; }
   
   virtual char getCote() const;

  void afficher()
  {
     std::cout << std::setprecision(1) << std::fixed;
     std::cout << getResultat() << " | " << getCote() << std::endl;
  }
};
#endif
