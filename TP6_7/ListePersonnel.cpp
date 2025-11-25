#include "ListePersonnel.h"
#include <iostream>
using namespace std;

// Constructeur : initialisation à la liste vide avec allocation dynamique
ListePersonnel::ListePersonnel(int tailleInitiale) {
    taille = tailleInitiale;
    nb = 0;
    tab = new Personnel*[taille];
    for (int i = 0; i < taille; i++) {
        tab[i] = nullptr;
    }
}

// Destructeur
ListePersonnel::~ListePersonnel() {
    delete[] tab;
}

// Méthode privée pour doubler la taille du tableau
void ListePersonnel::doubleTableau() {
    int nouvelleTaille = taille * 2;
    Personnel** nouveauTab = new Personnel*[nouvelleTaille];
    
    // Copier les pointeurs existants
    for (int i = 0; i < nb; i++) {
        nouveauTab[i] = tab[i];
    }
    
    // Initialiser les nouvelles cases
    for (int i = nb; i < nouvelleTaille; i++) {
        nouveauTab[i] = nullptr;
    }
    
    // Libérer l'ancien tableau et mettre à jour
    delete[] tab;
    tab = nouveauTab;
    taille = nouvelleTaille;
    
    cout << "Tableau double, nouvelle taille: " << taille << endl;
}

// Ajoute un personnel à la liste
void ListePersonnel::ajoutPersonnel(Personnel* ptPersonnel) {
    if (nb >= taille) {
        doubleTableau();
    }
    tab[nb] = ptPersonnel;
    nb++;
}

// Affiche les noms et les salaires de tous les éléments de la liste
void ListePersonnel::afficherSalaires() {
    cout << "=== Liste des salaires ===" << endl;
    for (int i = 0; i < nb; i++) {
        cout << "Nom: " << tab[i]->getNom() 
             << " " << tab[i]->getPrenom() 
             << " - Salaire: " << tab[i]->calculSalaire() << endl;
    }
}