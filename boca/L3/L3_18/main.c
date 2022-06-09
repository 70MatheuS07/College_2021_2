#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main()
{
    float saldo_atual = 0;
    int i = 0, num = 0;
    float valor = 0;
    char operacao;

    scanf("%f %d ", &saldo_atual, &num);

    for (i = 0; i < num; i++)
    {
        scanf("%c %f ", &operacao, &valor);

        if (operacao == 'D')
        {
            saldo_atual += valor;
        }

        else if (operacao == 'S')
        {
            saldo_atual -= valor;
        }
    }

    if (saldo_atual > 0)
    {
        printf("Positivo: %.2f", saldo_atual);
    }

    else if (saldo_atual < 0)
    {
        printf("Negativo: %.2f", saldo_atual);
    }

    else
    {
        printf("Zerado: %.2f", saldo_atual);
    }

    return 0;
}