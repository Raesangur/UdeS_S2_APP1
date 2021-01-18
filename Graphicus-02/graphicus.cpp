/********
 * Fichier: graphicus-01.cpp
 * Auteurs: C.-A. Brunet
 * Date: 08 janvier 2018 (creation)
 * Description: gestionnaire de tests pour l'application Graphicus. Ce
 *    fichier fait partie de la distribution de Graphicus.
 ********/
#include "tests.h"
#include "vector.h"

int main()
{
    int          ptrr = 2;
    vector<int>  a(3, 0);
    vector<int*> b(1, &ptrr);

    Tests tests;

    tests.tests_application();
    return 0;
}
