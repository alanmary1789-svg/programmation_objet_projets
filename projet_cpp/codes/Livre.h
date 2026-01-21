#ifndef LIVRE_H
#define LIVRE_H

#include <string>
#include <iostream>

class Biblio;

using namespace std;

//Enumerations
enum Etat{libre = 0, emprunte = 1, prete = 2}; //recu si le livre est 

enum Public{ados = 0, jeunesse = 1, tout_public = 2, adulte = 3};

class Livre{
    private:
        string code;
        string auteur;
        string titre;
        string editeur;
        string isbn;
        Etat etat;
        Public audience;
        Biblio* proprietaire; 
    
    public:
        //Constructeurs
        Livre(string c = "", string a = "", string t = "", string e = "", string is = "", Etat et = libre, Public pub = tout_public, Biblio* biblio = nullptr);
        Livre(const Livre& livre);

        //Getters 
        string getCode() const;
        string getAuteur() const;
        string getTitre() const;
        string getEditeur() const;
        string getIsbn() const;
        Etat getEtat() const;
        Public getPublic() const;
        Biblio* getProprio() const;  // IMPORTANCE CRUCIALE


        //Setters
        void setCode(string c);
        void setAuteur(string a);
        void setTitre(string t);
        void setEditeur(string e);
        void setIsbn(string is);
        void setEtat(Etat et);
        void setPublic(Public pub);
        void setProprio(Biblio* biblio);

        //Affichage
        void afficher() const;

        //Méthodes
        bool emprunter(); // verifie si le livre est emprunté
        bool rendre(); //verifie l'état du livre pour le rendre
        bool estdispo_emprunt(Biblio* biblio) const; 


};

#endif 