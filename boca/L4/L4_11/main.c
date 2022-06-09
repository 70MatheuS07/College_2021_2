#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct Boleto
{
    int codigo;
    float valor;

} tBoleto;

tBoleto LehBoleto();

tBoleto MaisCaro(tBoleto boleto, tBoleto boletoMaisCaro);

tBoleto MaisBarato(tBoleto boleto, tBoleto boletoMaisBarato);

float ValorBoleto(tBoleto boleto);

void ImprimeBoleto(tBoleto boletoMaisCaro, tBoleto boletoMaisBarato);

int main()
{
    int n = 0, i = 0;

    float somaDosBoletos = 0;

    tBoleto boleto, boletoMaisCaro = {0, -1000000}, boletoMaisBarato = {0, 1000000};

    scanf("%d\n", &n);

    for (i = 0; i < n; i++)
    {
        boleto = LehBoleto();

        boletoMaisCaro = MaisCaro(boleto, boletoMaisCaro);

        boletoMaisBarato = MaisBarato(boleto, boletoMaisBarato);

        somaDosBoletos += ValorBoleto(boleto);
    }

    ImprimeBoleto(boletoMaisCaro, boletoMaisBarato);

    printf("Soma: %.2f", somaDosBoletos);

    return 0;
}

tBoleto LehBoleto()
{
    tBoleto boleto;

    scanf("%d %f", &boleto.codigo, &boleto.valor);

    return boleto;
}

tBoleto MaisCaro(tBoleto boleto, tBoleto boletoMaisCaro)
{
    if (boleto.valor > boletoMaisCaro.valor)
    {
        return boleto;
    }

    return boletoMaisCaro;
}

tBoleto MaisBarato(tBoleto boleto, tBoleto boletoMaisBarato)
{
    if (boleto.valor < boletoMaisBarato.valor)
    {
        return boleto;
    }

    return boletoMaisBarato;
}

float ValorBoleto(tBoleto boleto)
{
    return boleto.valor;
}

void ImprimeBoleto(tBoleto boletoMaisCaro, tBoleto boletoMaisBarato)
{
    printf("Mais caro: Cod: %d valor: %.2f\n", boletoMaisCaro.codigo, boletoMaisCaro.valor);

    printf("Mais barato: Cod: %d valor: %.2f\n", boletoMaisBarato.codigo, boletoMaisBarato.valor);
}
