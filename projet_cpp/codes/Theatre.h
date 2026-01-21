#ifndef THEATRE_H
#define THEATRE_H

#include "Livre.h"
#include <iostream>
#include <string>

using namespace std;

class Theatre : public Livre{
    private:
        int siecle;
    
    public:
    //Constructeur
    Theatre(string c = "", string a = "", string t = "", string e = "", string is = "", Etat et = libre, Public pub = tout_public,
    int s = 0);
    Theatre(const Theatre& theatre);

    //Getter
    int getSiecle() const;

    //Setters
    void setSiecle(int s);

    //Affichage
    void afficher() const;
};

#endif