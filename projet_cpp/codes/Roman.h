#ifndef ROMAN_H
#define ROMAN_H

#include "Livre.h"
#include <string>
#include <iostream>

using namespace std;

enum Genre{
    defaut = -1,
    litterature = 0,
    noir = 1,
    animalier = 2,
    amour = 3,
    moeurs = 4,
    gothique = 5,
    courtois = 6,
    epistolaire = 7,
    feuilleton = 8,
    graphique = 9,
    historique = 10,
    photo = 11,
    picaresque = 12,
    memoire = 13,
    populaire = 14,
    aventure = 15,
    anticipation = 16,
    espionnage = 17,
    apprentissage = 18,
    chevalerie = 19,
    autobiographique = 20,
    nouveau_roman = 21,
    chevaleresque = 22, 
    conte = 23,
    nouvelle = 24
};

class Roman : public Livre{
    private:
        Genre genre;
    
    public:
    //Constructeur
    Roman(string c = "", string a = "", string t = "", string e = "", string is = "", Etat et = libre, Public pub = tout_public,
        Genre g = defaut);
    Roman(const Roman& roman);

    //Getters
    Genre getGenre() const;

    //Setters
    void setGenre(Genre g);

    //Affichage
    void afficher() const;
};

#endif 