#include <stdlib.h>
#include <stdio.h>

typedef struct
{
    int dia;
    int mes;
    int ano;

} tData;

tData LeData();

void ImprimeData(tData data);

int EhBissexto(tData data);

tData ConfereData(tData data);

int QtdDeDiasNoMes(tData data);

int main()
{
    int i = 0, n = 0;

    tData data;

    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        data = LeData();

        data = ConfereData(data);

        ImprimeData(data);

        if (EhBissexto(data) == 1)
        {
            printf(":Bisexto\n");
        }
        else
        {
            printf(":Normal\n");
        }
    }

    return 0;
}

tData LeData()
{
    tData data;

    scanf("%d %d %d", &data.dia, &data.mes, &data.ano);

    return data;
}

void ImprimeData(tData data)
{
    printf("'%02d/%02d/%04d'", data.dia, data.mes, data.ano);
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

tData ConfereData(tData data)
{
    if (data.mes > 12)
    {
        data.mes = 12;
    }
    else if (data.mes < 1)
    {
        data.mes = 1;
    }

    if (data.dia > QtdDeDiasNoMes(data))
    {
        data.dia = QtdDeDiasNoMes(data);
    }
    else if (data.dia < 1)
    {
        data.dia = 1;
    }

    return data;
}

int QtdDeDiasNoMes(tData data)
{
    if (data.mes == 1 || data.mes == 3 || data.mes == 5 ||
        data.mes == 7 || data.mes == 8 || data.mes == 10 ||
        data.mes == 12)
    {
        return 31;
    }

    else if (data.mes == 4 || data.mes == 6 ||
             data.mes == 9 || data.mes == 11)
    {
        return 30;
    }

    if (data.mes == 2)
    {
        if (EhBissexto(data) == 1)
        {
            return 29;
        }
        else
        {
            return 28;
        }
    }
}