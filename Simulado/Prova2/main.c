#include <stdlib.h>
#include <stdio.h>

typedef struct Data
{
    int dia;
    int mes;
    int ano;

} tData;

typedef struct Cadastro
{
    char nome[50];
    tData data;
    char cpf[20];
    int agencia;
    int conta;
    char digitoVerificador;
    float saldo;
    float debitos[3];

} tCadastro;

typedef struct Saldo
{
    char nome[50];
    tData data;
    char cpf[20];
    int agencia;
    int conta;
    char digitoVerificador;
    float saldoFinal;

} tSaldo;

int LehCadastro(tCadastro cadastro[500]);

void RegistraCadastroEmSaldo(tCadastro cadastro[500], tSaldo saldo[], int num);

void CopiaNome(tCadastro cadastro[500], tSaldo saldo[], int i);

void CopiaData(tCadastro cadastro[500], tSaldo saldo[], int i);

void CopiaCpf(tCadastro cadastro[500], tSaldo saldo[], int i);

float CalculaSaldo(tCadastro cadastro[500], int i);

void OrdenaDecrescente(tSaldo saldo[], int num);

void TrocaValor(tSaldo saldo[], int i, int j);

void CriaArquivoSaida(tCadastro cadastro[500], tSaldo saldo[], int num, int agencia);

int main(int argc, char **argv)
{
    int num = 0, i = 0, agencia = 0;

    agencia = atoi(argv[1]);

    tCadastro cadastro[500];

    num = LehCadastro(cadastro);

    tSaldo saldo[num];

    RegistraCadastroEmSaldo(cadastro, saldo, num);

    OrdenaDecrescente(saldo, num);

    CriaArquivoSaida(cadastro, saldo, num, agencia);

    return 0;
}

int LehCadastro(tCadastro cadastro[500])
{
    int i = 0, result = 0;
    char caracter;

    FILE *correntistas;

    correntistas = fopen("CORRENTISTAS.txt", "r");

    while (!feof(correntistas))
    {
        while (1)
        {
            fscanf(correntistas, "%c", &caracter);

            if (caracter == '\n' || i == 50)
            {
                if (i < 50)
                {
                    cadastro[result].nome[i] = '\0';
                }

                i = 0;
                break;
            }
            else
            {
                cadastro[result].nome[i] = caracter;
                i++;
            }
        }
        fscanf(correntistas, "%d %d %d\n", &cadastro[result].data.dia, &cadastro[result].data.mes, &cadastro[result].data.ano);

        while (1)
        {
            fscanf(correntistas, "%c", &caracter);

            if (caracter == '\n' || i == 20)
            {
                if (i < 20)
                {
                    cadastro[result].cpf[i] = '\0';
                }

                i = 0;
                break;
            }
            else
            {
                cadastro[result].cpf[i] = caracter;
                i++;
            }
        }

        fscanf(correntistas, "%d\n", &cadastro[result].agencia);

        fscanf(correntistas, "%d\n", &cadastro[result].conta);

        fscanf(correntistas, "%c\n", &cadastro[result].digitoVerificador);

        fscanf(correntistas, "%f\n", &cadastro[result].saldo);

        fscanf(correntistas, "%f %f %f\n\n", &cadastro[result].debitos[0], &cadastro[result].debitos[1], &cadastro[result].debitos[2]);

        result++;
    }

    fclose(correntistas);

    return result;
}

void RegistraCadastroEmSaldo(tCadastro cadastro[500], tSaldo saldo[], int num)
{
    int i = 0;

    for (i = 0; i < num; i++)
    {
        CopiaNome(cadastro, saldo, i);

        CopiaData(cadastro, saldo, i);

        CopiaCpf(cadastro, saldo, i);

        saldo[i].agencia = cadastro[i].agencia;

        saldo[i].conta = cadastro[i].conta;

        saldo[i].digitoVerificador = cadastro[i].digitoVerificador;

        saldo[i].saldoFinal = CalculaSaldo(cadastro, i);
    }
}

void CopiaNome(tCadastro cadastro[500], tSaldo saldo[], int i)
{
    int j = 0;

    while (1)
    {
        if (j == 50)
        {
            break;
        }

        else
        {
            saldo[i].nome[j] = cadastro[i].nome[j];
            j++;
        }
    }
}

void CopiaData(tCadastro cadastro[500], tSaldo saldo[], int i)
{
    saldo[i].data.dia = cadastro[i].data.dia;
    saldo[i].data.mes = cadastro[i].data.mes;
    saldo[i].data.ano = cadastro[i].data.ano;
}

void CopiaCpf(tCadastro cadastro[500], tSaldo saldo[], int i)
{
    int j = 0;

    while (1)
    {
        if (j == 20)
        {
            break;
        }

        else
        {
            saldo[i].cpf[j] = cadastro[i].cpf[j];
            j++;
        }
    }
}

float CalculaSaldo(tCadastro cadastro[500], int i)
{
    float result = 0;

    result = cadastro[i].saldo;
    result -= cadastro[i].debitos[0];
    result -= cadastro[i].debitos[1];
    result -= cadastro[i].debitos[2];

    return result;
}

void OrdenaDecrescente(tSaldo saldo[], int num)
{
    int i, menor, aux, j;

    for (i = 0; i < num - 1; i++)
    {
        for (j = i + 1; j < num; j++)
        {
            if (saldo[i].saldoFinal < saldo[j].saldoFinal)
            {
                TrocaValor(saldo, i, j);
            }
        }
    }
}

void TrocaValor(tSaldo saldo[], int i, int j)
{
    tSaldo aux;

    aux = saldo[j];
    saldo[j] = saldo[i];
    saldo[i] = aux;
}

void CriaArquivoSaida(tCadastro cadastro[500], tSaldo saldo[], int num, int agencia)
{
    int i = 0, j = 0;
    int cont = 0;
    char lixo;

    FILE *saldosCorrentistas;

    saldosCorrentistas = fopen("SALDOSCORRENTISTAS.txt", "a+");

    fprintf(saldosCorrentistas, "Agencia = %d\n\n\n", agencia);

    for (i = 0; i < num; i++)
    {
        if (agencia == saldo[i].agencia)
        {
            fprintf(saldosCorrentistas, "%s %s\n", saldo[i].nome, saldo[i].cpf);
            fprintf(saldosCorrentistas, "%d %d %d\n", saldo[i].data.dia, saldo[i].data.mes, saldo[i].data.ano);
            fprintf(saldosCorrentistas, "%d %d %c\n", saldo[i].agencia, saldo[i].conta, saldo[i].digitoVerificador);
            fprintf(saldosCorrentistas, "%.2f\n\n", saldo[i].saldoFinal);

            if (saldo[i].saldoFinal < 0)
            {
                cont++;
            }
        }
    }

    fprintf(saldosCorrentistas, "Numero de clientes da agencia %03d com saldo negativo: %d", agencia, cont);

    fclose(saldosCorrentistas);
}