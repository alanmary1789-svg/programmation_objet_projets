#ifndef BIBLIO_H
#define BIBLIO_H

#include "Livre.h"
#include "Liste.h"
#include <string>
#include <iostream>

using namespace std;

class Biblio{
    private:
        string nom;
        string adresse;
        string code;
        Liste<Livre*> liste;
    
    public:
    //Constructeurs
    Biblio(string n = "", string a = "", string c = "");
    //Destructeurs
    ~Biblio();

    //Getters
    string getNom() const;
    string getAdresse() const;
    string getCode() const;
    Liste<Livre*> getListe() const;

    //Setters
    void setNom(string n);
    void setAdresse(string a);
    void setCode(string c);

    //Affichage
    

    //Méthodes
    bool ajouterLivre(Livre* livre);
    bool supprimerLivre(Livre* livre);
    Livre* chercherLivre(const string& c) const;
    Livre* chercherLivre_IBSN(const string& c) const;

    bool demanderLivre(const string& c, Biblio* biblio);
    bool preterLivre(const string& c, Biblio* biblio);
    bool rendreLivre(const string& c);
    
    bool acheterLivre(Livre* livre);

};

#endif