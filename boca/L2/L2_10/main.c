#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main()
{
    int n = 0, m = 0, i = 1, resultadoTabuada = 0;

    scanf("%d %d", &n, &m);

    while (n <= m)
    {
        while (i <= 10)
        {
            resultadoTabuada = (n * i);
            printf("%d x %d = %d\n", n, i, resultadoTabuada);

            resultadoTabuada = 0;
            i++;
        }

        i = 1;
        n++;
    }

    return 0;
}