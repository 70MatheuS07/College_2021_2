#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main()
{
    int num = 0, ordem = 0;

    scanf("%d %d", &num, &ordem);

    if (ordem == 1)
    {
        num %= 10;

        if (num % 2 == 0)
        {
            printf("PAR");
        }

        else
        {
            printf("IMPAR");
        }
    }

    else if (ordem == 2)
    {
        num %= 100;
        num /= 10;

        if (num % 2 == 0)
        {
            printf("PAR");
        }

        else
        {
            printf("IMPAR");
        }
    }

    else
    {
        num %= 1000;
        num /= 100;

        if (num % 2 == 0)
        {
            printf("PAR");
        }

        else
        {
            printf("IMPAR");
        }
    }

    return 0;
}