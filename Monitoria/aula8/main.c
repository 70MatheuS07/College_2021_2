#include <stdlib.h>
#include <stdio.h>

typedef struct Estoque
{
    int id;
    char peca[1001];
    int quantidade;
    float preco;

} tEstoque;

typedef struct Pedidos
{
    char nome[1001];
    int id;
    char pecaPedida[1001];
    int quantidade;
    float precoTotal;

} tPedidos;

void InicializaEstoque(tEstoque estoque[100]);

void InicializaPedidos(tPedidos pedidos[1000]);

void RegistraEstoque(tEstoque estoque[100], int vetor[2]);

void ImprimeEstoque(tEstoque estoque[100], int vetor[2]);

void RegistraPedido(tPedidos pedidos[1000], tEstoque estoque[100], int vetor[2]);

void ImprimePedidosCliente(tPedidos pedidos[1000], int vetor[2]);

void CalculaImprimeLucro(tPedidos pedidos[1000], tEstoque estoque[100], int vetor[2]);

int main()
{
    int comando = 0;
    int vetor[2] = {-1, -1};

    tEstoque estoque[100];

    tPedidos pedidos[1000];

    InicializaEstoque(estoque);

    InicializaPedidos(pedidos);

    while (1)
    {
        scanf("%d\n", &comando);

        if (comando == 0)
        {
            break;
        }

        else if (comando == 1)
        {
            RegistraEstoque(estoque, vetor);
        }

        else if (comando == 2)
        {
            ImprimeEstoque(estoque, vetor);
        }

        else if (comando == 3)
        {
            RegistraPedido(pedidos, estoque, vetor);
        }

        else if (comando == 4)
        {
            ImprimePedidosCliente(pedidos, vetor);
        }

        else if (comando == 5)
        {
            CalculaImprimeLucro(pedidos, estoque, vetor);
        }
    }

    return 0;
}

void InicializaEstoque(tEstoque estoque[100])
{
    int i, j;

    for (i = 0; i < 100; i++)
    {
        estoque[i].id = 0;

        for (j = 0; j < 1001; j++)
        {
            estoque[i].peca[j] = '\0';
        }

        estoque[i].quantidade = 0;

        estoque[i].preco = 0;
    }
}

void InicializaPedidos(tPedidos pedidos[1000])
{
    int i, j;

    for (i = 0; i < 1000; i++)
    {
        for (j = 0; j < 1001; j++)
        {
            pedidos[i].nome[j] = '\0';
        }

        pedidos[i].id = 0;

        for (j = 0; j < 1001; j++)
        {
            pedidos[i].pecaPedida[j] = '\0';
        }

        pedidos[i].quantidade = 0;

        pedidos[i].precoTotal = 0;
    }
}

void RegistraEstoque(tEstoque estoque[100], int vetor[2])
{
    vetor[0] += 1;

    scanf("%d\n", &estoque[vetor[0]].id);
    scanf("%[^\n]\n", estoque[vetor[0]].peca);
    scanf("%d\n", &estoque[vetor[0]].quantidade);
    scanf("%f\n", &estoque[vetor[0]].preco);

    printf("%s cadastrado com sucesso!\n", estoque[vetor[0]].peca);
}

void ImprimeEstoque(tEstoque estoque[100], int vetor[2])
{
    int i = 0;

    printf("\n### ESTOQUE ###\n");

    for (i = 0; i <= vetor[0]; i++)
    {
        printf("%d %s %d UN. R$ %.2f\n", estoque[i].id, estoque[i].peca, estoque[i].quantidade, estoque[i].preco);
    }

    printf("### FIM DO ESTOQUE ###\n\n");
}

void RegistraPedido(tPedidos pedidos[1000], tEstoque estoque[100], int vetor[2])
{
    char nome[1001];
    int id = 0;
    int quantidade = 0;
    int i = 0, j = 0;

    scanf("%s\n", nome);
    scanf("%d\n", &id);
    scanf("%d\n", &quantidade);

    for (i = 0; i <= vetor[0]; i++)
    {
        if (estoque[i].id == id)
        {
            if (estoque[i].quantidade >= quantidade)
            {
                vetor[1] += 1;

                for (j = 0; j < 1001; j++)
                {
                    pedidos[vetor[1]].nome[j] = nome[j];
                    pedidos[vetor[1]].pecaPedida[j] = estoque[i].peca[j];
                }

                pedidos[vetor[1]].id = id;
                pedidos[vetor[1]].quantidade = quantidade;

                estoque[i].quantidade -= quantidade;

                printf("Pedido de %s registrado!\n", nome);
                break;
            }

            else
            {
                printf("Pedido de %s negado!\n", nome);
                break;
            }
        }
    }
}

void ImprimePedidosCliente(tPedidos pedidos[1000], int vetor[2])
{
    int i, j;
    char nome[1001];
    int igual = 1;
    int soUmaVez = 0;

    scanf("%s\n", nome);

    for (i = 0; i <= vetor[1]; i++)
    {
        for (j = 0; j < 1001; j++)
        {
            if (pedidos[i].nome[j] == '\0')
            {
                break;
            }

            if (pedidos[i].nome[j] != nome[j])
            {
                igual = 0;
                break;
            }
        }

        if (igual == 1)
        {
            if (soUmaVez == 0)
            {
                printf("\n## Pedidos de %s ##\n", nome);
                soUmaVez++;
            }

            printf("%d %s\n", pedidos[i].quantidade, pedidos[i].pecaPedida);
        }

        igual = 1;
    }
}

void CalculaImprimeLucro(tPedidos pedidos[1000], tEstoque estoque[100], int vetor[2])
{
    int i, j, k;
    int igual = 1;
    float lucroTotal = 0;

    for (i = 0; i <= vetor[0]; i++)
    {
        for (j = 0; j <= vetor[1]; j++)
        {
            for (k = 0; k < 1001; k++)
            {
                if (estoque[i].peca[k] != pedidos[j].pecaPedida[k])
                {
                    igual = 0;
                    break;
                }
            }

            if (igual == 1)
            {
                pedidos[j].precoTotal = (float)(estoque[i].preco * pedidos[j].quantidade);

                lucroTotal += pedidos[j].precoTotal;
            }

            igual = 1;
        }
    }

    printf("\n## O lucro da loja foi de R$ %.2f\n", lucroTotal);
}