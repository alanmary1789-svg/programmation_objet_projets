#include "Vector.h"
#include <iostream>

using namespace std;

//Initialisation du compteur d''instances
int Vector::instanceCount = 0;

// Constructeurs
Vector::Vector(){
    size = 0;
    elements = NULL;
    instanceCount++;
}

// Constructeur avec taille 
Vector::Vector(int n){
    size = n;
    elements = new double[size];
    for (int i = 0; i < size; i++) {
        elements[i] = 0.0;
    }
    instanceCount++;
}

Vector::Vector(double x, double y){
    size = 2;
    elements = new double[size];
    elements[0], elements[1] = x, y;
    instanceCount++;
}

Vector::Vector(double x, double y, double z){
    size = 3;
    elements = new double[size];
    elements[0], elements[1], elements[2] = x, y, z;
    instanceCount++;
}

Vector::Vector(double x, double y, double z, double w){
    size = 4;
    elements = new double[size];
    elements[0], elements[1], elements[2], elements[3] = x, y, z, w;
    instanceCount++;
}

Vector::Vector(const Vector &v){
    size = v.size;
    elements = new double[size];
    for (int i = 0; i < size; i++){
        elements[i] = v.elements[i];
    }
    instanceCount++;
}

// Destructeur
Vector::Vector(){
    if(elements != NULL){
        delete[] elements;
    }
    instanceCount--;
}

// Méthodes d'accès 
int Vector::getSize() const{
    return size;
}

int Vector::getInstanceCount(){
    return instanceCount;
}

// Opérateurs 
Vector& Vector::operator=(const Vector &v){
    if(this != &v){
        if(elements != NULL){
            
        }
    }
}