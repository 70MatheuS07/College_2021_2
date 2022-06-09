#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void PreencheVetor(int num[], int n);
int IdentificaMaiorDiferencaAltura(int num[], int n);
void ClassificaAlturas(int num[], int n, int diferenca);

int main()
{
    int n = 0, i = 0;
    int rtn = -1;
    int diferenca = 0;

    scanf("%d", &n);

    int num[n];

    PreencheVetor(num, n);

    diferenca = IdentificaMaiorDiferencaAltura(num, n);

    if (n == 1)
    {
        printf("IMPOSSIVEL");
    }
    else
    {
        ClassificaAlturas(num, n, diferenca);
    }
    return 0;
}

void PreencheVetor(int num[], int n)
{
    int i = 0;

    for (i = 0; i < n; i++)
    {
        scanf("%d", &num[i]);
    }
}

int IdentificaMaiorDiferencaAltura(int num[], int n)
{
    int i = 0;
    int a = 0;
    int maiorDiferenca = -1;
    int diferenca = 0;

    for (i = 0; i < n; i++)
    {
        a = i + 1;

        if (a < n)
        {
            diferenca = num[i] - num[a];

            if (diferenca < 0)
            {
                diferenca *= -1;
            }

            if (maiorDiferenca < diferenca)
            {
                maiorDiferenca = diferenca;
            }
        }
    }

    return maiorDiferenca;
}

void ClassificaAlturas(int num[], int n, int diferenca)
{
    int i = 0;
    int a = 0, b = 0;
    int cont = 0;
    int result = 0;

    for (i = 0; i < n; i++)
    {
        a = i + 1;

        if (n == 2)
        {
            a = 0;
            i = 1;

            printf(" (%d %d)", a, i);
        }

        else if (n > 2)
        {
            if (a < n)
            {
                if (num[i] >= num[a])
                {
                    if (num[i] - num[a] == diferenca)
                    {
                        printf(" (%d %d)", i, a);
                    }
                }

                else if (num[i] < num[a])
                {
                    if (num[a] - num[i] == diferenca)
                    {
                        printf(" (%d %d)", i, a);
                    }
                }
            }
        }
    }
}