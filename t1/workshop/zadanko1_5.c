#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
    Stwórz strukturę czlowiek która będzie zawierała poniższe pola:
    - imie
    - wiek
    - zawod
    Stwórz funkcję zapisującą do pliku strukturę człowiek (nazwa pliku podana jako argument programu numer 2).
    Pod 1 argumentem podaj rodzaj operacji.
    Np: ODCZYT i ZAPIS
    A 2 argument tego programu to nazwa pliku na którym mamy wykonać tą operację.
    Stwórz funkcję odczytującą strukturę z pliku i zwracającą te dane jako strukturę.
    Stwórz funkcję wypisującą zawartość struktury w konsoli.
    Wywołaj ją po odczytaniu pliku.
*/

typedef struct {
    char imie[20];
    int wiek;
    char zawod[20];
} Czlowiek;

Czlowiek get_struct_from_file(char* file_name);
int save_struct_to_file(char* file_name, Czlowiek* ziutek);
void print_struct(Czlowiek* ziutek);

int main(int argc, char** argv)
{
    char file_access = *argv[1];
    char* file_name = argv[2];

    if (file_access != 'r' && file_access != 'w'){
        printf("niewlasciwy rodzaj operacji na pliku!\n");
        return -1;
    }

    if (file_access == 'r'){
        Czlowiek ziutek = get_struct_from_file(file_name);
        print_struct(&ziutek);
    }

    if (file_access == 'w'){
        Czlowiek ziutek = {"Dym", 10, "w chuj"};
        size_t result = save_struct_to_file(file_name, &ziutek);
        if (result == -1){
            return -1;
        }
    }

    return 0;
}

Czlowiek get_struct_from_file(char* file_name){
    FILE* handle = fopen(file_name, "r");
    Czlowiek ziutek;
    if(handle == NULL)
    {
        printf("Plik nie istnieje, zwracam pusty ziutek\n");
        return ziutek;
    }
    fread(&ziutek, sizeof(ziutek), 1, handle);
    fclose(handle);
    return ziutek;
}

int save_struct_to_file(char* file_name, Czlowiek* ziutek){
    FILE* handle = fopen(file_name, "w");
    if (handle == NULL)
    {
        printf("Nie udało się otworzyć pliku do zapisu\n");
        return -1;
    }

    size_t bytes_saved = fwrite(ziutek, 1, sizeof(*ziutek), handle);
    if(bytes_saved == sizeof(*ziutek))
    {
        printf("Operacja się powiodła\n");
    }

    fclose(handle);
    return bytes_saved;
}

void print_struct(Czlowiek* ziutek){
    printf("# Ziutek #\n"
           "Imię: %s\n"
           "Wiek: %d\n"
           "Zawód:%s",
           ziutek->imie, ziutek->wiek, ziutek->zawod);
}
