#include <stdio.h>
#include <stdlib.h>

/*
 T1D5 - Pamiętaj bo pamięć to rzecz święta xD (pzdr bonusrpk)
 Zarządzanie pamięcią - utrwalenie
 22.05.2025
 
 
 Postępuj zgodnie z instrukcjami w komentarzach, i dopisz brakujący kod.
 Zwróć uwagę na użycie funkcji calloc i free.
 Zastanów się, dlaczego używamy calloc zamiast malloc.
 */

int main(void) {
    // Zadanie 1: Poproś użytkownika o podanie liczby elementów
    int n;
    printf("drogi użytkowniku, podaj proszę liczbę elementów: ");
    scanf("%d", &n);

    // Zadanie 2: Przydziel pamięć dynamicznie dla 'n' elementów używając calloc
    int* array = calloc(n, sizeof(int));

    // Zadanie 3: Sprawdź, czy pamięć została pomyślnie przydzielona
    if (!array){
        printf("programik się wypierdolił pozdrawiam serdecznie\n");
        return -1;
    }

    // Zadanie 4: Wprowadź elementy do przydzielonej pamięci
    for (int i = 0; i < n; i++){
        int element;
        printf("poproszę o elemencik: ");
        scanf("%d", &element);
        array[i] = element;
    }

    // Zadanie 5: Wyświetl te elementy
    printf("wprowadzone elemenciki:\n");
    for (int i = 0; i < n; i++){
        if (i < n-1){
            printf("%d, ", array[i]);
        } else {
            printf("%d\n", array[i]);
        }
    }

    // Zadanie 6: Zwolnij przydzieloną pamięć
    free(array);
    return 0;
}