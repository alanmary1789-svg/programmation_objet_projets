#include "Agenda.h"
#include <iostream>
using namespace std;

Agenda::Agenda() : premier(nullptr) {}

Agenda::Agenda(const Agenda& a) {
    if (a.premier == nullptr) {
        premier = nullptr;
    } else {
        premier = new NoeudRDV(a.premier->getRdv());
        NoeudRDV* courantSource = a.premier->getSuivant();
        NoeudRDV* courantCopie = premier;
        
        while (courantSource != nullptr) {
            courantCopie->setSuivant(new NoeudRDV(courantSource->getRdv()));
            courantCopie = courantCopie->getSuivant();
            courantSource = courantSource->getSuivant();
        }
    }
}

Agenda::~Agenda() {
    while (premier != nullptr) {
        NoeudRDV* temp = premier;
        premier = premier->getSuivant();
        delete temp;
    }
}

void Agenda::ajoute(const RDV& r) {
    NoeudRDV* nouveau = new NoeudRDV(r, premier);
    premier = nouveau;
}

void Agenda::enleve() {
    if (premier != nullptr) {
        NoeudRDV* temp = premier;
        premier = premier->getSuivant();
        delete temp;
    }
}

void Agenda::affiche() const {
    if (premier == nullptr) {
        cout << "L'agenda est vide." << endl;
    } else {
        cout << "\n=== AGENDA ===" << endl;
        NoeudRDV* courant = premier;
        int num = 1;
        
        while (courant != nullptr) {
            cout << "\nRendez-vous #" << num << ":" << endl;
            courant->getRdv().affiche();
            courant = courant->getSuivant();
            num++;
        }
        cout << "==============" << endl;
    }
}

bool Agenda::estVide() const {
    return premier == nullptr;
}