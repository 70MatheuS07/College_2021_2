#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int Propriedade(int num);

int main()
{
    int n = 0, m = 0, num = 0;

    scanf("%d %d", &n, &m);

    num = n + 1;

    while (num < m)
    {
        if (Propriedade(num) == 1)
        {
            printf("%d\n", num);
        }

        num++;
    }

    return 0;
}

int Propriedade(int num)
{
    int ab = 0, cd = 0, ef = 0;

    ab = (num / 100);
    cd = (num - (ab * 100));
    ef = (ab + cd);

    if (ef * ef == num)
    {
        return 1;
    }

    return 0;
}