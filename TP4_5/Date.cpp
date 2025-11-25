#include "Date.h"
#include <iostream>
using namespace std;

bool Date::checkDate(int j, int m, int a) {
    if (a < 2000 || a > 2050) return false;
    if (m < 1 || m > 12) return false;
    if (j < 1 || j > 31) return false;
    
    // Vérification des jours selon les mois
    if (m == 2) {
        // Février
        bool bissextile = (a % 4 == 0 && a % 100 != 0) || (a % 400 == 0);
        if (bissextile && j > 29) return false;
        if (!bissextile && j > 28) return false;
    } else if (m == 4 || m == 6 || m == 9 || m == 11) {
        // Mois à 30 jours
        if (j > 30) return false;
    }
    
    return true;
}

Date::Date(int j, int m, int a) {
    if (checkDate(j, m, a)) {
        jour = j;
        mois = m;
        annee = a;
    } else {
        jour = 1;
        mois = 1;
        annee = 2000;
    }
}

void Date::affiche() const {
    cout << jour << "/" << mois << "/" << annee;
}

int Date::getJour() const {
    return jour;
}

int Date::getMois() const {
    return mois;
}

int Date::getAnnee() const {
    return annee;
}

void Date::setJour(int j) {
    if (checkDate(j, mois, annee)) {
        jour = j;
    }
}

void Date::setMois(int m) {
    if (checkDate(jour, m, annee)) {
        mois = m;
    }
}

void Date::setAnnee(int a) {
    if (checkDate(jour, mois, a)) {
        annee = a;
    }
}

bool Date::estEgal(const Date& d) const {
    return (jour == d.jour && mois == d.mois && annee == d.annee);
}

bool Date::estSuperieur(const Date& d) const {
    if (annee != d.annee) return annee > d.annee;
    if (mois != d.mois) return mois > d.mois;
    return jour > d.jour;
}