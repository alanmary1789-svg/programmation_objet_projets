#include "Theatre.h"
#include <string>
#include <iostream>

using namespace std;

//Constructeur
Theatre::Theatre(string c, string a, string t, string e, string is, Etat et, Public pub, int s)
    :Livre(c,a,t,e,is,et,pub){
    siecle = s;
}

Theatre::Theatre(const Theatre& theatre):Livre(theatre){
    siecle = theatre.siecle;
}

//Getters
int Theatre::getSiecle() const {return siecle;}

//Setters
void Theatre::setSiecle(int s){siecle = s;}

//Affichage
void Theatre::afficher() const {
    Livre::afficher();
    cout << "Catégorie : Théatre, Siecle : " << siecle;
}

