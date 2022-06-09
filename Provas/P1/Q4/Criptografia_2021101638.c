#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int CalculaChave(int chavePrivada, int base, int primo);

long long int FuncaoPowPrivada(int chavePrivada, int base);

long long int FuncaoPowPublica(int chavePublica, int chavePrivada);

int main()
{
    int opcao = 0, chavePrivada = 0, base = 0, primo = 0;
    int chave = 0;

    scanf("%d %d %d %d", &opcao, &chavePrivada, &base, &primo);

    chave = CalculaChave(chavePrivada, base, primo);

    return 0;
}

int CalculaChave(int chavePrivada, int base, int primo)
{
    long long int result = 0;
    int chavePublica = 0;
    int chave = 0;

    result = FuncaoPowPrivada(chavePrivada, base);

    chavePublica = result % primo;

    result = FuncaoPowPublica(chavePrivada, chavePublica);

    chave = result % primo;

    return chave;
}

long long int FuncaoPowPrivada(int chavePrivada, int base)
{
    long long int result = 0;
    int i = 0;

    result = base;

    for (i = 1; i < chavePrivada; i++)
    {
        result *= (long long int)base;
    }

    return result;
}

long long int FuncaoPowPublica(int chavePublica, int chavePrivada)
{
    long long int result = 0;
    int i = 0;

    result = chavePublica;

    for (i = 1; i < chavePrivada; i++)
    {
        result *= (long long int)chavePublica;
    }

    return result;
}