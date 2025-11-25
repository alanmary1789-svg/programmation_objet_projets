#include "Personnel.h"
#include <iostream>
using namespace std;

// Constructeur
Personnel::Personnel(string n, string p, string a, string t, float s) 
    : Personne(n, p, a, t) {
    salaire = s;
}

// Méthode calculSalaire
float Personnel::calculSalaire() {
    return salaire;
}

// Getter
float Personnel::getSalaire() {
    return salaire;
}

// Setter
void Personnel::setSalaire(float s) {
    salaire = s;
}

// Affiche
void Personnel::affiche() {
    Personne::affiche();
    cout << "Salaire: " << salaire << endl;
}