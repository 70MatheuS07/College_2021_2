#include <stdlib.h>
#include <stdio.h>

typedef struct Data
{
    int dia;
    int mes;
    int ano;

} tData;

tData LehData();

int CalculaAno(tData data);

int CalculaMes(tData data);

int CalculaSeculo(tData data);

int EhBissexto(tData data);

int EhJaneiro(tData data);

int EhFevereiro(tData data);

int AdicionaDias(tData data);

int CalculaDia(int result_total);

void ImprimeDia(int vetor[100], int i);

void InicializaVetor(int vetor[100]);

int main()
{
    tData data;

    int i = 0, cont = 0;

    int dia = 0, mes = 0, ano = 0;

    int result_ano = 0, result_mes = 0, result_seculo = 0, result_total = 0, result_dia = 0;

    int vetor[100];

    char letra = '\0';

    InicializaVetor(vetor);

    while (scanf("%d-%d-%d ", &dia, &mes, &ano) == 3)
    {
        result_ano = 0;
        result_mes = 0;
        result_seculo = 0;
        result_total = 0;
        result_dia = 0;

        data = LehData(dia, mes, ano);

        result_ano = CalculaAno(data);

        result_mes = CalculaMes(data);

        result_seculo = CalculaSeculo(data);

        result_total += result_mes;
        result_total += result_ano;
        result_total += result_seculo;

        if (EhBissexto(data) == 1)
        {
            if (EhJaneiro(data) == 1)
            {
                result_total -= 1;
            }

            else if (EhFevereiro(data) == 1)
            {
                result_total -= 1;
            }
        }

        result_total += AdicionaDias(data);

        result_dia = CalculaDia(result_total);

        vetor[cont] = result_dia;

        cont++;
    }

    for (i = 0; i < cont; i++)
    {
        ImprimeDia(vetor, i);

        if (i != cont - 1)
        {
            printf(", ");
        }
    }

    printf("\n");

    return 0;
}

tData LehData(int dia, int mes, int ano)
{
    tData data;

    data.dia = dia;
    data.mes = mes;
    data.ano = ano;

    return data;
}

int CalculaAno(tData data)
{
    int resto = 0, result = 0;

    resto = data.ano % 100;

    result += resto;

    resto /= 4;

    result += resto;

    result %= 7;

    return result;
}

int CalculaMes(tData data)
{
    int resto = 0, result = 0;

    if (data.mes == 1)
    {
        return 0;
    }

    else if (data.mes == 2)
    {
        return 3;
    }

    else if (data.mes == 3)
    {
        return 3;
    }

    else if (data.mes == 4)
    {
        return 6;
    }

    else if (data.mes == 5)
    {
        return 1;
    }

    else if (data.mes == 6)
    {
        return 4;
    }

    else if (data.mes == 7)
    {
        return 6;
    }

    else if (data.mes == 8)
    {
        return 2;
    }

    else if (data.mes == 9)
    {
        return 5;
    }

    else if (data.mes == 10)
    {
        return 0;
    }

    else if (data.mes == 11)
    {
        return 3;
    }

    else if (data.mes == 12)
    {
        return 5;
    }
}

int CalculaSeculo(tData data)
{
    int resto = 0, result = 0;

    resto = data.ano / 100;

    if (resto == 17)
    {
        return 4;
    }

    else if (resto == 18)
    {
        return 2;
    }

    else if (resto == 19)
    {
        return 0;
    }

    else if (resto == 20)
    {
        return 6;
    }

    else if (resto == 21)
    {
        return 4;
    }

    else if (resto == 22)
    {
        return 2;
    }

    else if (resto == 23)
    {
        return 0;
    }
}

int EhBissexto(tData data)
{
    if (!(data.ano % 400))
    {
        return 1;
    }

    if (!(data.ano % 100))
    {
        return 0;
    }

    if (!(data.ano % 4))
    {
        return 1;
    }

    return 0;
}

int EhJaneiro(tData data)
{
    if (data.mes == 1)
    {
        return 1;
    }

    return 0;
}

int EhFevereiro(tData data)
{
    if (data.mes == 2)
    {
        return 1;
    }

    return 0;
}

int AdicionaDias(tData data)
{
    int result = 0;

    result = data.dia;

    return result;
}

int CalculaDia(int result_total)
{
    int resto = 0;

    resto = result_total % 7;

    return resto;
}

void ImprimeDia(int vetor[100], int i)
{

    if (vetor[i] == 0)
    {
        printf("DOMINGO");
    }

    else if (vetor[i] == 1)
    {
        printf("SEGUNDA");
    }

    else if (vetor[i] == 2)
    {
        printf("TERCA");
    }

    else if (vetor[i] == 3)
    {
        printf("QUARTA");
    }

    else if (vetor[i] == 4)
    {
        printf("QUINTA");
    }

    else if (vetor[i] == 5)
    {
        printf("SEXTA");
    }

    else if (vetor[i] == 6)
    {
        printf("SABADO");
    }
}

void InicializaVetor(int vetor[100])
{
    int i = 0;

    for (i = 0; i < 100; i++)
    {
        vetor[i] = '\0';
    }
}
