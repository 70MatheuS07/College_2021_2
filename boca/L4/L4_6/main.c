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

tPonto LePonto();

tReta LeReta();

tPonto Defini_Inicial(tReta reta);

int ComparaDistancia(tPonto ponto, tReta reta);

void ImprimePonto(tPonto ponto, int quadrante);

tPonto AchaSimetrico(tPonto ponto);

int IdentificaQuadrante(tPonto ponto);

float DistanciaEntrePontos(tPonto ponto1, tPonto ponto2);

tPonto InicializaPonto(int x, int y);

int ObtemOrdenada(tPonto ponto);

int ObtemAbscissa(tPonto ponto);

tPonto MovePonto(tPonto ponto, int deltaX, int deltaY);

void ImprimeDistancia(float distancia);

void ImprimeResultado(int distancia);

tReta InicializaReta(tPonto ponto1, tPonto ponto2);

void ImprimeReta(tReta reta);

tPonto DefiniFinal(tReta reta);

tReta MovimentaReta(tReta reta, int deltaX, int deltaY);

float TamanhoDaReta(tReta reta);

int main()
{
    int n = 0, i = 1;
    int distancia = -1;

    tPonto ponto = {0, 0};
    tReta reta = {0, 0, 0, 0};

    scanf("%d\n", &n);

    for (i = 1; i <= n; i++)
    {
        ponto = LePonto();

        reta = LeReta();

        distancia = ComparaDistancia(ponto, reta);

        ImprimeResultado(distancia);
    }

    return 0;
}

tPonto LePonto()
{
    tPonto ponto;

    scanf("%d %d ", &ponto.x, &ponto.y);

    return ponto;
}

tReta LeReta()
{
    tReta retaRtn;

    retaRtn.pi = LePonto();
    retaRtn.pf = LePonto();

    return retaRtn;
}

int ComparaDistancia(tPonto ponto, tReta reta)
{
    float distanciaPi = 0, distanciaPf = 0;
    float deltaXi = 0, deltaXf = 0;
    float deltaYi = 0, deltaYf = 0;

    distanciaPi = DistanciaEntrePontos(ponto, reta.pi);

    distanciaPf = DistanciaEntrePontos(ponto, reta.pf);

    if (distanciaPi > distanciaPf)
    {
        return 2;
    }

    else if (distanciaPi == distanciaPf)
    {
        return 1;
    }

    else if (distanciaPi < distanciaPf)
    {
        return 0;
    }
}

void ImprimeResultado(int distancia)
{
    if (distancia == 0)
    {
        printf("INICIO\n");
    }

    else if (distancia == 1)
    {
        printf("EQUIDISTANTE\n");
    }

    else if (distancia == 2)
    {
        printf("FIM\n");
    }
}

void ImprimePonto(tPonto ponto, int quadrante)
{
    printf("(%d,%d) %d", ponto.x, ponto.y, quadrante);
}

tPonto AchaSimetrico(tPonto ponto)
{
    ponto.x *= -1;

    ponto.y *= -1;

    return ponto;
}

int IdentificaQuadrante(tPonto ponto)
{
    if (ponto.x == 0 || ponto.y == 0)
    {
        return 0;
    }

    else if (ponto.x > 0)
    {
        if (ponto.y > 0)
        {
            return 1;
        }

        else if (ponto.y < 0)
        {
            return 4;
        }
    }
    else
    {
        if (ponto.y > 0)
        {
            return 2;
        }

        else if (ponto.y < 0)
        {
            return 3;
        }
    }
}

float DistanciaEntrePontos(tPonto ponto1, tPonto ponto2)
{
    float distancia = 0, deltaX = 0, deltaY = 0;

    deltaX = ponto2.x - ponto1.x;
    deltaY = ponto2.y - ponto1.y;
    distancia = (pow(deltaX, 2)) + (pow(deltaY, 2));
    distancia = sqrt(distancia);

    return distancia;
}

tPonto InicializaPonto(int x, int y)
{
    tPonto pontoRtn;

    pontoRtn = (tPonto){x, y};

    return pontoRtn;
}

int PegaAbscissa(tPonto ponto)
{
    int x = 0;

    x = ponto.x;

    return x;
}

int PegaOrdenada(tPonto ponto)
{
    int y = 0;

    y = ponto.y;

    return y;
}

tPonto MovePonto(tPonto ponto, int deltaX, int deltaY)
{
    ponto.x += deltaX;
    ponto.y += deltaY;

    return ponto;
}

void ImprimeDistancia(float distancia)
{
    printf("%.2f\n", distancia);
}

tReta InicializaReta(tPonto ponto1, tPonto ponto2)
{
    tReta retaRtn;

    retaRtn = (tReta){ponto1, ponto2};

    return retaRtn;
}

void ImprimeReta(tReta reta)
{
    printf("[(%d,%d):(%d,%d)]", reta.pi.x, reta.pi.y, reta.pf.x, reta.pf.y);
}

tPonto Defini_Inicial(tReta reta)
{
    tPonto inicial = {0, 0};

    inicial.x = reta.pi.x;
    inicial.y = reta.pi.y;

    return inicial;
}

tPonto Defini_Final(tReta reta)
{
    tPonto final = {0, 0};

    final.x = reta.pf.x;
    final.y = reta.pf.y;

    return final;
}

tReta MovimentaReta(tReta reta, int deltaX, int deltaY)
{
    reta.pi = MovePonto(reta.pi, deltaX, deltaY);
    reta.pf = MovePonto(reta.pf, deltaX, deltaY);

    return reta;
}

float TamanhoDaReta(tReta reta)
{
    float tamanho = 0;

    tamanho = DistanciaEntrePontos(reta.pi, reta.pf);

    return tamanho;
}