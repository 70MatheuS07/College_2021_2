#include <stdlib.h>
#include <stdio.h>

int main()
{
    int linha = 0, coluna = 0, valor = 0, matriz, i, j, valorMaior = 0, linhaDoMaior = 0, colunaDoMaior = 0;

    scanf("%d %d", &linha, &coluna);

    if ((linha >= 1) && (linha <= 100) && (coluna >= 1) && (coluna <= 100))
    {
        for (i = 1; i <= linha; i++)
        {
            for (j = 1; j <= coluna; j++)
            {
                scanf("%d ", &valor);

                if ((valor >= -32767) && (valor <= 32767))
                {
                    if (valor >= valorMaior)
                    {
                        valorMaior = valor;
                        linhaDoMaior = i;
                        colunaDoMaior = j;
                    }
                }
            }
        }
    }

    printf("%d (%d, %d)", valorMaior, linhaDoMaior, colunaDoMaior);

    return 0;
}