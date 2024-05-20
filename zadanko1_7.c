#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
    Zapytaj użytkownika o 1 liczbę N.
    Po otrzymaniu tej liczby stwórz tablicę o rozmiarze tej liczby.
    Poproś użytkownika o wypełnienie tej tablicy (pytaj go po kolei o każdą zmienną).
    Użytkownik poda Ci N stringów.
    Posortuj te stringi w zależności od długości, wypisz je po kolei od najkrótszego do najdłuższego.
*/

int compare_strs(const void * _a, const void * _b) {

    char* a = *(char**)_a;
    char* b = *(char**)_b;

    int len_a = strlen(a);
    int len_b = strlen(b);

    if (len_a > len_b) return 1;
    if (len_a < len_b) return -1;
    return 0;
}

int main(int argc, char** argv)
{
    int N;
    printf("podaj rozmiar tablicy draniu: ");
    scanf("%d", &N);
    char** array = malloc(sizeof(char*) * N);

    
    for (int i = 0; i < N; i++){
        char* element = malloc(sizeof(char) * 100);
        printf("podaj stringa draniu: ");
        scanf("%s", element);
        array[i] = element;
    }

    printf("tablica przed sortowaniem:\n");
    for (int i = 0; i < N; i++){
        printf("%s, ", array[i]);
    }

    qsort(array, N, sizeof(*array), compare_strs);

    printf("\ntablica po sortowaniu:\n");
    for (int i = 0; i < N; i++){
        printf("%s, ", array[i]);
    }

    free(array);
    return 0;
}


