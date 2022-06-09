#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main()
{

    int n = 0, m = 0, den = 1, i = 0, multiplo = 0;

    scanf("%d %d", &n, &m);

    n += 1;
    m -= 1;

    for (n = n; n <= m; n++)
    {
        //Reaproveitando L2_8

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
            den = 1;
            i = 0;
            multiplo = n * 2;

            printf("%d\n", n);

            if (multiplo <= m)
            {
                multiplo = (multiplo / 2) + 1;

                while (multiplo <= m)
                {
                    if (multiplo % n == 0)
                    {
                        printf("%d ", multiplo);
                    }

                    multiplo++;
                }

                printf("\n");
            }

            else if (multiplo * 2 > m)
            {
                printf("*\n");
            }
        }

        den = 1;
        i = 0;
        multiplo = 1;
    }

    return 0;
}