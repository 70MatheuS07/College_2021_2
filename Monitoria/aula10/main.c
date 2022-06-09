#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Dicionario
{
    char tipo[10];
    char palavra[12];

} tDicionario;

void RegistraDicionario(tDicionario dicionario[20]);

void OrganizaDicionario(tDicionario dicionario[20]);

void ImprimeDicionarioPedido(tDicionario dicionario[20]);

int main()
{
    tDicionario dicionario[20];

    RegistraDicionario(dicionario);

    OrganizaDicionario(dicionario);

    ImprimeDicionarioPedido(dicionario);

    return 0;
}

void RegistraDicionario(tDicionario dicionario[20])
{
    int i = 0, j = 0, k = 0;
    char caracter;

    FILE *arquivo;

    arquivo = fopen("dicionario.csv", "r");

    for (i = 0; i < 20; i++)
    {
        j = 0;

        while (1)
        {
            fscanf(arquivo, "%c", &caracter);

            if (caracter == ',')
            {
                dicionario[i].tipo[j] = '\0';
                j++;
                break;
            }

            else
            {
                dicionario[i].tipo[j] = caracter;
                j++;
            }
        }

        j = 0;

        while (1)
        {
            fscanf(arquivo, "%c", &caracter);

            if (caracter == '\n')
            {
                dicionario[i].palavra[j] = '\0';
                break;
            }

            else
            {
                dicionario[i].palavra[j] = caracter;
                j++;
            }
        }
    }

    fclose(arquivo);
}

void OrganizaDicionario(tDicionario dicionario[20])
{
    int i = 0, j = 0, cont = 0;
    int c = 0, f = 5, n = 10, p = 15;

    char carro[6] = {"Carro"};
    char fruta[6] = {"Fruta"};
    char nome[5] = {"Nome"};
    char profissao[10] = {"Profissao"};
    char tipoCopia[10];
    char palavraCopia[12];

    for (i = 0; i < 20; i++)
    {
        if (strcmp(carro, dicionario[i].tipo) == 0)
        {
            for (cont = i; cont >= c; cont--)
            {
                if (cont == i)
                {
                    strcpy(tipoCopia, dicionario[cont].tipo);
                    strcpy(palavraCopia, dicionario[cont].palavra);
                }

                else if (cont == c)
                {
                    strcpy(dicionario[cont + 1].tipo, dicionario[cont].tipo);
                    strcpy(dicionario[cont + 1].palavra, dicionario[cont].palavra);

                    strcpy(dicionario[cont].tipo, tipoCopia);
                    strcpy(dicionario[cont].palavra, palavraCopia);
                }

                else
                {
                    strcpy(dicionario[cont + 1].tipo, dicionario[cont].tipo);
                    strcpy(dicionario[cont + 1].palavra, dicionario[cont].palavra);
                }
            }

            c++;
        }
    }

    for (i = f; i < 20; i++)
    {
        if (strcmp(fruta, dicionario[i].tipo) == 0)
        {
            for (cont = i; cont >= c; cont--)
            {
                if (cont == i)
                {
                    strcpy(tipoCopia, dicionario[cont].tipo);
                    strcpy(palavraCopia, dicionario[cont].palavra);
                }

                else if (cont == c)
                {
                    strcpy(dicionario[cont + 1].tipo, dicionario[cont].tipo);
                    strcpy(dicionario[cont + 1].palavra, dicionario[cont].palavra);

                    strcpy(dicionario[cont].tipo, tipoCopia);
                    strcpy(dicionario[cont].palavra, palavraCopia);
                }

                else
                {
                    strcpy(dicionario[cont + 1].tipo, dicionario[cont].tipo);
                    strcpy(dicionario[cont + 1].palavra, dicionario[cont].palavra);
                }
            }

            c++;
        }
    }

    for (i = n; i < 20; i++)
    {
        if (strcmp(nome, dicionario[i].tipo) == 0)
        {
            for (cont = i; cont >= c; cont--)
            {
                if (cont == i)
                {
                    strcpy(tipoCopia, dicionario[cont].tipo);
                    strcpy(palavraCopia, dicionario[cont].palavra);
                }

                else if (cont == c)
                {
                    strcpy(dicionario[cont + 1].tipo, dicionario[cont].tipo);
                    strcpy(dicionario[cont + 1].palavra, dicionario[cont].palavra);

                    strcpy(dicionario[cont].tipo, tipoCopia);
                    strcpy(dicionario[cont].palavra, palavraCopia);
                }

                else
                {
                    strcpy(dicionario[cont + 1].tipo, dicionario[cont].tipo);
                    strcpy(dicionario[cont + 1].palavra, dicionario[cont].palavra);
                }
            }

            c++;
        }
    }

    for (i = p; i < 20; i++)
    {
        if (strcmp(profissao, dicionario[i].tipo) == 0)
        {
            for (cont = i; cont >= c; cont--)
            {
                if (cont == i)
                {
                    strcpy(tipoCopia, dicionario[cont].tipo);
                    strcpy(palavraCopia, dicionario[cont].palavra);
                }

                else if (cont == c)
                {
                    strcpy(dicionario[cont + 1].tipo, dicionario[cont].tipo);
                    strcpy(dicionario[cont + 1].palavra, dicionario[cont].palavra);

                    strcpy(dicionario[cont].tipo, tipoCopia);
                    strcpy(dicionario[cont].palavra, palavraCopia);
                }

                else
                {
                    strcpy(dicionario[cont + 1].tipo, dicionario[cont].tipo);
                    strcpy(dicionario[cont + 1].palavra, dicionario[cont].palavra);
                }
            }

            c++;
        }
    }
}

void ImprimeDicionarioPedido(tDicionario dicionario[20])
{
    int i = 0, j = 0;
    int c = 0, f = 5, n = 10, p = 15;

    int tipo = 0, palavra = 0;

    char matriz[20][30];

    scanf("%d %d", &tipo, &palavra);

    if (palavra < 0 || palavra > 4)
    {
        printf("Fora do limite!\n");
    }

    else if (tipo == 0)
    {
        printf("Palavra escolhida: %s\n", dicionario[c + palavra].palavra);
    }

    else if (tipo == 1)
    {
        printf("Palavra escolhida: %s\n", dicionario[f + palavra].palavra);
    }

    else if (tipo == 2)
    {
        printf("Palavra escolhida: %s\n", dicionario[n + palavra].palavra);
    }

    else if (tipo == 3)
    {
        printf("Palavra escolhida: %s\n", dicionario[p + palavra].palavra);
    }
}