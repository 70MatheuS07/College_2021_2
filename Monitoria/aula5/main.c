#include <stdlib.h>
#include <stdio.h>

#define ESCOVADO 1
#define ARRUMADA 2
#define PREPARADO 3
#define PENDENTE -1

int TarefasPendentes(int dentes, int cama, int cafe);

int EscovarDentes();

int ArrumarCama();

int PrepararCafe();

int main()
{
    int num = 0;
    int dentes = PENDENTE;
    int cama = PENDENTE;
    int cafe = PENDENTE;

    while (1)
    {
        scanf("%d\n", &num);

        if (num == 0)
        {
            if (TarefasPendentes(dentes, cama, cafe) == 0)
            {
                printf("Saindo de casa!\n");
                break;
            }

            else
            {
                printf("### Ainda ha tarefas pendentes! ###\n");
            }
        }

        else if (num == 1)
        {
            if (dentes != PENDENTE)
            {
                printf("Isso ja foi feito!\n");
            }

            else
            {
                dentes = EscovarDentes();
            }
        }

        else if (num == 2)
        {
            if (cama != PENDENTE)
            {
                printf("Isso ja foi feito!\n");
            }

            else
            {
                cama = ArrumarCama();
            }
        }

        else if (num == 3)
        {
            if (cafe != PENDENTE)
            {
                printf("Isso ja foi feito!\n");
            }

            else
            {
                cafe = PrepararCafe();
            }
        }
    }

    return 0;
}

int TarefasPendentes(int dentes, int cama, int cafe)
{
    if (dentes == PENDENTE || cama == PENDENTE || cafe == PENDENTE)
    {
        return 1;
    }

    return 0;
}

int EscovarDentes()
{
    printf("Escovando os dentes!\n");

    return ESCOVADO;
}

int ArrumarCama()
{
    printf("Arrumando a cama!\n");

    return ARRUMADA;
}

int PrepararCafe()
{
    printf("Preparando o cafe!\n");

    return PREPARADO;
}