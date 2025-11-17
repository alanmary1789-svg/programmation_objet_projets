#include <iostream>
#include "date.h"
#include "heure.h"

using namespace std;

int main() {

    cout << "==============================" << endl;
    cout << "--- Test de la classe Date ---" << endl;
    cout << "==============================" << endl;

    cout << "1. Test constructeur par defaut (d1):" << endl;
    Date d1;
    cout << "   d1 affiche : ";
    d1.affiche();

    cout << "\n2. Test constructeur valeurs valides (d2):" << endl;
    Date d2(14, 10, 2025);
    cout << "   d2 affiche : ";
    d2.affiche();

    cout << "\n3. Test constructeur valeurs invalides (d3):" << endl;
    Date d3(40, 20, 1990);
    cout << "   d3 affiche : ";
    d3.affiche();

    cout << "\n4. Test des setters sur d2 (14/10/2025):" << endl;
    d2.setJour(25);
    d2.setMois(12);
    cout << "   d2 apres setJour(25) et setMois(12) : ";
    d2.affiche();
    
    d2.setAnnee(3000);
    d2.setMois(0);
    cout << "   d2 apres setAnnee(3000) et setMois(0) : ";
    d2.affiche();

    cout << "\n5. Test des getters sur d2 :" << endl;
    cout << "   Jour: " << d2.getJour() << endl;
    cout << "   Mois: " << d2.getMois() << endl;
    cout << "   Annee: " << d2.getAnnee() << endl;

    cout << "\n\n===============================" << endl;
    cout << "--- Test de la classe Heure ---" << endl;
    cout << "===============================" << endl;

    cout << "1. Test constructeur par defaut (h1):" << endl;
    Heure h1;
    cout << "   h1 affiche : ";
    h1.affiche();

    cout << "\n2. Test constructeur valeurs valides (h2):" << endl;
    Heure h2(14, 30);
    cout << "   h2 affiche : ";
    h2.affiche();

    cout << "\n3. Test constructeur valeurs invalides (h3):" << endl;
    Heure h3(25, 80);
    cout << "   h3 affiche : ";
    h3.affiche();

    cout << "\n4. Test des setters sur h2 (14:30):" << endl;
    h2.setHeure(8);
    h2.setMinute(5);
    cout << "   h2 apres setHeure(8) et setMinute(5) : ";
    h2.affiche();

    h2.setHeure(99);
    h2.setMinute(-10);
    cout << "   h2 apres setHeure(99) et setMinute(-10) : ";
    h2.affiche();

    cout << "\n5. Test des getters sur h2 :" << endl;
    cout << "   Heure: " << h2.getHeure() << endl;
    cout << "   Minute: " << h2.getMinute() << endl;

    cout << "\n--- Fin des tests ---" << endl;

    return 0;
}