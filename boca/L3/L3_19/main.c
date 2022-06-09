#include <stdlib.h>
#include <stdio.h>
#include <math.h>

float TempoChegada(float distanciaMaisProxima, float velocidade);

int main()
{
    char cidade;
    float velocidade = 0, distancia = 0, tempo = 0;
    int num = 0, i = 0;
    char cidadeMaisProxima;
    float distanciaMaisProxima = 100000;
    float distanciaTotal = 0;

    scanf("%d ", &num);

    for (i = 0; i < num; i++)
    {
        scanf("%c %f ", &cidade, &distancia);

        if (distanciaMaisProxima > distancia)
        {
            cidadeMaisProxima = cidade;
            distanciaMaisProxima = distancia;
        }

        distanciaTotal += distancia;
    }

    printf("c: %c d: %.2f ", cidadeMaisProxima, distanciaMaisProxima);

    scanf("%f", &velocidade);

    tempo = TempoChegada(distanciaMaisProxima, velocidade);

    printf("t: %.2f", tempo);

    return 0;
}

float TempoChegada(float distanciaMaisProxima, float velocidade)
{
    float result = 0;

    result = distanciaMaisProxima / velocidade;

    return result;
}