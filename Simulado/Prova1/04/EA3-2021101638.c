#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define dolar 5.67

float ConverteDinheiro(float dinheiro);
float ConverteTemperatura(float temperatura);
float ConverteVelocidade(float velocidade);

int main()
{
    int especificacao = 0;
    float dinheiro = 0, dolares = 0;
    float temperatura = 0, graus = 0;
    float velocidade = 0, metros_por_seg = 0;

    while (1)
    {
        printf("Opcoes:\n");
        printf("- 1 = Conversor de dolares\n");
        printf("- 2 = Conversor de temperatura\n");
        printf("- 3 = Conversor de velocidade\n");
        printf("- 4 = Sair\n\n");

        printf("O que deseja converter: ");

        scanf("%d", &especificacao);

        if (especificacao == 1)
        {
            printf("Quantos R$ voce tem: ");
            scanf("%f", &dinheiro);
            printf("Hoje, $1 esta R$5.67\n");
            dolares = ConverteDinheiro(dinheiro);
            printf("Entao, voce pode ter: $%.2f\n\n", dolares);
        }

        else if (especificacao == 2)
        {
            printf("Qual a temperatura em Fahrenheit: ");
            scanf("%f", &temperatura);
            graus = ConverteTemperatura(temperatura);
            printf("A temperatura em Celsius e: %.2f\n\n", graus);
        }

        else if (especificacao == 3)
        {
            printf("Velocidade do veiculo(Km/H): ");
            scanf("%f", &velocidade);
            metros_por_seg = ConverteVelocidade(velocidade);
            printf("Velocidade em M/s: %.2f\n\n", metros_por_seg);
        }

        else if (especificacao == 4)
        {
            break;
        }
    }

    return 0;
}

float ConverteDinheiro(float dinheiro)
{
    float conta = 0;

    conta = dinheiro / dolar;

    return conta;
}

float ConverteTemperatura(float temperatura)
{
    float celsius = 0;

    celsius = (temperatura - 32) / 1.80;

    return celsius;
}

float ConverteVelocidade(float velocidade)
{
    float transformador = 0;

    transformador = velocidade / 3.60;

    return transformador;
}