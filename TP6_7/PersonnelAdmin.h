#ifndef PERSONNELADMIN_H
#define PERSONNELADMIN_H

#include "Personnel.h"
#include <string>
using namespace std;

class PersonnelAdmin : public Personnel {
private:
    int heuresSup;
    float taux;

public:
    // Constructeur (heuresSup est un paramètre par défaut mis à 0)
    PersonnelAdmin(string n, string p, string a = "", string t = "", 
                   float s = 0.0, int hSup = 0, float tx = 0.0);
    
    // Méthode calculSalaire (redéfinition)
    float calculSalaire();
    
    // Getters
    int getHeuresSup();
    float getTaux();
    
    // Setters
    void setHeuresSup(int hSup);
    void setTaux(float tx);
    
    // Affiche
    void affiche();
};

#endif