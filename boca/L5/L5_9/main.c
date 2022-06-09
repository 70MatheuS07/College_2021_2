#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void PreencheVetor(int num[], int n);
void InverteVetor(int num[], int n);
void ImprimeVetor(int num[], int n);

int main()
{
    int n = 0;
    int result = -1;

    scanf("%d", &n);

    int num[n];

    PreencheVetor(num, n);
    InverteVetor(num, n);
    ImprimeVetor(num, n);

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

void InverteVetor(int num[], int n)
{
    int i = 0;
    int num_esquerda = 0;
    int num_direita = 0;
    int a = 0;

    a = n - 1;

    if (n == 0 || n == 1)
    {
        return;
    }

    else if (n % 2 == 0)
    {
        if (n != 2)
        {
            n = n / 2;

            for (i = 0; i < n; i++)
            {
                num_esquerda = num[i];
                num_direita = num[a];

                num[a] = num_esquerda;
                num[i] = num_direita;

                a--;
            }
        }
        else
        {
            num_esquerda = num[i];
            num_direita = num[a];

            num[a] = num_esquerda;
            num[i] = num_direita;
        }
    }

    else if (n % 2 != 0)
    {
        n = a / 2;

        for (i = 0; i < n; i++)
        {
            num_esquerda = num[i];
            num_direita = num[a];

            num[a] = num_esquerda;
            num[i] = num_direita;

            a--;
        }
    }
}

void ImprimeVetor(int num[], int n)
{
    int i = 0;

    printf("{");

    for (i = 0; i < n; i++)
    {
        printf("%d", num[i]);

        if (i < n - 1)
        {
            printf(", ");
        }
    }

    printf("}");
}