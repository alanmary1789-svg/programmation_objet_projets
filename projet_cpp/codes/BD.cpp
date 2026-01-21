#include "BD.h"
#include <string>
#include <iostream>

using namespace std;

//Constructeur
BD::BD(string c, string a, string t, string e, string is, Etat et, Public pub, string dessin)
    :Livre(c,a,t,e,is,et,pub){
    dessinateur = dessin;
}

BD::BD(const BD& bd):Livre(bd){dessinateur = bd.dessinateur;}

//Affichage
void BD::afficher() const {
    Livre::afficher(); cout << endl;
    cout << "Catégorie : BD, " << "Dessinateur : " << dessinateur; 
}

//Getter
string BD::getDessinateur() const {return dessinateur;}

//Setter
void BD::setDessinateur(string dessin){dessinateur = dessin;}

