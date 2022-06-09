#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct Forma
{
    float base;
    float altura;
    float raio;

} tForma;

tForma LehForma();

int EhCirculo(tForma forma);

int EhQuadrado(tForma forma);

int EhRetangulo(tForma forma);

void ImprimeFormas(int qtdCirculos, int qtdQuadrados, int qtdRetangulos);

int main()
{
    int n, i;
    int qtdQuadrados = 0, qtdCirculos = 0, qtdRetangulos = 0;

    tForma forma;

    scanf("%d\n", &n);

    for (i = 0; i < n; i++)
    {
        forma = LehForma();

        if (EhCirculo(forma) == 1)
        {
            qtdCirculos++;
        }

        else if (EhQuadrado(forma) == 1)
        {
            qtdQuadrados++;
        }

        else if (EhRetangulo(forma) == 1)
        {
            qtdRetangulos++;
        }
    }

    ImprimeFormas(qtdCirculos, qtdQuadrados, qtdRetangulos);

    return 0;
}

tForma LehForma()
{
    tForma forma;

    scanf("%f %f %f\n", &forma.base, &forma.altura, &forma.raio);

    return forma;
}

int EhCirculo(tForma forma)
{
    if (forma.altura < 0 && forma.base < 0 && forma.raio > 0)
    {
        return 1;
    }

    return 0;
}

int EhQuadrado(tForma forma)
{
    if (forma.altura > 0 && forma.base > 0 && forma.raio < 0 && forma.base == forma.altura)
    {
        return 1;
    }

    return 0;
}

int EhRetangulo(tForma forma)
{
    if (forma.altura > 0 && forma.base > 0 && forma.raio < 0 && forma.base != forma.altura)
    {
        return 1;
    }

    return 0;
}

void ImprimeFormas(int qtdCirculos, int qtdQuadrados, int qtdRetangulos)
{
    printf("Circulos: %d\n", qtdCirculos);
    printf("Quadrados: %d\n", qtdQuadrados);
    printf("Retangulos: %d", qtdRetangulos);
}