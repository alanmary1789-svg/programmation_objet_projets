#ifndef PERSONNEL_H
#define PERSONNEL_H

#include "Personne.h"
#include <string>
using namespace std;

class Personnel : public Personne {
private:
    float salaire;

public:
    // Constructeur
    Personnel(string n, string p, string a = "", string t = "", float s = 0.0);
    
    // Méthode calculSalaire VIRTUELLE
    virtual float calculSalaire();
    
    // Getters
    float getSalaire();
    
    // Setters
    void setSalaire(float s);
    
    // Affiche
    void affiche();
};

#endif