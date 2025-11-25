#include "PersonnelAdmin.h"
#include <iostream>
using namespace std;

// Constructeur
PersonnelAdmin::PersonnelAdmin(string n, string p, string a, string t, 
                               float s, int hSup, float tx) 
    : Personnel(n, p, a, t, s) {
    heuresSup = hSup;
    taux = tx;
}

// Méthode calculSalaire (redéfinition)
float PersonnelAdmin::calculSalaire() {
    return getSalaire() + (taux * heuresSup);
}

// Getters
int PersonnelAdmin::getHeuresSup() {
    return heuresSup;
}

float PersonnelAdmin::getTaux() {
    return taux;
}

// Setters
void PersonnelAdmin::setHeuresSup(int hSup) {
    heuresSup = hSup;
}

void PersonnelAdmin::setTaux(float tx) {
    taux = tx;
}

// Affiche
void PersonnelAdmin::affiche() {
    Personnel::affiche();
    cout << "Heures supplementaires: " << heuresSup << endl;
    cout << "Taux: " << taux << endl;
    cout << "Salaire total: " << calculSalaire() << endl;
}