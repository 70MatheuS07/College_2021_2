#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main()
{
    float a = 0, b = 0, c = 0;
    float delta = 0, x1 = 0, x2 = 0;

    scanf("%f %f %f", &a, &b, &c);

    delta = (b * b) - (4 * a * c);

    if (delta < 0)
    {
        printf("Nao ha raizes reais");
    }

    else
    {
        x1 = ((-1 * b) + (sqrt(delta))) / (2 * a);
        x2 = ((-1 * b) - (sqrt(delta))) / (2 * a);

        printf("x1: %.2f x2: %.2f", x1, x2);
    }

    return 0;
}