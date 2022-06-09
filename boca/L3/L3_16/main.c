#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main()
{
    int i = 0;
    char caracter;
    int cont = 0;

    while (1)
    {
        scanf("%c", &caracter);

        if (caracter == '.')
        {
            break;
        }

        if ((caracter >= 'a' && caracter <= 'z') || (caracter >= 'A' && caracter <= 'Z'))
        {
            cont++;
        }
    }

    printf("RESP: %d", cont);

    return 0;
}