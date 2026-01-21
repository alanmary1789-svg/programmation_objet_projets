#ifndef BD_H
#define BD_H

#include "Livre.h"
#include <string>
#include <iostream>

class BD : public Livre{
    private:
        string dessinateur;
    
    public:
        //Constructeur
        BD(string c = "", string a = "", string t = "", string e = "", string is = "", Etat et = libre, Public pub = tout_public,
        string dessin = "");  
            
        BD(const BD& bd);
        
        //Affichage 
        void afficher() const;

        //Getter
        string getDessinateur() const;

        //Setter
        void setDessinateur(string dess);


};

#endif