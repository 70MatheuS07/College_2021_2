#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int EhPrimo(int num);
void ImprimeMultiplos(int num, int n, int m);

int main()
{
    int n = 0, m = 0, num = 0;

    scanf("%d %d", &n, &m);

    num = n + 1;

    while (num < m)
    {
        if (EhPrimo(num) == 1)
        {
            printf("%d\n", num);

            ImprimeMultiplos(num, n, m);
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

void ImprimeMultiplos(int num, int n, int m)
{
    int i = 1, cont = 0;

    for (i = n + 1; i < m; i++)
    {
        if (num % i == 0 && num > i)
        {
            printf("%d ", i);
            cont++;
        }

        else if (i % num == 0 && num < i)
        {
            printf("%d ", i);
            cont++;
        }
    }

    if (cont == 0)
    {
        printf("*\n");
    }
    else
    {
        printf("\n");
    }
}