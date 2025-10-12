#include "point.h"
#include <iostream>
#include <cmath> // Pour la fonction sqrt()

// Initialisation du membre statique en dehors de la classe
int Point::compteurInstances = 0;

// Constructeur par défaut
Point::Point() : x(0.0), y(0.0), z(0.0) {
    compteurInstances++;
    std::cout << "Constructeur par défaut appelé." << std::endl;
}

// Constructeur de recopie
Point::Point(const Point& autrePoint) : x(autrePoint.x), y(autrePoint.y), z(autrePoint.z) {
    compteurInstances++;
    std::cout << "Constructeur de recopie appelé." << std::endl;
}

// Constructeur utilitaire
Point::Point(double _x, double _y, double _z) : x(_x), y(_y), z(_z) {
    compteurInstances++;
    std::cout << "Constructeur utilitaire appelé." << std::endl;
}

// Destructeur
Point::~Point() {
    compteurInstances--;
    std::cout << "Destructeur appelé. " << "Point (" << x << ", " << y << ", " << z << ") détruit." << std::endl;
}

// Getters
double Point::getX() const { return x; }
double Point::getY() const { return y; }
double Point::getZ() const { return z; }

// Setters
void Point::setX(double _x) { x = _x; }
void Point::setY(double _y) { y = _y; }
void Point::setZ(double _z) { z = _z; }

// Saisie des coordonnées
void Point::saisir() {
    std::cout << "Entrez les coordonnées (x y z) : ";
    std::cin >> x >> y >> z;
}

// Affichage des coordonnées
void Point::afficher() const {
    std::cout << "Coordonnées : (" << x << ", " << y << ", " << z << ")" << std::endl;
}

// Translation du point
void Point::translater(double dx, double dy, double dz) {
    x += dx;
    y += dy;
    z += dz;
}

// Calcul de la distance euclidienne entre deux points
double Point::calculerDistance(const Point& autrePoint) const {
    double dx = x - autrePoint.x;
    double dy = y - autrePoint.y;
    double dz = z - autrePoint.z;
    return std::sqrt(dx*dx + dy*dy + dz*dz);
}

// Getter statique pour le compteur d'instances
int Point::getCompteurInstances() {
    return compteurInstances;
}



