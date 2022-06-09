#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main()
{
    int x = 0, y = 0;
    int i = 0;
    float distancia = 0;
    float maiorDistancia = 0;
    int pontoMaiorDistancia_X = 0, pontoMaiorDistancia_Y = 0;

    for (i = 0; i < 5; i++)
    {
        scanf("%d %d ", &x, &y);

        distancia = (float)sqrt((x * x) + (y * y));

        if (maiorDistancia < distancia)
        {
            maiorDistancia = distancia;
            pontoMaiorDistancia_X = x;
            pontoMaiorDistancia_Y = y;
        }

        printf("%.2f ", distancia);
    }

    printf("Maior: %.2f p: (%d,%d)", maiorDistancia, pontoMaiorDistancia_X, pontoMaiorDistancia_Y);

    return 0;
}