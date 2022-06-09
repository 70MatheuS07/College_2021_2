#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main()
{
    int pessoas = 0, itens = 0;
    int result = 0;

    scanf("%d %d", &pessoas, &itens);

    if (pessoas == 1 || itens == 1)
    {
        printf("RESP:1");
    }

    else if (itens == pessoas)
    {
        printf("RESP:%d", pessoas);
    }

    else if (itens % pessoas == 0)
    {
        printf("RESP:%d", pessoas);
    }

    else
    {
        result = itens % pessoas;

        printf("RESP:%d", result);
    }

    return 0;
}