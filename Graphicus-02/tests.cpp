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
#include "couche.h"
#include "canevas.h"



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
    std::cout << "\n\nTests sur couche:\n----------------------" << std::endl; 
    // Tests sur la classe Couche
    Couche c1;
    c1.SetEtat(Couche::Etat::Active);
    c1.AjouterForme(new Rectangle(10, 10));
    c1.AjouterForme(new Cercle(4, {0, 1}));
    c1.AjouterForme(new Rectangle);
    c1.AjouterForme(new Carre(5));
    c1.AjouterForme(c1.RetirerForme(0));
    c1.AjouterForme(new Cercle(*dynamic_cast<Cercle*>(c1.GetForme(0))));
    dynamic_cast<Cercle*>(c1.GetForme(c1.NombreForme() - 1))->setRayon(2);
    std::cout << "Aire: " << c1.Aire() << ", pour " << c1.NombreForme() << " elements" << std::endl;
    c1.afficher(std::cout);

    std::cout << "\nTranslation de 5x - 2y:" << std::endl;
    c1.Translater(5, -2);
    c1.afficher(std::cout);

    std::cout << "\nCacher la couche:" << std::endl;
    c1.SetEtat(Couche::Etat::Cachee);
    c1.afficher(std::cout);

    std::cout << "\nReset de la couche:" << std::endl;
    c1.Reinitialiser();
    c1.afficher(std::cout);
}

void Tests::tests_unitaires_canevas()
{
    // Tests sur la classe Canevas
    std::cout << "\n\nTests sur canevas:\n----------------------" << std::endl;
    Canevas c1;
    std::cout << "Canevas de " << c1.nombreCouche() << " couches" << std::endl;

    c1.activerCouche(0);
    c1.ajouterForme(new Rectangle(1, 1, {2, 3});
    c1.ajouterForme(new Carre(3));
    c1.ajouterForme(new Cercle(r, {7, 8});

    c1.cacherCouche(1);

    c1.activerCouche(2);
    c1.ajouterForme(new Rectangle(3, 4, {5, 6});
    c1.ajouterForme(new Carre(1, {3, 4});
    c1.ajouterForme(new Cercle(3));

    c1.ajouterCouche(c1.getCouche(1));
    c1.
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
