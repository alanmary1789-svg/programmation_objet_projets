#ifndef ALBUM_H
#define ALBUM_H

#include "Livre.h"
#include <string>
#include <iostream>

using namespace std;

class Album : public Livre{
    private:
        bool dessin;
        bool photo;
    
    public:
        //Constructeur 
        Album(string c = "", string a = "", string t = "", string e = "", string is = "", Etat et = libre, Public pub = tout_public,
        bool des = false, bool ph = false);
        Album(const Album& album);

        //Getters
        bool getDessin() const;
        bool getPhoto() const;

        //Setters
        void setDessin(bool des);
        void setPhoto(bool ph);

        //Affichage
        void afficher() const;
};

#endif