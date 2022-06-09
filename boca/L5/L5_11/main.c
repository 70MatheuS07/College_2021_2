#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void PreencheVetorA(int numA[], int n1);

void PreencheVetorB(int numB[], int n2);

void OrdenaCrescenteVetorA(int numA[], int n1);

void OrdenaCrescenteVetorB(int numB[], int n2);

void ImprimeResposta(int numA[], int n1, int numB[], int n2);

int main()
{
    int n1 = 0, n2 = 0;

    scanf("%d", &n1);

    int numA[n1];

    PreencheVetorA(numA, n1);

    scanf("%d", &n2);

    int numB[n2];

    PreencheVetorB(numB, n2);

    OrdenaCrescenteVetorA(numA, n1);
    OrdenaCrescenteVetorB(numB, n2);

    ImprimeResposta(numA, n1, numB, n2);

    return 0;
}

void PreencheVetorA(int numA[], int n1)
{
    int i = 0;

    for (i = 0; i < n1; i++)
    {
        scanf(" %d", &numA[i]);
    }
}

void PreencheVetorB(int numB[], int n2)
{
    int i = 0;

    for (i = 0; i < n2; i++)
    {
        scanf(" %d", &numB[i]);
    }
}

void OrdenaCrescenteVetorA(int numA[], int n1)
{
    int i = 0;
    int j = 0;
    int num_maior = 0, num_menor = 0;

    for (i = 0; i < n1; i++)
    {
        for (j = 0; j < n1; j++)
        {
            if (numA[i] < numA[j])
            {
                num_maior = numA[i];
                num_menor = numA[j];

                numA[j] = num_maior;
                numA[i] = num_menor;
            }
        }
    }
}

void OrdenaCrescenteVetorB(int numB[], int n2)
{
    int i = 0;
    int j = 0;
    int num_maior = 0, num_menor = 0;

    for (i = 0; i < n2; i++)
    {
        for (j = 0; j < n2; j++)
        {
            if (numB[i] < numB[j])
            {
                num_maior = numB[i];
                num_menor = numB[j];

                numB[j] = num_maior;
                numB[i] = num_menor;
            }
        }
    }
}

void ImprimeResposta(int numA[], int n1, int numB[], int n2)
{
    int i = 0, j = 0;
    int cont_A = 0, cont_B = 0;

    for (i = 0; i < n1; i++)
    {
        for (j = cont_B; j < n2; j++)
        {
            if (numA[i] <= numB[j])
            {
                printf("A");
                cont_A++;
                break;
            }

            else if (numB[j] < numA[i])
            {
                printf("B");
                cont_B++;
            }
        }

        if (i == n1 - 1)
        {
            while (cont_A != n1)
            {
                printf("A");
                cont_A++;
            }

            while (cont_B != n2)
            {
                printf("B");
                cont_B++;
            }
        }
    }
}