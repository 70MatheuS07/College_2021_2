#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main()
{
    int num1 = 0, num2 = 0, num3 = 0;

    float media = 0;

    scanf("%d %d %d", &num1, &num2, &num3);

    if (num1 > num2 && num2 > num3 && num1 > num3)
    {
        media = (float)(num1 + num2) / 2;
        printf("%d %d %.2f\n", num1, num2, media);
    }

    else if (num1 > num2 && num3 > num2 && num1 > num3)
    {
        media = (float)(num1 + num3) / 2;
        printf("%d %d %.2f\n", num1, num3, media);
    }

    else if (num2 > num1 && num1 > num3 && num2 > num3)
    {
        media = (float)(num2 + num1) / 2;
        printf("%d %d %.2f\n", num2, num1, media);
    }

    else if (num2 > num3 && num3 > num1 && num2 > num1)
    {
        media = (float)(num2 + num3) / 2;
        printf("%d %d %.2f\n", num2, num3, media);
    }

    else if (num3 > num1 && num1 > num2 && num3 > num2)
    {
        media = (float)(num3 + num1) / 2;
        printf("%d %d %.2f\n", num3, num1, media);
    }

    else if (num3 > num2 && num2 > num1 && num3 > num1)
    {
        media = (float)(num3 + num2) / 2;
        printf("%d %d %.2f\n", num3, num2, media);
    }

    else if (num1 == num2)
    {
        if (num3 > num1)
        {
            media = (float)(num3 + num1) / 2;

            printf("%d %d %.2f\n", num3, num1, media);
        }

        else
        {
            media = (float)(num1 + num2) / 2;

            printf("%d %d %.2f\n", num1, num2, media);
        }
    }

    else if (num1 == num3)
    {
        if (num2 > num1)
        {
            media = (float)(num2 + num1) / 2;

            printf("%d %d %.2f\n", num2, num1, media);
        }

        else
        {
            media = (float)(num1 + num3) / 2;

            printf("%d %d %.2f\n", num1, num3, media);
        }
    }

    else if (num2 == num3)
    {
        if (num1 > num2)
        {
            media = (float)(num1 + num2) / 2;

            printf("%d %d %.2f\n", num1, num2, media);
        }

        else
        {
            media = (float)(num2 + num3) / 2;

            printf("%d %d %.2f\n", num2, num3, media);
        }
    }

    else
    {
        media = (float)(num1 + num2) / 2;

        printf("%d %d %.2f\n", num1, num2, media);
    }

    return 0;
}