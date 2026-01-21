#ifndef LISTE_H
#define LISTE_H

#include "Noeud.h"
#include <iostream>
#include <string>

using namespace std;

template <typename T>
class Liste{
    private:
        Noeud<T>* tete;
        int taille;
    
    public:
    //Constructeur
    Liste();
    Liste(const Liste<T>& l);

    //Destructeur 
    ~Liste();

    //Opérateur 
    Liste<T>& operator=(const Liste<T>& l);
    Liste<T> operator+(const Liste<T>& l) const;

    //Getters 
    Noeud<T>* getTete() const;
    int getTaille() const;

    //Setters
    void setTete(Noeud<T>* t);
    void setTaille(int n);

    //Méthodes 
    void insererDebut(T valeur);
    void insererFin(T valeur);
    void inserer(T valeur, int i);

    bool supprimerDebut();
    bool supprimerFin();
    bool supprimer(T valeur);
    void vider();

    Noeud<T>* rechercher(T val) const;
    T getElement(int i) const;
    bool contient(T val) const;

    //Affichage
    void afficher();

    //Copie 
    void copierListe(const Liste<T>& l);

};


//Constructeur
template <typename T>
Liste<T>::Liste(){tete = nullptr; taille = 0;}

template <typename T>
Liste<T>::Liste(const Liste<T>& l){tete = nullptr; taille = 0; copierListe(l);}

//Destructeur
template <typename T>
Liste<T>::~Liste(){vider();};

//Opérateurs
template <typename T>
Liste<T>& Liste<T>::operator=(const Liste<T>& l){
    if(this != &l){
        copierListe(l);
    }
    return *this;
}

template <typename T>
Liste<T> Liste<T>::operator+(const Liste<T>& l) const {
    Liste<T> resultat(*this);  // Copie de la liste actuelle
    Noeud<T>* courant = l.tete;
    while(courant != nullptr){
        resultat.insererFin(courant->getInfo());
        courant = courant->getSuivant();
    }
    return resultat;
}

//Getters
template <typename T>
Noeud<T>* Liste<T>::getTete() const {return tete;}

template <typename T>
int Liste<T>::getTaille() const {return taille;}

//Setters
template <typename T>
void Liste<T>::setTete(Noeud<T>* t){tete = t;}

template <typename T>
void Liste<T>::setTaille(int n){taille = n;}

//Méthodes
template <typename T>
void Liste<T>::insererDebut(T valeur){
    Noeud<T>* nouveau = new Noeud<T>(valeur);
    nouveau -> setSuivant(tete);
    tete = nouveau;
    taille++;
}

template <typename T>
void Liste<T>::insererFin(T valeur){
    Noeud<T>* nouveau = new Noeud<T>(valeur);
    if(tete == nullptr){tete = nouveau;}
    else{
        Noeud<T>* courant = tete;
        while(courant -> getSuivant() != nullptr){courant = courant -> getSuivant();};
        courant -> setSuivant(nouveau);
    };
    taille++;
}

template <typename T>
void Liste<T>::inserer(T valeur, int i){
    if(i < 0 || i > taille){cout <<  "Erreur : Indice hors limite" << endl; return;}
    if(i == 0){insererDebut(valeur); return;}
    if(i == taille){insererFin(valeur); return;}

    Noeud<T>* nouveau = new Noeud<T>(valeur);
    Noeud<T>* courant = tete;

    for(int k = 0; k < i-1; k++){
        courant = courant -> getSuivant();
    };

    nouveau -> setSuivant(courant -> getSuivant());
    courant -> setSuivant(nouveau);
    taille++;    
}

template <typename T>
bool Liste<T>::supprimerDebut(){
    if(tete == nullptr){return false;}
    
    Noeud<T>* aSupprimer = tete; 
    tete = tete -> getSuivant(); 
    delete aSupprimer; 
    taille--;
    return true;
}

template <typename T>
bool Liste<T>::supprimerFin(){
    //Cas liste nulle
    if(tete == nullptr){return false;}

    //Cas liste à un élément
    if(tete -> getSuivant() == nullptr){delete tete; tete = nullptr; taille--; return true;}
    Noeud<T>* courant = tete;

    //Cas général 
    while(courant -> getSuivant() -> getSuivant() != nullptr){courant = courant -> getSuivant();};
    delete (courant -> getSuivant());
    courant -> setSuivant(nullptr);
    taille--;
    return true;
}

template <typename T>
bool Liste<T>::supprimer(T valeur){
    if(tete == nullptr){return false;}

    if(tete -> getInfo() == valeur){return supprimerDebut();}
    
    Noeud<T>* courant = tete;
    Noeud<T>* suivant = courant -> getSuivant();
    while(suivant != nullptr){
        if(suivant -> getInfo() == valeur){
            courant -> setSuivant(suivant -> getSuivant());
            delete suivant; taille--;
            return true;
        }
        courant = suivant;
        suivant = suivant -> getSuivant();
    }
    return false;
}


template <typename T>
void Liste<T>::vider(){
    while(tete != nullptr){
        Noeud<T>* aSupprimer = tete; tete = tete -> getSuivant(); 
        delete aSupprimer;
    }
    taille = 0;
}

template <typename T>
Noeud<T>* Liste<T>::rechercher(T val) const {
    Noeud<T>* courant = tete;
    while(courant != nullptr){
        if(courant -> getInfo() == val){return courant;}
        courant = courant -> getSuivant();
    }
    return nullptr;
}

template <typename T>
T Liste<T>::getElement(int i) const {
    if(i < 0 || i > taille){cout << "Erreur : Indice hors limite" << endl;}
    
    Noeud<T>* courant = tete; 
    for(int k = 0; k < i; k++){courant = courant -> getSuivant();}
    return courant -> getInfo();
}

template <typename T>
bool Liste<T>::contient(T val) const {
    Noeud<T>* courant = tete;
    while(courant != nullptr){
        if(courant -> getInfo() == val){return true;};
        courant = courant -> getSuivant();
    }
    return false;
}

//Méthode de copie
template <typename T>
void Liste<T>::copierListe(const Liste<T>& l){
    vider();
    Noeud<T>* courant = l.tete;
    while(courant != nullptr){insererFin(courant -> getInfo()); courant = courant -> getSuivant();}
}

//Affichage
template <typename T>
void Liste<T>::afficher(){cout << *this;}

#endif