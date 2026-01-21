#ifndef NOEUD_H
#define NOEUD_H

#include <iostream>

using namespace std;

template <typename T>

class Noeud{
    private: 
        T info;
        Noeud<T>* suivant;

    public:
    //Constructeur 
    Noeud();
    Noeud(T valeur);
    Noeud(const Noeud<T>& noeud);

    //Destructeur
    ~Noeud();

    //Opérateur
    Noeud<T>& operator = (const Noeud<T>& noeud);

    //Getters
    T getInfo() const;
    Noeud<T>* getSuivant() const ;

    //Setters
    void setInfo(T inf);
    void setSuivant(Noeud<T>* next);

};


//Constructeur
template <typename T>
Noeud<T>::Noeud(){suivant = nullptr;}

template <typename T>
Noeud<T>::Noeud(T valeur){info = valeur; suivant = nullptr;}

template <typename T>
Noeud<T>::Noeud(const Noeud<T>& next){info = next.info; suivant = next.suivant;}

//Destructeur
template <typename T>
Noeud<T>::~Noeud(){suivant = nullptr;}

//Opérateur
template <typename T>
Noeud<T>& Noeud<T>::operator = (const Noeud<T>& noeud){if(this != &noeud){info = noeud.info;}; return *this;}


//Getters
template <typename T>
T Noeud<T>::getInfo() const {return info;}

template <typename T>
Noeud<T>* Noeud<T>::getSuivant() const {return suivant;}

//Setters
template <typename T>
void Noeud<T>::setInfo(T valeur){info = valeur;}

template <typename T>
void Noeud<T>::setSuivant(Noeud<T>* next){suivant = next;}

#endif