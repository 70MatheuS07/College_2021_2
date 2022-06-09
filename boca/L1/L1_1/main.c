#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main()
{
    int num1 = 0, num2 = 0;
    float result1 = 0.0, result2 = 0.0;
    float total = 0.0;

    scanf("%d %d", &num1, &num2);

    result1 = sqrt(num1);
    result2 = sqrt(num2);

    total = result1 + result2;

    printf("%.2f", total);

    return 0;
}