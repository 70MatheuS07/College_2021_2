#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void Propriedade(int n, int m);

int main()
{
    int n = 0, m = 0;

    scanf("%d %d", &n, &m);

    Propriedade(n, m);

    return 0;
}

void Propriedade(int n, int m)
{
    int ab = 1, cd = 1, ef = 1, i = 0;

    i = n;
    n += 1;
    m -= 1;

    for (i; (i < m) && (n > 1000) && (m < 9999); i++)
    {
        while (n < m)
        {
            ab = (n / 100);
            cd = (n - (ab * 100));
            ef = (ab + cd);

            if ((ef * ef) == n)
            {

                printf("%d\n", n);
            }

            ab = 1;
            cd = 1;
            ef = 1;

            n++;
        }
    }
}