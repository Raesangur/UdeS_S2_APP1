/********
 * Fichier: tests.cpp
 * Auteurs: C.-A. Brunet
 * Date: 08 janvier 2018 (creation)
 * Description: Implementation des methodes des classes decrites dans
 *    tests.h.  Ce fichier peut etre adapte a vos besoins de tests.
 *    Ce fichier fait partie de la distribution de Graphicus.
 ********/

#include <iostream>

#include "canevas.h"
#include "carre.h"
#include "cercle.h"
#include "couche.h"
#include "rectangle.h"
#include "tests.h"

static const char* PrintResult(bool val)
{
    return val ? "Succès" : "Échec";
}


void Tests::tests_unitaires_formes()
{
    // Tests sur les formes geometriques
    std::cout << "\tTests unitaires sur les formes\n" << std::endl;
    Cercle    cer(3);
    Rectangle rec(cer.getRayon(), 9, {1, 1});
    Carre     car(3, {0, 4});

    std::cout << "Affichage des formes instanciees:\n----" << std::endl;
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
    std::cout << "\n\tTests unitaires sur les vecteurs\n" << std::endl;
    vector<Forme*, VEC_DO_NOT_DELETE_ELEMENTS> v1;
    std::cout << "Test 1:\nCreation d'un vecteur vide\nAjout d'un cercle (r=6)\n" << std::endl;
    Forme* c1 = new Cercle();
    dynamic_cast<Cercle*>(c1)->setRayon(6);
    std::cout << "Affichage:" << std::endl;
    v1.push_back(c1);
    std::cout << v1;

    std::cout << "\nTest 2:\nAjout d'autres formes :\nrectangle(L=5, H=4, ancr={3;9}) carre(L=10, "
                 "ancr={3,9})) cercle(r=4, ancr={0;0})"
              << std::endl;
    Forme* rec1 = new Rectangle(5, 4, {3, 9});
    Forme* car1 = new Carre(10, {2, 19});
    Forme* cer2 = new Cercle(4);
    v1.push_back(rec1);
    v1.push_back(car1);
    v1.push_back(cer2);
    std::cout << "\nAffichage:" << std::endl;
    std::cout << v1;

    std::cout << "\nTest 3:\nRetirer le dernier element du vecteur" << std::endl;
    v1.pop_back();
    std::cout << "\nAffichage:" << std::endl;
    std::cout << v1;

    std::cout << "\nTest 4:\nRetirer le 2e element du vecteur" << std::endl;
    v1.remove(1);
    std::cout << "\nAffichage:" << std::endl;
    std::cout << v1;

    std::cout << "\nTest 5:\nConstruire une copie de ce vecteur" << std::endl;
    vector<Forme*> v2(v1);
    std::cout << v2;

    std::cout << "\nTest 6:\nVider le vecteur" << std::endl;
    v1.clear();
    std::cout << "\nAffichage:\n" << std::endl;
    std::cout << v1;
    std::cout << "Le vecteur est vide!" << std::endl;

    std::cout << "\nTest 7:\nReserver une taille plus grande et constructeur avec 5 cercles"
              << std::endl;
    vector<Forme*> v3(5, cer2);
    v3.reserve(10);
    std::cout << "\nLa nouvelle capacite est de " << v3.capacity() << "!\nAffichage:" << std::endl;
    std::cout << v3;

    std::cout << "\nTest 8:\nVoir la capacite si on ajoute une forme au vecteur ayant 5 formes sur "
                 "une capacite de 10"
              << std::endl;
    v3.push_back(rec1);
    std::cout << "\nLa capacite est de " << v3.capacity() << "!\nAffichage:" << std::endl;
    std::cout << v3;

    std::cout << "\nTest 9:\nUtilisation de la methode pop_back et retour a la bonne capacite"
              << std::endl;
    v3.pop_back();
    v3.shrink_to_fit();
    std::cout << "\nLa capacite est de " << v3.capacity() << "\tLa taille est de" << v3.size()
              << "!\nAffichage:" << std::endl;
    std::cout << v3;
}

