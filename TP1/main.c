#include <stdio.h>

//Partie 1 : Notion de pointeur

void echange(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


//Partie 2 : Sans allocation dynamique : Matrice 1 

#define MAX_SIZE 50 // Taille maximale de la matrice

// Fonction pour saisir les éléments d'une matrice carrée
void saisir(int matrice[MAX_SIZE][MAX_SIZE], int taille) {
    printf("Saisie de la matrice de taille %dx%d :\n", taille, taille);
    for (int i = 0; i < taille; i++) {
        for (int j = 0; j < taille; j++) {
            printf("Entrez l'element [%d][%d] : ", i, j);
            scanf("%d", &matrice[i][j]);
        }
    }
}

// Fonction pour afficher les éléments d'une matrice
void afficher(int matrice[MAX_SIZE][MAX_SIZE], int taille) {
    printf("Affichage de la matrice :\n");
    for (int i = 0; i < taille; i++) {
        for (int j = 0; j < taille; j++) {
            printf("%d\t", matrice[i][j]);
        }
        printf("\n");
    }
}

// Fonction pour additionner deux matrices
void additionner(int matrice1[MAX_SIZE][MAX_SIZE], int matrice2[MAX_SIZE][MAX_SIZE], int resultat[MAX_SIZE][MAX_SIZE], int taille) {
    for (int i = 0; i < taille; i++) {
        for (int j = 0; j < taille; j++) {
            resultat[i][j] = matrice1[i][j] + matrice2[i][j];
        }
    }
}

// Fonction pour multiplier deux matrices
void multiplier(int matrice1[MAX_SIZE][MAX_SIZE], int matrice2[MAX_SIZE][MAX_SIZE], int resultat[MAX_SIZE][MAX_SIZE], int taille) {
    for (int i = 0; i < taille; i++) {
        for (int j = 0; j < taille; j++) {
            resultat[i][j] = 0;
            for (int k = 0; k < taille; k++) {
                resultat[i][j] += matrice1[i][k] * matrice2[k][j];
            }
        }
    }
}

// Fonction de menu pour l'utilisateur
int menu() {
    int choix;
    printf("\n--- Menu d'operations sur les matrices ---\n");
    printf("1. Addition de deux matrices\n");
    printf("2. Multiplication de deux matrices\n");
    printf("3. Afficher une matrice\n");
    printf("4. Quitter\n");
    printf("Entrez votre choix : ");
    scanf("%d", &choix);
    return choix;
}

//Partie 3 : Matrice avec allocation dynamique de mémoire : recherche des points clos 

// Définition du type Matrice pour plus de clarté 
typedef int **Matrice;

// Déclaration des fonctions 
Matrice SaisirMatrice(int *lignes, int *colonnes);
void AfficherMatrice(Matrice mat, int lignes, int colonnes);
Matrice MaxLigne(Matrice mat, int lignes, int colonnes);
Matrice MinColonne(Matrice mat, int lignes, int colonnes);
void TrouvePointsClos(Matrice mat, Matrice max_lignes, Matrice min_colonnes, int lignes, int colonnes);
void LibererMatrice(Matrice mat, int lignes);


//Fonction SaisirMatrice

Matrice SaisirMatrice(int *lignes, int *colonnes) {
    printf("Entrez le nombre de lignes : ");
    scanf("%d", lignes);
    printf("Entrez le nombre de colonnes : ");
    scanf("%d", colonnes);

    // Allocation du tableau de pointeurs
    Matrice mat = (Matrice)malloc(*lignes * sizeof(int *));
    if (mat == NULL) {
        printf("Erreur d'allocation pour les lignes.\n");
        exit(1);
    }

    // Allocation des tableaux pour chaque ligne
    for (int i = 0; i < *lignes; i++) {
        mat[i] = (int *)malloc(*colonnes * sizeof(int));
        if (mat[i] == NULL) {
            printf("Erreur d'allocation pour une colonne.\n");
            // Libérer la mémoire déjà allouée avant de quitter
            for (int k = 0; k < i; k++) {
                free(mat[k]);
            }
            free(mat);
            exit(1);
        }
    }

    printf("Saisie des elements de la matrice :\n");
    for (int i = 0; i < *lignes; i++) {
        for (int j = 0; j < *colonnes; j++) {
            printf("Mat[%d][%d] : ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }
    return mat;
}

//Fonction AfficherMatrice
void AfficherMatrice(Matrice mat, int lignes, int colonnes) {
    if (mat == NULL) {
        printf("La matrice n'a pas ete allouee.\n");
        return;
    }
    printf("\nMatrice :\n");
    for (int i = 0; i < lignes; i++) {
        for (int j = 0; j < colonnes; j++) {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
}

//Fonction Maxlig

Matrice MaxLigne(Matrice mat, int lignes, int colonnes) {
    Matrice max_lignes = (Matrice)calloc(lignes, sizeof(int *));
    if (max_lignes == NULL) {
        exit(1);
    }
    for (int i = 0; i < lignes; i++) {
        max_lignes[i] = (int *)calloc(colonnes, sizeof(int));
        if (max_lignes[i] == NULL) {
            exit(1);
        }
    }

    for (int i = 0; i < lignes; i++) {
        int max_val = mat[i][0];
        // Trouver la valeur maximale de la ligne
        for (int j = 1; j < colonnes; j++) {
            if (mat[i][j] > max_val) {
                max_val = mat[i][j];
            }
        }
        // Marquer les éléments qui correspondent au maximum
        for (int j = 0; j < colonnes; j++) {
            if (mat[i][j] == max_val) {
                max_lignes[i][j] = 1;
            }
        }
    }
    return max_lignes;
}

//Fonction MinColonne

Matrice MinColonne(Matrice mat, int lignes, int colonnes) {
    Matrice min_colonnes = (Matrice)calloc(lignes, sizeof(int *));
    if (min_colonnes == NULL) {
        exit(1);
    }
    for (int i = 0; i < lignes; i++) {
        min_colonnes[i] = (int *)calloc(colonnes, sizeof(int));
        if (min_colonnes[i] == NULL) {
            exit(1);
        }
    }

    for (int j = 0; j < colonnes; j++) {
        int min_val = mat[0][j];
        // Trouver la valeur minimale de la colonne
        for (int i = 1; i < lignes; i++) {
            if (mat[i][j] < min_val) {
                min_val = mat[i][j];
            }
        }
        // Marquer les éléments qui correspondent au minimum
        for (int i = 0; i < lignes; i++) {
            if (mat[i][j] == min_val) {
                min_colonnes[i][j] = 1;
            }
        }
    }
    return min_colonnes;
}

//Fonction TrouvePointsClos

void TrouvePointsClos(Matrice mat, Matrice max_lignes, Matrice min_colonnes, int lignes, int colonnes) {
    printf("\nRecherche des Points-Clos :\n");
    int trouve = 0;
    for (int i = 0; i < lignes; i++) {
        for (int j = 0; j < colonnes; j++) {
            // Un point-clos est la conjonction des deux conditions
            if (max_lignes[i][j] == 1 && min_colonnes[i][j] == 1) {
                printf("Point-Clos trouve : Mat[%d][%d] = %d\n", i, j, mat[i][j]);
                trouve = 1;
            }
        }
    }
    if (!trouve) {
        printf("Aucun Point-Clos trouve.\n");
    }
}

//Fonction LibererMatrice
void LibererMatrice(Matrice mat, int lignes) {
    if (mat == NULL) return;
    for (int i = 0; i < lignes; i++) {
        free(mat[i]);
    }
    free(mat);
}


//Programme principale 


int main() {

    //Test pour la partie 1

    int x = 10;
    int y = 20;

    printf("Avant l'appel de la fonction echange :\n");
    printf("x = %d, y = %d\n", x, y);

    // Appel de la fonction echange en passant les adresses des variables
    echange(&x, &y);

    printf("\nAprès l'appel de la fonction echange :\n");
    printf("x = %d, y = %d\n", x, y);

    return 0;

    //Test pour la partie 2 

    #define MAX_SIZE 10 // Taille maximale de la matrice

    // (Ici se trouvent les 5 fonctions : saisir, afficher, additionner, multiplier, menu)

    int taille;
    int matrice1[MAX_SIZE][MAX_SIZE];
    int matrice2[MAX_SIZE][MAX_SIZE];
    int resultat[MAX_SIZE][MAX_SIZE];
    int choix;

    printf("Entrez la taille de la matrice carree (max %d) : ", MAX_SIZE);
    scanf("%d", &taille);

    if (taille <= 0 || taille > MAX_SIZE) {
        printf("Taille invalide. Le programme va se terminer.\n");
        return 1;
    }

    // Saisie des deux matrices
    saisir(matrice1, taille);
    saisir(matrice2, taille);
    
    do {
        choix = menu();
        switch (choix) {
            case 1:
                printf("\n--- Resultat de l'addition ---\n");
                additionner(matrice1, matrice2, resultat, taille);
                afficher(resultat, taille);
                break;
            case 2:
                printf("\n--- Resultat de la multiplication ---\n");
                multiplier(matrice1, matrice2, resultat, taille);
                afficher(resultat, taille);
                break;
            case 3:
                printf("\n--- Affichage des matrices initiales ---\n");
                printf("Matrice 1:\n");
                afficher(matrice1, taille);
                printf("Matrice 2:\n");
                afficher(matrice2, taille);
                break;
            case 4:
                printf("Programme termine. Au revoir !\n");
                break;
            default:
                printf("Choix invalide, veuillez reessayer.\n");
                break;
        }
    } while (choix != 4);

    return 0;

    //Test partie 3

    int lignes, colonnes;
    Matrice ma_matrice = NULL;
    Matrice max_lignes = NULL;
    Matrice min_colonnes = NULL;

    // Saisie et affichage de la matrice
    ma_matrice = SaisirMatrice(&lignes, &colonnes);
    AfficherMatrice(ma_matrice, lignes, colonnes);

    // Création des matrices binaires
    max_lignes = MaxLigne(ma_matrice, lignes, colonnes);
    min_colonnes = MinColonne(ma_matrice, lignes, colonnes);

    // Recherche et affichage des points-clos
    TrouvePointsClos(ma_matrice, max_lignes, min_colonnes, lignes, colonnes);

    // Libération de la mémoire
    LibererMatrice(ma_matrice, lignes);
    LibererMatrice(max_lignes, lignes);
    LibererMatrice(min_colonnes, lignes);

    return 0;
}
