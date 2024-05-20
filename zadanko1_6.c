#include <stdlib.h>
#include <stdio.h>

/*
    Zapytaj użytkownika o 1 liczbę N.
    Po otrzymaniu tej liczby stwórz tablicę o rozmiarze tej liczby.
    Poproś użytkownika o wypełnienie tej tablicy (pytaj go po kolei o każdą zmienną).
    Użytkownik poda Ci N liczb całkowitych.
    Posortuj te liczby od największej do najmniejszej i je wypisz w tej kolejności.
*/

int compare_nums(const void * _a, const void * _b) {
    int a = *(int*)_a;
    int b = *(int*)_b;

    if (a < b) return 1;
    if (a > b) return -1;
    return 0;
}

int main(int argc, char** argv)
{
    int N;
    printf("podaj rozmiar tablicy draniu: ");
    scanf("%d", &N);
    int* array = malloc(sizeof(int) * N);

    int element;
    for (int i = 0; i < N; i++){
        printf("\npodaj liczbe draniu: ");
        scanf("%d", &element);
        array[i] = element;
    }

    printf("tablica przed sortowaniem:\n");
    for (int i = 0; i < N; i++){
        printf("%d, ", array[i]);
    }

    qsort(array, N, sizeof(*array), compare_nums);

    printf("\ntablica po sortowaniu:\n");
    for (int i = 0; i < N; i++){
        printf("%d, ", array[i]);
    }

    free(array);
    return 0;
}


