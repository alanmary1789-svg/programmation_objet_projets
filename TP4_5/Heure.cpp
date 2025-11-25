#include "Heure.h"
#include <iostream>
#include <iomanip>
using namespace std;

Heure::Heure() : heures(0), minutes(0) {}

Heure::Heure(int h, int m) {
    if (h >= 0 && h < 24 && m >= 0 && m < 60) {
        heures = h;
        minutes = m;
    } else {
        heures = 0;
        minutes = 0;
    }
}

void Heure::affiche() const {
    cout << setfill('0') << setw(2) << heures << "h" 
         << setw(2) << minutes;
}

int Heure::getHeures() const {
    return heures;
}

int Heure::getMinutes() const {
    return minutes;
}

void Heure::setHeures(int h) {
    if (h >= 0 && h < 24) {
        heures = h;
    }
}

void Heure::setMinutes(int m) {
    if (m >= 0 && m < 60) {
        minutes = m;
    }
}

bool Heure::estEgal(const Heure& h) const {
    return (heures == h.heures && minutes == h.minutes);
}

bool Heure::estSuperieur(const Heure& h) const {
    if (heures != h.heures) return heures > h.heures;
    return minutes > h.minutes;
}