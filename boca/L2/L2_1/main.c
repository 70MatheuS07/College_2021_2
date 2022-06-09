#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void NumerosPares(int n, int m);

int main()
{
    int n = 0, m = 0;

    scanf("%d %d", &n, &m);

    NumerosPares(n, m);

    return 0;
}

void NumerosPares(int n, int m)
{
    int i = 0;

    printf("RESP:");

    for (i = n + 1; i < m; i++)
    {
        if (i % 2 == 0)
        {
            printf("%d ", i);
        }
    }
}