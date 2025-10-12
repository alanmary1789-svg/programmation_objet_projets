#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

class Vector {
private:
    // Pointeur vers un tableau dynamique pour stocker les coordonnées du vecteur.
    double* coordinates;
    // La dimension (ou taille) du vecteur.
    int size;
    // Compteur d'instances, statique pour être partagé.
    static int instanceCount;

public:
    // Constructeur par défaut : crée un vecteur vide de taille 0.
    Vector();

    // Constructeur utilitaire : crée un vecteur avec une dimension donnée, initialisé à zéro.
    explicit Vector(int s);

    // Constructeur de recopie : crée un nouveau vecteur à partir d'un vecteur existant.
    Vector(const Vector& other);

    // Destructeur : libère la mémoire allouée dynamiquement.
    ~Vector();

    // Surcharge de l'opérateur d'affectation pour gérer la copie de vecteurs.
    Vector& operator=(const Vector& other);

    // Méthode pour accéder à une coordonnée spécifique. Le mot-clé const garantit que la méthode ne modifie pas l'objet.
    double getCoordinate(int index) const;

    // Méthode pour modifier une coordonnée spécifique.
    void setCoordinate(int index, double value);

    // Méthode d'affichage du vecteur.
    void display() const;

    // Méthode pour calculer la norme euclidienne du vecteur.
    double calculateNorm() const;

    // Méthode pour vérifier si le vecteur est égal à un autre.
    bool equals(const Vector& other) const;

    // Méthode pour calculer le produit scalaire avec un autre vecteur.
    double dotProduct(const Vector& other) const;

    // Surcharge de l'opérateur de multiplication par un scalaire.
    Vector operator*(double scalar) const;

    // Surcharge de l'opérateur d'addition de deux vecteurs.
    Vector operator+(const Vector& other) const;

    // Méthode statique pour obtenir le nombre d'instances de la classe.
    static int getInstanceCount();
};

#endif // VECTOR_H