#include "Vector.h"
#include <iostream>
#include <cmath>
#include <stdexcept>

// Initialisation du membre statique. Notez l'absence de parenthèses après 'instanceCount'.
int Vector::instanceCount = 0;

// Constructeur par défaut
Vector::Vector() : coordinates(nullptr), size(0) {
    instanceCount++;
    std::cout << "Constructeur par defaut (vecteur vide) appele." << std::endl;
}

// Constructeur utilitaire
Vector::Vector(int s) : size(s) {
    if (s < 0) {
        throw std::invalid_argument("La dimension du vecteur ne peut pas etre negative.");
    }
    coordinates = new double[size](); 
    instanceCount++;
    std::cout << "Constructeur utilitaire (taille " << size << ") appele." << std::endl;
}

// Constructeur de recopie
Vector::Vector(const Vector& other) : size(other.size) {
    coordinates = new double[size];
    for (int i = 0; i < size; ++i) {
        coordinates[i] = other.coordinates[i];
    }
    instanceCount++;
    std::cout << "Constructeur de recopie appele." << std::endl;
}

// Destructeur
Vector::~Vector() {
    delete[] coordinates;
    instanceCount--;
    std::cout << "Destructeur appele. " << "Vecteur de taille " << size << " detruit." << std::endl;
}

// Surcharge de l'operateur d'affectation
Vector& Vector::operator=(const Vector& other) {
    if (this != &other) { 
        delete[] coordinates;
        size = other.size;
        coordinates = new double[size];
        for (int i = 0; i < size; ++i) {
            coordinates[i] = other.coordinates[i];
        }
    }
    std::cout << "Operateur d'affectation appele." << std::endl;
    return *this;
}

// Getter pour les coordonnees
double Vector::getCoordinate(int index) const {
    if (index < 0 || index >= size) {
        throw std::out_of_range("L'index de la coordonnee est hors limites.");
    }
    return coordinates[index];
}

// Setter pour les coordonnees
void Vector::setCoordinate(int index, double value) {
    if (index < 0 || index >= size) {
        throw std::out_of_range("L'index de la coordonnee est hors limites.");
    }
    coordinates[index] = value;
}

// Affichage
void Vector::display() const {
    std::cout << "Vector (dim " << size << "): [";
    for (int i = 0; i < size; ++i) {
        std::cout << coordinates[i] << (i == size - 1 ? "" : ", ");
    }
    std::cout << "]" << std::endl;
}

// Calcul de la norme euclidienne
double Vector::calculateNorm() const {
    double sumOfSquares = 0.0;
    for (int i = 0; i < size; ++i) {
        sumOfSquares += coordinates[i] * coordinates[i];
    }
    return std::sqrt(sumOfSquares);
}

// Verification de l'egalite
bool Vector::equals(const Vector& other) const {
    if (size != other.size) {
        return false;
    }
    for (int i = 0; i < size; ++i) {
        if (coordinates[i] != other.coordinates[i]) {
            return false;
        }
    }
    return true;
}

// Produit scalaire
double Vector::dotProduct(const Vector& other) const {
    if (size != other.size) {
        throw std::invalid_argument("Les vecteurs doivent avoir la meme dimension pour le produit scalaire.");
    }
    double result = 0.0;
    for (int i = 0; i < size; ++i) {
        result += coordinates[i] * other.coordinates[i];
    }
    return result;
}

// Multiplication par un scalaire
Vector Vector::operator*(double scalar) const {
    Vector result(size);
    for (int i = 0; i < size; ++i) {
        result.coordinates[i] = coordinates[i] * scalar;
    }
    return result;
}

// Addition de deux vecteurs
Vector Vector::operator+(const Vector& other) const {
    if (size != other.size) {
        throw std::invalid_argument("Les vecteurs doivent avoir la meme dimension pour l'addition.");
    }
    Vector result(size);
    for (int i = 0; i < size; ++i) {
        result.coordinates[i] = coordinates[i] + other.coordinates[i];
    }
    return result;
}

// Getter statique pour le compteur d'instances
int Vector::getInstanceCount() {
    return instanceCount;
}