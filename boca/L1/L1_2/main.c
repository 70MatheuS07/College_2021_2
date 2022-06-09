#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main()
{
    float num1 = 0.0, num2 = 0.0;
    float total = 0.0;

    scanf("%f %f", &num1, &num2);

    num1 *= 2;
    num2 *= 2;

    total = num1 + num2;

    printf("%.2f", total);

    return 0;
}