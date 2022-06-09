#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void PreencheVetor(int num[], int n);
int QtdDeNumerosDentro(int num[], int n, int a, int b);
int QtdDeNumerosFora(int num[], int n, int a, int b);
void ImprimeQtdDentroFora(int qtdDentro, int qtdFora);

int main()
{
    int n = 0;
    int qtdDentro = 0;
    int qtdFora = 0;

    scanf("%d", &n);

    int num[n];

    PreencheVetor(num, n);

    int a = 0;
    int b = 0;

    scanf("%d", &a);
    scanf("%d", &b);

    qtdDentro = QtdDeNumerosDentro(num, n, a, b);

    qtdFora = QtdDeNumerosFora(num, n, a, b);

    ImprimeQtdDentroFora(qtdDentro, qtdFora);

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

int QtdDeNumerosDentro(int num[], int n, int a, int b)
{
    int i = 0, cont = 0;

    for (i = 0; i < n; i++)
    {
        if (num[i] >= a && num[i] <= b)
        {
            cont++;
        }
    }

    return cont;
}

int QtdDeNumerosFora(int num[], int n, int a, int b)
{
    int i = 0, cont = 0;

    for (i = 0; i < n; i++)
    {
        if (num[i] < a)
        {
            cont++;
        }

        else if (num[i] > b)
        {
            cont++;
        }
    }

    return cont;
}

void ImprimeQtdDentroFora(int qtdDentro, int qtdFora)
{
    printf("%d %d", qtdDentro, qtdFora);
}