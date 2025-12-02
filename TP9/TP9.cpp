#include<iostream>
using namespace std;
#include <iostream>
using namespace std;

template <class T, class U> 
void fct(T a, U b) {
    cout << "je suis la fonction1" << endl;
}

template <class T, class U> 
void fct(T* a, U b) {
    cout << "je suis la fonction 2" << endl;
}

template <class T> 
void fct(T, T, T) {
    cout << "je suis la fonction 3" << endl;
}

void fct(int a, float b) {
    cout << "Je suis la fonction 4" << endl;
}

int main() {
    int n=0, p=0, q=0;
    float x=0.0, y=0.0;
    double z=0.0;
    
    cout << "fct (n, p) ;";
    fct(n, p);
    
    cout << "fct (x, y) ;";
    fct(x, y);
    
    cout << "fct (n, x) ;";
    fct(n, x);
    
    cout << "fct (n, z) ;";
    fct(n, z);
    
    cout << "fct (&n, p) ;";
    fct(&n, p);
    
    cout << "fct (&n, x) ;";
    fct(&n, x);
    
    cout << "fct (&n, &p, &q);";
    fct(&n, &p, &q);
    
    return 0;
}

// Exercice 2 : patron de fonction somme 
//Patron de fonction pour calculer la somme d'un tableau 
template <class T>
T somme(T* tableau, int taille) {
    T resultat = 0;
    for (int i = 0; i < taille; i++) {
        resultat += tableau[i];
    }
    return resultat;
}

//Exercice 3 : patron pour recherche díndice de minimum 
template <class T, class U>
int indiceMinimum(T* tableau, int taille, U* tableauSecondaire) {
        int indiceMin = 0;
        T valeurMin = tableau[0];
        
        for (int i = 1; i < taille; i++){
            if (tableau[i] < valeurMin){
                valeurMin = tableau[i];
                indiceMin = i;
            }
        }
        return indiceMin;
}


//Exercice 4 : Patron de classes pour les vecteurs dynamiques 
template <class T>
class Vecteur {
    private :
    T* elements;
    int taille;

    public :
    Vecteur(int n) {
        taille = n;
        elements = new T[taille];
        for (int i = 0; i < taille; i++){
            elements[i] = 0;
        }
    }

    //destructeur de la classe vecteur
    ~Vecteur() {delete [] elements;}

    //Surcharge de l'opérateur []
    T& operator [](int indice) {return elements[indice];}

    //Getter
    int getTaille() {return taille;} 
};