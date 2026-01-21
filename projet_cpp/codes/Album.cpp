#include "Album.h"
#include <string>
#include <iostream>

using namespace std;

//Constructeur
Album::Album(string c, string a, string t, string e, string is, Etat et, Public pub, bool des, bool ph)
    :Livre(c,a,t,e,is,et,pub){
    dessin = des; photo = ph;
}

Album::Album(const Album& album):Livre(album){dessin = album.dessin; photo = album.photo;}

//Getters
bool Album::getDessin() const {return dessin;}

bool Album::getPhoto() const {return photo;}

//Setters 
void Album::setDessin(bool des){dessin = des;}

void Album::setPhoto(bool ph){photo = ph;}

//Affichage
void Album::afficher() const {
    Livre::afficher(); cout << endl;
    cout << "Catégorie : Album, Genre : ";
    if(dessin && photo){cout << "Dessins et photos";}
    else{
        if(dessin == true){cout << "Dessins";};
        if(photo == true){cout << "Photos";}; 
    };
}

