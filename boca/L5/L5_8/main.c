#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void PreencheVetor(int num[], int n);
void TrocaPosicaoVetor(int num[], int n);
void ImprimeVetor(int num[], int n);

int main()
{
    int n = 0;
    int result = -1;

    scanf("%d", &n);

    int num[n];

    PreencheVetor(num, n);

    TrocaPosicaoVetor(num, n);

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

void TrocaPosicaoVetor(int num[], int n)
{
    int i = 0;
    int cont = 0;
    int vetor_atual = 0;
    int vetor_posterior = 0;
    int a = 0;

    for (i = 0; i < n; i++)
    {
        a = i + 1;

        if (n == 0)
        {
            break;
        }

        else if (n == 1)
        {
            break;
        }

        else if (n == 2)
        {
            vetor_atual = num[a];
            vetor_posterior = num[i];

            num[i] = vetor_atual;
            num[a] = vetor_posterior;
            break;
        }

        else if (n >= 3)
        {
            if (a < n)
            {
                vetor_atual = num[a];
                vetor_posterior = num[i];

                num[i] = vetor_atual;
                num[a] = vetor_posterior;

                i++;
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