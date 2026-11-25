// Exercice 4 — Une mesure oubliée -- BUG

#include <stdio.h>

int calculer_somme(int tab[], int taille) {
    int somme = 0;

    for (int i = 0; i <= taille; i++) {
        somme += tab[i];
    }

    return somme;
}

int main(void) {
    int mesures[] = {10, 20, 30, 40};
    int taille = 4;

    printf("Somme : %d\n", calculer_somme(mesures, taille));

    return 0;
}
