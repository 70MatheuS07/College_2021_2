#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct Produto
{
    int codigo;
    float preco;
    int estoque;

} tProduto;

tProduto LeProduto();

int TemProdutoEmEstoque(tProduto produto);

void ImprimeProduto(tProduto produto);

int EhProduto1MaiorQ2(tProduto produto, tProduto produtoMaior);

int EhProduto1MenorQ2(tProduto produto, tProduto produtoMenor);

int main()
{
    int i = 0, n = 0;
    tProduto produto;
    tProduto produtoMaior = {-32.768, pow(3.4, -38), -32.768};
    tProduto produtoMenor = {32.767, pow(3.4, 38), 32.767};

    scanf("%d ", &n);

    for (i = 1; i <= n; i++)
    {
        produto = LeProduto();

        if (TemProdutoEmEstoque(produto) == 0)
        {
            printf("FALTA:");

            ImprimeProduto(produto);
        }

        if (EhProduto1MaiorQ2(produto, produtoMaior) == 1)
        {
            produtoMaior = produto;
        }

        if (EhProduto1MenorQ2(produto, produtoMenor) == 1)
        {
            produtoMenor = produto;
        }
    }

    printf("MAIOR:");

    produto = produtoMaior;

    ImprimeProduto(produto);

    printf("MENOR:");

    produto = produtoMenor;

    ImprimeProduto(produto);

    return 0;
}

tProduto LeProduto()
{
    tProduto produto;

    scanf("%d;%f;%d ", &produto.codigo, &produto.preco, &produto.estoque);

    return produto;
}

int TemProdutoEmEstoque(tProduto produto)
{
    if (produto.estoque != 0)
    {
        return 1;
    }

    return 0;
}

void ImprimeProduto(tProduto produto)
{
    printf("COD %d, PRE %.2f, QTD %d\n", produto.codigo, produto.preco, produto.estoque);
}

int EhProduto1MaiorQ2(tProduto produto, tProduto produtoMaior)
{
    if (produto.preco > produtoMaior.preco)
    {
        return 1;
    }

    return 0;
}

int EhProduto1MenorQ2(tProduto produto, tProduto produtoMenor)
{
    if (produto.preco < produtoMenor.preco)
    {
        return 1;
    }

    return 0;
}