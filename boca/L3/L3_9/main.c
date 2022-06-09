#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int verificapH(float pH);

int verificaGotaChuvaAcida(float pH);

float porcentagem(float total, float valor);

void imprimeResultadosAnalise(float porcentagemGotasChuvaAcida, float porcentagemGotasChuvaNormal);

int main()
{
    int area = 0, densidade = 0, tempo = 0;
    int acido = 0, basico = 0, neutro = 0;
    int classifica_pH = 3, classificaGotaDeChuvaAcida = 3;
    int gotaDeChuvaAcida = 0, gotaDeChuvaNormal = 0, i = 0;
    float pH = 0.00, total = 0.00, valor = 0.00, gotaMaisAcida = 7.00, gotaMaisBasica = 7.00, gotaMaisNeutra = 7.00;
    float gotaMaisNeutraAcida = 0.00, gotaMaisNeutraBasica = 14.00;
    float porcentagemGotasChuvaNormal = 0.00, porcentagemGotasChuvaAcida = 0.00;

    scanf("%d %d %d", &area, &densidade, &tempo);

    if (area >= 0 && area <= 50 && densidade >= 0 && densidade <= 50 && tempo >= 0 && tempo <= 12)
    {
        total = area * densidade * tempo;

        if (total != 0)
        {
            for (i = 1; i <= total; i++)
            {
                scanf("%f", &pH);

                if (pH >= 0.00 && pH <= 14.00)
                {
                    classifica_pH = verificapH(pH);

                    if (classifica_pH == 1)
                    {
                        acido += 1;

                        classificaGotaDeChuvaAcida = verificaGotaChuvaAcida(pH);

                        if (classificaGotaDeChuvaAcida == 1)
                        {
                            gotaDeChuvaAcida += 1;
                        }

                        if (pH < gotaMaisAcida)
                        {
                            gotaMaisAcida = pH;
                        }
                    }

                    else if (classifica_pH == 2)
                    {
                        basico += 1;

                        if (pH > gotaMaisBasica)
                        {
                            gotaMaisBasica = pH;
                        }
                    }
                    else
                    {
                        neutro += 1;
                    }

                    if (neutro == 0)
                    {
                        if (pH < 7)
                        {
                            if (pH < gotaMaisNeutraAcida && total == 0)
                            {
                                gotaMaisNeutraAcida = pH;
                            }

                            if (pH > gotaMaisNeutraAcida && pH < 7)
                            {
                                gotaMaisNeutraAcida = pH;
                            }
                        }

                        else if (pH > 7)
                        {
                            if (pH > gotaMaisNeutraBasica && total == 0)
                            {
                                gotaMaisNeutraBasica = pH;
                            }

                            if (pH < gotaMaisNeutraBasica && pH > 7)
                            {
                                gotaMaisNeutraBasica = pH;
                            }
                        }

                        if (7 - gotaMaisNeutraAcida < gotaMaisNeutraBasica - 7)
                        {
                            gotaMaisNeutra = gotaMaisNeutraAcida;
                        }
                        else
                        {
                            gotaMaisNeutra = gotaMaisNeutraBasica;
                        }
                    }
                    else
                    {
                        gotaMaisNeutra = 7.00;
                    }
                }
            }

            printf("%d %d %d ", acido, basico, neutro);

            printf("%.2f %.2f %.2f\n", gotaMaisAcida, gotaMaisBasica, gotaMaisNeutra);

            valor = gotaDeChuvaAcida;

            porcentagemGotasChuvaAcida = porcentagem(total, valor);

            gotaDeChuvaNormal = total - gotaDeChuvaAcida;

            valor = gotaDeChuvaNormal;

            porcentagemGotasChuvaNormal = porcentagem(total, valor);

            imprimeResultadosAnalise(porcentagemGotasChuvaAcida, porcentagemGotasChuvaNormal);
        }
        else
        {
            printf("Nenhuma gota foi avaliada");
        }
    }

    return 0;
}

int verificapH(float pH)
{
    if (pH < 7.00)
    {
        return (1);
    }

    else if (pH > 7.00)
    {
        return (2);
    }

    else
    {
        return (0);
    }
}

int verificaGotaChuvaAcida(float pH)
{
    if (pH < 5.70)
    {
        return (1);
    }
    else
    {
        return (0);
    }
}

float porcentagem(float total, float valor)
{
    float porcentagem = 0.00;

    porcentagem = (valor / total) * 100;

    return (porcentagem);
}

void imprimeResultadosAnalise(float porcentagemGotasChuvaAcida, float porcentagemGotasChuvaNormal)
{
    if (porcentagemGotasChuvaAcida >= 75.00)
    {
        printf("Chuva Acida ");
    }

    else if (porcentagemGotasChuvaNormal >= 75.00)
    {
        printf("Chuva Normal ");
    }
    else
    {
        printf("Chuva com indicios de chuva acida ");
    }

    printf("%.2f%% ", porcentagemGotasChuvaAcida);

    printf("%.2f%%", porcentagemGotasChuvaNormal);
}