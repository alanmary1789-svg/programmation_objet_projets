#include <iostream>
#include "Date.h"
#include "Heure.h"
#include "Rdv.h"
#include "Agenda.h"
#include "AgendaOrdonne.h"

using namespace std;

void testDate() {
    cout << "\n========== TEST CLASSE DATE ==========" << endl;
    
    Date d1;
    cout << "Date par defaut: ";
    d1.affiche();
    cout << endl;
    
    Date d2(25, 12, 2024);
    cout << "Date 25/12/2024: ";
    d2.affiche();
    cout << endl;
    
    Date d3(31, 2, 2024); // Date invalide
    cout << "Date invalide (31/2/2024): ";
    d3.affiche();
    cout << endl;
}

void testHeure() {
    cout << "\n========== TEST CLASSE HEURE ==========" << endl;
    
    Heure h1;
    cout << "Heure par defaut: ";
    h1.affiche();
    cout << endl;
    
    Heure h2(14, 30);
    cout << "Heure 14h30: ";
    h2.affiche();
    cout << endl;
}

void testRDV() {
    cout << "\n========== TEST CLASSE RDV ==========" << endl;
    
    RDV rdv1;
    Date d1(15, 6, 2024);
    Heure h1(10, 0);
    rdv1.setDate(d1);
    rdv1.setHeure(h1);
    rdv1.setLieu("Salle A");
    rdv1.setNombreDeParticipants(2);
    rdv1.setParticipant(0, "Alice");
    rdv1.setParticipant(1, "Bob");
    
    cout << "\nRDV 1:" << endl;
    rdv1.affiche();
    
    RDV rdv2;
    Date d2(15, 6, 2024);
    Heure h2(10, 0);
    rdv2.setDate(d2);
    rdv2.setHeure(h2);
    rdv2.setLieu("Salle B");
    
    cout << "\n\nTest compatibilite:" << endl;
    if (rdv1.estCompatibleAvec(rdv2)) {
        cout << "Les RDV sont compatibles (pas au meme moment)" << endl;
    } else {
        cout << "Les RDV ne sont PAS compatibles (meme moment)" << endl;
    }
}

void testAgenda() {
    cout << "\n========== TEST CLASSE AGENDA (LIFO) ==========" << endl;
    
    Agenda agenda;
    
    // Creation de plusieurs RDV
    RDV rdv1;
    Date d1(10, 3, 2024);
    Heure h1(9, 0);
    rdv1.setDate(d1);
    rdv1.setHeure(h1);
    rdv1.setLieu("Bureau 101");
    rdv1.setNombreDeParticipants(1);
    rdv1.setParticipant(0, "Jean");
    
    RDV rdv2;
    Date d2(12, 3, 2024);
    Heure h2(14, 30);
    rdv2.setDate(d2);
    rdv2.setHeure(h2);
    rdv2.setLieu("Salle de reunion");
    rdv2.setNombreDeParticipants(2);
    rdv2.setParticipant(0, "Marie");
    rdv2.setParticipant(1, "Paul");
    
    RDV rdv3;
    Date d3(15, 3, 2024);
    Heure h3(16, 0);
    rdv3.setDate(d3);
    rdv3.setHeure(h3);
    rdv3.setLieu("Cafeteria");
    
    cout << "\nAjout de 3 RDV..." << endl;
    agenda.ajoute(rdv1);
    agenda.ajoute(rdv2);
    agenda.ajoute(rdv3);
    
    cout << "\nAffichage de l'agenda:" << endl;
    agenda.affiche();
    
    cout << "\n\nSuppression d'un RDV..." << endl;
    agenda.enleve();
    agenda.affiche();
    
    cout << "\n\nVidage de la liste..." << endl;
    while (!agenda.estVide()) {
        agenda.enleve();
    }
    agenda.affiche();
}

void testAgendaOrdonne() {
    cout << "\n========== TEST CLASSE AGENDA ORDONNE ==========" << endl;
    
    AgendaOrdonne agendaOrd;
    
    // Creation de plusieurs RDV (ajoutes dans le desordre)
    RDV rdv1;
    Date d1(15, 3, 2024);
    Heure h1(16, 0);
    rdv1.setDate(d1);
    rdv1.setHeure(h1);
    rdv1.setLieu("Cafeteria");
    rdv1.setNombreDeParticipants(1);
    rdv1.setParticipant(0, "Sophie");
    
    RDV rdv2;
    Date d2(10, 3, 2024);
    Heure h2(9, 0);
    rdv2.setDate(d2);
    rdv2.setHeure(h2);
    rdv2.setLieu("Bureau 101");
    rdv2.setNombreDeParticipants(1);
    rdv2.setParticipant(0, "Jean");
    
    RDV rdv3;
    Date d3(12, 3, 2024);
    Heure h3(14, 30);
    rdv3.setDate(d3);
    rdv3.setHeure(h3);
    rdv3.setLieu("Salle de reunion");
    rdv3.setNombreDeParticipants(2);
    rdv3.setParticipant(0, "Marie");
    rdv3.setParticipant(1, "Paul");
    
    cout << "\nAjout de 3 RDV (dans le desordre)..." << endl;
    agendaOrd.ajoute(rdv1); // 15/3 16h00
    agendaOrd.ajoute(rdv2); // 10/3 09h00
    agendaOrd.ajoute(rdv3); // 12/3 14h30
    
    cout << "\nAffichage de l'agenda ordonne (tri automatique):" << endl;
    agendaOrd.affiche();
    
    cout << "\n\nSuppression du RDV du 12/3 a 14h30..." << endl;
    agendaOrd.enleve(rdv3);
    agendaOrd.affiche();
}

int main() {
    cout << "====================================" << endl;
    cout << "    TESTS TP4 et TP5 - C++" << endl;
    cout << "====================================" << endl;
    
    testDate();
    testHeure();
    testRDV();
    testAgenda();
    testAgendaOrdonne();
    
    cout << "\n\n====================================" << endl;
    cout << "       FIN DES TESTS" << endl;
    cout << "====================================" << endl;
    
    return 0;
}