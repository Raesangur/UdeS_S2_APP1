#include <iostream>
#include <iomanip>

#include "EvaluationChoixMultiples.h"

using namespace std; 

void afficher(const Evaluation *);

int main()
{
   const int NUM_TESTS = 4;

   Evaluation *tests[NUM_TESTS] =
   {
      new Evaluation(88.0),
      new EvaluationChoixMultiples(100, 25, 70.0),
      new Evaluation(67.0),
      new EvaluationChoixMultiples(50, 12, 60.0)
   };

   /* Version equivalente en deux etapes
   Evaluation *tests[NUM_TESTS] ;
   tests[0] = new Evaluation(88.0);
   tests[1] = new EvaluationSommative(100, 25, 70.0);
   tests[2] = new Evaluation(67.0);
   tests[3] = new EvaluationSommative(50, 12, 60.0);
   */

   for (int count = 0; count < NUM_TESTS; count++)
   {
      cout << "Test #" << (count + 1) << ":\n";
      afficher(tests[count]);
      cout << endl;
   }
   return 0;
}

void afficher(const Evaluation * evaluation)
{
   cout << setprecision(1) << fixed;
   cout << "Le score numerique est " << evaluation->getResultat() << "." << endl;
   cout << "La cote est  " << evaluation->getCote() << "." << endl;
}
