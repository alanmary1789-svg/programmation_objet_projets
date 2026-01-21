#include "Recueil.h"
#include <string>
#include <iostream>

using namespace std;

//Constructeur
Recueil::Recueil(string c, string a, string t, string e, string is, Etat et, Public pub, bool v, bool pr)
    :Livre(c,a,t,e,is,et,pub){
        vers = v; prose = pr;
}

Recueil::Recueil(const Recueil& recueil):Livre(recueil){
    vers = recueil.vers; prose = recueil.prose;
}

//Getters 
bool Recueil::getVers() const {return vers;}

bool Recueil::getProse() const {return prose;}

//Setters
void Recueil::setVers(bool v){vers = v;}

void Recueil::setProse(bool pr){prose = pr;}

//Affichage
void Recueil::afficher() const {
    Livre::afficher(); cout << endl;
    cout << "Catégorie : Recueil" << endl;
    cout << "Genre : ";
    if(vers == true && prose == true){
        cout << "Vers et proses";
    }
    else{
        if(vers == true){cout << "Vers";};
        if(prose == true){cout << "Proses";}
    };
}

