// Exercice 7 — Gestion des véhicules
//
// Objectif : combiner structures, tableaux dynamiques, pointeurs et switch.
//
// On souhaite gérer plusieurs véhicules. Chaque véhicule possède :
// - un numéro d'identification
// - une vitesse
// - un type représenté par un entier :
//   - 1 : voiture
//   - 2 : camion
//   - 3 : moto.

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int identifiant;
    float vitesse;
    int type;
} Vehicule;

void afficher_type(int type) {
    switch (type) {
        case 1:
            printf("Voiture");
            break;

        case 2:
            printf("Camion");
            break;

        case 3:
            printf("Moto");
            break;

        default:
            printf("Type inconnu");
    }
}

int main(void) {
    int taille = 3;

    Vehicule *garage = malloc(taille * sizeof *garage);

    if (garage == NULL) {
        printf("Erreur d'allocation\n");
        return 1;
    }

    // TODO 1 : remplir les trois véhicules :
    // garage[0] : identifiant 101, vitesse 90, type 1
    // garage[1] : identifiant 102, vitesse 70, type 2
    // garage[2] : identifiant 103, vitesse 110, type 3

    int i = 0;

    while (i < taille) {
        printf("Vehicule %d : ", garage[i].identifiant);

        afficher_type(garage[i].type);

        printf(" - %.1f km/h\n", garage[i].vitesse);

        i++;
    }

    // TODO 2 : libérer la mémoire.

    return 0;
}
