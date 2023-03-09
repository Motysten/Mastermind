#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

void show(char arr[4]) {
    char *letters[6] = {"P", "B", "M", "Y", "O", "G"};
    for (int i = 0; i < 4; ++i) {
        printf("%s", letters[arr[i] - 1]);
    }
    printf("\n");
}

void responseGen(int *tab) {
    int index = 0;
    while (index < 4) {
        int value = rand()%7;
        if (value != 0) {
            tab[index] = value;
            ++index;
        }
    }
}

int convert(char letter) {
    if (letter == 'P') {
        return 1;
    } else if (letter == 'B') {
        return 2;
    } else if (letter == 'M') {
        return 3;
    } else if (letter == 'Y') {
        return 4;
    } else if (letter == 'O') {
        return 5;
    } else if (letter == 'G') {
        return 6;
    }
}

void saisie(char *arr) {
    printf("Rentrez vos lettres svp :\n");
    for (int i = 0; i < 4; i++) {
        printf("%2d > ", i + 1);
        scanf("%s", &arr[i]);
    }
}

void validator(int *solution, int *user, int *result) {
    for (int i = 0; i < 4; i++) {
        bool contains = false;
        for (int j = 0; j < 4; j++) {
            if (solution[j] == user[i]) {
                contains = true;
            }
        }
        result[i] = 0;
        if (contains) {
            result[i] = 2;
            if (solution[i] == user[i]) {
                result[i] = 1;
            }
        }
    }
}

void rangementator(int *tab) {
    int tab2[4];

    for (int i = 0; i < 4; i++) {
        tab2[i] = tab[i];
    }

    for (int i = 0; i < 4; i++) {
        int index = rand()%4;
        while (tab[index] != 3) {
            int index = rand()%4;
        }
        tab[index] = tab2[i];
    }
}

int main() {
    srand(time(NULL));
    int solution[4] = {1, 2, 3, 4};
    int user[4] = {1, 2, 4, 4};
    int result[4] = {3, 3, 3, 3};

    validator(solution, user, result);

    for (int i = 0; i < 4; i++) {
        printf("%d", result[i]);
    }

    system("pause");
    return 0;
}