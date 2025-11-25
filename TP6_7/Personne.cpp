#include "Personne.h"
#include <iostream>
using namespace std;

// Constructeur
Personne::Personne(string n, string p, string a, string t) {
    nom = n;
    prenom = p;
    adresse = a;
    telephone = t;
}

// Méthode affiche
void Personne::affiche() {
    cout << "Nom: " << nom << endl;
    cout << "Prenom: " << prenom << endl;
    cout << "Adresse: " << adresse << endl;
    cout << "Telephone: " << telephone << endl;
}

// Getters
string Personne::getNom() {
    return nom;
}

string Personne::getPrenom() {
    return prenom;
}

string Personne::getAdresse() {
    return adresse;
}

string Personne::getTelephone() {
    return telephone;
}

// Setters
void Personne::setNom(string n) {
    nom = n;
}

void Personne::setPrenom(string p) {
    prenom = p;
}

void Personne::setAdresse(string a) {
    adresse = a;
}

void Personne::setTelephone(string t) {
    telephone = t;
}