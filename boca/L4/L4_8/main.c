#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct Animal
{
    float peso;
    float qtd_animais;
    float valor_racao;
    float porcentagem_peso;

} tAnimal;

tAnimal InicializaAnimal();

tAnimal LehAnimal();

float QtdRacao(tAnimal animal);

float CalculaPreco(float qtd_racao, tAnimal animal);

int main()
{
    int num = 0;
    int i = 0;

    float qtd_racao = 0;
    float preco_racao = 0;
    float preco_total_racao = 0;

    scanf("%d\n", &num);

    tAnimal animal;

    for (i = 0; i < num; i++)
    {
        animal = InicializaAnimal();

        animal = LehAnimal();

        qtd_racao = QtdRacao(animal);

        preco_racao = CalculaPreco(qtd_racao, animal);

        preco_total_racao += preco_racao;
    }

    preco_total_racao = ceilf(preco_total_racao * 100) / 100;

    printf("Valor total: %.2f reais", preco_total_racao);

    return 0;
}

tAnimal InicializaAnimal()
{
    tAnimal animal;

    animal.peso = 0;
    animal.porcentagem_peso = 0;
    animal.qtd_animais = 0;
    animal.valor_racao = 0;

    return animal;
}

tAnimal LehAnimal()
{
    tAnimal animal;

    scanf("%f %f %f %f\n", &animal.qtd_animais, &animal.porcentagem_peso, &animal.peso, &animal.valor_racao);

    return animal;
}

float QtdRacao(tAnimal animal)
{
    float racao = 0;

    racao = (animal.peso * animal.porcentagem_peso) / 100.00;

    return racao;
}

float CalculaPreco(float qtd_racao, tAnimal animal)
{
    float preco;

    preco = (qtd_racao * animal.qtd_animais) * animal.valor_racao;

    return preco;
}