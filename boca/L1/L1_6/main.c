#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main()
{
    int nota1 = 0, nota2 = 0;
    float media = 0.0;

    scanf("%d %d", &nota1, &nota2);

    media = (float)(nota1 + nota2) / 2;

    if (media < 5.0)
    {
        printf("%.1f - Reprovado", media);
    }

    else if (media >= 7.0)
    {
        printf("%.1f - Aprovado", media);
    }

    else
    {
        printf("%.1f - De Recuperacao", media);
    }

    return 0;
}