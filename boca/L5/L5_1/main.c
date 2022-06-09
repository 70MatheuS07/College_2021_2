#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void PreencheVetor(int num[], int n);
int IdentificaMenorNota(int num[], int n);
int IdentificaMaiorNota(int num[], int n);
int SomaDasNotas(int num[], int n);
float CalculaMedia(int soma, int n);
float CalculaDesvioPadrao(int n, int num[], float media);
int QuantidadeDeAlunosAcimaDaMedia(int num[], int n, int media);
int QuantidadeDeAlunosReprovados(int num[], int n);

int main()
{
    int n = 0, i = 0;
    int menorNota = 0;
    int maiorNota = 0;
    int soma = 0;
    float media;
    float desvioPadrao;
    int qtdAlunosAcimaDaMediaDoConcurso = 0;
    int qtdAlunosReprovados = 0;

    scanf("%d", &n);

    int num[n];

    PreencheVetor(num, n);

    menorNota = IdentificaMenorNota(num, n);
    printf("MENOR:%d, ", menorNota);

    maiorNota = IdentificaMaiorNota(num, n);
    printf("MAIOR:%d, ", maiorNota);

    soma = SomaDasNotas(num, n);
    media = CalculaMedia(soma, n);
    printf("MEDIA:%.2f, ", media);

    desvioPadrao = CalculaDesvioPadrao(n, num, media);
    printf("STD:%.2f, ", desvioPadrao);

    qtdAlunosAcimaDaMediaDoConcurso = QuantidadeDeAlunosAcimaDaMedia(num, n, media);
    printf("ACIMA_MEDIA_CONC:%d, ", qtdAlunosAcimaDaMediaDoConcurso);

    qtdAlunosReprovados = QuantidadeDeAlunosReprovados(num, n);
    printf("REPROV:%d", qtdAlunosReprovados);

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

int IdentificaMenorNota(int num[], int n)
{
    int menorNota = 101;
    int i = 0;

    for (i = 0; i < n; i++)
    {
        if (num[i] < menorNota)
        {
            menorNota = num[i];
        }
    }

    return menorNota;
}

int IdentificaMaiorNota(int num[], int n)
{
    int maiorNota = -1;
    int i = 0;

    for (i = 0; i < n; i++)
    {
        if (num[i] > maiorNota)
        {
            maiorNota = num[i];
        }
    }

    return maiorNota;
}

int SomaDasNotas(int num[], int n)
{
    int soma = 0;
    int i = 0;

    for (i = 0; i < n; i++)
    {
        soma += num[i];
    }

    return soma;
}

float CalculaMedia(int soma, int n)
{
    float media = 0;

    media = (float)soma / n;

    return media;
}

float CalculaDesvioPadrao(int n, int num[], float media)
{
    float somado = 0;
    float somatorio = 0;
    float desvio = 0;
    int i = 0;

    for (i = 0; i < n; i++)
    {
        somado = pow((num[i] - media), 2);
        somatorio += somado;
    }

    desvio = somatorio / n;

    desvio = sqrt(desvio);

    return desvio;
}

int QuantidadeDeAlunosAcimaDaMedia(int num[], int n, int media)
{
    int i = 0;
    int cont = 0;

    for (i = 0; i < n; i++)
    {
        if (num[i] > media)
        {
            cont += 1;
        }
    }

    return cont;
}

int QuantidadeDeAlunosReprovados(int num[], int n)
{
    int i = 0;
    int cont = 0;

    for (i = 0; i < n; i++)
    {
        if (num[i] < 70)
        {
            cont += 1;
        }
    }

    return cont;
}