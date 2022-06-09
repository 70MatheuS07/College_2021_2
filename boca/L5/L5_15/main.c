#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int codigo;
    char sobrenome[21];
    char nome[21];
    int nota;
    int idade;

} tCandidato;

tCandidato LeCandidato();

void OrdenaCrescente(tCandidato candidatos[], int num);

void TrocaValor(tCandidato candidatos[], int i, int j);

void ImprimeCandidato(tCandidato candidato);

int main()
{
    int num = 0, i = 0;

    scanf("%d", &num);

    tCandidato candidatos[num];

    for (i = 0; i < num; i++)
    {
        candidatos[i] = LeCandidato();
    }

    OrdenaCrescente(candidatos, num);

    for (i = 0; i < num; i++)
    {
        ImprimeCandidato(candidatos[i]);
    }

    return 0;
}

tCandidato LeCandidato()
{
    tCandidato candidato;

    scanf("%*[^{]");
    scanf("%*[{ ]");
    scanf("%d", &candidato.codigo);
    scanf("%*[, ]");
    scanf("%[^,],", candidato.sobrenome);
    scanf("%*[ ]");
    scanf("%[^,],", candidato.nome);
    scanf("%d", &candidato.nota);
    scanf("%*[, ]");
    scanf("%d", &candidato.idade);
    scanf("%*[^\n]\n");

    return candidato;
}

void OrdenaCrescente(tCandidato candidatos[], int num)
{
    int i, menor, aux, j;

    for (i = 0; i < num - 1; i++)
    {
        for (j = i + 1; j < num; j++)
        {
            if (strcmp(candidatos[i].nome, candidatos[j].nome) > 0)
            {
                TrocaValor(candidatos, i, j);
            }
            else if (strcmp(candidatos[i].nome, candidatos[j].nome) == 0)
            {
                if (strcmp(candidatos[i].sobrenome, candidatos[j].sobrenome) > 0)
                {
                    TrocaValor(candidatos, i, j);
                }
            }
        }
    }
}

void TrocaValor(tCandidato candidatos[], int i, int j)
{
    tCandidato aux;

    aux = candidatos[j];
    candidatos[j] = candidatos[i];
    candidatos[i] = aux;
}

void ImprimeCandidato(tCandidato candidato)
{
    printf("CAND(%d): %s %s, Nota:%d, Idade:%d\n", candidato.codigo, candidato.nome, candidato.sobrenome, candidato.nota, candidato.idade);
}