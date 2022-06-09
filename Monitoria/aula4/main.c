#include <stdlib.h>
#include <stdio.h>

void VerificaPrimo();

int main()
{
    VerificaPrimo();

    return 0;
}

void VerificaPrimo()
{

    int n = 0, m = 0, den = 1, i = 0, j = 0;
    int cont = 0;

    scanf("%d %d\n", &n, &m);

    for (n = n + 1; n < m; n++)
    {
        while (den <= n)
        {
            if (n % den == 0)
            {
                i++;
            }

            den++;
        }

        if (i == 2)
        {
            printf("%d ", n);
            cont++;
        }

        den = 1;
        i = 0;
    }

    if (cont == 0)
    {
        printf("Nao tem primo");
    }
}