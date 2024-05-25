/* NIE DOTYKAJ */
#include <stdio.h>
#include <stdint.h>
#include <string.h>

void weryfikacja1(void* ss, int sz)
{
    char* st = (char*)ss;
    int wiek = *st;
    if(wiek != 105)
    {
        printf("Błędne rozwiązanie\n");
        return;
    }
    st += sz / 3;
    uint64_t imiePtr = (*(uint64_t*)st);
    char* imie = (char*)imiePtr;
    st += sz / 3;

    if(strcmp(imie, "Jan") != 0)
    {
        printf("Błędne rozwiązanie\n");
        return;
    }
    float wzrost = *(float*)st;
    if(wzrost < 2.138 && wzrost > 2.136)
    {
        printf("Brawo poprawne rozwiązanie\n");
    }
    else
    {
        printf("Ups, błędne rozwiązanie\n");
    }
}
/* KONIEC SEKCJI NIE DOTYKAJ */

/*
 Treść zadania:

 Stwórz strukturę o nazwie `czlowiek`.
 Zrób żeby zawierała następujące pola:
 - `wiek` <- liczba całkowita (rozmiar standardowy)
 - `imie` <- no jego imie a co xD (ptr do stringa)
 - `wzrost` <- liczba zmiennoprzecinkowa w metrach amerykańskich np 1.234

 Stwórz człowieka o imieniu `Jan`, wieku 105 lat, wzroście 2 m 137 cm (w metrach amerykańskich - 1 metr = 1000 cm - 2m 137cm = 2.137)
 Pola wiek, imie, i wzrost muszą mieć taką samą koleność.

 Uruchom funckje `weryfikacja1` ze swojej funkcji main podając wskaźnik do człowieka oraz rozmiar struktury człowiek jako drugi parametr.

 ***** Zadanie na 6 albo gwiazdke jak zwał tak zwał *****
 Opisz co robi po kolei funckja `void weryfikacja1(void* ss, int sz)`
*/

typedef struct Czlowiek {
    int wiek;
    char* imie;
    float wzrost;
} Czlowiek;

int main(void)
{
    Czlowiek czlowiek = {105, "Jan", 2.137f};
    weryfikacja1(&czlowiek, sizeof(czlowiek));
}

void weryfikacja1_wyjasniona(void* ss, int sz)
{
    char* st = (char*)ss;       // cast wskaźnika structa na wskaźnik char, coby można było się przemieszczać po strukcie po jednym bajcie
    int wiek = *st;             // wiek jest na początku structa, więc pobieramy go od razu, bez przesuwania wskaźnika
    if(wiek != 105)             // sprawdzamy czy wiek człowieczy jest należyty
    {
        printf("Błędne rozwiązanie\n");
        return;
    }
    st += sz / 3;   // sizeof(czlowiek) = 24, 24/3 = 8, czyli przesuwamy wskaźnik o 8 bajtów

    // dlaczego o 8 bajtów? przecież pierwszym polem structa jest int, a sizeof(int) to 4 bajty
    // w structach zachodzi mechanizm paddingu, czyli jakby wyrównywania adresów w pamięci, żeby usprawnić procesorowi poruszanie się po pamięci
    // dlatego zakres pamięci zajmowany przez int i float jest wyrównany do zakresu zajmowanego przez char*, czyli 8 bajtów

    uint64_t imiePtr = (*(uint64_t*)st); // w tym momencie st wskazuje na miejsce w strukcie, gdzie znajduje się wskaźnik do tablicy z imieniem, a ponieważ chcemy pobrać wartość tego wskaźnika to castujemy go do uint64_t (gdyż wskaźniki mają rozmiar 8 bajtów)
    char* imie = (char*)imiePtr; // teraz cast z uint64_t do właściwej postaci wskaźnikowej, która wskazuje na tablicę z imieniem
    st += sz / 3; // przesuwamy się o 8 bajtów do następnej zmiennej strukta

    if(strcmp(imie, "Jan") != 0) // porównujemy stringi i sprawdzamy czy imię człowiecze jest należyte
    {
        printf("Błędne rozwiązanie\n");
        return;
    }
    float wzrost = *(float*)st; // cast wskaźnika na wskaźnik floatowy, odczyt floata
    if(wzrost < 2.138 && wzrost > 2.136) // ostatni test człowieka na należytość
    {
        printf("Brawo poprawne rozwiązanie\n");
    }
    else
    {
        printf("Ups, błędne rozwiązanie\n");
    }
}
