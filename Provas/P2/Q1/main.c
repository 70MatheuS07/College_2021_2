#include <stdlib.h>
#include <stdio.h>

#define TAM 40

int CarregarPalavrasConjugacoes(char conjugacoes[17], char palavrasConjugacoes[200000][TAM]);

int CarregarPalavrasIrregulares(char irregulares[16], char palavrasIrregulares[200000][TAM]);

int EhVerboInfinitivo(char entrada[TAM]);

int EhVerboIrregular(char entrada[TAM], char palavrasIrregulares[315][TAM]);

int EhIgual(char entrada[TAM], char palavrasIrregulares[315][TAM], int i);

void Conjuga(char entrada[TAM], char palavrasConjugacoes[200000][TAM], int quantidadePalavrasConjugacoes);

int Prefixo(char entrada[TAM], char prefixo[TAM]);

int ContemPrefixo(char palavrasConjugacoes[200000][TAM], char prefixo[TAM], int i, int tamanhoPrefixo);

void ImprimeConjugacoes(char palavrasConjugacoes[200000][TAM], int i);

int main()
{
    char conjungacoes[17] = {"conjugacoes.txt"};
    char irregulares[16] = {"irregulares.txt"};

    char palavrasConjugacoes[200000][TAM];
    char palavrasIrregulares[315][TAM];

    int quantidadePalavrasConjugacoes = 0;
    int quantidadePalavrasIrregulares = 0;

    char entrada[TAM];

    quantidadePalavrasConjugacoes = CarregarPalavrasConjugacoes(conjungacoes, palavrasConjugacoes);

    quantidadePalavrasIrregulares = CarregarPalavrasIrregulares(irregulares, palavrasIrregulares);

    scanf("%s", entrada);

    if (EhVerboInfinitivo(entrada) == 1)
    {
        if (EhVerboIrregular(entrada, palavrasIrregulares) == 1)
        {
            printf("Verbo nao eh regular.\n");
        }

        else
        {
            Conjuga(entrada, palavrasConjugacoes, quantidadePalavrasConjugacoes);
        }
    }

    else
    {
        if (EhVerboIrregular(entrada, palavrasIrregulares) == 1)
        {
            printf("Verbo nao eh regular.\n");
        }

        else
        {
            printf("Verbo nao esta no infinitivo.\n");
        }
    }

    return 0;
}

int CarregarPalavrasConjugacoes(char conjugacoes[17], char palavrasConjugacoes[200000][TAM])
{
    char caracter;

    int i = 0, j = 0, result = 0;

    FILE *arquivo;

    arquivo = fopen(conjugacoes, "r");

    while (!feof(arquivo))
    {
        fscanf(arquivo, "%c", &caracter);

        if (caracter == '\n')
        {
            palavrasConjugacoes[i][j] = '\0';
            i++;
            j = 0;
        }

        else
        {
            palavrasConjugacoes[i][j] = caracter;
            j++;
        }
    }

    fclose(arquivo);

    return i - 1;
}

int CarregarPalavrasIrregulares(char irregulares[16], char palavrasIrregulares[200000][TAM])
{
    char caracter;

    int i = 0, j = 0, result = 0;

    FILE *arquivo;

    arquivo = fopen(irregulares, "r");

    while (!feof(arquivo))
    {
        fscanf(arquivo, "%c", &caracter);

        if (caracter == '\n')
        {
            palavrasIrregulares[i][j] = '\0';

            i++;
            j = 0;
        }

        else
        {
            palavrasIrregulares[i][j] = caracter;
            j++;
        }
    }

    fclose(arquivo);

    return i - 1;
}

int EhVerboInfinitivo(char entrada[TAM])
{
    int i = 0;

    for (i = 0; i < TAM; i++)
    {
        if (entrada[i] == '\0')
        {
            if (entrada[i - 2] == 'a' && entrada[i - 1] == 'r')
            {
                return 1;
            }

            else if (entrada[i - 2] == 'e' && entrada[i - 1] == 'r')
            {
                return 1;
            }

            else if (entrada[i - 2] == 'i' && entrada[i - 1] == 'r')
            {
                return 1;
            }
        }
    }

    return 0;
}

int EhVerboIrregular(char entrada[TAM], char palavrasIrregulares[315][TAM])
{
    int i = 0, j = 0;

    for (i = 0; i < 315; i++)
    {
        for (j = 0; j < TAM; j++)
        {
            if (entrada[j] == '\0')
            {
                break;
            }

            else if (entrada[j] != palavrasIrregulares[i][j])
            {
                break;
            }

            else if (entrada[j] == palavrasIrregulares[i][j])
            {
                if (EhIgual(entrada, palavrasIrregulares, i) == 1)
                {
                    return 1;
                }
            }
        }
    }

    return 0;
}

int EhIgual(char entrada[TAM], char palavrasIrregulares[315][TAM], int i)
{
    int j = 0;

    for (j = 0; j < TAM; j++)
    {
        if (entrada[j] == '\0')
        {
            break;
        }

        else if (entrada[j] != palavrasIrregulares[i][j])
        {
            return 0;
        }
    }

    return 1;
}

void Conjuga(char entrada[TAM], char palavrasConjugacoes[200000][TAM], int quantidadePalavrasConjugacoes)
{
    int i = 0, j = 0;

    char prefixo[TAM];
    int tamanhoPrefixo = 0;

    tamanhoPrefixo = Prefixo(entrada, prefixo);

    for (i = 0; i < quantidadePalavrasConjugacoes; i++)
    {
        if (ContemPrefixo(palavrasConjugacoes, prefixo, i, tamanhoPrefixo) == 1)
        {
            ImprimeConjugacoes(palavrasConjugacoes, i);
        }
    }
}

int Prefixo(char entrada[TAM], char prefixo[TAM])
{
    int i = 0, j = 0;

    while (1)
    {
        if (entrada[i] == '\0')
        {
            prefixo[i - 2] = '\0';
            prefixo[i - 1] = '\0';
            prefixo[i] = '\0';
            break;
        }

        else
        {
            prefixo[i] = entrada[i];
            i++;
        }
    }

    return i - 2;
}

int ContemPrefixo(char palavrasConjugacoes[200000][TAM], char prefixo[TAM], int i, int tamanhoPrefixo)
{
    int j = 0;

    for (j = 0; j < tamanhoPrefixo; j++)
    {
        if (prefixo[j] == '\0')
        {
            break;
        }

        else if (prefixo[j] != palavrasConjugacoes[i][j])
        {
            return 0;
        }
    }

    return 1;
}

void ImprimeConjugacoes(char palavrasConjugacoes[200000][TAM], int i)
{
    int j = 0;

    for (j = 0; j < TAM; j++)
    {
        if (palavrasConjugacoes[i][j] == '\0')
        {
            break;
        }

        else
        {
            printf("%c", palavrasConjugacoes[i][j]);
        }
    }

    printf("\n");
}