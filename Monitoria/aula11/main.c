#include <stdlib.h>
#include <stdio.h>

void LehStrings(char string1[100], char string2[100]);

void ContaTamanhoStrings(char string1[100], char string2[100], int tamanhoStrings[2]);

void TiraEspacos(char string1[100], char string2[100], char string1_SemSpace[100], char string2_SemSpace[100]);

void JuntaStrings(char string1_SemSpace[100], char string2_SemSpace[100], char stringsJuntas[200]);

void InverteString(char stringsJuntas[200], char stringJuntasInvertida[200]);

int EhPalindromo(char stringsJuntas[200], char stringJuntasInvertida[200]);

int main()
{
    char string1[100];
    char string2[100];
    char string1_SemSpace[100];
    char string2_SemSpace[100];
    char stringsJuntas[200];
    char stringsJuntasInvertida[200];
    int tamanhoStrings[2] = {0, 0};

    LehStrings(string1, string2);

    ContaTamanhoStrings(string1, string2, tamanhoStrings);

    printf("QUANTIDADE DE CARACTERES DA STRING 1: %d\n", tamanhoStrings[0]);
    printf("QUANTIDADE DE CARACTERES DA STRING 2: %d\n\n", tamanhoStrings[1]);

    TiraEspacos(string1, string2, string1_SemSpace, string2_SemSpace);

    JuntaStrings(string1_SemSpace, string2_SemSpace, stringsJuntas);

    InverteString(stringsJuntas, stringsJuntasInvertida);

    if (EhPalindromo(stringsJuntas, stringsJuntasInvertida) == 1)
    {
        printf("FORMA PALINDROMO: sim\n\n");
    }

    else
    {
        printf("FORMA PALINDROMO: nao\n\n");
    }

    printf("TUDO MAIUSCULO: %s %s\n", string1, string2);

    return 0;
}

void LehStrings(char string1[100], char string2[100])
{
    int i = 0;
    char caracter;

    for (i = 0; i < 100; i++)
    {
        scanf("%c", &caracter);

        if (caracter >= 'a' && caracter <= 'z')
        {
            caracter -= 32;
        }

        if (caracter == '\n')
        {
            string1[i] = '\0';

            break;
        }

        else
        {
            string1[i] = caracter;
        }
    }

    for (i = 0; i < 100; i++)
    {
        scanf("%c", &caracter);

        if (caracter >= 'a' && caracter <= 'z')
        {
            caracter -= 32;
        }

        if (caracter == '\n')
        {
            string2[i] = '\0';

            break;
        }

        else
        {
            string2[i] = caracter;
        }
    }
}

void ContaTamanhoStrings(char string1[100], char string2[100], int tamanhoStrings[2])
{
    int i = 0;

    for (i = 0; i < 100; i++)
    {
        if (string1[i] == '\0')
        {
            break;
        }

        else
        {
            tamanhoStrings[0]++;
        }
    }

    for (i = 0; i < 100; i++)
    {

        if (string2[i] == '\0')
        {
            break;
        }

        else
        {
            tamanhoStrings[1]++;
        }
    }
}

void TiraEspacos(char string1[100], char string2[100], char string1_SemSpace[100], char string2_SemSpace[100])
{
    int i = 0, a = 0;

    for (i = 0; i < 100; i++)
    {
        if (string1[i + a] == ' ')
        {
            a++;
        }

        string1_SemSpace[i] = string1[i + a];
    }

    a = 0;

    for (i = 0; i < 100; i++)
    {
        if (string2[i + a] == ' ')
        {
            a++;
        }

        string2_SemSpace[i] = string2[i + a];
    }
}

void JuntaStrings(char string1_SemSpace[100], char string2_SemSpace[100], char stringsJuntas[200])
{
    int i = 0, j = 0;

    while (1)
    {
        if (string1_SemSpace[i] == '\0')
        {
            break;
        }

        else
        {
            stringsJuntas[j] = string1_SemSpace[i];
            i++;
            j++;
        }
    }

    i = 0;

    while (1)
    {
        if (string2_SemSpace[i] == '\0')
        {
            break;
        }

        else
        {
            stringsJuntas[j] = string2_SemSpace[i];
            i++;
            j++;
        }
    }

    stringsJuntas[j] = '\0';
}

void InverteString(char stringsJuntas[200], char stringJuntasInvertida[200])
{
    int i = 0, j = 0;
    int cont = 0;

    while (1)
    {
        if (stringsJuntas[cont] == '\0')
        {
            break;
        }

        else
        {
            cont++;
        }
    }

    for (i = cont - 1; j < cont; i--)
    {
        stringJuntasInvertida[j] = stringsJuntas[i];

        j++;
    }
}

int EhPalindromo(char stringsJuntas[200], char stringJuntasInvertida[200])
{
    int i = 0;

    for (i = 0; i < 200; i++)
    {
        if (stringsJuntas[i] == '\0')
        {
            return 1;
        }

        if (stringsJuntas[i] != stringJuntasInvertida[i])
        {
            return 0;
        }
    }
}