#ifndef ENSEIGNANTVACATAIRE_H
#define ENSEIGNANTVACATAIRE_H

#include "Personnel.h"
#include <string>
using namespace std;

class EnseignantVacataire : public Personnel {
private:
    string casier;
    int nbreHeures;
    float taux;

public:
    // Constructeur (nbreHeures est un paramètre par défaut mis à 0)
    EnseignantVacataire(string n, string p, string a = "", string t = "", 
                        float s = 0.0, string cas = "", int nbH = 0, float tx = 0.0);
    
    // Méthode calculSalaire (redéfinition)
    float calculSalaire();
    
    // Getters
    string getCasier();
    int getNbreHeures();
    float getTaux();
    
    // Setters
    void setCasier(string cas);
    void setNbreHeures(int nbH);
    void setTaux(float tx);
    
    // Affiche
    void affiche();
};

#endif