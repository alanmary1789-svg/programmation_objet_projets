// heure.h
#ifndef HEURE_H
#define HEURE_H

class Heure {

private:
    int heure;
    int minute;

public:
    // Constructeur par défaut
    Heure();

    // Constructeur avec deux valeurs
    Heure(int h, int m);

    // Méthode d'affichage
    void affiche();

    // Getters
    int getHeure();
    int getMinute();

    // Setters
    void setHeure(int h);
    void setMinute(int m);
};

#endif // HEURE_H