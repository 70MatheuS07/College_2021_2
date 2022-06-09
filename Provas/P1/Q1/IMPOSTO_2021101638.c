#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main()
{
    int estado = 0;
    float valor_produto = 0;
    float conta = 0, imposto = 0;

    scanf("%d %f", &estado, &valor_produto);

    if (estado == 27)
    {
        conta += valor_produto;
        imposto = (valor_produto * 7) / 100;
        conta += imposto;

        printf("R$ %.2f", conta);
    }

    else if (estado == 31)
    {
        conta += valor_produto;
        imposto = (valor_produto * 12) / 100;
        conta += imposto;

        printf("R$ %.2f", conta);
    }

    else if (estado == 15)
    {
        conta += valor_produto;
        imposto = (valor_produto * 15) / 100;
        conta += imposto;

        printf("R$ %.2f", conta);
    }

    else if (estado == 77)
    {
        conta += valor_produto;
        imposto = (valor_produto * 16) / 100;
        conta += imposto;

        printf("R$ %.2f", conta);
    }

    else
    {
        printf("Estado nao reconhecido.");
    }

    return 0;
}