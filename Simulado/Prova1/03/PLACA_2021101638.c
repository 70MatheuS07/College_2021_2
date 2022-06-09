#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main()
{
    char letra1, letra2, letra3;
    char num1, num2, num3, num4;
    int problemaLetra = 0, problemaNumeros = 0;

    scanf("%c%c%c-%c%c%c%c", &letra1, &letra2, &letra3, &num1, &num2, &num3, &num4);

    if ((letra1 < 'a' || letra1 > 'z') && (letra1 < 'A' || letra1 > 'Z'))
    {
        problemaLetra++;
    }

    if ((letra2 < 'a' || letra2 > 'z') && (letra2 < 'A' || letra2 > 'Z'))
    {
        problemaLetra++;
    }

    if ((letra3 < 'a' || letra3 > 'z') && (letra3 < 'A' || letra3 > 'Z'))
    {
        problemaLetra++;
    }

    if (num1 < '0' || num1 > '9')
    {
        problemaNumeros++;
    }

    if (num2 < '0' || num2 > '9')
    {
        problemaNumeros++;
    }

    if (num3 < '0' || num3 > '9')
    {
        problemaNumeros++;
    }

    if (num4 < '0' || num4 > '9')
    {
        problemaNumeros++;
    }

    if (problemaLetra > 0 && problemaNumeros == 0)
    {
        printf("Codigo invalido!Problema nas letras\n");
    }

    else if (problemaLetra == 0 && problemaNumeros > 0)
    {
        printf("Codigo invalido!Problema nos numeros\n");
    }

    else if (problemaLetra > 0 && problemaNumeros > 0)
    {
        printf("Codigo invalido!Problema nas letras e nos numeros\n");
    }

    else
    {
        printf("Codigo valido!\n");
    }

    return 0;
}