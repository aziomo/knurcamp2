#include <stdio.h>
#include <string.h>

/*
Poproś użytkownika o podanie 2 stringów.
Połącz te 2 stringi ze sobą i zapisz je do pliku dupa.txt.
*/

int main(int argc, char** argv)
{
    char str1[100];
    char str2[100];
    char final_str[200];

    printf("Podaj pierwszy string:\n");
    scanf("%s", str1);

    printf("Podaj drugi string:\n");
    scanf("%s", str2);
    strcat(final_str, str1);
    strcat(final_str, str2);


    const char* plikDoZapisu = "dupa.txt";
    FILE* uchwyt = fopen(plikDoZapisu, "w");
    if(uchwyt == NULL)
    {
        printf("Nie udało się otworzyć pliku do zapisu\n");
        return -1;
    }

    size_t ret = fwrite(final_str, 1, strlen(final_str), uchwyt);
    if(ret == strlen(final_str))
    {
        printf("Operacja się powiodła\n");
    }

    fclose(uchwyt);

    return 0;
}
