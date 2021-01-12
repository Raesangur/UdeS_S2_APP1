#ifndef TABLEAUENTIER_H
#define TABLEAUENTIER_H

class TableauEntier
{
private:
   int *tableau;               // Pointeur au tableau
   int numElements;            // Nombre d'elements dans le tableau
   bool estValide(int) const;  // Valide un index
public:
   TableauEntier(int);         // Constructeur
   ~TableauEntier();           // Destructeur
   void setElement(int, int);  // Fixe la valeur d'un element
   int getElement(int) const;  // Donne la valeur d'un element
};
#endif
