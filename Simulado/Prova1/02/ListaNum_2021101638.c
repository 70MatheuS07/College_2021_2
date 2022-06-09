#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main()
{
    int n = 0, num = 0, i = 0;
    int defineSaida = -1;
    int par = 0, impar = 0;

    scanf("%d\n", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%d ", &num);

        if (i == 0)
        {
            if (num % 2 == 0)
            {
                defineSaida = 0;
                par++;
            }

            else
            {
                defineSaida = 1;
                impar++;
            }
        }

        else
        {
            if (num % 2 == 0)
            {
                par++;
            }

            else
            {
                impar++;
            }
        }
    }

    if (defineSaida == 0)
    {
        printf("QTD PARES:%d", par);
    }

    else
    {
        printf("QTD IMPARES:%d", impar);
    }

    return 0;
}