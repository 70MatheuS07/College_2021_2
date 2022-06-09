#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main()
{
    int num1 = 0, num2 = 0, num3 = 0;

    scanf("%d %d %d", &num1, &num2, &num3);

    if (num1 < num2 && num2 < num3)
    {
        printf("N1 = %d, N2 = %d, N3 = %d", num1, num2, num3);
    }

    else if (num1 < num3 && num3 < num2)
    {
        printf("N1 = %d, N3 = %d, N2 = %d", num1, num3, num2);
    }

    else if (num2 < num1 && num1 < num3)
    {
        printf("N2 = %d, N1 = %d, N3 = %d", num2, num1, num3);
    }

    else if (num2 < num3 && num3 < num1)
    {
        printf("N2 = %d, N3 = %d, N1 = %d", num2, num3, num1);
    }

    else if (num3 < num1 && num1 < num2)
    {
        printf("N3 = %d, N1 = %d, N2 = %d", num3, num1, num2);
    }

    else if (num3 < num2 && num2 < num1)
    {
        printf("N3 = %d, N2 = %d, N1 = %d", num3, num2, num1);
    }

    return 0;
}