// date.h
#ifndef DATE_H
#define DATE_H

class Date {

private:
    // Attributs privés (encapsulation) [cite: 256, 281]
    int jour;
    int mois;
    int annee;

    // Méthode privée pour la validation, comme demandé
    bool checkDate(int j, int m, int a);

public:
    // Constructeur avec valeurs par défaut 
    // Par défaut, j=1, m=1, a=2000
    Date(int j = 1, int m = 1, int a = 2000);

    // Méthode d'affichage 
    void affiche();

    // Getters
    int getJour();
    int getMois();
    int getAnnee();

    // Setters 
    void setJour(int j);
    void setMois(int m);
    void setAnnee(int a);
};

#endif // DATE_H