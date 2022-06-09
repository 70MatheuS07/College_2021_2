#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void PreencheVetor(int num[], int n);
int ProcuraIguais(int num[], int nProcurado, int n);
void ImprimeQtdNumerosIguais(int qtdNumerosIguais);

int main()
{
    int nProcurado = 0, n = 0;
    int qtdNumerosIguais = 0;

    scanf("%d", &nProcurado);

    scanf("%d", &n);

    int num[n];

    PreencheVetor(num, n);

    qtdNumerosIguais = ProcuraIguais(num, nProcurado, n);

    ImprimeQtdNumerosIguais(qtdNumerosIguais);

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

int ProcuraIguais(int num[], int nProcurado, int n)
{
    int i = 0;

    for (i = 0; i < n; i++)
    {
        if (num[i] == nProcurado)
        {
            return i;
        }
    }

    return n;
}

void ImprimeQtdNumerosIguais(int qtdNumerosIguais)
{
    printf("RESP:%d", qtdNumerosIguais);
}

