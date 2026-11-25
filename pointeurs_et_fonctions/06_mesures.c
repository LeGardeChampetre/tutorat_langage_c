// Exercice 6 — Parcours d'un tableau avec des pointeurs
//
// Objectif : faire le lien entre tableaux, adresses, indices et arithmétique des pointeurs.
//
// On dispose d'un tableau contenant les mesures de cinq capteurs.
// Il faut calculer leur somme et déterminer la plus grande mesure.

#include <stdio.h>

int calculer_somme(int *tab, int taille) {
    int somme = 0;

    for (int i = 0; i < taille; i++) {
        // TODO : ajouter l'élément courant à la somme.
    }

    return somme;
}

int trouver_maximum(int *tab, int taille) {
    int maximum = *tab;

    for (int i = 1; i < taille; i++) {
        // TODO : comparer l'élément courant au maximum.
        // Mettre à jour maximum si nécessaire.
    }

    return maximum;
}

int main(void) {
    int mesures[] = {12, 18, 9, 24, 15};
    int taille = 5;

    printf("Somme : %d\n", calculer_somme(mesures, taille));
    printf("Maximum : %d\n", trouver_maximum(mesures, taille));

    return 0;
}
