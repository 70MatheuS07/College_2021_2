#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void Fib(int num);

void Fatora(int conta);

int main()
{
    int num = 0;

    scanf("%d", &num);

    Fib(num);

    return 0;
}

void Fib(int num)
{
    int i = 0, j = 3;
    int conta = 0;

    if (num == 1)
    {
        printf("Nao ha fatores primos.");

        return;
    }

    for (i = 0; i < num; i++)
    {
        conta = (pow((1 + sqrt(5)) / 2, j) - pow((1 - sqrt(5)) / 2, j)) / sqrt(5);

        printf("%d: ", conta);

        Fatora(conta);

        j++;
    }
}

void Fatora(int conta)
{
    int i = 2;
    int cont = 0, cont_total = 0;

    while (i <= conta)
    {
        if (conta % i == 0)
        {
            conta /= i;
            cont++;
        }

        if (conta % i != 0)
        {
            if (cont > 0)
            {
                printf("(%d, %d) ", i, cont);
                cont_total++;
            }

            cont = 0;
            i++;
        }
    }

    printf("[%d]\n", cont_total);
}