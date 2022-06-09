#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define PI 3.141593

int main()
{
    float raio_menor = 0;
    float raio_maior = 0;
    float area_menor = 0;
    float area_maior = 0;
    float area_cinza = 0;

    scanf("%f", &raio_menor);

    raio_maior = 1.5 * raio_menor;

    area_menor = PI * raio_menor * raio_menor;

    area_maior = PI * raio_maior * raio_maior;

    area_cinza = area_maior - area_menor;

    printf("%.4f\n", area_cinza);

    return 0;
}