// Exercice 2 — Une allocation trop petite -- BUG

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int taille = 5;

    int *tab = malloc(taille * sizeof(int *));

    if (tab == NULL) {
        return 1;
    }

    for (int i = 0; i < taille; i++) {
        tab[i] = i * 10;
    }

    for (int i = 0; i < taille; i++) {
        printf("%d ", tab[i]);
    }

    free(tab);

    return 0;
}
