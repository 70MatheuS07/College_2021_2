#include <stdlib.h>
#include <stdio.h>

int main()
{
    int n = 0, nNegativo = 0, nPositivo = 0, somaNegativos = 0, somaPositivos = 0, i = 1;

    while (i < 100 && i > -100)
    {
        scanf("%d", &n);

        if (n < 0)
        {
            nNegativo += 1;

            somaNegativos += n;

            i = 1;
        }

        if (n > 0)
        {
            nPositivo += 1;

            somaPositivos += n;

            i = 1;
        }

        if (n = 0)
        {
            i = 101;
        }

        i++;
    }

    printf("%d ", nNegativo);

    printf("%d ", nPositivo);

    printf("%d ", somaNegativos);

    printf("%d", somaPositivos);

    return 0;
}