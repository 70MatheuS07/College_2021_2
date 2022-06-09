#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Pessoa
{
    char nome[20];
    float altura;
    float peso;
    int cpf;
    char sexo;

} tPessoa;

void InicializaPessoas(tPessoa armazenaPessoas[], int num);

void LehPessoas(tPessoa armazenaPessoas[], int num);

int AchaCpf(tPessoa armazenaPessoas[], int num);

float CalculaIMC(tPessoa armazenaPessoas[], int cpf_selecionado);

void ImprimeSaida(tPessoa armazenaPessoas[], int cpf_selecionado, float imc);

int main()
{
    int num = 0;
    int cpf_selecionado = 0;
    float imc = 0;

    scanf("%d\n", &num);

    tPessoa armazenaPessoas[num];

    LehPessoas(armazenaPessoas, num);

    cpf_selecionado = AchaCpf(armazenaPessoas, num);

    imc = CalculaIMC(armazenaPessoas, cpf_selecionado);

    ImprimeSaida(armazenaPessoas, cpf_selecionado, imc);

    return 0;
}

void InicializaPessoas(tPessoa armazenaPessoas[], int num)
{
    int i = 0, j = 0;

    for (i = 0; i < num; i++)
    {
        armazenaPessoas[i].altura = 0;
        armazenaPessoas[i].peso = 0;
        armazenaPessoas[i].cpf = 0;
        armazenaPessoas[i].sexo = '\0';

        for (j = 0; j < 20; j++)
        {
            armazenaPessoas[i].nome[j] = '\0';
        }
    }
}

void LehPessoas(tPessoa armazenaPessoas[], int num)
{
    int i = 0, j = 0;

    for (i = 0; i < num; i++)
    {
        scanf("%s %f %f %d %c\n", armazenaPessoas[i].nome, &armazenaPessoas[i].altura, &armazenaPessoas[i].peso, &armazenaPessoas[i].cpf, &armazenaPessoas[i].sexo);
    }
}

int AchaCpf(tPessoa armazenaPessoas[], int num)
{
    int i = 0, j = 0;
    char caracter, lixo;

    scanf("%d\n", &j);

    for (i = 0; i < num; i++)
    {
        if (armazenaPessoas[i].cpf == j)
        {
            return i;
        }
    }
}

float CalculaIMC(tPessoa armazenaPessoas[], int cpf_selecionado)
{
    float result = 0;

    result = armazenaPessoas[cpf_selecionado].peso / (armazenaPessoas[cpf_selecionado].altura * armazenaPessoas[cpf_selecionado].altura);

    return result;
}

void ImprimeSaida(tPessoa armazenaPessoas[], int cpf_selecionado, float imc)
{
    int i = 0;

    printf("Sexo    Nome    IMC\n");
    printf("%c       ", armazenaPessoas[cpf_selecionado].sexo);

    for (i = 0; i < 20; i++)
    {
        if (armazenaPessoas[cpf_selecionado].nome[i] == '\0')
        {
            break;
        }

        printf("%c", armazenaPessoas[cpf_selecionado].nome[i]);
    }

    printf("    %.2f\n", imc);
}
