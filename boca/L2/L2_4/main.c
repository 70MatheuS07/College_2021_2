#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main()
{
    int num = -1, i = 0;
    int num_maior = -2147483648;
    int total = 0;
    float media = 0;

    while (1)
    {
        scanf("%d\n", &num);

        if (num == 0)
        {
            break;
        }

        if (num > num_maior)
        {
            num_maior = num;
        }

        total += num;

        media = (float)total / (i + 1);

        printf("%d %.6f\n", num_maior, media);
        i++;
    }

    return 0;
}