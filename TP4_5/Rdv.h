#ifndef RDV_H
#define RDV_H

#include "Date.h"
#include "Heure.h"
#include <string>
using namespace std;

class RDV {
private:
    Date date;
    Heure heure;
    string lieu;
    int nombreDeParticipants;
    string* participants;
    int capaciteMax;
    
public:
    RDV();
    RDV(const RDV& r);
    ~RDV();
    
    void affiche() const;
    void saisieParticipants();
    void saisieLieu();
    void saisie();
    
    void setDate(const Date& dateRdv);
    void setHeure(const Heure& heureRdv);
    void setLieu(const string& lieuRdv);
    void setNombreDeParticipants(int nombreDeParticipants);
    void setParticipants(string* ps);
    void setParticipant(int i, string s);
    
    Date getDate() const;
    Heure getHeure() const;
    string getLieu() const;
    int getNombreDeParticipants() const;
    
    bool estCompatibleAvec(const RDV& r) const;
    bool estEgal(const RDV& r) const;
    bool estSuperieur(const RDV& r) const;
};

#endif