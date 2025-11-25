#include "EnseignantPermanent.h"
#include <iostream>
using namespace std;

// Constructeur
EnseignantPermanent::EnseignantPermanent(string n, string p, string a, string t, 
                                         float s, string bur, int gr, float prime) 
    : Personnel(n, p, a, t, s) {
    bureau = bur;
    grade = gr;
    primeMensuelle = prime;
}

// Méthode calculSalaire (redéfinition)
float EnseignantPermanent::calculSalaire() {
    return getSalaire() + (grade * primeMensuelle / 100.0);
}

// Getters
string EnseignantPermanent::getBureau() {
    return bureau;
}

int EnseignantPermanent::getGrade() {
    return grade;
}

float EnseignantPermanent::getPrimeMensuelle() {
    return primeMensuelle;
}

// Setters
void EnseignantPermanent::setBureau(string bur) {
    bureau = bur;
}

void EnseignantPermanent::setGrade(int gr) {
    grade = gr;
}

void EnseignantPermanent::setPrimeMensuelle(float prime) {
    primeMensuelle = prime;
}

// Affiche
void EnseignantPermanent::affiche() {
    Personnel::affiche();
    cout << "Bureau: " << bureau << endl;
    cout << "Grade: " << grade << endl;
    cout << "Prime mensuelle: " << primeMensuelle << endl;
    cout << "Salaire total: " << calculSalaire() << endl;
}