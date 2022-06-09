#include <stdlib.h>
#include <stdio.h>

char ExcluiSpaces(char letra);

int main()
{
    char letra = 0;

    printf("RESP:");

    while (letra != 1)
    {
        scanf("%c", &letra);

        letra = ExcluiSpaces(letra);
    }

    return 0;
}

char ExcluiSpaces(char letra)
{
    if (letra == 32)
    {
        return 0;
    }

    else if (letra == 33)
    {
        printf("!");
        return 1;
    }

    else if (letra == 46)
    {
        printf(".");
        return 1;
    }

    else if (letra == 63)
    {
        printf("?");
        return 1;
    }

    else if (letra != (32) || (33) || (46) || (63))
    {
        printf("%c", letra);
        return 0;
    }
}