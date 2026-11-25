// Exercice 5 — Le problème du point et de la flèche -- BUG

#include <stdio.h>

typedef struct {
    int numero;
    float temperature;
} Capteur;

void afficher_capteur(Capteur *capteur) {
    printf("Capteur numero %d\n", capteur.numero);
    printf("Temperature : %.1f\n", capteur.temperature);
}

int main(void) {
    Capteur capteur_1;

    capteur_1.numero = 12;
    capteur_1.temperature = 21.5;

    afficher_capteur(&capteur_1);

    return 0;
}
