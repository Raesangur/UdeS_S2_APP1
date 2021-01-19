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
    std::cout << "\n\nDébut de graphicus-02:\n" << std::endl;    // (oui deux retours de ligne)

    Tests tests;

    tests.tests_application_cas_02();
    return 0;
}
