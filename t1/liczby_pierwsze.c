#include <stdio.h>
#include <stdbool.h>

/*
 Zaimplementuj ciało funkcji isPrime która zwróci true jeśli podany int §num§ jest liczba pierwszą.
 Zwróć false w przeciwnym wypadku.

  "Na gwiazdkę: Opisz co robi każda linijka w tym pliku poza rozwiązaniem"
  mam opisać co robi if, printf i scanf? XD jedyną nowością jest tu ternary operator, czyli if w innej postaci LIKE
 */

bool isPrime(int num) {
    int i = num;

    int common_denominators = 0;
    while (i > 0){
        int remainder = num % i;
        if (remainder == 0){
            common_denominators++;
        }
        i--;
    }

    return common_denominators == 2;
}



void selfTest(void) {
    printf("Self-checking code:\n");
    printf("Test 1: %s\n", isPrime(2) ? "POPRAWNY" : "NIEPRAWIDŁOWY");
    printf("Test 2: %s\n", isPrime(11) ? "POPRAWNY" : "NIEPRAWIDŁOWY");
    printf("Test 3: %s\n", isPrime(99) ?  "NIEPRAWIDŁOWY" : "POPRAWNY");
    printf("Test 4: %s\n", isPrime(97) ? "POPRAWNY" : "NIEPRAWIDŁOWY");
}

int main(void) {
    int num;
    printf("Podaj liczbe: ");
    scanf("%d", &num);

    if (isPrime(num)) {
        printf("%d jest liczba pierwsza.\n", num);
    } else {
        printf("%d nie jest liczba pierwsza.\n", num);
    }

    // Run the self-checking code
    selfTest();

    return 0;
}