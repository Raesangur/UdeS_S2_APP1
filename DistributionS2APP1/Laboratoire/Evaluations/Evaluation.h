#ifndef EVALUATION_H
#define EVALUATION_H

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
};
#endif
