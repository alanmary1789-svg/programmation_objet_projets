#include "Livre.h"
#include <string>
#include <iostream>

using namespace std;

//Constructeurs
Livre::Livre(string c, string a, string t, string e, string is, Etat et, Public pub, Biblio* biblio){
    code = c; auteur = a; titre = t; editeur = e; isbn = is; etat = et; audience = pub; proprietaire = biblio;
}

Livre::Livre(const Livre& livre){
    code = livre.code; auteur = livre.auteur; titre = livre.titre; editeur = livre.editeur; isbn = livre.isbn; etat = livre.etat; audience = livre.audience; proprietaire = livre.proprietaire;
}

//Getters
string Livre::getCode() const {return code;}

string Livre::getAuteur() const {return auteur;}

string Livre::getTitre() const {return titre;}

string Livre::getEditeur() const {return editeur;}

string Livre::getIsbn() const {return isbn;}

Etat Livre::getEtat() const {return etat;}

Public Livre::getPublic() const {return audience;}

Biblio* Livre::getProprio() const {return proprietaire;}

//Setters
void Livre::setCode(string c){code = c;}

void Livre::setAuteur(string a){auteur = a;}

void Livre::setTitre(string t){titre = t;}

void Livre::setEditeur(string e){editeur = e;}

void Livre::setIsbn(string is){isbn = is;}

void Livre::setEtat(Etat et){etat = et;}

void Livre::setPublic(Public pub){audience = pub;}

void Livre::setProprio(Biblio* biblio){proprietaire = biblio;}

//Affichage
void Livre::afficher() const {
    cout << "Titre : " << titre << endl;
    cout << "Auteur : " << auteur << ", Editeur : " << editeur << endl;
    cout << "Public : " << audience << endl;
    cout << "Code : " << code << ", ISBN : " << isbn << endl;
    cout << "Etat : " << etat;
    cout << "Prorietaire : " << proprietaire ;
}

//Méthodes
bool Livre::emprunter(){ 
    if(etat != libre){
        if(etat == emprunte){cout << "Livre emprunté" << endl;}else{cout << "Livre prété" << endl;};
        return false;
    }
    else{etat = emprunte; return true;};    
}

bool Livre::rendre(){
    if(etat == libre){cout << "Livre deja libre" << endl; return false;}
    else{etat = libre; return true;};
}

bool Livre::estdispo_emprunt(Biblio* biblio) const {
    if(etat == emprunte){return false;}
    if(etat == libre || (etat == prete && proprietaire != biblio)){return true;}
    return false;
}

