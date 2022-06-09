#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main()
{
    int temperatura = 0;
    char escala;
    float conta = 0.0;

    scanf("%d %c", &temperatura, &escala);

    if (escala == 'c' || escala == 'C')
    {
        conta = (float)temperatura * 1.8;
        conta += 32;

        printf("%.2f (F)", conta);
    }

    else
    {
        temperatura -= 32;

        conta = (float)temperatura / 1.8;

        printf("%.2f (C)", conta);
    }

    return 0;
}