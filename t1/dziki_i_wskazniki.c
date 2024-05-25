#include <stdio.h>

// T1D4: Dziki i wskaźniki
// Zaimplementuj funkcję void swap(int *a, int *b) aby podmienić zawartość a na b i b na a.
// Zadanie bonusowe: Napisz funkcję, która przyjmuje wskaźnik do innej funkcji.
// Wywołaj z tej funkcji ten wskaźnik.
// Spraw aby funkcja pod wskaźnikiem wypisała na ekranie "SIGMA".

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void konsument_wskaznika_funkcji(void(*fn_ptr)()){
    (*fn_ptr)();
}

void sigma_funkcja(){
    printf("\n"
           "     _\n"
           " ___(_) __ _ _ __ ___   __ _\n"
           "/ __| |/ _` | '_ ` _ \\ / _` |\n"
           "\\__ \\ | (_| | | | | | | (_| |\n"
           "|___/_|\\__, |_| |_| |_|\\__,_|\n"
           "       |___/\n");
}

int main(void) {
    int x = 10;
    int y = 20;
    printf("Przed swapem: x = %d, y = %d\n", x, y);
    swap(&x, &y);
    printf("Po swapie: x = %d, y = %d\n", x, y);


    konsument_wskaznika_funkcji(sigma_funkcja);

    return 0;
}