#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main()
{
    int num = 0;

    scanf("%d", &num);

    if (num % 2 == 0)
    {
        printf("Par");
    }

    else
    {
        printf("Impar");
    }

    return 0;
}