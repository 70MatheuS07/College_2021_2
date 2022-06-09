#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char texto[500][500];
    char caracter;
    int i = 0, j = 0, cont = 0;

    while (scanf("%c", &caracter) == 1)
    {
        if ((caracter >= 'a' && caracter <= 'z') || (caracter >= 'A' && caracter <= 'Z'))
        {
            texto[i][j] = caracter;

            j++;
            cont = 1;
        }
        else
        {
            if (cont == 0)
            {
                continue;
            }

            texto[i][j] = '\0';

            i++;
            j = 0;
            cont = 0;
        }
    }

    for (i--; i >= 0; i--)
    {
        printf(" %s", texto[i]);
    }

    printf(" ");

    return 0;
}