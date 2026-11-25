// Exercice 7 — Deux pointeurs, une seule variable ? -- BUG

#include <stdio.h>

void modifier_pointeur(int *p) {
    int autre = 50;
    p = &autre;
}

int main(void) {
    int valeur = 10;
    int *p = &valeur;

    modifier_pointeur(p);

    *p = 25;

    printf("Valeur : %d\n", valeur);

    return 0;
}
