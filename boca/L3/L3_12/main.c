#include <stdio.h>

int somadosdigitos(int n);

void parImpar(int n);

void valorPrimo(int n);

int main()
{
    int n = 0;

    scanf("%d", &n);

    somadosdigitos(n);

    return 0;
}

int Somadosdigitos(int n)
{
    int resto = 0, soma = 0;

    if (n >= 10)
    {
        while (n > 9)
        {
            soma = 0;

            while (n > 0)
            {

                resto = n % 10;
                n = (n - resto) / 10;
                soma = soma + resto;
            }

            if (soma != n)
            {
                n = soma;

                parImpar(n);

                valorPrimo(n);
            }
        }
    }

    else
    {
        parImpar(n);

        valorPrimo(n);
    }

    return 0;
}

void parImpar(int n)
{
    if (n % 2 == 0)
    {
        printf("%d Par ", n);
    }
    else
    {
        printf("%d Impar ", n);
    }
}

void valorPrimo(int n)
{
    int den = 1, loop = 0;

    while (den <= n)
    {
        if (n % den == 0)
        {
            loop++;
        }
        den++;
    }

    if (loop == 2)
    {
        printf("Primo\n");
    }
    else
    {
        printf("Nao e primo\n");
    }
}