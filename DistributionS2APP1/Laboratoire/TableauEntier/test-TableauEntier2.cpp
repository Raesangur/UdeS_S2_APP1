#include <iostream>
#include "TableauEntier.h"

using namespace std;

int main()
{
   const int TAILLE = 20;
   TableauEntier nombres(TAILLE);
   int table[TAILLE];                         // Ligne ajoutee
   int val, x;

   val = 0;                                   // Ligne ajoutee
   // Sauvegarde des 9 dans le tableau.
   // Affiche un asterisque si succes.
   for (x = 0; x < TAILLE ; x++)
   {
      nombres.setElement(x, 9);
      table[x] = val++;                       // Ligne ajoutee
      cout << "* ";
   }
   cout << endl;

   // Affichage des valeurs.
   for (x = 0; x < TAILLE; x++)
   {
      val = nombres.getElement(x);
      cout << val << " ";
			cout << table[x] << endl;            // Ligne ajoutee
   }
   cout << endl;

   // Tentative hors du tableau.
   nombres.setElement(50, 9);
   
   return 0;
}
