#include "Roman.h"
#include <string>
#include <iostream>

using namespace std;

//Constructeur
Roman::Roman(string c, string a, string t, string e, string is, Etat et, Public pub, Genre g)
    :Livre(c,a,t,e,is,et,pub){
    genre = g;
}

Roman::Roman(const Roman& roman):Livre(roman){genre = roman.genre;}

//Getters
Genre Roman::getGenre() const {return genre;}

//Setters
void Roman::setGenre(Genre g){genre = g;}

//Affichage 
void Roman::afficher() const {
    Livre::afficher();
    cout << "Catégorie : Roman, Genre : " << genre;
}

