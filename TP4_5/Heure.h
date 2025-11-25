#ifndef HEURE_H
#define HEURE_H

class Heure {
private:
    int heures;
    int minutes;
    
public:
    Heure();
    Heure(int h, int m);
    
    void affiche() const;
    
    int getHeures() const;
    int getMinutes() const;
    
    void setHeures(int h);
    void setMinutes(int m);
    
    bool estEgal(const Heure& h) const;
    bool estSuperieur(const Heure& h) const;
};

#endif