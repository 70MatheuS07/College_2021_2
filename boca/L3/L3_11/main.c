#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int EhPar(int x);

void PrintaPares(int N);

void PrintaImpares(int N);

int main()
{
    int x = 0, N = 0;

    scanf("%d %d", &x, &N);

    if (EhPar(x) == 0)
    {
        PrintaPares(N);
    }
    else
    {
        PrintaImpares(N);
    }

    return 0;
}

int EhPar(int x)
{
    if (x == 1)
    {
        return 1;
    }

    return 0;
}

void PrintaPares(int N)
{
    int i = 0;

    for (i = 2; i <= (2 * N); i++)
    {
        printf("%d ", i);

        i += 1;
    }
}

void PrintaImpares(int N)
{
    int i = 0;

    for (i = 1; i <= (2 * N); i++)
    {
        printf("%d ", i);

        i += 1;
    }
}