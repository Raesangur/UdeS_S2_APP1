#include "EvaluationChoixMultiples.h"

EvaluationChoixMultiples::EvaluationChoixMultiples()
{
   numQuestions = 0;
   pointsParQuestion = 0.0;
   numQuestionsRatees = 0;
}

EvaluationChoixMultiples::EvaluationChoixMultiples(int numQ, int numR , double min) : EvaluationReussiEchec(min)
{
   set(numQ, numR);
}

void EvaluationChoixMultiples::set(int numQ, int numR)
{ 
   double res;

   numQuestions = numQ;
   numQuestionsRatees = numR;

   pointsParQuestion = 100.0 / numQuestions;

   res = 100.0 - ( getNumQuestionsRatees() * getPointsParQuestion());

   setResultat(res);
}