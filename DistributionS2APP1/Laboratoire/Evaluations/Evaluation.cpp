#include "Evaluation.h"

char Evaluation::getCote() const
{
   char cote;
   
   if (resultat > 89)
      cote = 'A';
   else if (resultat > 79)
      cote = 'B';
   else if (resultat > 69)
      cote = 'C';
   else if (resultat > 59)
      cote = 'D';
   else
      cote = 'F';
   
   return cote;
}

