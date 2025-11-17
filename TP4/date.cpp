// Date.cpp
#include "date.h"
#include <iostream> // Nécessaire pour l'affichage (cout) 

using namespace std; // Pour utiliser cout et endl 

// Constructeur
Date::Date(int j, int m, int a) {
    
    // Méthode checkDate - méthode privée
    if (checkDate(j, m, a)) {
        // Si les valeurs sont valides, on les assigne
        // L'utilisation de 'this->' est une bonne pratique vue en cours [cite: 423]
        this->jour = j;
        this->mois = m;
        this->annee = a;
    } else {
        // Sinon, utilisation des valeurs par défaut 01.01.2000
        this->jour = 1;
        this->mois = 1;
        this->annee = 2000;
    }
}

// Méthode de validation- méthode privée
bool Date::checkDate(int j, int m, int a) {
    
    // Vérification des contraintes de l'énoncé
    bool anneeValide = (a >= 2000 && a <= 2050);
    bool moisValide = (m >= 1 && m <= 12);
    bool jourValide = (j >= 1 && j <= 31); // Simplifié, comme indiqué

    // La date est valide uniquement si les 3 conditions sont vraies
    return (anneeValide && moisValide && jourValide);
}

// Méthode affiche
void Date::affiche() {
    // On utilise 'cout' pour l'opérateur de sortie 
    // this->' est utilisé pour accéder aux attributs de l'objet 
    cout << this->jour << "/" << this->mois << "/" << this->annee << endl;
}

// Getters
int Date::getJour() {
    return this->jour;
}

int Date::getMois() {
    return this->mois;
}

int Date::getAnnee() {
    return this->annee;
}

// Setters

void Date::setJour(int j) {
    if (j >= 1 && j <= 31) {
        this->jour = j;
    }
}   

void Date::setMois(int m) {
    if (m >= 1 && m <= 12) {
        this->mois = m;
    }
}

void Date::setAnnee(int a) {
    // Validation : l'année doit être entre 2000 et 2050
    if (a >= 2000 && a <= 2050) {
        this->annee = a;
    }
}

