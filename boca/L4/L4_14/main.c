#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define PI 3.141592

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

float AreaCirculo(tForma forma);

float AreaQuadrado(tForma forma);

float AreaRetangulo(tForma forma);

int main()
{
    int n, i;
    int qtdQuadrados = 0, qtdCirculos = 0, qtdRetangulos = 0;

    float areaCirculo = 0, areaQuadrado = 0, areaRetangulo = 0;
    float totalAreaCirculo = 0, totalAreaQuadrado = 0, totalAreaRetangulo = 0;

    tForma forma;

    scanf("%d\n", &n);

    for (i = 0; i < n; i++)
    {
        forma = LehForma();

        if (EhCirculo(forma) == 1)
        {
            areaCirculo = AreaCirculo(forma);

            totalAreaCirculo += areaCirculo;

            qtdCirculos++;
        }

        else if (EhQuadrado(forma) == 1)
        {
            areaQuadrado = AreaQuadrado(forma);

            totalAreaQuadrado += areaQuadrado;

            qtdQuadrados++;
        }

        else if (EhRetangulo(forma) == 1)
        {
            areaRetangulo = AreaRetangulo(forma);

            totalAreaRetangulo += areaRetangulo;

            qtdRetangulos++;
        }
    }

    printf("Circulos: %d Area: %.2f\n", qtdCirculos, totalAreaCirculo);
    printf("Quadrados: %d Area: %.2f\n", qtdQuadrados, totalAreaQuadrado);
    printf("Retangulos: %d Area: %.2f", qtdRetangulos, totalAreaRetangulo);

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

float AreaCirculo(tForma forma)
{
    float result;

    result = PI * forma.raio * forma.raio;

    return result;
}

float AreaQuadrado(tForma forma)
{
    float result;

    result = forma.base * forma.altura;

    return result;
}

float AreaRetangulo(tForma forma)
{
    float result;

    result = forma.base * forma.altura;

    return result;
}