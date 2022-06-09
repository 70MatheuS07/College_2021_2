#include <stdlib.h>
#include <stdio.h>

void EhPrimo(int num);

int main()
{
    int num;

    scanf("%d\n", &num);

    EhPrimo(num);

    return 0;
}

void EhPrimo(int num)
{

    int n = 0, m = 0, den = 1, i = 0, j = 0;
    int cont = 0;

    for (j = 0; j < num; j++)
    {
        scanf("%d %d\n", &n, &m);

        for (n = n; n <= m; n++)
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

        printf("\n");

        cont = 0;
    }
}