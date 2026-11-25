// Exercice 3 — Corriger une mesure
//
// Objectif : comprendre le passage des paramètres par valeur.
//
// Un capteur fournit une mesure qui doit être corrigée en ajoutant un décalage de calibration.
// Attention, le code fourni peut nécessiter des corrections pour fonctionner... :)

#include <stdio.h>

void corriger_mesure(float mesure, float decalage) {
    // TODO : modifier la mesure en lui ajoutant le décalage.
}

int main(void) {
    float temperature = 18.5;

    corriger_mesure(temperature, 2.0);

    printf("Temperature corrigee : %.1f\n", temperature);

    return 0;
}
