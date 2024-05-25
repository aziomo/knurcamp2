#include <stdio.h>

/*
 T1D6
 BOMBELKOWE SORTOWANIE NA WSKAZNIKACH HEHE
 Powodzenia bombelku, napisz ciało funkcji sortujPrzezWskazniki.
 Aby spełniała swoje zadanie i posortowała liczby rosnąco.
 */

void swap(int* a, int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void sortujPrzezWskazniki(int *tab, int rozmiar) {
    for (int i = rozmiar; i > 0; i--){
        for (int j = 0; j < i-1; j++) {
            if (tab[j] > tab[j+1]) {
                swap(&tab[j], &tab[j+1]);
            }
        }
    }
}

int main() {
    int liczby[] = {34, 67, 23, 28, 98, 15};
    int rozmiar = sizeof(liczby) / sizeof(liczby[0]);

    printf("Tablica przed sortowaniem: \n");
    for (int i = 0; i < rozmiar; i++) {
        printf("%d ", liczby[i]);
    }
    printf("\n");

    sortujPrzezWskazniki(liczby, rozmiar);

    printf("Tablica po sortowaniu: \n");
    for (int i = 0; i < rozmiar; i++) {
        printf("%d ", liczby[i]);
    }
    printf("\n");

    return 0;
}