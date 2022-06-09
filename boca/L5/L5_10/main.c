#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void PreencheVetor(int num[], int n);
void OrdenaCrescente(int num[], int n);
void ImprimeVetor(int num[], int n);

int main()
{
    int n = 0;
    int result = -1;

    scanf("%d", &n);

    int num[n];

    PreencheVetor(num, n);
    OrdenaCrescente(num, n);
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

void OrdenaCrescente(int num[], int n)
{
    int i = 0;
    int j = 0;
    int num_maior = 0, num_menor = 0;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (num[i] < num[j])
            {
                num_maior = num[i];
                num_menor = num[j];

                num[j] = num_maior;
                num[i] = num_menor;
            }
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