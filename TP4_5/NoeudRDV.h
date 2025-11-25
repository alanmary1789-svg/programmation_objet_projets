#ifndef NOEUDRDV_H
#define NOEUDRDV_H

#include "Rdv.h"

class NoeudRDV {
private:
    RDV rdv;
    NoeudRDV* suivant;
    
public:
    NoeudRDV(const RDV& r);
    NoeudRDV(const RDV& r, NoeudRDV* suiv);
    
    RDV getRdv() const;
    NoeudRDV* getSuivant() const;
    
    void setRdv(const RDV& r);
    void setSuivant(NoeudRDV* suiv);
};

#endif