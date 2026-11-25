#include <stdio.h>

typedef struct {
    float moyenne;
    float minimum;
    float maximum;
} Bilan;

// Partie A : afficher les températures
void afficher_temperatures(float temperatures[], int taille) {
    // TODO
}

// Partie B : calculer la moyenne
float calculer_moyenne(float temperatures[], int taille) {
    // TODO
}

// Partie C : trouver la température maximale
float trouver_maximum(float temperatures[], int taille) {
    // TODO
}

// Partie D : remplir un bilan
void calculer_bilan(float temperatures[], int taille, Bilan *bilan) {
    // TODO
}

// Partie E : compter les températures au-dessus d'un seuil
int compter_superieures(float temperatures[], int taille, float seuil) {
    // TODO
}

// Partie E : demander un seuil à l'utilisateur
void demander_seuil(float temperatures[], int taille) {
    float seuil;

    printf("Entrez une température seuil : ");

    // TODO : récupérer la saisie utilisateur avec scanf

    int nb = compter_superieures(temperatures, taille, seuil);

    printf("Nombre de températures supérieures ou égales à %.2f °C : %d\n",
           seuil, nb);
}

int main(void) {
    float temperatures[] = {18.5, 21.0, 16.5, 23.0, 19.5};
    int taille = 5;

    Bilan bilan;

    afficher_temperatures(temperatures, taille);

    printf("Moyenne : %.2f\n",
           calculer_moyenne(temperatures, taille));

    calculer_bilan(temperatures, taille, &bilan);

    printf("Minimum : %.2f\n", bilan.minimum);
    printf("Maximum : %.2f\n", bilan.maximum);

    demander_seuil(temperatures, taille);

    return 0;
}
