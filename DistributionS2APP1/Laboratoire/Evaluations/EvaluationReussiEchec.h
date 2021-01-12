#ifndef EVALUATIONREUSSIECHEC_H
#define EVALUATIONREUSSIECHEC_H

#include "Evaluation.h"

// Evaluation Reussi ou Echec (EvaluationRE)
class EvaluationReussiEchec : public Evaluation
{
protected:
   double resultatMinimum;
public:
   EvaluationReussiEchec() // Constructeur par defaut
      { resultatMinimum = 0.0; }
   
   EvaluationReussiEchec(double res)
      { resultatMinimum = res; }

   void setResultatMinimum(double res)
      { resultatMinimum = res; }

   double getResultatMinimum() const
      { return resultatMinimum; }
   
   virtual char getCote() const;
};
#endif
