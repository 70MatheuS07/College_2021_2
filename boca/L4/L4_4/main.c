#include <stdlib.h>
#include <stdio.h>

typedef struct
{
    int x;
    int y;

} tPonto;

tPonto LePonto();

void ImprimePonto(tPonto ponto);

int QuadranteDoPonto(tPonto ponto);

void ImprimeQuadrante(int quadrante);

tPonto AlteraAbscissaX(tPonto ponto);

tPonto AlteraOrdeenadaY(tPonto ponto);

int main()
{
    int i = 0, n = 0;
    int quadrante = -1;

    tPonto ponto;

    scanf("%d\n", &n);

    for (i = 1; i <= n; i++)
    {
        ponto = LePonto();

        ImprimePonto(ponto);

        quadrante = QuadranteDoPonto(ponto);

        printf(" ");

        ImprimeQuadrante(quadrante);

        printf(" ");

        ponto = AlteraAbscissaX(ponto);

        ponto = AlteraOrdeenadaY(ponto);

        ImprimePonto(ponto);

        quadrante = QuadranteDoPonto(ponto);

        printf(" ");

        ImprimeQuadrante(quadrante);

        printf("\n");
    }

    return 0;
}

tPonto LePonto()
{
    tPonto ponto;

    scanf("%d %d", &ponto.x, &ponto.y);

    return ponto;
}

void ImprimePonto(tPonto ponto)
{
    printf("(%d,%d)", ponto.x, ponto.y);
}

int QuadranteDoPonto(tPonto ponto)
{
    if (ponto.x > 0 && ponto.y > 0)
    {
        return 1;
    }

    else if (ponto.x < 0 && ponto.y > 0)
    {
        return 2;
    }

    else if (ponto.x < 0 && ponto.y < 0)
    {
        return 3;
    }

    else if (ponto.x > 0 && ponto.y < 0)
    {
        return 4;
    }

    return 0;
}

void ImprimeQuadrante(int quadrante)
{
    printf("%d", quadrante);
}

tPonto AlteraAbscissaX(tPonto ponto)
{
    if (ponto.x > 0 || ponto.x < 0)
    {
        ponto.x *= -1;
    }

    return ponto;
}

tPonto AlteraOrdeenadaY(tPonto ponto)
{
    if (ponto.y > 0 || ponto.y < 0)
    {
        ponto.y *= -1;
    }

    return ponto;
}