#!/usr/bin/env bash

# Quiz interactif de compréhension du C
# Chapitre 1 : fonctions et pointeurs
#
# Ce script n'effectue aucune compilation : les résultats affichés sont
# connus à l'avance. Il sert de support de prédiction et de discussion.

set -u

# --- Palette ANSI (sobre, style Markdown) ---
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
printf "%s\n" "${BOLD}${CYAN}             QUIZ C — FONCTIONS ET POINTEURS${RESET}"
printf "%s\n" "${DIM}============================================================${RESET}"
echo
printf "%s\n" "${BOLD}Pour chaque situation :${RESET}"
printf "  ${CYAN}1.${RESET} Lisez le code.\n"
printf "  ${CYAN}2.${RESET} Essayez de prédire son résultat avant de regarder la réponse.\n"
printf "  ${CYAN}3.${RESET} Discutez de l'explication.\n"
echo
printf "%s\n" "${DIM}Il n'y a ni score ni réponse à valider : le but est de comprendre.${RESET}"
pause

question "1" "Une variable et son adresse" \
'int main(void) {
    int x = 10;
    int *p = &x;

    *p = 25;

    printf("%d\n", x);
    return 0;
}' \
'25' \
'p contient l adresse de x.
*p désigne la valeur stockée à cette adresse.
Modifier *p revient donc à modifier x.'

question "2" "Passage d un paramètre par valeur" \
'void modifier(int n) {
    n = 20;
}

int main(void) {
    int x = 10;
    modifier(x);

    printf("%d\n", x);
    return 0;
}' \
'10' \
'La fonction reçoit une copie de la valeur de x.
La variable n est indépendante de x.
Modifier n ne modifie donc pas x dans main.'

question "3" "Modifier une variable depuis une fonction" \
'void modifier(int *n) {
    *n = 20;
}

int main(void) {
    int x = 10;
    modifier(&x);

    printf("%d\n", x);
    return 0;
}' \
'20' \
'On transmet à la fonction l adresse de x avec &x.
Le paramètre n reçoit cette adresse.
En modifiant *n, la fonction modifie directement x.'

question "4" "Copier un pointeur" \
'int a = 1;
int b = 2;

int *p = &a;
int *q = &b;

p = q;
*p = 7;

printf("a = %d\n", a);
printf("b = %d\n", b);' \
'a = 1
b = 7' \
'L instruction p = q copie l adresse contenue dans q.
p et q désignent maintenant tous les deux b.
*p = 7 modifie donc b, pas a.'

question "5" "Copier une valeur avec deux pointeurs" \
'int a = 1;
int b = 2;

int *p = &a;
int *q = &b;

*p = *q;

printf("a = %d\n", a);
printf("b = %d\n", b);' \
'a = 2
b = 2' \
'*p désigne la valeur de a.
*q désigne la valeur de b.
L instruction *p = *q copie la valeur de b dans a.
Les pointeurs continuent de désigner leurs variables respectives.'

question "6" "Lien entre tableaux et pointeurs" \
'int tab[] = {3, 6, 9, 12};

printf("%d\n", tab[2]);
printf("%d\n", *(tab + 2));' \
'9
9' \
'Dans une expression, le nom du tableau donne accès à son premier élément.
tab + 2 désigne l adresse de son troisième élément.
*(tab + 2) permet de lire la valeur à cette adresse.
Pour lire cet élément, tab[2] et *(tab + 2) sont équivalents.'

clear 2>/dev/null || true
echo
printf "%s\n" "${DIM}============================================================${RESET}"
printf "%s\n" "${BOLD}${CYAN}                    FIN DU QUIZ${RESET}"
printf "%s\n" "${DIM}============================================================${RESET}"
echo
printf "%s\n" "${BOLD}À retenir :${RESET}"
printf "${CYAN}-${RESET} Un pointeur contient une adresse.\n"
printf "${CYAN}-${RESET} ${YELLOW}*p${RESET} permet d accéder à la valeur située à cette adresse.\n"
printf "${CYAN}-${RESET} En C, les paramètres sont transmis par valeur, y compris les pointeurs.\n"
printf "${CYAN}-${RESET} Un tableau et un pointeur sont liés, mais ne sont pas exactement la même chose.\n"
echo
printf "%s\n" "${DIM}Vous pouvez relancer le quiz pour refaire les prédictions.${RESET}"
