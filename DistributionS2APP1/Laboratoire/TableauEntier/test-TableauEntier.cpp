#include <iostream>
#include "TableauEntier.h"

using namespace std;

int main()
{
   const int TAILLE = 20;
   TableauEntier nombres(TAILLE);
   int table[TAILLE];
   int val, x;
   val = 0;
   // Sauvegarde des 9 dans le tableau.
   // Affiche un asterisque si succes.
   for (x = 0; x < TAILLE ; x++)
   {
      nombres.setElement(x, 9);
      table[x] = val++;
      cout << "* ";
   }
   cout << endl;

   // Affichage des valeurs.
   for (x = 0; x < TAILLE; x++)
   {
      val = nombres.getElement(x);
      cout << val << " ";
      cout << table[x] << endl;
   }
   cout << endl;

   // Tentative hors du tableau.
   nombres.setElement(50, 9);
   
   return 0;
}
