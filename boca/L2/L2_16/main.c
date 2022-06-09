#include <stdlib.h>
#include <stdio.h>

int main()
{
    int num1 = 0, num2 = 0, numMenor1 = 32001, i = 0, posicaoFinal = 0, posicaoInicial = 0, primeira = 0, ultima = 0, numMenor2 = 0;

    while ((scanf("%d", &num1)) == 1)
    {
        if (num1 < numMenor1)
        {
            numMenor1 = num1;
        }
    }

    getchar();

    while ((scanf("%d", &num2)) == 1)
    {
        if (num2 == numMenor1)
        {
            i++;

            if (i == 1)
            {
                primeira = posicaoInicial;
            }

            numMenor2 = num2;
        }

        if (num2 == numMenor2)
        {
            ultima = posicaoFinal;
        }

        posicaoInicial++;
        posicaoFinal++;
    }

    if ((numMenor1 < numMenor2) || (numMenor2 > numMenor1))
    {
        printf("%d %d %d", numMenor1, posicaoInicial, posicaoFinal);
    }

    if (numMenor1 == numMenor2)
    {
        printf("%d %d %d", numMenor1, primeira, ultima);
    }

    return 0;
}