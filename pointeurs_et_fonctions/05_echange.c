// Exercice 5 — Échanger deux valeurs
//
// Objectif : utiliser des pointeurs pour modifier directement les variables de l'appelant.
//
// On souhaite écrire une fonction echanger qui échange le contenu de deux variables entières.

#include <stdio.h>

void echanger(int *a, int *b) {
    int temporaire;

    // TODO 1 : sauvegarder la valeur pointée par a.

    // TODO 2 : placer la valeur pointée par b dans la variable pointée par a.

    // TODO 3 : replacer l'ancienne valeur de a dans la variable pointée par b.
}

int main(void) {
    int vitesse_1 = 50;
    int vitesse_2 = 80;

    printf("Avant : %d et %d\n", vitesse_1, vitesse_2);

    // TODO 4 : appeler correctement echanger.

    printf("Apres : %d et %d\n", vitesse_1, vitesse_2);

    return 0;
}
