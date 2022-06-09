#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

#define PASSAGEM 100
#define COMBUSTIVEL 5

typedef struct Posicao
{
    float x;
    float y;
    int passageiros;

} tPosicao;

typedef struct Stats
{
    int totalPassageiros;
    float distanciaPercorrida;
    float lucro;

} tStats;

typedef struct Onibus
{
    int id;
    tPosicao posicoes[4];
    tStats estatisticas;

} tOnibus;

void PreencheOnibus(tOnibus onibus[30], int num, int semente);

tPosicao InicializaPosicao(int semente);

int PessoasNoPonto();

float DistanciaTotal(tOnibus onibus[30], int i);

void ImprimeRelatorio(tOnibus onibus[30], int num);

void OrdenaDecrescente(tOnibus onibus[30], int num);

void TrocaValor(tOnibus onibus[30], int i, int j);

float CalculaLucro(tOnibus onibus[30], int i);

int main()
{
    int semente = 0, num = 0;

    tOnibus onibus[30];

    scanf("%d\n%d", &semente, &num);

    if ((semente > 0 && semente <= 100) && (num >= 1 && num <= 30))
    {
        PreencheOnibus(onibus, num, semente);

        OrdenaDecrescente(onibus, num);

        ImprimeRelatorio(onibus, num);
    }

    else
    {
        printf("Entrada invalida!\n");
    }

    return 0;
}

void PreencheOnibus(tOnibus onibus[30], int num, int semente)
{
    int i = 0, j = 0, l = 0;

    for (i = 0; i < num; i++)
    {
        onibus[i].id = i + 1;

        for (j = 0; j < 4; j++)
        {
            onibus[i].posicoes[j] = InicializaPosicao(semente);
            onibus[i].estatisticas.totalPassageiros += onibus[i].posicoes[j].passageiros;
        }

        onibus[i].estatisticas.distanciaPercorrida = DistanciaTotal(onibus, i);

        onibus[i].estatisticas.lucro = CalculaLucro(onibus, num);
    }
}

float CalculaLucro(tOnibus onibus[30], int i)
{
    int j = 0;
    float lucro = 0;

    for (j = 0; j < 4; j++)
    {
        lucro = (onibus[i].estatisticas.totalPassageiros * PASSAGEM) - (onibus[i].estatisticas.distanciaPercorrida * COMBUSTIVEL);
    }

    return lucro;
}

tPosicao InicializaPosicao(int semente)
{
    float result = 0;
    int num = 0;

    tPosicao posicao;

    srand((unsigned)time(NULL));

    result = (((float)rand() / (float)(RAND_MAX)) * semente);

    posicao.x = result;

    result = (((float)rand() / (float)(RAND_MAX)) * semente);

    posicao.y = result;

    posicao.passageiros = PessoasNoPonto();

    return posicao;
}

int PessoasNoPonto()
{
    int num = 0;

    srand((unsigned)time(NULL));

    num = (rand() % 2);

    if (num == 1)
    {
        num = (rand() % 20);
    }

    return num;
}

float DistanciaTotal(tOnibus onibus[30], int i)
{
    int j = 0;
    float x = 0, y = 0;
    float distancia = 0, deltaX = 0, deltaY = 0;
    float distanciaTotal = 0;

    for (j = 0; j < 4; j++)
    {
        deltaX = x - onibus[i].posicoes[j].x;
        deltaY = y - onibus[i].posicoes[j].y;
        distancia = (pow(deltaX, 2)) + (pow(deltaY, 2));
        distancia = sqrt(distancia);
        distanciaTotal += distancia;

        x = onibus[i].posicoes[j].x;
        y = onibus[i].posicoes[j].y;
    }

    return distanciaTotal;
}

void ImprimeRelatorio(tOnibus onibus[30], int num)
{
    int i = 0, j = 0;

    for (i = 0; i < num; i++)
    {
        printf("%d\t%d\t%.2f\t%.2f\n", onibus[i].id, onibus[i].estatisticas.totalPassageiros, onibus[i].estatisticas.distanciaPercorrida, onibus[i].estatisticas.lucro);

        for (j = 0; j < 4; j++)
        {
        }
    }
}

void OrdenaDecrescente(tOnibus onibus[30], int num)
{
    int i, menor, aux, j;

    for (i = 0; i < num - 1; i++)
    {
        for (j = i + 1; j < num; j++)
        {
            if (onibus[i].estatisticas.lucro < onibus[j].estatisticas.lucro)
            {
                TrocaValor(onibus, i, j);
            }
        }
    }
}

void TrocaValor(tOnibus onibus[30], int i, int j)
{
    tOnibus aux;

    aux = onibus[j];
    onibus[j] = onibus[i];
    onibus[i] = aux;
}