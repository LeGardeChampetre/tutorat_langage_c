#include <stdio.h>

// Les commandes pour compiler puis executer:
// gcc -std=c11 -Wall -Wextra -Wpedantic <nomdufichier>.c -o carnet
// ./carnet

typedef struct {
    float moyenne;
    float minimum;
    float maximum;
} Bilan;

// Partie A : afficher les températures
void afficher_temperatures(float temperatures[], int taille) {
    if(temperatures == NULL || taille <= 0) return;

    for(int i=0; i < taille; i++){
        printf("%.2f °C\n", temperatures[i]);
    }
}

// Partie B : calculer la moyenne
float calculer_moyenne(float temperatures[], int taille) {
    if(temperatures == NULL || taille <= 0) return 0;

    float somme = temperatures[0];
    for(int i = 1; i < taille; i++){
        somme += temperatures[i];
    }
    return somme/=taille;
}

// Partie C : trouver la température maximale
float trouver_maximum(float temperatures[], int taille) {
    if(temperatures == NULL || taille <= 0) return 0;

    float max = temperatures[0];
    for(int i = 1; i < taille; i++){
        if(temperatures[i] > max)
            max = temperatures[i];
    }

    return max;
}

// Fonction ajoutée pour simplifier
 float trouver_minimum (float temperatures[], int taille) {
    if(temperatures == NULL || taille <= 0) return 0;

    float min = temperatures[0];
    for(int i = 1; i < taille; i++){
        if(temperatures[i] < min)
            min = temperatures[i];
    }

    return min;
}

// Partie D : remplir un bilan
void calculer_bilan(float temperatures[], int taille, Bilan *bilan) {
    if(bilan == NULL) return;

    float max = trouver_maximum(temperatures, taille);
    float moyenne = calculer_moyenne(temperatures, taille);
    float min = trouver_minimum(temperatures, taille);

    bilan->minimum = min;
    bilan->maximum = max;
    bilan->moyenne = moyenne;
}

// Partie E : compter les températures au-dessus d'un seuil
int compter_superieures(float temperatures[], int taille, float seuil) {
    if(temperatures == NULL || taille <=0) return 0;

    int nb = 0;

    for (int i = 0; i < taille; i++){
        if(temperatures[i] >= seuil)
            nb++;
    }
    return nb;
}

// Partie E : demander un seuil à l'utilisateur
void demander_seuil(float temperatures[], int taille) {
    float seuil;

    printf("Entrez une température seuil : ");

    if (scanf("%f", &seuil) != 1) {
        printf("Saisie invalide.\n");
        return;
    }

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
