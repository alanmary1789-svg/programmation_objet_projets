// rdv.cpp
#include "rdv.h"
#include <iostream>
#include <string>

using namespace std;

// Constructeur : initialise le nombre de participants à 0 et réserve le tableau
RDV::RDV() {
    this->nombreDeParticipants = 0;
    // "réserve un tableau de 10 éléments"
    this->listeDeParticipants = new string[10];
    // Les objets date et heure sont initialisés par leurs constructeurs par défaut
}

// Destructeur : libère la mémoire allouée pour la liste
RDV::~RDV() {
    delete[] this->listeDeParticipants;
}

// Affiche toutes les informations du rendez-vous
void RDV::affiche() {
    cout << "--- INFOS RENDEZ-VOUS ---" << endl;
    cout << "Date : ";
    this->date.affiche(); // méthode de la classe Date
    cout << "Heure : ";
    this->heure.affiche(); // méthode de la classe Heure
    cout << "Lieu : " << this->lieu << endl;
    cout << "Participants (" << this->nombreDeParticipants << ") :" << endl;
    
    for (int i = 0; i < this->nombreDeParticipants; i++) {
        cout << "  - " << this->listeDeParticipants[i] << endl;
    }
    cout << "---------------------------" << endl;
}

// Saisie du lieu 
void RDV::saisieLieu() {
    cout << "Saisie du lieu : ";
    getline(cin, this->lieu);
}

// Saisie des participants
void RDV::saisieParticipants() {
    cout << "Nombre de participants (max 10) : ";
    cin >> this->nombreDeParticipants;

    if (this->nombreDeParticipants > 10) {
        cout << "Maximum 10 participants. Le nombre est ajuste a 10." << endl;
        this->nombreDeParticipants = 10;
    }

    cin.ignore(); // Nettoie le buffer après 'cin'

    for (int i = 0; i < this->nombreDeParticipants; i++) {
        cout << "Nom du participant " << i + 1 << " : ";
        getline(cin, this->listeDeParticipants[i]);
    }
}

// Saisie complète 
void RDV::saisie() {
    int j, m, a, h, min;
    
    cout << "Saisie de la date (J M A) : ";
    cin >> j >> m >> a;
    this->date.setJour(j);
    this->date.setMois(m);
    this->date.setAnnee(a);

    cout << "Saisie de l'heure (H MIN) : ";
    cin >> h >> min;
    this->heure.setHeure(h);
    this->heure.setMinute(min);

    cin.ignore(); // Nettoie le buffer avant 'getline'

    this->saisieLieu();
    this->saisieParticipants();
}

void RDV::setDate(const Date& dateRdv) {
    this->date = dateRdv;
}

void RDV::setHeure(const Heure& heureRdv) {
    this->heure = heureRdv;
}

void RDV::setLieu(const std::string& lieuRdv) {
    this->lieu = lieuRdv;
}

void RDV::setNombreDeParticipants(int nombreDeParticipants) {
    this->nombreDeParticipants = nombreDeParticipants;
}

void RDV::setParticipants(std::string* ps) {
    this->listeDeParticipants = ps;
}

void RDV::setParticipant(int i, std::string s) {
    // On vérifie qu'on ne sort pas du tableau alloué (taille 10)
    if (i >= 0 && i < 10) {
        this->listeDeParticipants[i] = s;
    }
}