#ifndef EVALUATIONCHOIXMULTIPLES_H
#define EVALUATIONCHOIXMULTIPLES_H

#include "EvaluationReussiEchec.h"

class EvaluationChoixMultiples : public EvaluationReussiEchec
{
private:
   int numQuestions;
   double pointsParQuestion;
   int numQuestionsRatees;
public:
   // Constructeur par defaut
   EvaluationChoixMultiples();

   EvaluationChoixMultiples(int, int, double);

   void set(int, int);

   double getNumQuestions() const
      { return numQuestions; }
      
   double getPointsParQuestion() const
      { return pointsParQuestion; }
   
   int getNumQuestionsRatees() const
      { return numQuestionsRatees; }
};
#endif