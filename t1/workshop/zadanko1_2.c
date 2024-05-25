#include <stdio.h>
#include <stdlib.h>

/*
Zadanie 2:
Przyjmij 3 parametry (może to być albo argument programu albo możesz odczytać 3 zmienne z inputu użytkownika).
1 parametr to liczba całkowita
2 parametr to jeden z tych znaków: * / + -
3 parametr to liczba całkowita
Wykonaj operację matematyczną która powstanie z tych zmiennych i wypisz jej rezultat na ekranie.
 */

int operacja_matematyczna(int op1, int op2, char operator);

int main(int argc, char** argv)
{
    if (argc < 4) {
        printf("lipa\n");
    }

    int parametr1 = atoi(argv[1]);
    char parametr2 = *argv[2];
    int parametr3 = atoi(argv[3]);

    printf("%d", operacja_matematyczna(parametr1, parametr3, parametr2));
    return 0;
}

int operacja_matematyczna(int op1, int op2, char operator){
    switch (operator) {
        case '*':
            return op1 * op2;
        case '/':
            return op1 / op2;
        case '+':
            return op1 + op2;
        case '-':
            return op1 - op2;
        default:
            printf("podałeś zły znak mój miły\n");
            return -1;
    }
}