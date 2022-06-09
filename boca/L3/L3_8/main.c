#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void LehMatriz(int i, int j, int matriz[i][j]);
int VerificaPrimo(int num);
int VerificaNegativo(int num);
int TransformaPrimo(int num);
void ImprimeMatriz(int i, int j, int matriz[i][j]);

int main()
{
    int i = 0, j = 0, num = 0, k = 0, l = 0;

    scanf("%d %d\n", &i, &j);

    int matriz[i][j];

    LehMatriz(i, j, matriz);

    for (k = 0; k < i; k++)
    {
        for (l = 0; l < j; l++)
        {
            num = matriz[k][l];

            if (num >= -32000 && num <= 32000)
            {
                if (VerificaPrimo(num) == 0)
                {
                    if (VerificaNegativo(num) == 0)
                    {
                        num = TransformaPrimo(num);
                    }
                    else
                    {
                        num *= -1;

                        num = TransformaPrimo(num);

                        num *= -1;
                    }
                }
            }

            matriz[k][l] = num;
        }
    }

    ImprimeMatriz(i, j, matriz);

    return 0;
}

void LehMatriz(int i, int j, int matriz[i][j])
{
    int k = 0, l = 0, num = 0;

    for (k = 0; k < i; k++)
    {
        scanf("\t");

        for (l = 0; l < j; l++)
        {
            if (l - 1 == j)
            {
                scanf("%d", &num);

                matriz[k][l] = num;
            }
            else
            {
                scanf("%d ", &num);

                matriz[k][l] = num;
            }
        }

        scanf("\n");
    }
}

int VerificaPrimo(int num)
{
    int i = 1, cont = 0;

    while (i < num)
    {
        if (num % i == 0)
        {
            cont++;
        }

        i++;
    }

    if (cont == 2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int VerificaNegativo(int num)
{
    if (num < 0)
    {
        return 1;
    }

    return 0;
}

int TransformaPrimo(int num)
{
    int i = 1, cont = 0, num1 = 0;

    num1 = num;

    while (1)
    {
        while (i <= num1)
        {
            if (num1 % i == 0)
            {
                cont++;
            }

            i++;
        }

        if (num1 > 32000 || num1 < -32000)
        {
            return num;
        }

        else if (cont == 2)
        {
            return num1;
        }
        else
        {
            num1++;
            cont = 0;
            i = 1;
        }
    }
}

void ImprimeMatriz(int i, int j, int matriz[i][j])
{
    int k = 0, l = 0;

    for (k = 0; k < i; k++)
    {
        printf("\t");

        for (l = 0; l < j; l++)
        {
            if (l - 1 == j)
            {
                printf("%d", matriz[k][l]);
            }
            else
            {
                printf("%d ", matriz[k][l]);
            }
        }

        printf("\n");
    }
}