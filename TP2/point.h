#ifndef POINT_H
#define POINT_H

class Point {
private:
    // Attributs privés de la classe. Ils représentent les coordonnées
    // du point dans l'espace 3D.
    double x;
    double y;
    double z;

    // Compteur d'instances, statique pour qu'il soit partagé par toutes les instances
    // de la classe Point.
    static int compteurInstances;

public:
    // Constructeur par défaut. Initialise les coordonnées à zéro.
    Point();

    // Constructeur de recopie. Crée un nouveau Point à partir d'un Point existant.
    Point(const Point& autrePoint);

    // Constructeur utilitaire. Permet de créer un Point avec des valeurs initiales.
    Point(double _x, double _y, double _z);

    // Destructeur. Il est appelé quand un objet est détruit.
    // On l'utilise ici pour décrémenter le compteur d'instances.
    ~Point();

    // Méthodes "getters" (accesseurs) pour récupérer les valeurs des coordonnées.
    double getX() const;
    double getY() const const;
    double getZ() const;

    // Méthodes "setters" (mutateurs) pour modifier les valeurs des coordonnées.
    void setX(double _x);
    void setY(double _y);
    void setZ(double _z);

    // Méthode de saisie des coordonnées par l'utilisateur.
    void saisir();

    // Méthode d'affichage des coordonnées.
    void afficher() const;

    // Méthode pour translater le point d'une certaine distance.
    void translater(double dx, double dy, double dz);

    // Méthode pour calculer la distance entre deux points.
    double calculerDistance(const Point& autrePoint) const;

    // Méthode statique pour obtenir le nombre d'instances de la classe.
    static int getCompteurInstances();
};

#endif // POINT_H


