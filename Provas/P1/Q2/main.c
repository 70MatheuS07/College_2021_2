#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main()
{
    char referencia, caracter;
    int letras = 0, digitos = 0, total = 0;
    int tem_referencia = -1;

    scanf("%c ", &referencia);

    while (scanf("%c", &caracter) == 1)
    {
        total++;

        if (caracter >= 'a' && caracter <= 'z')
        {
            letras++;
        }

        else if (caracter >= 'A' && caracter <= 'Z')
        {
            letras++;
        }

        else if (caracter >= '0' && caracter <= '9')
        {
            digitos++;
        }

        if (caracter == referencia)
        {
            tem_referencia = 1;
            break;
        }

        else if (caracter == '.')
        {
            break;
        }
    }

    if (tem_referencia == 1)
    {
        letras -= 1;
        total -= 1;

        printf("letras: %d\n", letras);
        printf("digitos: %d\n", digitos);
        printf("Total de caracteres ate a primeira ocorrencia de %c: %d\n", referencia, total);
    }

    else
    {
        total -= 1;

        printf("letras: %d\n", letras);
        printf("digitos: %d\n", digitos);
        printf("Total de caracteres: %d\n", total);
    }

    return 0;
}