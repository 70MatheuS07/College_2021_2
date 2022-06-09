#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main()
{
    float peso = 0, altura = 0;
    float IMC = 0;

    scanf("%f %f", &peso, &altura);

    IMC = peso / (pow(altura, 2));

    printf("%.2f\n", IMC);

    return 0;
}