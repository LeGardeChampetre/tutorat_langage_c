// Exercice 6 — Fiche technique d'un appareil
//
// Objectif : découvrir la syntaxe des structures et apprendre à accéder à leurs champs.
//
// On souhaite représenter un appareil avec :
// - un identifiant entier ;
// - une puissance électrique en watts ;
// - un état de fonctionnement.

#include <stdio.h>

// TODO 1 : définir une structure Appareil
// avec les trois champs demandés.

int main(void) {

    // TODO 2 : déclarer une variable de type Appareil.

    // TODO 3 : donner les valeurs suivantes :
    // identifiant : 42
    // puissance : 1500.0
    // en_fonctionnement : 1

    printf("Appareil %d\n", appareil.identifiant);
    printf("Puissance : %.1f W\n", appareil.puissance);

    if (appareil.en_fonctionnement) {
        printf("Etat : en fonctionnement\n");
    } else {
        printf("Etat : arrete\n");
    }

    return 0;
}
