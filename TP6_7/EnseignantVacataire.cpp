#include "EnseignantVacataire.h"
#include <iostream>
using namespace std;

// Constructeur
EnseignantVacataire::EnseignantVacataire(string n, string p, string a, string t, 
                                         float s, string cas, int nbH, float tx) 
    : Personnel(n, p, a, t, s) {
    casier = cas;
    nbreHeures = nbH;
    taux = tx;
}

// Méthode calculSalaire (redéfinition)
float EnseignantVacataire::calculSalaire() {
    return taux * nbreHeures;
}

// Getters
string EnseignantVacataire::getCasier() {
    return casier;
}

int EnseignantVacataire::getNbreHeures() {
    return nbreHeures;
}

float EnseignantVacataire::getTaux() {
    return taux;
}

// Setters
void EnseignantVacataire::setCasier(string cas) {
    casier = cas;
}

void EnseignantVacataire::setNbreHeures(int nbH) {
    nbreHeures = nbH;
}

void EnseignantVacataire::setTaux(float tx) {
    taux = tx;
}

// Affiche
void EnseignantVacataire::affiche() {
    Personnel::affiche();
    cout << "Casier: " << casier << endl;
    cout << "Nombre d'heures: " << nbreHeures << endl;
    cout << "Taux: " << taux << endl;
    cout << "Salaire total: " << calculSalaire() << endl;
}