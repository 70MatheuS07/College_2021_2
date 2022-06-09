#include <stdio.h>

int main()
{

    int n = 0, m = 0, den = 1, i = 0;

    scanf("%d %d", &n, &m);

    printf("RESP:");

    n = n + 1;
    m = m - 1;

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
        }

        den = 1;
        i = 0;
    }

    return 0;
}