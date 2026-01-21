#include "Biblio.h"
#include "Livre.h"
#include <string>
#include <iostream>

using namespace std;

//Constructeurs
Biblio::Biblio(string n, string a, string c){nom = n; adresse = a; code = c;}

//Destructeur
Biblio::~Biblio(){
    Noeud<Livre*>* courant = liste.getTete();
    while(courant != nullptr){
        Livre* livre = courant->getInfo();
        if(livre->getProprio() == this){  // Supprimer seulement mes livres
            delete livre;
        }
        courant = courant->getSuivant();
    }
}

//Getters
string Biblio::getNom() const {return nom;}

string Biblio::getAdresse() const {return adresse;}

string Biblio::getCode() const {return code;}

Liste<Livre*> Biblio::getListe() const {return liste;}


//Setters
void Biblio::setNom(string no){nom = no;}

void Biblio::setAdresse(string a){adresse = a;}

void Biblio::setCode(string c){code = c;}


//Méthodes
bool Biblio::ajouterLivre(Livre* livre){
    if(livre == nullptr){return false;}
    if(chercherLivre(livre -> getCode()) != nullptr){return false;}
    liste.insererFin(livre);
    return true;
}

bool Biblio::supprimerLivre(Livre* livre){
    if(livre == nullptr) return false;
    if(livre->getProprio() != this) return false;  // Je ne peux supprimer que mes livres
    if(livre->getEtat() != libre) return false;         // Seulement si libre
    if(liste.supprimer(livre)){
        delete livre;
        return true;
    }
    return false;
}

Livre* Biblio::chercherLivre(const string& c) const {
    Noeud<Livre*>* courant = liste.getTete();
    while(courant != nullptr){
        if(courant -> getInfo() -> getCode() == c){return courant -> getInfo();};
        courant = courant -> getSuivant();
    };
    return nullptr;
}

Livre* Biblio::chercherLivre_IBSN(const string& c) const {
    Noeud<Livre*>* courant = liste.getTete();
    while(courant != nullptr){
        if(courant -> getInfo() -> getIsbn() == c){return courant -> getInfo();};
        courant = courant -> getSuivant();
    };
    return nullptr;
}

bool Biblio::demanderLivre(const string& isbn, Biblio* biblio){
    Livre* livre = biblio->chercherLivre_IBSN(isbn);
    if(livre != nullptr && livre-> estdispo_emprunt(this)){
        livre->setEtat(prete);
        liste.insererFin(livre);
        return true;
    }
    return false;
}


bool Biblio::preterLivre(const string& c, Biblio* biblio){
    Livre* livre = chercherLivre(c);
    if(livre != nullptr && livre-> estdispo_emprunt(biblio) && livre->getProprio() == this){
        livre->setEtat(prete);
        biblio->liste.insererFin(livre);
        return true;
    }
    return false;
}

bool Biblio::rendreLivre(const string& c){//une biblio rend à un biblio
    Livre* livre = chercherLivre(c);
    if(livre != nullptr && livre->getEtat() == prete && livre -> getProprio() != this){
        // Je suis l'emprunteur, je rends le livre
        livre->setEtat(libre);
        liste.supprimer(livre);  // Retirer de ma liste
        return true;
    }
    return false;
}

bool Biblio::acheterLivre(Livre* livre){
    if(livre == nullptr){return false;};
    livre -> setEtat(libre);
    livre -> setProprio(this);
    return ajouterLivre(livre);
}



