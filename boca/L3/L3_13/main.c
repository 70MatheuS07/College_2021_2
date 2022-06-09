#include <stdio.h>

int CalculaValorPalavra();
int EhPrimo(int n);
int ProximoPrimo(int n);

int main()
{
    int n = 0;

    while (1)
    {
        n = CalculaValorPalavra();

        if (n == 0)
        {
            break;
        }

        if (EhPrimo(n))
        {
            printf("E primo\n");
        }
        else
        {
            n = ProximoPrimo(n);

            printf("Nao e primo %d\n", n);
        }
    }

    return 0;
}

int CalculaValorPalavra()
{
    int n = 0, soma = 0;
    char c;

    while (1)
    {
        scanf("%c", &c);

        if (c >= 'a' && c <= 'z')
        {
            n = c - 96;
            soma += n;
        }

        else if (c >= 'A' && c <= 'Z')
        {
            n = c - 38;
            soma += n;
        }

        else
        {
            n = soma;
            return n;
        }
    }

    return 0;
}

int EhPrimo(int n)
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
        return (1);
    }
    else
    {
        return (0);
    }
}

int ProximoPrimo(int n)
{
    while (EhPrimo(n) == 0)
    {
        n++;
    }

    return n;
}