#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main()
{
    int num = 0;
    int total = 0;
    int qtd_notas_quinhentos = 0, qtd_notas_cem = 0, qtd_notas_cinquenta = 0, qtd_notas_dez = 0, qtd_notas_cinco = 0, qtd_notas_um = 0;

    scanf("%d", &num);

    while (num > 0)
    {
        if (num >= 500)
        {
            num -= 500;
            qtd_notas_quinhentos++;
        }

        else if (num >= 100)
        {
            num -= 100;
            qtd_notas_cem++;
        }

        else if (num >= 50)
        {
            num -= 50;
            qtd_notas_cinquenta++;
        }

        else if (num >= 10)
        {
            num -= 10;
            qtd_notas_dez++;
        }

        else if (num >= 5)
        {
            num -= 5;
            qtd_notas_cinco++;
        }

        else if (num >= 1)
        {
            num -= 1;
            qtd_notas_um++;
        }
    }

    if (qtd_notas_quinhentos > 0)
    {
        printf("%d (500)", qtd_notas_quinhentos);

        if (qtd_notas_cem > 0)
        {
            printf(", %d (100)", qtd_notas_cem);
        }

        if (qtd_notas_cinquenta > 0)
        {
            printf(", %d (50)", qtd_notas_cinquenta);
        }

        if (qtd_notas_dez > 0)
        {
            printf(", %d (10)", qtd_notas_dez);
        }

        if (qtd_notas_cinco > 0)
        {
            printf(", %d (5)", qtd_notas_cinco);
        }

        if (qtd_notas_um > 0)
        {
            printf(", %d (1)", qtd_notas_um);
        }
    }

    else
    {
        if (qtd_notas_cem > 0)
        {
            printf("%d (100)", qtd_notas_cem);

            if (qtd_notas_cinquenta > 0)
            {
                printf(", %d (50)", qtd_notas_cinquenta);
            }

            if (qtd_notas_dez > 0)
            {
                printf(", %d (10)", qtd_notas_dez);
            }

            if (qtd_notas_cinco > 0)
            {
                printf(", %d (5)", qtd_notas_cinco);
            }

            if (qtd_notas_um > 0)
            {
                printf(", %d (1)", qtd_notas_um);
            }
        }

        else
        {
            if (qtd_notas_cinquenta > 0)
            {
                printf("%d (50)", qtd_notas_cinquenta);

                if (qtd_notas_dez > 0)
                {
                    printf(", %d (10)", qtd_notas_dez);
                }

                if (qtd_notas_cinco > 0)
                {
                    printf(", %d (5)", qtd_notas_cinco);
                }

                if (qtd_notas_um > 0)
                {
                    printf(", %d (1)", qtd_notas_um);
                }
            }

            else
            {
                if (qtd_notas_dez > 0)
                {
                    printf("%d (10)", qtd_notas_dez);

                    if (qtd_notas_cinco > 0)
                    {
                        printf(", %d (5)", qtd_notas_cinco);
                    }

                    if (qtd_notas_um > 0)
                    {
                        printf(", %d (1)", qtd_notas_um);
                    }
                }

                else
                {
                    if (qtd_notas_cinco > 0)
                    {
                        printf("%d (5)", qtd_notas_cinco);

                        if (qtd_notas_um > 0)
                        {
                            printf(", %d (1)", qtd_notas_um);
                        }
                    }

                    else
                    {
                        if (qtd_notas_um > 0)
                        {
                            printf("%d (1)", qtd_notas_um);
                        }
                    }
                }
            }
        }
    }

    total = qtd_notas_quinhentos + qtd_notas_cem + qtd_notas_cinquenta + qtd_notas_dez + qtd_notas_cinco + qtd_notas_um;

    if (total > 0)
    {
        printf(". Total: %d cedulas.\n", total);
    }

    else
    {
        printf("Total: %d cedulas.\n", total);
    }

    return 0;
}