void Tests::tests_unitaires_couche()
{
    std::cout << "\n\n\tTests sur couche:\n----------------------" << std::endl;
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
    std::cout << "\n\n\tTests sur canevas:\n----------------------" << std::endl;
    Canevas c1;
    std::cout << "Canevas de " << c1.nombreCouche() << " couches" << std::endl;

    c1.activerCouche(0);
    c1.ajouterForme(new Rectangle(1, 1, {2, 3}));
    c1.ajouterForme(new Carre(3));
    c1.ajouterForme(new Cercle(6, {7, 8}));
    std::cout << "Première couche:" << std::endl;
    c1.getCouche().afficher(std::cout);


    c1.cacherCouche(1);

    c1.activerCouche(2);
    c1.ajouterForme(new Rectangle(3, 4, {5, 6}));
    c1.ajouterForme(new Carre(1, {3, 4}));
    c1.ajouterForme(new Cercle(3));

    c1.ajouterCouche(c1.getCouche(1));
    std::cout << "Canevas de " << c1.nombreCouche() << " couches" << std::endl;
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
    std::cout << "\nTESTS APPLICATION (CAS 01)" << std::endl;
    // Il faut ajouter les operations realisant ce scenario de test.
    Canevas c;

    std::cout << "\n-------------------------\n1. Activer la couche 1." << std::endl;
    bool resultat = c.activerCouche(1);
    std::cout << "Résultat: " << PrintResult(resultat) << std::endl;

    std::cout << "\n-------------------------\n2. Ajouter trois formes géométriques (un rectangle, "
                 "un carré et un cercle) "
                 "avec des points d’ancrages différents."
              << std::endl;
    std::cout << "Ajout du rectangle (l = 4, h = 3.14, Coords: {10, 8}):\n";
    resultat = c.ajouterForme(new Rectangle(4, 3.14, {10, 8}));
    std::cout << "Résultat: " << PrintResult(resultat) << std::endl;
    std::cout << "Ajout du carré (c = 5, Coords: {-5, 4}):\n";
    resultat = c.ajouterForme(new Carre(5, {-5, 4}));
    std::cout << "Résultat: " << PrintResult(resultat) << std::endl;
    std::cout << "Ajout du cercle (r = 0.7978845, Coords: {12, 3}):\t // 0.7978845 = √(2/π)\n";
    Cercle* pcer = new Cercle(0.7978845, {12, 3});
    resultat     = c.ajouterForme(pcer);
    std::cout << "Résultat: " << PrintResult(resultat) << std::endl;
    std::cout << "Aire du cercle: " << pcer->aire() << std::endl;
    std::cout << "\n-------------------------\n3. Activer la couche 2." << std::endl;
    resultat = c.activerCouche(2);
    std::cout << "Résultat: " << PrintResult(resultat);

    std::cout << "\n-------------------------\n4. Ajouter une forme géométriques." << std::endl;
    std::cout << "Copie du rectangle de la couche 1:\n";
    resultat = c.ajouterForme(new Rectangle(c.getCouche(1).GetForme(0)));
    std::cout << "Résultat: " << PrintResult(resultat);

    std::cout << "\n-------------------------\n5. Afficher le canevas" << std::endl;
    c.afficher(std::cout);

    std::cout << "\n-------------------------\n6. Afficher l'aire du canevas." << std::endl;
    std::cout << "Aire: " << c.aire() << std::endl;

    std::cout << "\n-------------------------\n7. Activer la couche 0." << std::endl;
    resultat = c.activerCouche(0);
    std::cout << "Résultat: " << PrintResult(resultat) << std::endl;

    std::cout << "\n-------------------------\n8. Ajouter trois formes géométriques différentes."
              << std::endl;
    std::cout << "Ajout d'un cercle (r = 2, Coords: {10, 8}):\n";
    resultat = c.ajouterForme(new Cercle(2, {10, 8}));
    std::cout << "Résultat: " << PrintResult(resultat) << std::endl;
    std::cout << "Ajout d'un rectangle (l = 40, h = 0.01, Coords: {0, 1}):\n";
    resultat = c.ajouterForme(new Rectangle(40, 0.01, {0, 1}));
    std::cout << "Résultat: " << PrintResult(resultat) << std::endl;
    std::cout << "Ajout d'un autre rectangle (l = 4, h = 3, Coords: {100, -5}):\n";
    resultat = c.ajouterForme(new Rectangle(4, 3, {100, -5}));
    std::cout << "Résultat: " << PrintResult(resultat) << std::endl;

    std::cout << "\n-------------------------\n9. Cacher la couche 2." << std::endl;
    resultat = c.cacherCouche(2);
    std::cout << "Résultat: " << PrintResult(resultat) << std::endl;

    std::cout << "\n-------------------------\n10. Activer la couche 1." << std::endl;
    resultat = c.activerCouche(1);
    std::cout << "Résultat: " << PrintResult(resultat) << std::endl;

    std::cout << "\n-------------------------\n11. Translater la couche (12x + 4y)." << std::endl;
    resultat = c.translater(12, 4);
    std::cout << "Résultat: " << PrintResult(resultat) << std::endl;

    std::cout << "\n-------------------------\n12. Afficher le canevas" << std::endl;
    c.afficher(std::cout);

    std::cout << "\n-------------------------\n13. Afficher l'aire du canevas." << std::endl;
    std::cout << "Aire: " << c.aire() << std::endl;

    std::cout << "\n-------------------------\n14. Retirer la première forme de la couche."
              << std::endl;
    resultat = c.retirerForme(0);
    std::cout << "Résultat: " << PrintResult(resultat) << std::endl;

    std::cout << "\n-------------------------\n15. Afficher le canevas" << std::endl;
    c.afficher(std::cout);

    std::cout << "\n-------------------------\n16. Afficher l'aire du canevas." << std::endl;
    std::cout << "Aire: " << c.aire() << std::endl;

    std::cout << "\n-------------------------\n17. Réinitialiser le canevas." << std::endl;
    resultat = c.reinitialiser();
    std::cout << "Résultat: " << PrintResult(resultat) << std::endl;

    std::cout << "\n-------------------------\n18. Afficher le canevas" << std::endl;
    c.afficher(std::cout);

    std::cout << "\n-------------------------\n19. Afficher l'aire du canevas." << std::endl;
    std::cout << "Aire: " << c.aire() << std::endl;

    std::cout << "Fin du test d'application pour la validation!" << std::endl;
}

void Tests::tests_application_cas_02()
{
    std::cout << "TESTS APPLICATION (CAS 02)" << std::endl;

    Canevas c1;
    std::cout << "Canevas de " << c1.nombreCouche() << " couches" << std::endl;

    c1.activerCouche(0);
    c1.ajouterForme(new Rectangle(1, 2.5, {2, 3}));
    c1.ajouterForme(new Carre(9));
    c1.ajouterForme(new Cercle(3.1415, {7, -6}));
    std::cout << "Première couche:" << std::endl;
    c1.getCouche().afficher(std::cout);


    c1.cacherCouche(1);

    c1.activerCouche(2);
    c1.ajouterForme(new Rectangle(3.1415, 4, {5, 7}));
    c1.ajouterForme(new Carre(9.4, {-3, 2}));
    c1.ajouterForme(new Cercle(65535));

    c1.ajouterCouche(c1.getCouche(1));
    std::cout << "Canevas de " << c1.nombreCouche() << " couches" << std::endl;
}
