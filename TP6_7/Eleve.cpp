#include "Eleve.h"
#include <iostream>
using namespace std;

// Constructeur
Eleve::Eleve(string n, string p, string a, string t, 
             string promo, float gpa, string grp) 
    : Personne(n, p, a, t) {
    promotion = promo;
    GPA = gpa;
    groupeTD = grp;
}

// Méthode affiche
void Eleve::affiche() {
    Personne::affiche();
    cout << "Promotion: " << promotion << endl;
    cout << "Groupe TD: " << groupeTD << endl;
    cout << "GPA: " << GPA << endl;
}

// Getters
string Eleve::getPromotion() {
    return promotion;
}

string Eleve::getGroupeTD() {
    return groupeTD;
}

float Eleve::getGPA() {
    return GPA;
}

// Setters
void Eleve::setPromotion(string promo) {
    promotion = promo;
}

void Eleve::setGroupeTD(string grp) {
    groupeTD = grp;
}

void Eleve::setGPA(float gpa) {
    GPA = gpa;
}