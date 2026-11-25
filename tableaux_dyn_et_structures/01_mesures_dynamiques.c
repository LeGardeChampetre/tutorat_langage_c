// Exercice 1 — Les mesures d'une série de capteurs
//
// Objectif : comprendre comment réserver dynamiquement un tableau d'entiers, le remplir et libérer sa mémoire.
//
// On souhaite créer un tableau dont la taille est déterminée pendant l'exécution du programme.

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int taille = 5;

    // TODO 1 : réserver dynamiquement un tableau de
    // "taille" entiers.

    if (mesures == NULL) {
        printf("Erreur d'allocation\n");
        return 1;
    }

    // TODO 2 : remplir le tableau avec les valeurs
    // 10, 20, 30, 40 et 50.

    printf("Mesures :\n");

    for (int i = 0; i < taille; i++) {
        printf("%d ", mesures[i]);
    }

    printf("\n");

    // TODO 3 : libérer la mémoire réservée.

    return 0;
}
