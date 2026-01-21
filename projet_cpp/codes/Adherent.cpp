#include "Adherent.h"
#include <string>
#include <iostream>

using namespace std;

// Initialisation du compteur 
int Adherent::nbAdherents = 0;

// Constructeurs
Adherent::Adherent(string nm, string pnm, string adr, int numAdh, Biblio* bib, int max){
    nom = nm; 
    prenom = pnm; 
    adresse = adr; 
    numAdherent = numAdh;
    biblio = bib; 
    nbMaxEmprunt = max;
    // livresEmpruntes s'initialise automatiquement (liste vide)
    nbAdherents++;
}

Adherent::Adherent(const Adherent& adherent){
    nom = adherent.nom; 
    prenom = adherent.prenom; 
    adresse = adherent.adresse; 
    numAdherent = adherent.numAdherent;
    biblio = adherent.biblio; 
    nbMaxEmprunt = adherent.nbMaxEmprunt;
    livresEmpruntes = adherent.livresEmpruntes;  // Copie via operator= de Liste
    nbAdherents++;
}

// Destructeur
Adherent::~Adherent(){
    nbAdherents--;
}

// Getters
string Adherent::getNom() const {return nom;}

string Adherent::getPrenom() const {return prenom;}

string Adherent::getAdresse() const {return adresse;}

int Adherent::getNumAdherent() const {return numAdherent;}

Biblio* Adherent::getBiblio() const {return biblio;}

Liste<Livre*> Adherent::getLivresEmpruntes() const {return livresEmpruntes;}

int Adherent::getNbLivresEmpruntes() const {return livresEmpruntes.getTaille();}

int Adherent::getNbMaxEmprunt() const {return nbMaxEmprunt;}

int Adherent::getNbAdherents(){return nbAdherents;}

// Setters
void Adherent::setNom(string nm){nom = nm;}

void Adherent::setPrenom(string pnm){prenom = pnm;}

void Adherent::setAdresse(string adr){adresse = adr;}

void Adherent::setNumAdherent(int numAdh){numAdherent = numAdh;}

void Adherent::setBiblio(Biblio* bib){biblio = bib;}

void Adherent::setNbMaxEmprunt(int max){nbMaxEmprunt = max;}

// Affichage
void Adherent::afficher() const {
    cout << "=== Information de l'adherent ===" << endl;
    cout << "Nom : " << nom << ", Prenom : " << prenom << endl;
    cout << "Numero d'adherent : " << numAdherent << endl;
    if(biblio != nullptr){
        cout << "Bibliotheque : " << biblio->getNom() << endl;
    }
    cout << "Nombre de livres empruntes : " << getNbLivresEmpruntes();
    cout << ", Maximum d'emprunts autorises : " << nbMaxEmprunt << endl; 
}

void Adherent::afficherLivresEmpruntes() const {
    cout << "=== Liste des livres empruntes ===" << endl;
    if(livresEmpruntes.getTaille() == 0){
        cout << "Aucun livre emprunte" << endl;
        return;
    }
    Noeud<Livre*>* courant = livresEmpruntes.getTete();
    int i = 1;
    while(courant != nullptr){
        cout << i << ". " << courant->getInfo()->getTitre() << endl;
        courant = courant->getSuivant();
        i++;
    }
}

// Méthodes 
bool Adherent::peutEmprunter() const {
    return getNbLivresEmpruntes() < nbMaxEmprunt;
}

bool Adherent::emprunterLivre(const string& codeLivre){
    if(!peutEmprunter()) return false;
    if(biblio == nullptr) return false;
    
    Livre* livre = biblio->chercherLivre(codeLivre);
    if(livre == nullptr) return false;
    if(livre->getEtat() != libre) return false;
    
    livre->setEtat(emprunte);
    livresEmpruntes.insererFin(livre);
    return true;
}

bool Adherent::rendreLivre(const string& codeLivre){
    Noeud<Livre*>* courant = livresEmpruntes.getTete();
    while(courant != nullptr){
        if(courant->getInfo()->getCode() == codeLivre){
            Livre* livre = courant->getInfo();
            livre->setEtat(libre);
            livresEmpruntes.supprimer(livre);
            return true;
        }
        courant = courant->getSuivant();
    }
    return false;
}