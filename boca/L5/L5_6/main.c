#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void PreencheVetor1(int num1[], int n1);

void PreencheVetor2(int num2[], int n2);

int VarreComparaVetores(int num1[], int num2[], int n1, int n2);

void ImprimeResult(int result, int n1);

int main()
{
    int n1 = 0, n2 = 0;
    int result = 0;

    scanf("%d", &n1);

    int num1[n1];

    PreencheVetor1(num1, n1);

    scanf("%d", &n2);

    int num2[n2];

    PreencheVetor2(num2, n2);

    result = VarreComparaVetores(num1, num2, n1, n2);

    ImprimeResult(result, n1);

    return 0;
}

void PreencheVetor1(int num1[], int n1)
{
    int i;

    for (i = 0; i < n1; i++)
    {
        scanf("%d", &num1[i]);
    }
}

void PreencheVetor2(int num2[], int n2)
{
    int i;

    for (i = 0; i < n2; i++)
    {
        scanf("%d", &num2[i]);
    }
}

int VarreComparaVetores(int num1[], int num2[], int n1, int n2)
{
    int i1;
    int i2;
    int cont = 0;

    for (i1 = 0; i1 < n1; i1++)
    {
        for (i2 = 0; i2 < n2; i2++)
        {
            if (num1[i1] == num2[i2])
            {
                cont++;
                break;
            }
        }
    }

    return cont;
}

void ImprimeResult(int result, int n1)
{
    if (result == 0)
    {
        printf("NENHUM");
    }

    else if (result == n1)
    {
        printf("TODOS");
    }

    else if (result > 0 && result < n1)
    {
        printf("PARCIAL");
    }
}