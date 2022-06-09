#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int EhProduto(char produto);

int AcabaramOsProdutos(char produto);

int QtdDoProdutoMaisComprado();

int main()
{
    int cliente = 0;
    char produto, produtoAnterior;
    int qtdProdutos = 0;
    int qtdProdutoAnterior = 0;
    int qtdProduto = 0;
    int i = 0;
    int qtdProdutoMaisComprado = 0, qtdProdutoMaisCompradoAnterior = 0;
    int clienteProdutoMaisComprado = 0;

    while (1)
    {
        scanf("%d", &cliente);

        if (cliente == -1)
        {
            break;
        }

        scanf(" ");

        qtdProdutoMaisComprado = QtdDoProdutoMaisComprado();

        if (qtdProdutoMaisCompradoAnterior < qtdProdutoMaisComprado)
        {
            qtdProdutoMaisCompradoAnterior = qtdProdutoMaisComprado;
            clienteProdutoMaisComprado = cliente;
        }
    }

    printf("CLIENT:%d QTD:%d\n", clienteProdutoMaisComprado, qtdProdutoMaisComprado);

    return 0;
}

int EhProduto(char produto)
{
    if (produto >= 'A' && produto <= 'Z')
    {
        return 1;
    }

    return 0;
}

int AcabaramOsProdutos(char produto)
{
    if (produto == '0')
    {
        return 1;
    }

    return 0;
}

int QtdDoProdutoMaisComprado()
{
    char produto, produtoAnterior;
    int qtdProdutos = 0;
    int qtdProdutoAnterior = 0;
    int qtdProduto = 0;
    int i = 0;
    int qtdProdutoMaisComprado = 0;
    int clienteProdutoMaisComprado = 0;

    while (1)
    {
        scanf("%c", &produto);

        if (EhProduto(produto) == 1)
        {
            if (i == 0)
            {
                qtdProduto++;
            }

            if (produtoAnterior == produto && i > 0)
            {
                qtdProduto++;
            }

            else if (produtoAnterior != produto && i > 0)
            {
                qtdProdutoAnterior = qtdProduto;
                qtdProduto = 1;

                if (qtdProdutoMaisComprado < qtdProdutoAnterior)
                {
                    qtdProdutoMaisComprado = qtdProdutoAnterior;
                }
            }

            produtoAnterior = produto;
            i++;
        }

        else if (AcabaramOsProdutos(produto) == 1)
        {
            scanf("\n");
            break;
        }
    }

    return qtdProdutoMaisComprado;
}