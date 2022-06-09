#include <stdio.h>
#include <stdlib.h>

void ConcatenaString(char *nome, char *sobrenome, char *nomeCompleto);

int main()
{
    char nome[1000];
    char sobrenome[1000];
    char nomeCompleto[2000];

    while (scanf("%s", &*sobrenome) == 1 && scanf("%s", &*nome) == 1)
    {
        ConcatenaString(nome, sobrenome, nomeCompleto);
        printf("%s\n", nomeCompleto);
    }

    return 0;
}

void ConcatenaString(char *nome, char *sobrenome, char *nomeCompleto)
{
    int i = 0, j = 0;
    char c_atual;

    for (i = 0; nome[i] != '\0'; i++)
    {
        c_atual = nome[i];
        nomeCompleto[i] = c_atual;
    }

    for (j = 0; sobrenome[j] != '\0'; i++, j++)
    {
        c_atual = sobrenome[j];
        nomeCompleto[i] = c_atual;
    }
    nomeCompleto[i] = '\0';
}