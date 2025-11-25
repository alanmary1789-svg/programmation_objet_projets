#ifndef LISTEPERSONNEL_H
#define LISTEPERSONNEL_H

#include "Personnel.h"

class ListePersonnel {
private:
    Personnel** tab;
    int nb;
    int taille;

public:
    // Constructeur : initialisation à la liste vide avec taille initiale
    ListePersonnel(int tailleInitiale = 10);
    
    // Destructeur
    ~ListePersonnel();
    
    // Ajoute un personnel à la liste
    void ajoutPersonnel(Personnel* ptPersonnel);
    
    // Affiche les noms et les salaires de tous les éléments de la liste
    void afficherSalaires();
    
    // Méthode privée pour doubler le tableau
private:
    void doubleTableau();
};

#endif