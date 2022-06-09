#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main()
{
    float a = 0, b = 0, c = 0, d = 0;
    float x = 0, y = 0, xAnterior = 0, xPosterior = 0, yAnterior = 0, yPosterior = 0;
    int e = 0, f = 0, loopPico = 0, loopVale = 0;

    scanf("%f %f %f %f %d %d", &a, &b, &c, &d, &e, &f);

    float vale = (f + 1), pico = (f + 1);

    for (x = e; x <= f; x++)
    {
        xAnterior = x + 1;
        xPosterior = x - 1;

        y = (a * pow(x, 3)) + (b * pow(x, 2)) + (c * x) + d;
        yAnterior = (a * pow(xAnterior, 3)) + (b * pow(xAnterior, 2)) + (c * xAnterior) + d;
        yPosterior = (a * pow(xPosterior, 3)) + (b * pow(xPosterior, 2)) + (c * xPosterior) + d;

        if ((y > yAnterior) && (y > yPosterior) && (loopPico == 0))
        {
            pico = x;
            printf("Pico em x=%.f\n", pico);
            loopPico++;
        }

        if ((y < yAnterior) && (y < yPosterior) && (loopVale == 0))
        {
            vale = x;

            if (x != 0)
            {
                printf("Vale em x=%.f\n", vale);
            }

            else if (x == 0)
            {
                printf("Vale em x=0\n");
            }
            loopVale++;
        }
    }

    if (loopPico == 0)
    {
        printf("Nao ha pico\n");
    }

    if (loopVale == 0)
    {
        printf("Nao ha vale");
    }

    return 0;
}