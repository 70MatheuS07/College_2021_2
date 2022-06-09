#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int EhPrimo(int num);

int main()
{
    int n = 0, m = 0, num = 0;

    scanf("%d %d", &n, &m);

    num = n + 1;

    while (num < m)
    {
        if (EhPrimo(num) == 1)
        {
            printf("%d ", num);
        }

        num += 1;
    }

    return 0;
}

int EhPrimo(int num)
{
    int i = 1, cont = 0;

    for (i = 1; i <= num; i++)
    {
        if (num % i == 0)
        {
            cont++;
        }
    }

    if (cont == 2)
    {
        return 1;
    }

    return 0;
}