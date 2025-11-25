#include "AgendaOrdonne.h"
#include <iostream>
using namespace std;

AgendaOrdonne::AgendaOrdonne() : premier(nullptr) {}

AgendaOrdonne::AgendaOrdonne(const AgendaOrdonne& a) {
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

AgendaOrdonne::~AgendaOrdonne() {
    while (premier != nullptr) {
        NoeudRDV* temp = premier;
        premier = premier->getSuivant();
        delete temp;
    }
}

void AgendaOrdonne::ajoute(const RDV& r) {
    NoeudRDV* nouveau = new NoeudRDV(r);
    
    // Insertion dans une liste vide
    if (premier == nullptr || r.estSuperieur(premier->getRdv())) {
        nouveau->setSuivant(premier);
        premier = nouveau;
        return;
    }
    
    // Recherche de la position d'insertion
    NoeudRDV* precedent = premier;
    NoeudRDV* courant = premier->getSuivant();
    
    while (courant != nullptr && courant->getRdv().estSuperieur(r)) {
        precedent = courant;
        courant = courant->getSuivant();
    }
    
    // Insertion entre precedent et courant
    nouveau->setSuivant(courant);
    precedent->setSuivant(nouveau);
}

void AgendaOrdonne::enleve(const RDV& r) {
    if (premier == nullptr) {
        cout << "L'agenda est vide, impossible de supprimer." << endl;
        return;
    }
    
    // Suppression du premier element
    if (premier->getRdv().estEgal(r)) {
        NoeudRDV* temp = premier;
        premier = premier->getSuivant();
        delete temp;
        cout << "Rendez-vous supprime." << endl;
        return;
    }
    
    // Recherche du rendez-vous
    NoeudRDV* precedent = premier;
    NoeudRDV* courant = premier->getSuivant();
    
    while (courant != nullptr && !courant->getRdv().estEgal(r)) {
        precedent = courant;
        courant = courant->getSuivant();
    }
    
    if (courant != nullptr) {
        precedent->setSuivant(courant->getSuivant());
        delete courant;
        cout << "Rendez-vous supprime." << endl;
    } else {
        cout << "Rendez-vous non trouve." << endl;
    }
}

void AgendaOrdonne::affiche() const {
    if (premier == nullptr) {
        cout << "L'agenda est vide." << endl;
    } else {
        cout << "\n=== AGENDA ORDONNE ===" << endl;
        NoeudRDV* courant = premier;
        int num = 1;
        
        while (courant != nullptr) {
            cout << "\nRendez-vous #" << num << ":" << endl;
            courant->getRdv().affiche();
            courant = courant->getSuivant();
            num++;
        }
        cout << "======================" << endl;
    }
}

bool AgendaOrdonne::estVide() const {
    return premier == nullptr;
}