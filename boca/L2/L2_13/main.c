#include <stdlib.h>
#include <stdio.h>

void ModificaLetra();

int main()
{
    ModificaLetra();

    return 0;
}

void ModificaLetra()
{
    char letra, letraMaiuscula;

    while (letra != 1)
    {
        scanf("%c", &letra);

        if (letra == 32)
        {
            printf(" ");
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

        else if ((letra >= 65) && (letra <= 90))
        {
            printf("%c", letra);
        }

        else if ((letra >= 97) && (letra <= 122))
        {
            letraMaiuscula = letra - 32;

            printf("%c", letraMaiuscula);
        }

        else
        {
            printf("%c", letra);
        }
    }
}