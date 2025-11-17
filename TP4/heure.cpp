// heure.cpp
#include "heure.h"
#include <iostream> // Nécessaire pour cout

using namespace std; // Pour utiliser cout et endl

// Constructeur par défaut
// Initialise l'heure à 00:00
Heure::Heure() {
    this->heure = 0;
    this->minute = 0;
}

// Constructeur paramétré
Heure::Heure(int h, int m) {
    // Validation
    if (h >= 0 && h < 24) {
        this->heure = h;
    } else {
        this->heure = 0; // Valeur par défaut si invalide
    }

    if (m >= 0 && m < 60) {
        this->minute = m;
    } else {
        this->minute = 0; // Valeur par défaut si invalide
    }
}

void Heure::affiche() {
    cout << this->heure << ":" << this->minute << endl;
}

int Heure::getHeure() {
    return this->heure;
}

int Heure::getMinute() {
    return this->minute;
}

void Heure::setHeure(int h) {
    if (h >= 0 && h < 24) {
        this->heure = h;
    }
}

void Heure::setMinute(int m) {
    if (m >= 0 && m < 60) {
        this->minute = m;
    }
}