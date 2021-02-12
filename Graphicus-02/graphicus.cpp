/********
 * Fichier: graphicus-01.cpp
 * Auteurs: C.-A. Brunet
 * Date: 08 janvier 2018 (creation)
 * Description: gestionnaire de tests pour l'application Graphicus. Ce
 *    fichier fait partie de la distribution de Graphicus.
 ********/

// APP1
// Par:
// Lachance Pascal-Emmanuel
// Rivard Olivier

#include "tests.h"
#include "vector.h"

int main()
{
    std::cout << "\n\nDébut de graphicus-02:\n" << std::endl;    // (oui deux retours de ligne)

    Tests tests;

    tests.tests_application();
    return 0;
}
