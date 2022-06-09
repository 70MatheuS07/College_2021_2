#include <stdlib.h>
#include <stdio.h>

typedef struct Pessoa
{
    char nome;
    float altura;
    float peso;

} tPessoa;

tPessoa LehPessoa();

tPessoa EhMaisAlta(tPessoa pessoa, tPessoa pessoaMaisAlta);

tPessoa EhMaisBaixa(tPessoa pessoa, tPessoa pessoaMaisBaixa);

float IMC_PessoaMaisAlta(tPessoa pessoaMaisAlta);

float IMC_PessoaMaisBaixa(tPessoa pessoaMaisBaixa);

void ImprimePessoa(tPessoa pessoaMaisAlta, tPessoa pessoaMaisBaixa, float IMC_maisAlta, float IMC_maisBaixa);

int main()
{
    int i = 0, n = 0;

    float IMC_maisAlta = 0, IMC_maisBaixa = 0;

    tPessoa pessoa, pessoaMaisAlta = {'z', -1000, -1000}, pessoaMaisBaixa = {'z', 1000, 1000};

    scanf("%d\n", &n);

    for (i = 0; i < n; i++)
    {
        pessoa = LehPessoa();

        pessoaMaisAlta = EhMaisAlta(pessoa, pessoaMaisAlta);

        pessoaMaisBaixa = EhMaisBaixa(pessoa, pessoaMaisBaixa);
    }

    IMC_maisAlta = IMC_PessoaMaisAlta(pessoaMaisAlta);

    IMC_maisBaixa = IMC_PessoaMaisBaixa(pessoaMaisBaixa);

    ImprimePessoa(pessoaMaisAlta, pessoaMaisBaixa, IMC_maisAlta, IMC_maisBaixa);

    return 0;
}

tPessoa LehPessoa()
{
    tPessoa pessoa;

    scanf("%c,%f,%f\n", &pessoa.nome, &pessoa.altura, &pessoa.peso);

    return pessoa;
}

tPessoa EhMaisAlta(tPessoa pessoa, tPessoa pessoaMaisAlta)
{
    if (pessoa.altura > pessoaMaisAlta.altura)
    {
        pessoaMaisAlta.nome = pessoa.nome;
        pessoaMaisAlta.altura = pessoa.altura;
        pessoaMaisAlta.peso = pessoa.peso;
    }

    return pessoaMaisAlta;
}

tPessoa EhMaisBaixa(tPessoa pessoa, tPessoa pessoaMaisBaixa)
{
    if (pessoa.altura < pessoaMaisBaixa.altura)
    {
        pessoaMaisBaixa.nome = pessoa.nome;
        pessoaMaisBaixa.altura = pessoa.altura;
        pessoaMaisBaixa.peso = pessoa.peso;
    }

    return pessoaMaisBaixa;
}

float IMC_PessoaMaisAlta(tPessoa pessoaMaisAlta)
{
    float result = 0;

    result = pessoaMaisAlta.peso / (pessoaMaisAlta.altura * pessoaMaisAlta.altura);

    return result;
}

float IMC_PessoaMaisBaixa(tPessoa pessoaMaisBaixa)
{
    float result = 0;

    result = pessoaMaisBaixa.peso / (pessoaMaisBaixa.altura * pessoaMaisBaixa.altura);

    return result;
}

void ImprimePessoa(tPessoa pessoaMaisAlta, tPessoa pessoaMaisBaixa, float IMC_maisAlta, float IMC_maisBaixa)
{
    printf("Alta: N:%c A:%.2f P:%.2f I:%.2f\n", pessoaMaisAlta.nome, pessoaMaisAlta.altura, pessoaMaisAlta.peso, IMC_maisAlta);

    printf("Baixa: N:%c A:%.2f P:%.2f I:%.2f", pessoaMaisBaixa.nome, pessoaMaisBaixa.altura, pessoaMaisBaixa.peso, IMC_maisBaixa);
}