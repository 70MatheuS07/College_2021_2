#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define PI 3.141592

float AreaCirculo(float raio);

float VolumeCaixa(float raio, float altura);

int main()
{
    float casas = 0, raio = 0, altura = 0, qtdCaixasDagua = 0, qtdDias = 0;
    float volumeCaixa = 0;
    float volumeAguaTotal = 0;

    scanf("%f %f %f %f %f", &casas, &raio, &altura, &qtdCaixasDagua, &qtdDias);

    volumeCaixa = VolumeCaixa(raio, altura);

    volumeAguaTotal = volumeCaixa * qtdDias * casas * qtdCaixasDagua;

    printf("Resp: %.2f L", volumeAguaTotal);

    return 0;
}

float AreaCirculo(float raio)
{
    float result = 0;

    result = PI * (raio * raio);

    return result;
}

float VolumeCaixa(float raio, float altura)
{
    float result = 0, areaCirculo = 0;

    areaCirculo = AreaCirculo(raio);

    result = areaCirculo * altura;

    return result;
}