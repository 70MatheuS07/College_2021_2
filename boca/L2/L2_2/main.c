#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main()
{
    int n = 0, m = 0, i = 0;

    scanf("%d %d", &n, &m);

    for (i = n + 1; i < m; i++)
    {
        if (i % 3 == 0)
        {
            printf("%d ", i);
        }

        else if (i % 4 == 0)
        {
            printf("%d ", i);
        }

        else if (i % 7 == 0)
        {
            printf("%d ", i);
        }
    }

    return 0;
}