#ifndef PERSONNE_H
#define PERSONNE_H

#include <string>
using namespace std;

class Personne {
private:
    string nom;
    string prenom;
    string adresse;
    string telephone;

public:
    // Constructeur (adresse et telephone avec valeurs par défaut = chaîne vide)
    Personne(string n, string p, string a = "", string t = "");
    
    // Méthode affiche
    void affiche();
    
    // Getters
    string getNom();
    string getPrenom();
    string getAdresse();
    string getTelephone();
    
    // Setters
    void setNom(string n);
    void setPrenom(string p);
    void setAdresse(string a);
    void setTelephone(string t);
};

#endif