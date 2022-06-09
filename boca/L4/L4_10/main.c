#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct
{
    int x;
    int y;

} tPonto;

typedef struct
{
    tPonto pi;
    tPonto pf;

} tReta;

tPonto LehPonto();

float Distancia(tPonto ponto, tPonto pontoFixo);

int MaisProximo(float distancia, float distanciaMaisProxima);

tPonto RegistraPontoMaisProximo(tPonto ponto);

void ImprimePonto(tPonto pontoMaisProximo);

int main()
{
    int n = 0, i = 0;

    float distancia = 0, distanciaMaisProxima = 1000000;

    tPonto ponto, pontoFixo, pontoMaisProximo;

    scanf("%d\n", &n);

    for (i = 0; i < n; i++)
    {
        if (i == 0)
        {
            pontoFixo = LehPonto();
            i++;
        }

        ponto = LehPonto();

        distancia = Distancia(ponto, pontoFixo);

        if (MaisProximo(distancia, distanciaMaisProxima) == 1)
        {
            pontoMaisProximo = RegistraPontoMaisProximo(ponto);

            distanciaMaisProxima = distancia;
        }
    }

    ImprimePonto(pontoMaisProximo);

    return 0;
}

tPonto LehPonto()
{
    tPonto ponto;

    scanf("%d %d\n", &ponto.x, &ponto.y);

    return ponto;
}

float Distancia(tPonto ponto, tPonto pontoFixo)
{
    float distancia = 0, deltaX = 0, deltaY = 0;

    deltaX = pontoFixo.x - ponto.x;
    deltaY = pontoFixo.y - ponto.y;
    distancia = (pow(deltaX, 2)) + (pow(deltaY, 2));
    distancia = sqrt(distancia);

    return distancia;
}

int MaisProximo(float distancia, float distanciaMaisProxima)
{
    if (distancia < distanciaMaisProxima)
    {
        return 1;
    }

    return 0;
}

tPonto RegistraPontoMaisProximo(tPonto ponto)
{
    tPonto result;

    result.x = ponto.x;
    result.y = ponto.y;

    return result;
}

void ImprimePonto(tPonto pontoMaisProximo)
{
    printf("Mais proximo:(%d,%d)", pontoMaisProximo.x, pontoMaisProximo.y);
}