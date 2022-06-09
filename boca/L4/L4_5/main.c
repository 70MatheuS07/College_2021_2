#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct
{
    int x;
    int y;

} tPonto;

tPonto LePonto();

float CalculaDistanciaEntrePontos(tPonto ponto, tPonto pontoBase, float x, float y);

void ImprimeDistancia(float hipotenusa);

int main()
{
    int i = 0, n = 0;
    float hipotenusa, x, y;
    tPonto pontoBase = {0, 0};
    tPonto ponto;

    scanf("%d\n", &n);

    for (i = 1; i <= n; i++)
    {
        if (i == 1)
        {
            pontoBase = LePonto();
            printf("-\n");
        }
        else
        {
            ponto = LePonto();

            hipotenusa = CalculaDistanciaEntrePontos(ponto, pontoBase, x, y);

            ImprimeDistancia(hipotenusa);

            pontoBase = ponto;
        }
    }

    return 0;
}

tPonto LePonto()
{
    tPonto ponto;

    scanf("%d %d", &ponto.x, &ponto.y);

    return ponto;
}

float CalculaDistanciaEntrePontos(tPonto ponto, tPonto pontoBase, float x, float y)
{
    if (ponto.x == pontoBase.x)
    {
        ponto.y -= pontoBase.y;

        if (ponto.y < 0)
        {
            ponto.y *= -1;
        }
        return ponto.y;
    }

    else if (ponto.y == pontoBase.y)
    {
        ponto.x -= pontoBase.x;

        if (ponto.x < 0)
        {
            ponto.x *= -1;
        }
        return ponto.x;
    }

    else
    {
        ponto.x -= pontoBase.x;

        if (ponto.x < 0)
        {
            ponto.x *= -1;
        }

        ponto.y -= pontoBase.y;

        if (ponto.y < 0)
        {
            ponto.y *= -1;
        }

        x = ponto.x;
        y = ponto.y;

        x = sqrt(pow(x, 2) + pow(y, 2));
        return x;
    }
}

void ImprimeDistancia(float hipotenusa)
{
    printf("%.2f\n", hipotenusa);
}