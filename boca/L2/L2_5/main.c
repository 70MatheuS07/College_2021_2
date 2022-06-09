#include <stdlib.h>
#include <stdio.h>
#include <math.h>

double CalculaPi(int n);

int main()
{
    int n = 0;
    double raiz = 0;

    scanf("%d", &n);

    raiz = CalculaPi(n);

    printf("%.6f", raiz);

    return 0;
}

double CalculaPi(int n)
{
    int i = 1;
    double pi = 0, soma = 0;

    while (i <= n)
    {
        pi = (double)6 / (i * i);

        soma += pi;
        i++;
        pi = 0;
    }

    return sqrt(soma);
}