#ifndef ELEVE_H
#define ELEVE_H

#include "Personne.h"
#include <string>
using namespace std;

class Eleve : public Personne {
private:
    string promotion;
    string groupeTD;
    float GPA;

public:
    // Constructeur (promotion, GPA et groupeTD ont des valeurs par défaut)
    Eleve(string n, string p, string a = "", string t = "", 
          string promo = "", float gpa = -1, string grp = "");
    
    // Méthode affiche
    void affiche();
    
    // Getters
    string getPromotion();
    string getGroupeTD();
    float getGPA();
    
    // Setters
    void setPromotion(string promo);
    void setGroupeTD(string grp);
    void setGPA(float gpa);
};

#endif