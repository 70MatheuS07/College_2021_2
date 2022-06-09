#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void PreencheVetor(int num[], int n);
int ClassificaOrdem(int num[], int n);
void ImprimeOrdem(int rtn, int n);

int main()
{
    int n = 0, i = 0;
    int rtn = -1;

    scanf("%d", &n);

    int num[n];

    PreencheVetor(num, n);

    rtn = ClassificaOrdem(num, n);

    ImprimeOrdem(rtn, n);

    return 0;
}

void PreencheVetor(int num[], int n)
{
    int i = 0;

    for (i = 0; i < n; i++)
    {
        scanf("%d", &num[i]);
    }
}

int ClassificaOrdem(int num[], int n)
{
    int i = 0;
    int a = 0, b = 0;
    int cont = 0;

    for (i = 1; i < n; i++)
    {
        a = i - 1;
        b = i + 1;

        if (n == 1)
        {
            return cont;
        }

        else if (n == 2)
        {
            if (num[a] < num[i])
            {
                cont = n;

                return cont;
            }

            else if (num[a] > num[i])
            {
                cont = n * -1;

                return cont;
            }
        }

        else if (n >= 3)
        {
            if (num[a] < num[i] && num[b] > num[i])
            {
                cont++;
            }

            else if (num[a] > num[i] && num[b] < num[i])
            {
                cont--;
            }

            else if (num[a] == num[i] && num[b] == num[i])
            {
                cont += 0;
            }

            else if (num[a] == num[i] && num[b] > num[i])
            {
                cont++;
            }

            else if (num[a] < num[i] && num[b] == num[i])
            {
                cont++;
            }

            else if (i == n - 1)
            {
                if (num[a] < num[i])
                {
                    cont += 2;
                }

                else if (num[a] > num[i])
                {
                    cont -= 2;
                }
            }
        }
    }

    return cont;
}

void ImprimeOrdem(int rtn, int n)
{
    if (rtn == n && n != 1)
    {
        printf("CRESCENTE");
    }

    else if (rtn == n * -1 && n != 1)
    {
        printf("DECRESCENTE");
    }

    else if (rtn == 0)
    {
        printf("CRESCENTE&DECRESCENTE");
    }

    else if (rtn > n * -1 && rtn < n && rtn != 0)
    {
        printf("DESORDENADO");
    }
}