#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main()
{
    float x = 0, y = 0;

    scanf("%f %f", &x, &y);

    if (x == 0 && y == 0)
    {
        printf("ORIGEM\n");
    }

    else if (x != 0 && y == 0)
    {
        printf("X\n");
    }

    else if (x == 0 && y != 0)
    {
        printf("Y\n");
    }

    else if (x > 0 && y > 0)
    {
        printf("1\n");
    }

    else if (x < 0 && y > 0)
    {
        printf("2\n");
    }

    else if (x < 0 && y < 0)
    {
        printf("3\n");
    }

    else if (x > 0 && y < 0)
    {
        printf("4\n");
    }

    return 0;
}