#include <stdlib.h>
#include <stdio.h>

typedef struct Aluno
{
    char nome[21];
    int idade;
    float nota1;
    float nota2;
    float nota3;
    float media;
    int matricula;

} tAluno;

void RegistraAlunos(tAluno alunos[], int num);

void CalculaMedia(tAluno alunos[], int num);

void CriaSaida(tAluno alunos[], int num);

void ImprimeTerminal(tAluno alunos[], int num);

int main()
{
    int num = 0;

    scanf("%d\n", &num);

    tAluno alunos[num];

    // InicializaAlunos(alunos, num);

    RegistraAlunos(alunos, num);

    CalculaMedia(alunos, num);

    CriaSaida(alunos, num);

    ImprimeTerminal(alunos, num);

    return 0;
}

void InicializaAlunos(tAluno alunos[], int num)
{
    int i, j;

    for (i = 0; i < num; i++)
    {
        for (j = 0; j < 21; j++)
        {
            alunos[i].nome[j] = '\0';
        }

        alunos[i].idade = 0;
        alunos[i].nota1 = 0;
        alunos[i].nota2 = 0;
        alunos[i].nota3 = 0;
        alunos[i].media = 0;
        alunos[i].matricula = 0;
    }
}

void RegistraAlunos(tAluno alunos[], int num)
{
    int i;

    for (i = 0; i < num; i++)
    {
        scanf("%s\n", alunos[i].nome);
        scanf("%d\n", &alunos[i].idade);
        scanf("%f\n", &alunos[i].nota1);
        scanf("%f\n", &alunos[i].nota2);
        scanf("%f\n", &alunos[i].nota3);
        scanf("%d\n", &alunos[i].matricula);
    }
}

void CalculaMedia(tAluno alunos[], int num)
{
    int i;
    float result = 0;

    for (i = 0; i < num; i++)
    {
        result = ((alunos[i].nota1 + alunos[i].nota2 + alunos[i].nota3) / 3);

        alunos[i].media = result;
    }
}

void CriaSaida(tAluno alunos[], int num)
{
    int i;

    FILE *arquivo;

    arquivo = fopen("Saida.txt", "a+");

    for (i = 0; i < num; i++)
    {
        fprintf(arquivo, "%s,%d,%.2f,%d\n", alunos[i].nome, alunos[i].idade, alunos[i].media, alunos[i].matricula);
    }

    fclose(arquivo);
}

void ImprimeTerminal(tAluno alunos[], int num)
{
    int i, escolhido, matricula;

    scanf("%d\n", &escolhido);

    if (escolhido == 1)
    {
        scanf("%d\n", &matricula);

        for (i = 0; i < num; i++)
        {
            if (matricula == alunos[i].matricula)
            {
                printf("O aluno foi encontrado foi: %s\n", alunos[i].nome);
                break;
            }
        }
    }
}