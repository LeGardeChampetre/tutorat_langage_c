// Exercice 2 — Pourquoi ma fonction ne change-t-elle rien ?

#include <stdio.h>

void doubler(int nombre) {
    nombre = nombre * 2;
}

int main(void) {
    int valeur = 12;

    doubler(valeur);

    printf("Valeur doublee : %d\n", valeur);

    return 0;
}
