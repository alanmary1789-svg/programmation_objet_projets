#ifndef ENSEIGNANTPERMANENT_H
#define ENSEIGNANTPERMANENT_H

#include "Personnel.h"
#include <string>
using namespace std;

class EnseignantPermanent : public Personnel {
private:
    string bureau;
    int grade;
    float primeMensuelle;

public:
    // Constructeur (bureau est un paramètre par défaut mis à chaîne vide)
    EnseignantPermanent(string n, string p, string a = "", string t = "", 
                        float s = 0.0, string bur = "", int gr = 0, float prime = 0.0);
    
    // Méthode calculSalaire (redéfinition)
    float calculSalaire();
    
    // Getters
    string getBureau();
    int getGrade();
    float getPrimeMensuelle();
    
    // Setters
    void setBureau(string bur);
    void setGrade(int gr);
    void setPrimeMensuelle(float prime);
    
    // Affiche
    void affiche();
};

#endif