#include <stdlib.h>
#include <stdio.h>

void ModificaCaractere(char letra);

int main()
{
    char letra;

    printf("RESP:");

    ModificaCaractere(letra);

    return 0;
}

void ModificaCaractere(char letra)
{
    while (letra != 1)
    {
        scanf("%c", &letra);

        if (letra == 32)
        {

            printf("_");
        }

        else if (letra == 33)
        {

            printf("!");
            letra = 1;
        }

        else if (letra == 46)
        {

            printf(".");
            letra = 1;
        }

        else if (letra == 63)
        {

            printf("?");
            letra = 1;
        }

        else if (letra != (32) || (33) || (46) || (63))
        {

            printf("%c", letra);
        }
    }
}