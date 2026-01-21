#ifndef RECUEIL_H
#define RECUEIL_H

#include "Livre.h"
#include <string>
#include <iostream>

using namespace std;

class Recueil : public Livre{
    private:
        bool vers;
        bool prose;
    
    public:
    //Constructeur 
    Recueil(string c = "", string a = "", string t = "", string e = "", string is = "", Etat et = libre, Public pub = tout_public,
    bool v = false, bool pr = false);
    Recueil(const Recueil& recueil);
    
    //Getters
    bool getVers() const;
    bool getProse() const;
    
    //Setters
    void setVers(bool v);
    void setProse(bool pr);

    //Affichage
    void afficher() const;

};

#endif