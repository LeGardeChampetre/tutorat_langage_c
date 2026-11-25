// Exercice 8 — Un garage qui perd ses véhicules -- BUG

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int identifiant;
    float kilometrage;
} Voiture;

int main(void) {
    int taille = 3;

    Voiture *garage = malloc(taille * sizeof *garage);

    if (garage == NULL) {
        return 1;
    }

    garage[0].identifiant = 101;
    garage[0].kilometrage = 25000;

    garage[1].identifiant = 102;
    garage[1].kilometrage = 40000;

    garage[2].identifiant = 103;
    garage[2].kilometrage = 15000;

    int i = 0;

    while (i < taille) {
        printf("Voiture %d : %.0f km\n",
               garage[i].identifiant,
               garage[i].kilometrage);

        free(garage);

        i++;
    }

    return 0;
}
