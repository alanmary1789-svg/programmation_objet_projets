#include "Rdv.h"
#include <iostream>
using namespace std;

RDV::RDV() : nombreDeParticipants(0), capaciteMax(10) {
    participants = new string[capaciteMax];
}

RDV::RDV(const RDV& r) {
    date = r.date;
    heure = r.heure;
    lieu = r.lieu;
    nombreDeParticipants = r.nombreDeParticipants;
    capaciteMax = r.capaciteMax;
    
    participants = new string[capaciteMax];
    for (int i = 0; i < nombreDeParticipants; i++) {
        participants[i] = r.participants[i];
    }
}

RDV::~RDV() {
    delete[] participants;
}

void RDV::affiche() const {
    cout << "Rendez-vous le ";
    date.affiche();
    cout << " a ";
    heure.affiche();
    cout << endl;
    cout << "Lieu: " << lieu << endl;
    cout << "Nombre de participants: " << nombreDeParticipants << endl;
    if (nombreDeParticipants > 0) {
        cout << "Participants:" << endl;
        for (int i = 0; i < nombreDeParticipants; i++) {
            cout << "  - " << participants[i] << endl;
        }
    }
}

void RDV::saisieParticipants() {
    cout << "Nombre de participants: ";
    cin >> nombreDeParticipants;
    
    if (nombreDeParticipants > capaciteMax) {
        nombreDeParticipants = capaciteMax;
        cout << "Limite a " << capaciteMax << " participants." << endl;
    }
    
    cin.ignore();
    for (int i = 0; i < nombreDeParticipants; i++) {
        cout << "Nom du participant " << (i+1) << ": ";
        getline(cin, participants[i]);
    }
}

void RDV::saisieLieu() {
    cout << "Lieu du rendez-vous: ";
    cin.ignore();
    getline(cin, lieu);
}

void RDV::saisie() {
    int j, m, a, h, min;
    
    cout << "=== Saisie du rendez-vous ===" << endl;
    
    cout << "Date (jour mois annee): ";
    cin >> j >> m >> a;
    Date d(j, m, a);
    setDate(d);
    
    cout << "Heure (heures minutes): ";
    cin >> h >> min;
    Heure he(h, min);
    setHeure(he);
    
    saisieLieu();
    saisieParticipants();
}

void RDV::setDate(const Date& dateRdv) {
    date = dateRdv;
}

void RDV::setHeure(const Heure& heureRdv) {
    heure = heureRdv;
}

void RDV::setLieu(const string& lieuRdv) {
    lieu = lieuRdv;
}

void RDV::setNombreDeParticipants(int nb) {
    if (nb >= 0 && nb <= capaciteMax) {
        nombreDeParticipants = nb;
    }
}

void RDV::setParticipants(string* ps) {
    for (int i = 0; i < nombreDeParticipants && i < capaciteMax; i++) {
        participants[i] = ps[i];
    }
}

void RDV::setParticipant(int i, string s) {
    if (i >= 0 && i < capaciteMax) {
        participants[i] = s;
    }
}

Date RDV::getDate() const {
    return date;
}

Heure RDV::getHeure() const {
    return heure;
}

string RDV::getLieu() const {
    return lieu;
}

int RDV::getNombreDeParticipants() const {
    return nombreDeParticipants;
}

bool RDV::estCompatibleAvec(const RDV& r) const {
    return !(date.estEgal(r.date) && heure.estEgal(r.heure));
}

bool RDV::estEgal(const RDV& r) const {
    return date.estEgal(r.date) && heure.estEgal(r.heure);
}

bool RDV::estSuperieur(const RDV& r) const {
    if (!date.estEgal(r.date)) {
        return date.estSuperieur(r.date);
    }
    return heure.estSuperieur(r.heure);
}