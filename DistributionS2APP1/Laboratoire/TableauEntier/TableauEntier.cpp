#include <iostream>
#include <cstdlib>

#include "TableauEntier.h"
using namespace std;

//***********************************************************
// Le constructeur alloue le tableau dynamiquement et       *
// initialise chaque valeur à zéro.                         *
//***********************************************************

TableauEntier::TableauEntier(int taille)
{ 
   tableau = new int[taille];
   numElements = taille;
   for (int i = 0; i < taille; i++)
      tableau[i] = 0;
}

//***********************************************************
// Le destructeur désalloue la mémoire.                     *
//***********************************************************

TableauEntier::~TableauEntier()
{ 
   delete [] tableau;
}

//***********************************************************
// Cette methode retourne vrai si son argument refere a un  *
// element valide. Sinon, elle retourne faux.               *
//***********************************************************

bool TableauEntier::estValide(int index) const
{
   bool statut;

   if (index < 0 || index >= numElements)
      statut = false;
   else
      statut = true;

   return statut;
}

//***********************************************************
// Sauvegarde la valeur dans un element valide du tableau.  *
// Si l'index est invalide, le tableau n'est pas modifie.   *
//***********************************************************

void TableauEntier::setElement(int index, int valeur)
{
   if (estValide(index))
      tableau[index] = valeur;
   else
      cout << "Erreur: index invalide" << endl;
}

//***********************************************************
// Retourne la valeur d'un element valide du tableau.       *
// Si l'index est invalide, la valeur -1 est retournee.     *
//***********************************************************

int TableauEntier::getElement(int index) const
{
   if (estValide(index))
      return tableau[index];
   else
   {
      cout << "Erreur: index invalide" << endl;
      return -1;
   }
}
