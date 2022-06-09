#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main()
{
    int qtd_num = 0;
    int num = 0, i = 0;
    int num_menor = 2147483647, num_maior = 0;
    int pares = 0, impares = 0;
    int soma = 0;
    float media = 0;

    scanf("%d\n", &qtd_num);

    for (i = 0; i < qtd_num; i++)
    {
        scanf("%d", &num);

        if (i != qtd_num - 1)
        {
            scanf(" ");
        }

        if (num_menor > num)
        {
            num_menor = num;
        }

        if (num_maior < num)
        {
            num_maior = num;
        }

        if (num % 2 == 0)
        {
            pares++;
        }

        else
        {
            impares++;
        }

        soma += num;
    }

    media = (float)soma / qtd_num;

    printf("%d %d %d %d %.6f", num_maior, num_menor, pares, impares, media);

    return 0;
}