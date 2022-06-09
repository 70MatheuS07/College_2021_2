#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct Estudante
{
    int matricula;
    float nota1;
    float nota2;
    float nota3;

} tEstudante;

tEstudante LehEstudante();

float CalculaMediaEstudante(tEstudante estudante);

float MaiorMedia(float media, float mediaMaior);

tEstudante SalvaEstudante(tEstudante estudante);

void ImprimeEstudanteMediaMaior(tEstudante estudanteMediaMaior);

int main()
{
    int n, i;

    float media = 0, somaMedia = 0, mediaMaior = -1000000, mediaGeral = 0;

    tEstudante estudante, estudanteMediaMaior;

    scanf("%d\n", &n);

    for (i = 0; i < n; i++)
    {
        estudante = LehEstudante();

        media = CalculaMediaEstudante(estudante);

        somaMedia += media;

        if (MaiorMedia(media, mediaMaior) == 1)
        {
            mediaMaior = media;

            estudanteMediaMaior = SalvaEstudante(estudante);
        }
    }

    mediaGeral = somaMedia / n;

    ImprimeEstudanteMediaMaior(estudanteMediaMaior);

    printf("Media geral: %.2f", mediaGeral);

    return 0;
}

tEstudante LehEstudante()
{
    tEstudante estudante;

    scanf("%d %f %f %f\n", &estudante.matricula, &estudante.nota1, &estudante.nota2, &estudante.nota3);

    return estudante;
}

float CalculaMediaEstudante(tEstudante estudante)
{
    float result = 0;

    result = (estudante.nota1 + estudante.nota2 + estudante.nota3) / 3;

    return result;
}

float MaiorMedia(float media, float mediaMaior)
{
    if (media > mediaMaior)
    {
        return 1;
    }

    return 0;
}

tEstudante SalvaEstudante(tEstudante estudante)
{
    return estudante;
}

void ImprimeEstudanteMediaMaior(tEstudante estudanteMediaMaior)
{
    printf("Maior media: mat:%d n1:%.2f n2:%.2f n3:%.2f\n", estudanteMediaMaior.matricula, estudanteMediaMaior.nota1, estudanteMediaMaior.nota2, estudanteMediaMaior.nota3);
}