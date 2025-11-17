#include "point.h"
#include "vector.h"
#include <iostream>

int main() {

    // Test du constructeur par défaut et du compteur pour point 
    std::cout << "--- Test du constructeur par defaut ---" << std::endl;
    Point p1;
    p1.afficher();
    std::cout << "Nombre d'instances : " << Point::getCompteurInstances() << std::endl;

    std::cout << "\n--- Test du constructeur utilitaire ---" << std::endl;
    Point p2(1.0, 2.0, 3.0);
    p2.afficher();
    std::cout << "Nombre d'instances : " << Point::getCompteurInstances() << std::endl;

    std::cout << "\n--- Test du constructeur de recopie ---" << std::endl;
    Point p3 = p2;
    p3.afficher();
    std::cout << "Nombre d'instances : " << Point::getCompteurInstances() << std::endl;

    std::cout << "\n--- Test des setters et getters ---" << std::endl;
    p1.setX(10.0);
    p1.setY(20.0);
    p1.setZ(30.0);
    std::cout << "Nouvelles coordonnées de p1 : (" << p1.getX() << ", " << p1.getY() << ", " << p1.getZ() << ")" << std::endl;

    std::cout << "\n--- Test de la methode saisir() ---" << std::endl;
    Point p4;
    p4.saisir();
    p4.afficher();

    std::cout << "\n--- Test de la methode translater() ---" << std::endl;
    p2.afficher();
    p2.translater(5.0, -1.0, 2.0);
    std::cout << "Apres translation de (5, -1, 2) : " << std::endl;
    p2.afficher();

    std::cout << "\n--- Test de la methode calculerDistance() ---" << std::endl;
    Point p5(10.0, 0.0, 0.0);
    std::cout << "La distance entre p1 et p5 est : " << p1.calculerDistance(p5) << std::endl;

    // La fin de la fonction main() va entraîner la destruction des objets
    // p1, p2, p3, p4 et p5. Les destructeurs seront appelés.
    std::cout << "\nFin du programme." << std::endl;
    return 0;


    //Test pour Vector

    std::cout << "--- Test du constructeur par defaut ---" << std::endl;
    Vector v1;
    v1.display();
    std::cout << "Nombre d'instances : " << Vector::getInstanceCount() << std::endl;

    std::cout << "\n--- Test du constructeur utilitaire et des setters ---" << std::endl;
    Vector v2(3);
    v2.setCoordinate(0, 1.0);
    v2.setCoordinate(1, 2.0);
    v2.setCoordinate(2, 3.0);
    v2.display();
    std::cout << "Nombre d'instances : " << Vector::getInstanceCount() << std::endl;

    std::cout << "\n--- Test du constructeur de recopie ---" << std::endl;
    Vector v3 = v2;
    v3.display();
    std::cout << "Nombre d'instances : " << Vector::getInstanceCount() << std::endl;

    std::cout << "\n--- Test de l'operateur d'affectation ---" << std::endl;
    Vector v4(2);
    v4.setCoordinate(0, 5.0);
    v4.setCoordinate(1, 6.0);
    v4 = v2; // Appel de l'operateur=
    v4.display();
    std::cout << "Nombre d'instances : " << Vector::getInstanceCount() << std::endl;

    std::cout << "\n--- Test de la norme ---" << std::endl;
    std::cout << "Norme de v2 : " << v2.calculateNorm() << std::endl;

    std::cout << "\n--- Test de l'egalite ---" << std::endl;
    Vector v5(3);
    v5.setCoordinate(0, 1.0); v5.setCoordinate(1, 2.0); v5.setCoordinate(2, 3.0);
    std::cout << "v2 et v5 sont-ils egaux ? " << (v2.equals(v5) ? "Oui" : "Non") << std::endl;

    std::cout << "\n--- Test du produit scalaire ---" << std::endl;
    Vector v6(3);
    v6.setCoordinate(0, 4.0); v6.setCoordinate(1, 5.0); v6.setCoordinate(2, 6.0);
    std::cout << "Produit scalaire de v2 et v6 : " << v2.dotProduct(v6) << std::endl;

    std::cout << "\n--- Test de la multiplication par un scalaire ---" << std::endl;
    Vector v7 = v2 * 2.0;
    v7.display();

    std::cout << "\n--- Test de l'addition de vecteurs ---" << std::endl;
    Vector v8 = v2 + v6;
    v8.display();
    std::cout << "Nombre d'instances : " << Vector::getInstanceCount() << std::endl;

    std::cout << "\nFin du programme." << std::endl;
    return 0;


}