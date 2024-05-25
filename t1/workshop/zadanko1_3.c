#include <stdio.h>

/*
Poproś użytkownika o podanie 1 liczby całkowitej N.
Wypisz ciąg fibonacziego do liczby N.
*/

int main(int argc, char** argv)
{
    int n, t1 = 0, t2 = 1, nastepnyWyraz;
    printf("Podaj dla mnie jedną liczbe całkowitą :3\n");
    scanf("%d", &n);


    printf("ciag Fibonacciego: ");
    for (int i = 1; i <= n; ++i) {
        printf("%d, ", t1);
        nastepnyWyraz = t1 + t2;
        t1 = t2;
        t2 = nastepnyWyraz;
    }

    return 0;
}

