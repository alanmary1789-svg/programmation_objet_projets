#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

class Vector {
    private:
        double* elements;
        int size;
        static int instanceCount;

    public: 
        // Constructeurs
        Vector();
        Vector(int n);
        Vector(const Vector &v);
        Vector(int n, double val);
        Vector(double x, double y);
        Vector(double x, double y, double z);
        Vector(double x, double y, double z, double w);
        Vector(const Vector& v)

        // Destructeur
        ~Vector();

        // Méthodes d'accès
        int getSize() const;
        static int getInstanceCount();

        // Opérateurs 
        Vector& operator=(const Vector &v);
        Vector& operator+(const Vector &v);
        Vector& operator+=(const Vector &v);
        double& operator*(const Vector &V);
        Vector& operator*(double scalar) const;
        bool operator==(const Vector &v) const;
        bool operator!=(const Vector &v) const;

        

}