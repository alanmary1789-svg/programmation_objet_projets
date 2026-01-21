#ifndef ADHERENT_H
#define ADHERENT_H

#include "Biblio.h"
#include "Livre.h"
#include "Liste.h"
#include <string>
#include <iostream>

using namespace std;

class Adherent{
    private:
        string nom;
        string prenom;
        string adresse;
        int numAdherent;
        Biblio* biblio;
        Liste<Livre*> livresEmpruntes;  // Objet Liste, pas un pointeur
        int nbMaxEmprunt;
        static int nbAdherents;
    
    public:
        //Constructeurs
        Adherent(string nm = "", string pnm = "", string adr = "", int numAdh = -1, Biblio* bib = nullptr, int max = 5);
        Adherent(const Adherent& adherent);
        
        //Destructeur
        ~Adherent();

        //Getters
        string getNom() const;
        string getPrenom() const;
        string getAdresse() const;
        int getNumAdherent() const;
        Biblio* getBiblio() const;
        Liste<Livre*> getLivresEmpruntes() const;
        int getNbLivresEmpruntes() const;
        int getNbMaxEmprunt() const;
        static int getNbAdherents();

        //Setters
        void setNom(string nm);
        void setPrenom(string pnm);
        void setAdresse(string adr);
        void setNumAdherent(int numAdh);
        void setBiblio(Biblio* bib);
        void setNbMaxEmprunt(int max);
        
        //Affichage
        void afficher() const;
        void afficherLivresEmpruntes() const;

        //Méthodes
        bool peutEmprunter() const;
        bool emprunterLivre(const string& codeLivre);
        bool rendreLivre(const string& codeLivre);
};

#endif