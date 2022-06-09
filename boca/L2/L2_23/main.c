#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main()
{
    char letra;
    int inicio = 0, Parenteses = 0, i = 0;

    while (1)
    {
        scanf("%c", &letra);

        if (letra == '(')
        {
            Parenteses = Parenteses + 1;
        }

        else if (letra == ')')
        {
            Parenteses = Parenteses - 1;
        }

        if (Parenteses == 0)
        {
            inicio = 0;

            if (letra == '.')
            {
                break;
            }
        }

        if (inicio == 1)
        {
            printf("%c", letra);
        }

        if (letra == '(')
        {
            inicio = 1;
        }

        if (i == 0)
        {
            printf("RESP:");
        }

        i++;
    }

    return 0;
}