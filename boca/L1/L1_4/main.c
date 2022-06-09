#define pi 3.141592
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main()
{
    float raio = 0.0;
    float area_circulo = 0.0;
    float area_circulo_metade = 0.0;
    float raio_metade = 0.0;

    scanf("%f", &raio);

    area_circulo = pi * pow(raio, 2);

    printf("%.2f ", area_circulo);

    area_circulo_metade = area_circulo / 2;

    raio_metade = sqrt(area_circulo_metade / pi);

    printf("%.2f", raio_metade);

    return 0;
}