// Exercice 4 — Agrandir un tableau dynamique -- BUG

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int taille = 3;

    int *mesures = malloc(taille * sizeof *mesures);

    if (mesures == NULL) {
        return 1;
    }

    mesures[0] = 10;
    mesures[1] = 20;
    mesures[2] = 30;

    taille = 5;

    mesures = realloc(mesures, taille * sizeof *mesures);

    if (mesures == NULL) {
        printf("Erreur de reallocation\n");
        return 1;
    }

    mesures[3] = 40;
    mesures[4] = 50;

    for (int i = 0; i < taille; i++) {
        printf("%d ", mesures[i]);
    }

    free(mesures);

    return 0;
}
