#ifndef AGENDAORDONNE_H
#define AGENDAORDONNE_H

#include "NoeudRDV.h"

class AgendaOrdonne {
private:
    NoeudRDV* premier;
    
public:
    AgendaOrdonne();
    AgendaOrdonne(const AgendaOrdonne& a);
    ~AgendaOrdonne();
    
    void ajoute(const RDV& r);
    void enleve(const RDV& r);
    void affiche() const;
    bool estVide() const;
};

#endif