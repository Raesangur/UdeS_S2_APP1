#include "EvaluationReussiEchec.h"

char EvaluationReussiEchec::getCote() const
{
   char cote;
   
   if (resultat >= resultatMinimum)
      cote = 'R';
   else 
      cote = 'E';
      
   return cote;
}