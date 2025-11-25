#include "NoeudRDV.h"

NoeudRDV::NoeudRDV(const RDV& r) : rdv(r), suivant(nullptr) {}

NoeudRDV::NoeudRDV(const RDV& r, NoeudRDV* suiv) : rdv(r), suivant(suiv) {}

RDV NoeudRDV::getRdv() const {
    return rdv;
}

NoeudRDV* NoeudRDV::getSuivant() const {
    return suivant;
}

void NoeudRDV::setRdv(const RDV& r) {
    rdv = r;
}

void NoeudRDV::setSuivant(NoeudRDV* suiv) {
    suivant = suiv;
}