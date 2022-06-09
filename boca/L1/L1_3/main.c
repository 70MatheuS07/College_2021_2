#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main()
{
    float canto_inferior_esquerdo_x = 0.0, canto_inferior_esquerdo_y = 0.0;
    float canto_superior_direito_x = 0.0, canto_superior_direito_y = 0.0;

    float largura = 0.0, altura = 0.0, total = 0.0;

    scanf("%f %f %f %f", &canto_inferior_esquerdo_x, &canto_inferior_esquerdo_y, &canto_superior_direito_x, &canto_superior_direito_y);

    largura = canto_superior_direito_x - canto_inferior_esquerdo_x;
    altura = canto_superior_direito_y - canto_inferior_esquerdo_y;

    largura *= 2;
    altura *= 2;

    total = largura + altura;

    printf("%.2f", total);

    return 0;
}