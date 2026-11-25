// Exercice 3 — Calculer la consommation moyenne
//
// Objectif : manipuler un tableau dynamique avec une boucle while et écrire une fonction qui reçoit un pointeur.
//
// Une entreprise relève la consommation électrique d'une machine à plusieurs instants.
// On souhaite calculer la consommation moyenne.

#include <stdio.h>
#include <stdlib.h>

float calculer_moyenne(float *valeurs, int taille) {
    float somme = 0;
    int i = 0;

    while (i < taille) {
        // TODO 1 : ajouter la valeur courante à la somme.
        i++;
    }

    return somme / taille;
}

int main(void) {
    int taille = 4;

    float *consommations = malloc(taille * sizeof *consommations);

    if (consommations == NULL) {
        printf("Erreur d'allocation\n");
        return 1;
    }

    int i = 0;

    // TODO 2 : remplir le tableau avec les valeurs
    // 120.5, 135.0, 110.5 et 134.0.
    // Utiliser une boucle while.

    // TODO 3 : afficher la moyenne calculée
    // avec la fonction calculer_moyenne.

    free(consommations);

    return 0;
}
