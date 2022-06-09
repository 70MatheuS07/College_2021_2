#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int EhBissexto(int ano);

int main()
{
    int mes = 0, ano = 0;

    scanf("%d %d", &mes, &ano);

    if (mes >= 1 && mes <= 12)
    {
        if (EhBissexto(ano) == 1)
        {
            switch (mes)
            {
                {
                case 1:
                    printf("janeiro 31 %d bissexto\n", ano);
                    break;
                }

                {
                case 2:
                    printf("fevereiro 29 %d bissexto\n", ano);
                    break;
                }

                {
                case 3:
                    printf("marco 31 %d bissexto\n", ano);
                    break;
                }

                {
                case 4:
                    printf("abril 30 %d bissexto\n", ano);
                    break;
                }

                {
                case 5:
                    printf("maio 31 %d bissexto\n", ano);
                    break;
                }

                {
                case 6:
                    printf("junho 30 %d bissexto\n", ano);
                    break;
                }

                {
                case 7:
                    printf("julho 31 %d bissexto\n", ano);
                    break;
                }

                {
                case 8:
                    printf("agosto 31 %d bissexto\n", ano);
                    break;
                }

                {
                case 9:
                    printf("setembro 30 %d bissexto\n", ano);
                    break;
                }

                {
                case 10:
                    printf("outubro 31 %d bissexto\n", ano);
                    break;
                }

                {
                case 11:
                    printf("novembro 30 %d bissexto\n", ano);
                    break;
                }

                {
                case 12:
                    printf("dezembro 31 %d bissexto\n", ano);
                    break;
                }
            }
        }

        else
        {
            switch (mes)
            {
                {
                case 1:
                    printf("janeiro 31 %d\n", ano);
                    break;
                }

                {
                case 2:
                    printf("fevereiro 28 %d\n", ano);
                    break;
                }

                {
                case 3:
                    printf("marco 31 %d\n", ano);
                    break;
                }

                {
                case 4:
                    printf("abril 30 %d\n", ano);
                    break;
                }

                {
                case 5:
                    printf("maio 31 %d\n", ano);
                    break;
                }

                {
                case 6:
                    printf("junho 30 %d\n", ano);
                    break;
                }

                {
                case 7:
                    printf("julho 31 %d\n", ano);
                    break;
                }

                {
                case 8:
                    printf("agosto 31 %d\n", ano);
                    break;
                }

                {
                case 9:
                    printf("setembro 30 %d\n", ano);
                    break;
                }

                {
                case 10:
                    printf("outubro 31 %d\n", ano);
                    break;
                }

                {
                case 11:
                    printf("novembro 30 %d\n", ano);
                    break;
                }

                {
                case 12:
                    printf("dezembro 31 %d\n", ano);
                    break;
                }
            }
        }
    }

    else
    {
        printf("opcao invalida\n");
    }

    return 0;
}

int EhBissexto(int ano)
{
    if (!(ano % 400))
    {
        return 1;
    }

    if (!(ano % 100))
    {
        return 0;
    }

    if (!(ano % 4))
    {
        return 1;
    }

    return 0;
}