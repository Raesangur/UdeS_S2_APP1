/********
 * Fichier: tests.cpp
 * Auteurs: C.-A. Brunet
 * Date: 08 janvier 2018 (creation)
 * Description: Implementation des methodes des classes decrites dans
 *    tests.h.  Ce fichier peut etre adapte a vos besoins de tests.
 *    Ce fichier fait partie de la distribution de Graphicus.
 ********/

#include <iostream>

#include "carre.h"
#include "cercle.h"
#include "rectangle.h"
#include "tests.h"



void Tests::tests_unitaires_formes()
{
    // Tests sur les formes geometriques
    Cercle cer(3);
    Rectangle rec(cer.getRayon(), 9, {1, 1});
    Carre car(3, {0, 4});

    car.afficher(std::cout);
    rec.afficher(std::cout);
    cer.afficher(std::cout);

    std::cout << "----\n";

    Forme* pcer = new Cercle(cer);
    Forme* prec = new Rectangle(rec);
    Forme* pcar = new Carre(car);

    pcer->afficher(std::cout);
    prec->afficher(std::cout);
    pcar->afficher(std::cout);

    std::cout << "----\n";

    dynamic_cast<Cercle*>(pcer)->setRayon(5);
    pcer->afficher(std::cout);

    delete pcer;
    delete prec;
    delete pcar;
}

void Tests::tests_unitaires_vecteur()
{
    // Tests sur la classe Vecteur
}

void Tests::tests_unitaires_couche()
{
    // Tests sur la classe Couche
}

void Tests::tests_unitaires_canevas()
{
    // Tests sur la classe Canevas
}

void Tests::tests_unitaires()
{
    // Fait tous les tests unitaires
    tests_unitaires_formes();
    tests_unitaires_vecteur();
    tests_unitaires_couche();
    tests_unitaires_canevas();
}

void Tests::tests_application()
{
    // Fait tous les tests applicatifs
    tests_application_cas_01();
    tests_application_cas_02();
}

void Tests::tests_application_cas_01()
{
    std::cout << "TESTS APPLICATION (CAS 01)" << std::endl;
    // Il faut ajouter les operations realisant ce scenario de test.
}

void Tests::tests_application_cas_02()
{
    std::cout << "TESTS APPLICATION (CAS 02)" << std::endl;
    // Il faut ajouter les operations realisant ce scenario de test.
}
