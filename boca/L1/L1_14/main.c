#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main()
{

    int x1 = 0, y1 = 0, x2 = 0, y2 = 0, x = 0, y = 0;

    scanf("%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x, &y);

    if (x1 > x2 && y1 > y2 && x <= x1 && x >= x2 && y <= y1 && y >= y2)
    {
        printf("Dentro");
    }

    else if (x1 < x2 && y1 < y2 && x >= x1 && x <= x2 && y >= y1 && y <= y2)
    {
        printf("Dentro");
    }

    else if (x1 > x2 && y1 < y2 && x <= x1 && x >= x2 && y >= y1 && y <= y2)
    {
        printf("Dentro");
    }

    else if (x1 < x2 && y1 > y2 && x >= x1 && x <= x2 && y <= y1 && y >= y2)
    {
        printf("Dentro");
    }

    else
    {
        printf("Fora");
    }

    return 0;
}