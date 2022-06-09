#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main()
{
    int n = 0, num = 0, i = 1, loop = 0, seleciona = 0;
    int n1 = 0, n2 = 0, n3 = 0, n4 = 0, n5 = 0, n6 = 0, n7 = 0, n8 = 0, n9 = 0;
    char letra;

    scanf("%d", &n);

    while (i <= n)
    {
        scanf("%d", &num);

        switch (i)
        {
            {
            case 1:
                n1 = num;
                i++;
                break;
            }
            {
            case 2:
                n2 = num;
                i++;
                break;
            }
            {
            case 3:
                n3 = num;
                i++;
                break;
            }
            {
            case 4:
                n4 = num;
                i++;
                break;
            }
            {
            case 5:
                n5 = num;
                i++;
                break;
            }
            {
            case 6:
                n6 = num;
                i++;
                break;
            }
            {
            case 7:
                n7 = num;
                i++;
                break;
            }
            {
            case 8:
                n8 = num;
                i++;
                break;
            }
            {
            case 9:
                n9 = num;
                i++;
                break;
            }
        }
    }

    getchar();

    while (loop < 2)
    {
        scanf("%c", &letra);

        if (letra == '"')
        {
            loop++;
        }

        if (letra == '%')
        {
            scanf("%d", &seleciona);

            if (seleciona <= n && seleciona >= 1)
            {
                switch (seleciona)
                {
                    {
                    case 1:
                        printf("%d", n1);
                        break;
                    }
                    {
                    case 2:
                        printf("%d", n2);
                        break;
                    }
                    {
                    case 3:
                        printf("%d", n3);
                        break;
                    }
                    {
                    case 4:
                        printf("%d", n4);
                        break;
                    }
                    {
                    case 5:
                        printf("%d", n5);
                        break;
                    }
                    {
                    case 6:
                        printf("%d", n6);
                        break;
                    }
                    {
                    case 7:
                        printf("%d", n7);
                        break;
                    }
                    {
                    case 8:
                        printf("%d", n8);
                        break;
                    }
                    {
                    case 9:
                        printf("%d", n9);
                        break;
                    }
                }
            }

            else
            {
                printf("ERRO");
            }
        }

        else if (letra != '"')
        {
            printf("%c", letra);
        }
    }

    return 0;
}