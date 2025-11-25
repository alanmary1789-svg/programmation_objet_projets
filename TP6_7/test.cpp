#include <iostream>
#include "Personne.h"
#include "Eleve.h"
#include "Personnel.h"
#include "PersonnelAdmin.h"
#include "EnseignantPermanent.h"
#include "EnseignantVacataire.h"
#include "ListePersonnel.h"

using namespace std;

int main() {
    cout << "========================================" << endl;
    cout << "TEST DES CLASSES" << endl;
    cout << "========================================" << endl << endl;
    
    // Test Classe Personne
    cout << "--- Test Classe Personne ---" << endl;
    Personne pers1("Dupont", "Jean", "10 rue de Paris", "0601020304");
    pers1.affiche();
    cout << endl;
    
    Personne pers2("Martin", "Marie");
    pers2.affiche();
    cout << endl;
    
    // Test Classe Eleve
    cout << "--- Test Classe Eleve ---" << endl;
    Eleve eleve1("Durand", "Pierre", "5 avenue Victor Hugo", "0612345678", 
                 "2024", 15.5, "TD1");
    eleve1.affiche();
    cout << endl;
    
    Eleve eleve2("Bernard", "Sophie", "", "", "2025", 16.2, "TD2");
    eleve2.affiche();
    cout << endl;
    
    // Test Classe PersonnelAdmin
    cout << "--- Test Classe PersonnelAdmin ---" << endl;
    PersonnelAdmin* admin1 = new PersonnelAdmin("Lefebvre", "Paul", 
                                                 "8 rue Nationale", "0623456789",
                                                 2500.0, 10, 15.0);
    admin1->affiche();
    cout << "Salaire calcule: " << admin1->calculSalaire() << endl;
    cout << endl;
    
    PersonnelAdmin* admin2 = new PersonnelAdmin("Moreau", "Claire",
                                                 "12 boulevard Voltaire", "0634567890",
                                                 2800.0, 5, 20.0);
    admin2->affiche();
    cout << "Salaire calcule: " << admin2->calculSalaire() << endl;
    cout << endl;
    
    // Test Classe EnseignantPermanent
    cout << "--- Test Classe EnseignantPermanent ---" << endl;
    EnseignantPermanent* ensP1 = new EnseignantPermanent("Rousseau", "Marc",
                                                          "20 rue Gambetta", "0645678901",
                                                          3500.0, "B201", 5, 500.0);
    ensP1->affiche();
    cout << "Salaire calcule: " << ensP1->calculSalaire() << endl;
    cout << endl;
    
    EnseignantPermanent* ensP2 = new EnseignantPermanent("Simon", "Lucie",
                                                          "15 place de la République", "0656789012",
                                                          4000.0, "C305", 8, 600.0);
    ensP2->affiche();
    cout << "Salaire calcule: " << ensP2->calculSalaire() << endl;
    cout << endl;
    
    // Test Classe EnseignantVacataire
    cout << "--- Test Classe EnseignantVacataire ---" << endl;
    EnseignantVacataire* ensV1 = new EnseignantVacataire("Laurent", "Thomas",
                                                          "25 rue de la Liberté", "0667890123",
                                                          0.0, "Casier12", 40, 45.0);
    ensV1->affiche();
    cout << "Salaire calcule: " << ensV1->calculSalaire() << endl;
    cout << endl;
    
    EnseignantVacataire* ensV2 = new EnseignantVacataire("Petit", "Emma",
                                                          "18 avenue Jean Jaurès", "0678901234",
                                                          0.0, "Casier8", 35, 50.0);
    ensV2->affiche();
    cout << "Salaire calcule: " << ensV2->calculSalaire() << endl;
    cout << endl;
    
    // Test ListePersonnel avec polymorphisme
    cout << "========================================" << endl;
    cout << "TEST LISTEPERSONNEL ET POLYMORPHISME" << endl;
    cout << "========================================" << endl << endl;
    
    ListePersonnel liste;
    
    // Ajout des employés à la liste
    liste.ajoutPersonnel(admin1);
    liste.ajoutPersonnel(admin2);
    liste.ajoutPersonnel(ensP1);
    liste.ajoutPersonnel(ensP2);
    liste.ajoutPersonnel(ensV1);
    liste.ajoutPersonnel(ensV2);
    
    // Affichage des salaires via polymorphisme
    liste.afficherSalaires();
    cout << endl;
    
    // Test avec ajouts supplémentaires pour tester le doublement du tableau
    cout << "--- Test doublement automatique du tableau ---" << endl;
    for (int i = 0; i < 8; i++) {
        PersonnelAdmin* temp = new PersonnelAdmin("Test", "Employe" + to_string(i),
                                                   "", "", 2000.0, 0, 0.0);
        liste.ajoutPersonnel(temp);
    }
    cout << endl;
    
    liste.afficherSalaires();
    
    cout << endl;
    cout << "========================================" << endl;
    cout << "FIN DES TESTS" << endl;
    cout << "========================================" << endl;
    
    return 0;
}