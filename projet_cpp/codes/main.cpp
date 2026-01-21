#include <iostream>
#include <string>

#include "Livre.h"
#include "Roman.h"
#include "BD.h"
#include "Theatre.h"
#include "Recueil.h"
#include "Album.h"
#include "Biblio.h"
#include "Adherent.h"

using namespace std;

// Fonction utilitaire pour afficher un séparateur
void separateur(const string& titre) {
    cout << "\n========================================" << endl;
    cout << "  " << titre << endl;
    cout << "========================================\n" << endl;
}

int main() {
    
    // ============================================
    // TEST 1 : Création des bibliothèques
    // ============================================
    separateur("TEST 1 : Creation des bibliotheques");
    
    Biblio biblio1("Bibliotheque Centrale", "10 rue des Livres", "BIB001");
    Biblio biblio2("Bibliotheque du Quartier", "25 avenue de la Lecture", "BIB002");
    
    cout << "Bibliotheque 1 : " << biblio1.getNom() << " - Code : " << biblio1.getCode() << endl;
    cout << "Bibliotheque 2 : " << biblio2.getNom() << " - Code : " << biblio2.getCode() << endl;
    
    // ============================================
    // TEST 2 : Création et achat de livres
    // ============================================
    separateur("TEST 2 : Creation et achat de livres");
    
    // Création de différents types de livres
    Roman* roman1 = new Roman("R001", "Victor Hugo", "Les Miserables", "Hachette", "978-2-01-001", libre, tout_public, litterature);
    Roman* roman2 = new Roman("R002", "Albert Camus", "L'Etranger", "Gallimard", "978-2-07-002", libre, adulte, litterature);
    
    BD* bd1 = new BD("BD001", "Goscinny", "Asterix le Gaulois", "Dargaud", "978-2-205-001", libre, tout_public, "Uderzo");
    BD* bd2 = new BD("BD002", "Herge", "Tintin au Tibet", "Casterman", "978-2-203-001", libre, jeunesse, "Herge");
    
    Theatre* theatre1 = new Theatre("TH001", "Moliere", "Le Malade Imaginaire", "Flammarion", "978-2-08-001", libre, tout_public, 17);
    
    Recueil* poesie1 = new Recueil("PO001", "Baudelaire", "Les Fleurs du Mal", "Gallimard", "978-2-07-003", libre, adulte, true, false);
    
    Album* album1 = new Album("AL001", "Collectif", "La Nature en Images", "National Geographic", "978-1-426-001", libre, tout_public, false, true);
    
    // Achat des livres par la bibliothèque 1
    cout << "Achat de livres pour " << biblio1.getNom() << " :" << endl;
    
    if(biblio1.acheterLivre(roman1)) cout << "  - Roman 'Les Miserables' achete" << endl;
    if(biblio1.acheterLivre(roman2)) cout << "  - Roman 'L'Etranger' achete" << endl;
    if(biblio1.acheterLivre(bd1)) cout << "  - BD 'Asterix le Gaulois' achetee" << endl;
    if(biblio1.acheterLivre(theatre1)) cout << "  - Theatre 'Le Malade Imaginaire' achete" << endl;
    if(biblio1.acheterLivre(poesie1)) cout << "  - Poesie 'Les Fleurs du Mal' achete" << endl;
    
    // Achat des livres par la bibliothèque 2
    cout << "\nAchat de livres pour " << biblio2.getNom() << " :" << endl;
    
    if(biblio2.acheterLivre(bd2)) cout << "  - BD 'Tintin au Tibet' achetee" << endl;
    if(biblio2.acheterLivre(album1)) cout << "  - Album 'La Nature en Images' achete" << endl;
    
    cout << "\nNombre de livres dans " << biblio1.getNom() << " : " << biblio1.getListe().getTaille() << endl;
    cout << "Nombre de livres dans " << biblio2.getNom() << " : " << biblio2.getListe().getTaille() << endl;
    
    // ============================================
    // TEST 3 : Recherche de livres
    // ============================================
    separateur("TEST 3 : Recherche de livres");
    
    Livre* livreRecherche = biblio1.chercherLivre("R001");
    if(livreRecherche != nullptr) {
        cout << "Livre trouve par code 'R001' : " << livreRecherche->getTitre() << endl;
    }
    
    livreRecherche = biblio1.chercherLivre_IBSN("978-2-07-002");
    if(livreRecherche != nullptr) {
        cout << "Livre trouve par ISBN '978-2-07-002' : " << livreRecherche->getTitre() << endl;
    }
    
    livreRecherche = biblio1.chercherLivre("INEXISTANT");
    if(livreRecherche == nullptr) {
        cout << "Livre 'INEXISTANT' non trouve (normal)" << endl;
    }
    
    // ============================================
    // TEST 4 : Création des adhérents
    // ============================================
    separateur("TEST 4 : Creation des adherents");
    
    Adherent adherent1("Dupont", "Jean", "5 rue de Paris", 1001, &biblio1, 3);
    Adherent adherent2("Martin", "Marie", "12 avenue Victor Hugo", 1002, &biblio1, 5);
    Adherent adherent3("Bernard", "Pierre", "8 boulevard Voltaire", 2001, &biblio2, 3);
    
    cout << "Adherent 1 : " << adherent1.getNom() << " " << adherent1.getPrenom();
    cout << " - Bibliotheque : " << adherent1.getBiblio()->getNom() << endl;
    
    cout << "Adherent 2 : " << adherent2.getNom() << " " << adherent2.getPrenom();
    cout << " - Bibliotheque : " << adherent2.getBiblio()->getNom() << endl;
    
    cout << "Adherent 3 : " << adherent3.getNom() << " " << adherent3.getPrenom();
    cout << " - Bibliotheque : " << adherent3.getBiblio()->getNom() << endl;
    
    cout << "\nNombre total d'adherents : " << Adherent::getNbAdherents() << endl;
    
    // ============================================
    // TEST 5 : Emprunt de livres par les adhérents
    // ============================================
    separateur("TEST 5 : Emprunt de livres");
    
    cout << "Adherent 1 peut emprunter : " << (adherent1.peutEmprunter() ? "Oui" : "Non") << endl;
    
    cout << "\nEmprunts par " << adherent1.getNom() << " :" << endl;
    if(adherent1.emprunterLivre("R001")) {
        cout << "  - 'Les Miserables' emprunte avec succes" << endl;
    }
    if(adherent1.emprunterLivre("BD001")) {
        cout << "  - 'Asterix le Gaulois' emprunte avec succes" << endl;
    }
    
    cout << "\nEmprunts par " << adherent2.getNom() << " :" << endl;
    if(adherent2.emprunterLivre("R002")) {
        cout << "  - 'L'Etranger' emprunte avec succes" << endl;
    }
    
    // Test : essayer d'emprunter un livre déjà emprunté
    cout << "\nTest emprunt d'un livre deja emprunte :" << endl;
    if(!adherent2.emprunterLivre("R001")) {
        cout << "  - Impossible d'emprunter 'Les Miserables' (deja emprunte) - OK" << endl;
    }
    
    // Afficher les livres empruntés
    cout << "\n";
    adherent1.afficherLivresEmpruntes();
    
    cout << "\nNombre de livres empruntes par " << adherent1.getNom() << " : " << adherent1.getNbLivresEmpruntes() << endl;
    cout << "Maximum autorise : " << adherent1.getNbMaxEmprunt() << endl;
    
    // ============================================
    // TEST 6 : Test de la limite d'emprunt
    // ============================================
    separateur("TEST 6 : Test limite d'emprunt");
    
    cout << adherent1.getNom() << " a deja " << adherent1.getNbLivresEmpruntes() << " livres (max " << adherent1.getNbMaxEmprunt() << ")" << endl;
    
    if(adherent1.emprunterLivre("TH001")) {
        cout << "  - 'Le Malade Imaginaire' emprunte (3eme livre)" << endl;
    }
    
    // Maintenant adherent1 a atteint sa limite
    cout << "\nAdherent 1 peut encore emprunter : " << (adherent1.peutEmprunter() ? "Oui" : "Non") << endl;
    
    if(!adherent1.emprunterLivre("PO001")) {
        cout << "  - Impossible d'emprunter 'Les Fleurs du Mal' (limite atteinte) - OK" << endl;
    }
    
    // ============================================
    // TEST 7 : Retour de livres
    // ============================================
    separateur("TEST 7 : Retour de livres");
    
    cout << "Avant retour - Livres empruntes par " << adherent1.getNom() << " : " << adherent1.getNbLivresEmpruntes() << endl;
    
    if(adherent1.rendreLivre("R001")) {
        cout << "  - 'Les Miserables' rendu avec succes" << endl;
    }
    
    cout << "Apres retour - Livres empruntes par " << adherent1.getNom() << " : " << adherent1.getNbLivresEmpruntes() << endl;
    
    // Vérifier que le livre est de nouveau disponible
    Livre* livreRendu = biblio1.chercherLivre("R001");
    cout << "\nEtat du livre 'Les Miserables' : " << livreRendu->getEtat() << " (0 = libre)" << endl;
    
    // Maintenant adherent1 peut à nouveau emprunter
    cout << "\nAdherent 1 peut emprunter : " << (adherent1.peutEmprunter() ? "Oui" : "Non") << endl;
    
    // ============================================
    // TEST 8 : Prêt inter-bibliothèques
    // ============================================
    separateur("TEST 8 : Pret inter-bibliotheques");
    
    cout << "Livre 'Les Fleurs du Mal' dans " << biblio1.getNom() << endl;
    Livre* livrePret = biblio1.chercherLivre("PO001");
    cout << "  - Etat initial : " << livrePret->getEtat() << " (0 = libre)" << endl;
    cout << "  - Proprietaire : " << livrePret->getProprio()->getNom() << endl;
    
    // Biblio2 demande un livre à Biblio1
    cout << "\n" << biblio2.getNom() << " demande 'Les Fleurs du Mal' a " << biblio1.getNom() << endl;
    if(biblio1.preterLivre("PO001", &biblio2)) {
        cout << "  - Pret effectue avec succes" << endl;
    }
    
    cout << "\nApres le pret :" << endl;
    cout << "  - Etat du livre : " << livrePret->getEtat() << " (2 = prete)" << endl;
    cout << "  - Proprietaire reste : " << livrePret->getProprio()->getNom() << endl;
    cout << "  - Livre present dans " << biblio2.getNom() << " : ";
    cout << (biblio2.chercherLivre("PO001") != nullptr ? "Oui" : "Non") << endl;
    
    // ============================================
    // TEST 9 : Emprunt d'un livre prêté
    // ============================================
    separateur("TEST 9 : Emprunt d'un livre prete");
    
    // Un adhérent de biblio1 ne peut pas emprunter un livre prêté
    cout << adherent1.getNom() << " (de " << biblio1.getNom() << ") essaie d'emprunter 'Les Fleurs du Mal' :" << endl;
    if(!adherent1.emprunterLivre("PO001")) {
        cout << "  - Impossible (livre prete a une autre bibliotheque) - OK" << endl;
    }
    
    // Un adhérent de biblio2 peut emprunter ce livre
    cout << "\n" << adherent3.getNom() << " (de " << biblio2.getNom() << ") essaie d'emprunter 'Les Fleurs du Mal' :" << endl;
    if(adherent3.emprunterLivre("PO001")) {
        cout << "  - Emprunt reussi" << endl;
    } else {
        cout << "  - Emprunt echoue (le livre est prete mais pas dans sa bibliotheque d'origine)" << endl;
    }
    
    // ============================================
    // TEST 10 : Retour d'un livre prêté entre bibliothèques
    // ============================================
    separateur("TEST 10 : Retour pret inter-bibliotheques");
    
    cout << "Avant retour :" << endl;
    cout << "  - Livres dans " << biblio2.getNom() << " : " << biblio2.getListe().getTaille() << endl;
    
    if(biblio2.rendreLivre("PO001")) {
        cout << "\n" << biblio2.getNom() << " rend 'Les Fleurs du Mal' a " << biblio1.getNom() << endl;
    }
    
    cout << "\nApres retour :" << endl;
    cout << "  - Etat du livre : " << livrePret->getEtat() << " (0 = libre)" << endl;
    cout << "  - Livres dans " << biblio2.getNom() << " : " << biblio2.getListe().getTaille() << endl;
    
    // ============================================
    // TEST 11 : Affichage des informations
    // ============================================
    separateur("TEST 11 : Affichage complet");
    
    cout << "--- Informations Adherent 1 ---" << endl;
    adherent1.afficher();
    cout << endl;
    adherent1.afficherLivresEmpruntes();
    
    cout << "\n--- Informations d'un livre ---" << endl;
    roman1->afficher();
    cout << endl;
    
    // ============================================
    // TEST 12 : Polymorphisme
    // ============================================
    separateur("TEST 12 : Test du polymorphisme");
    
    cout << "Affichage polymorphe des differents types de livres :" << endl;
    cout << "\n--- Roman ---" << endl;
    Livre* ptrLivre = biblio1.chercherLivre("R001");
    if(ptrLivre) ptrLivre->afficher();
    
    cout << "\n\n--- BD ---" << endl;
    ptrLivre = biblio1.chercherLivre("BD001");
    if(ptrLivre) ptrLivre->afficher();
    
    cout << "\n\n--- Theatre ---" << endl;
    ptrLivre = biblio1.chercherLivre("TH001");
    if(ptrLivre) ptrLivre->afficher();
    
    // ============================================
    // FIN DES TESTS
    // ============================================
    separateur("FIN DES TESTS");
    
    cout << "Tous les tests sont termines." << endl;
    cout << "Nombre total d'adherents : " << Adherent::getNbAdherents() << endl;
    
    // Note : Les destructeurs des bibliothèques vont supprimer les livres
    // dont elles sont propriétaires
    
    return 0;
}