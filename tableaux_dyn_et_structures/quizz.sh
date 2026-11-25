#!/usr/bin/env bash

# Quiz interactif de compréhension du C
# Chapitre 2 : pointeurs, mémoire dynamique et structures

set -u

if [[ -t 1 ]]; then
    RESET=$'\033[0m'
    BOLD=$'\033[1m'
    DIM=$'\033[2m'
    CYAN=$'\033[36m'
    GREEN=$'\033[32m'
    YELLOW=$'\033[33m'
    BLUE=$'\033[34m'
else
    RESET="" BOLD="" DIM="" CYAN="" GREEN="" YELLOW="" BLUE=""
fi

pause() {
    echo
    read -r -p "${DIM}Appuyez sur Entrée pour continuer...${RESET}" _
    echo
}

print_code_block() {
    local code="$1"
    while IFS= read -r line; do
        printf "  ${DIM}│${RESET} ${YELLOW}%s${RESET}\n" "$line"
    done <<< "$code"
}

question() {
    local numero="$1"
    local titre="$2"
    local code="$3"
    local resultat="$4"
    local explication="$5"

    clear 2>/dev/null || true
    echo
    printf "%s\n" "${DIM}============================================================${RESET}"
    printf "%s\n" "${BOLD}${CYAN}QUESTION ${numero} — ${titre}${RESET}"
    printf "%s\n" "${DIM}============================================================${RESET}"
    echo
    printf "%s\n" "${BOLD}Que va afficher ce programme ?${RESET}"
    echo
    print_code_block "$code"
    echo
    read -r -p "${BOLD}Votre prédiction : ${RESET}" prediction
    echo
    printf "%s\n" "${DIM}--------------------${RESET} ${BOLD}${GREEN}Résultat${RESET} ${DIM}------------------------------${RESET}"
    printf "${GREEN}%s${RESET}\n" "$resultat"
    echo
    printf "%s\n" "${DIM}-------------------${RESET} ${BOLD}${BLUE}Explication${RESET} ${DIM}----------------------------${RESET}"
    printf "%s\n" "$explication"
    echo
    pause
}

clear 2>/dev/null || true
echo
printf "%s\n" "${DIM}============================================================${RESET}"
printf "%s\n" "${BOLD}${CYAN}       QUIZ C — POINTEURS, MÉMOIRE DYNAMIQUE ET STRUCTURES${RESET}"
printf "%s\n" "${DIM}============================================================${RESET}"
echo
printf "%s\n" "${BOLD}Pour chaque situation :${RESET}"
printf "  ${CYAN}1.${RESET} Lisez le code.\n"
printf "  ${CYAN}2.${RESET} Essayez de prédire son résultat avant de regarder la réponse.\n"
printf "  ${CYAN}3.${RESET} Discutez de l'explication.\n"
echo
printf "%s\n" "${DIM}Il n'y a ni score ni réponse à valider : le but est de comprendre.${RESET}"
printf "%s\n" "${DIM}Les exemples supposent que les allocations réussissent.${RESET}"
pause

question "1" "Un pointeur, qu il vise une variable ou un bloc dynamique" \
'#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int x = 10;
    int *p = &x;

    int *tab = malloc(2 * sizeof *tab);
    tab[0] = *p;
    tab[1] = 25;

    *p = 15;

    printf("%d %d\n", x, tab[0]);

    free(tab);
    return 0;
}' \
'15 10' \
'p pointe vers la variable x, tandis que tab pointe vers un bloc de mémoire réservé avec malloc.
Dans les deux cas, * permet d accéder à la valeur située à l adresse pointée.
tab[0] reçoit une copie de la valeur de x au moment de l affectation : 10.
Modifier x ensuite ne modifie pas tab[0] : ce sont deux emplacements différents.'

question "2" "Deux pointeurs peuvent viser le même bloc" \
'#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *a = malloc(sizeof *a);
    *a = 12;

    int *b = a;
    *b = 30;

    printf("%d\n", *a);

    free(a);
    return 0;
}' \
'30' \
'b = a copie l adresse contenue dans a, pas le contenu du bloc.
a et b désignent donc le même entier en mémoire.
Modifier *b modifie aussi la valeur que l on lit avec *a.
Le bloc n a été alloué qu une fois : il faut le libérer une seule fois.
Après free(a), b ne doit plus être utilisé non plus : il pointe vers un bloc libéré.'

