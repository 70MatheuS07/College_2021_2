#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main()
{
    int n = 0, resto = 0, soma = 0;

    scanf("%d", &n);

    while (n > 9)
    {
        soma = 0;

        while (n > 0)
        {
            resto = n % 10;
            n = (n - resto) / 10;
            soma = soma + resto;
        }

        n = soma;
    }

    if (n > 0 && n < 10)
    {
        printf("RESP:%d", n);
    }
    else
    {
        printf("RESP:%d", soma);
    }

    return 0;
}