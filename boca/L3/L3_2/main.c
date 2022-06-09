#include <stdlib.h>
#include <stdio.h>
#include <math.h>

float Soma(float num1, float num2);
float Subtracao(float num1, float num2);
float Divisao(float num1, float num2);
float Multiplicacao(float num1, float num2);

int main()
{
    float num1 = 0, num2 = 0, result = 0;
    char operador;

    scanf("%f %f %c", &num1, &num2, &operador);

    if (operador == '+')
    {
        result = Soma(num1, num2);
    }

    else if (operador == '-')
    {
        result = Subtracao(num1, num2);
    }

    else if (operador == '*')
    {
        result = Multiplicacao(num1, num2);
    }

    else if (operador == '/')
    {
        result = Divisao(num1, num2);
    }

    num1 = result;

    while (scanf("%f %c", &num2, &operador) == 2)
    {
        if (operador == '+')
        {
            result = Soma(num1, num2);
        }

        else if (operador == '-')
        {
            result = Subtracao(num1, num2);
        }

        else if (operador == '*')
        {
            result = Multiplicacao(num1, num2);
        }

        else if (operador == '/')
        {
            result = Divisao(num1, num2);
        }

        num1 = result;
    }

    printf("%.2f", num1);

    return 0;
}

float Soma(float num1, float num2)
{
    float soma = 0;

    soma = num1 + num2;

    return soma;
}

float Subtracao(float num1, float num2)
{
    float subtracao = 0;

    subtracao = num1 - num2;

    return subtracao;
}

float Divisao(float num1, float num2)
{
    float divisao = 0;

    divisao = num1 / num2;

    return divisao;
}

float Multiplicacao(float num1, float num2)
{
    float multiplicacao = 0;

    multiplicacao = num1 * num2;

    return multiplicacao;
}