question "3" "Un tableau dynamique se parcourt comme un tableau classique" \
'#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *tab = malloc(3 * sizeof *tab);

    for (int i = 0; i < 3; i++) {
        tab[i] = (i + 1) * 5;
    }

    printf("%d %d\n", tab[1], *(tab + 2));

    free(tab);
    return 0;
}' \
'10 15' \
'malloc réserve un bloc assez grand pour trois entiers.
On accède à ses éléments avec la notation tab[i], comme pour un tableau classique.
Le nom tab utilisé dans tab + 2 désigne l adresse du premier élément ; ajouter 2 avance de deux éléments, pas de deux octets.
*(tab + 2) est donc équivalent à tab[2].'

question "4" "Que signifie libérer un bloc ?" \
'#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *tab = malloc(2 * sizeof *tab);
    tab[0] = 4;
    tab[1] = 8;

    free(tab);
    tab = NULL;

    if (tab == NULL) {
        printf("tab ne designe plus de bloc utilisable\n");
    }

    return 0;
}' \
'tab ne designe plus de bloc utilisable' \
'free(tab) rend au système le bloc précédemment réservé.
Après cette libération, il ne faut plus lire ni modifier les anciennes cases.
Affecter NULL à tab est une bonne précaution : ce pointeur ne contient alors plus l ancienne adresse.
Attention : cela ne met pas automatiquement à NULL les autres pointeurs qui auraient éventuellement copié cette adresse.'

question "5" "Agrandir un tableau avec realloc" \
'#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *tab = malloc(2 * sizeof *tab);
    tab[0] = 10;
    tab[1] = 20;

    int *nouveau = realloc(tab, 3 * sizeof *tab);

    if (nouveau != NULL) {
        tab = nouveau;
        tab[2] = 30;

        printf("%d %d %d\n", tab[0], tab[1], tab[2]);
        free(tab);
    } else {
        free(tab);
    }

    return 0;
}' \
'10 20 30 (si realloc réussit)' \
'realloc demande un bloc assez grand pour trois entiers.
Les données déjà présentes sont conservées dans la partie commune entre l ancien et le nouveau bloc.
Le bloc peut être déplacé : il faut donc utiliser l adresse renvoyée par realloc.
On la stocke d abord dans nouveau. Ainsi, si realloc échoue, tab contient encore l adresse de l ancien bloc et on peut le libérer.
La troisième case est nouvelle : on lui donne une valeur avant de la lire.'

question "6" "Un tableau dynamique de structures" \
'#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int identifiant;
    float note;
} Etudiant;

int main(void) {
    Etudiant *classe = malloc(2 * sizeof *classe);

    classe[0].identifiant = 101;
    classe[0].note = 13.5;

    classe[1].identifiant = 102;
    classe[1].note = 16.0;

    Etudiant *p = &classe[1];

    printf("%d %.1f\n", p->identifiant, p->note);

    free(classe);
    return 0;
}' \
'102 16.0' \
'classe pointe vers un bloc contenant deux structures Etudiant.
classe[1] désigne la deuxième structure ; le point permet d accéder à ses champs.
p est un pointeur vers cette structure : on utilise -> pour accéder à ses champs.
p->note est équivalent à (*p).note.
Un seul malloc a réservé tout le tableau : un seul free(classe) suffit.'

clear 2>/dev/null || true
echo
printf "%s\n" "${DIM}============================================================${RESET}"
printf "%s\n" "${BOLD}${CYAN}                         FIN DU QUIZ${RESET}"
printf "%s\n" "${DIM}============================================================${RESET}"
echo
printf "%s\n" "${BOLD}À retenir :${RESET}"
printf "${CYAN}-${RESET} Un pointeur peut viser une variable ou un bloc alloué dynamiquement.\n"
printf "${CYAN}-${RESET} Copier un pointeur copie une adresse ; les deux pointeurs peuvent viser le même objet.\n"
printf "${CYAN}-${RESET} Un tableau dynamique s utilise avec les indices ou l arithmétique des pointeurs.\n"
printf "${CYAN}-${RESET} free libère un bloc ; aucun pointeur vers ce bloc ne doit ensuite être déréférencé.\n"
printf "${CYAN}-${RESET} realloc peut déplacer le bloc : utilisez son pointeur de retour avec précaution.\n"
printf "${CYAN}-${RESET} On utilise ${YELLOW}.${RESET} avec une structure et ${YELLOW}->${RESET} avec un pointeur vers une structure.\n"
echo
printf "%s\n" "${DIM}Vous pouvez relancer le quiz pour refaire les prédictions.${RESET}"
