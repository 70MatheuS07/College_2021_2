#include <stdlib.h>
#include <stdio.h>

void LehNumeros(int numeros[], int n);

int AnalisaProgressaoAritmetica(int numeros[], int n);

void ImprimeProgressaoAritmetica(int result);

int main()
{
    int n = 0, result = 0;

    scanf("%d", &n);

    int numeros[n];

    LehNumeros(numeros, n);

    result = AnalisaProgressaoAritmetica(numeros, n);

    ImprimeProgressaoAritmetica(result);

    return 0;
}

void LehNumeros(int numeros[], int n)
{
    int i = 0;

    for (i = 0; i < n; i++)
    {
        scanf(" %d", &numeros[i]);
    }
}

int AnalisaProgressaoAritmetica(int numeros[], int n)
{
    int i = 0;
    int razao = 0;
    int razaoPositiva = -1;
    int razaoNegativa = 1;
    int razaoAnterior = 0;
    int a = i + 1;
    int cont = 0;

    for (i = 0; i < n; i++)
    {
        if (n == 1)
        {
            razao = -2147483647;

            return razao;
        }

        else if (n == 2)
        {
            if (numeros[i] > numeros[a])
            {
                razao = numeros[a] - numeros[i];

                return razao;
            }

            else if (numeros[i] < numeros[a])
            {
                razao = numeros[i] - numeros[a];

                return razao;
            }
        }

        else if (n >= 3)
        {

            a = i + 1;

            razao = numeros[a] - numeros[i];

            if (i == 0)
            {
                razaoAnterior = razao;
            }

            else if (a < n)
            {
                if (razao == razaoAnterior)
                {
                    if (a == n - 1)
                    {
                        return razao;
                    }
                }
                else
                {
                    cont = -2147483647;

                    return cont;
                }
            }
        }
    }
}

void ImprimeProgressaoAritmetica(int result)
{
    if (result == -2147483647)
    {
        printf("NAO");
    }
    else
    {
        printf("RESP:%d", result);
    }
}