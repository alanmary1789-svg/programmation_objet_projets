#include "Point.h"
#include <iostream>

int main() {
    // Test du constructeur par défaut et du compteur
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
}