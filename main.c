#include <stdio.h>

int main(int argc, char** argv)
{
    printf("siema eniu\n");

    return 0;
}
/*
Napisz używając C program hello world który wypisze w konsoli jakiś tam string jaki chcesz.
Ale ważne żebyś dał nową linie na końcu.
*/

/*
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    FILE* uchwyt = fopen("dupa.txt", "r");
    if(uchwyt == NULL)
    {
        printf("Plik nie istnieje\n");
        return -1;
    }

    char* buffer = malloc(1024 + 1);

    size_t ret = fread(buffer, 1, 1024, uchwyt);
    if(ret > 0)
    {
        buffer[ret] = 0x00;

        printf("Odczytałem z pliku: %s\n", buffer);
    }

    free(buffer);
    fclose(uchwyt);

    return 0;
}
*/

/*
 #include <stdio.h>
#include <string.h>

int main(int argc, char** argv)
{
    const char* uuh = "daj suba widzu bo jestem menelem\npotrzebuje na piwo";
    const char* plikDoZapisu = "piwo.txt";
    FILE* uchwyt = fopen(plikDoZapisu, "w");
    if(uchwyt == NULL)
    {
        printf("Nie udało się otworzyć pliku do zapisu\n");
        return -1;
    }

    size_t ret = fwrite(uuh, 1, strlen(uuh), uchwyt);
    if(ret == strlen(uuh))
    {
        printf("Operacja się powiodła\n");
    }

    fclose(uchwyt);
    return 0;
}

 */