#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int EhPalindromo(int num);

int main()
{
    int num = 0, result = 3;

    while (scanf("%d", &num) == 1)
    {
        result = EhPalindromo(num);

        if (result == 1)
        {
            printf("S\n");
        }
        else if (result == 0)
        {
            printf("N\n");
        }

        num = 0;
    }

    return 0;
}

int EhPalindromo(int num)
{
    int cont = 0, verdade = 1, mentira = 0, palindromo = 0, loop = 0;
    int unidade = 0, dezena = 0, centena = 0;
    int milhar = 0, dezenaDeMilhar = 0, centenaDeMilhar = 0;
    int bilhar = 0, dezenaDeBilhar = 0, centenaDeBilhar = 0;
    int trilhar = 0;

    loop = num;

    while (loop != 0)
    {
        loop = loop / 10;
        cont++;
    }

    if (cont == 1)
    {
        num = 1;
        return (num);
    }

    else if (cont == 2)
    {
        unidade = num % 10;
        dezena = (num % 100) - unidade;
        unidade = unidade * 10;
        dezena = dezena / 10;
        palindromo = unidade + dezena;

        if (num == palindromo)
        {
            num = 1;
            return (num);
        }
        else
        {
            num = 0;
            return (num);
        }
    }

    else if (cont == 3)
    {
        unidade = num % 10;
        dezena = (num % 100) - unidade;
        centena = (num % 1000) - (dezena + unidade);
        unidade = unidade * 100;
        centena = centena / 100;
        palindromo = unidade + dezena + centena;

        if (num == palindromo)
        {
            num = 1;
            return (num);
        }
        else
        {
            num = 0;
            return (num);
        }
    }

    else if (cont == 4)
    {
        unidade = num % 10;
        dezena = (num % 100) - unidade;
        centena = (num % 1000) - (unidade + dezena);
        milhar = (num % 10000) - (unidade + dezena + centena);
        unidade = unidade * 1000;
        dezena = dezena * 10;
        centena = centena / 10;
        milhar = milhar / 1000;

        palindromo = unidade + dezena + centena + milhar;

        if (num == palindromo)
        {
            num = 1;
            return (num);
        }
        else
        {
            num = 0;
            return (num);
        }
    }

    else if (cont == 5)
    {
        unidade = num % 10;
        dezena = (num % 100) - unidade;
        centena = (num % 1000) - (unidade + dezena);
        milhar = (num % 10000) - (unidade + dezena + centena);
        dezenaDeMilhar = (num % 100000) - (unidade + dezena + centena + milhar);
        unidade = unidade * 10000;
        dezena = dezena * 100;
        milhar = milhar / 100;
        dezenaDeMilhar = dezenaDeMilhar / 10000;

        palindromo = unidade + dezena + centena + milhar + dezenaDeMilhar;

        if (num == palindromo)
        {
            num = 1;
            return (num);
        }
        else
        {
            num = 0;
            return (num);
        }
    }

    else if (cont == 6)
    {
        unidade = num % 10;
        dezena = (num % 100) - unidade;
        centena = (num % 1000) - (unidade + dezena);
        milhar = (num % 10000) - (unidade + dezena + centena);
        dezenaDeMilhar = (num % 100000) - (unidade + dezena + centena + milhar);
        centenaDeMilhar = (num % 1000000) - (unidade + dezena + centena + milhar + dezenaDeMilhar);
        unidade = unidade * 100000;
        dezena = dezena * 1000;
        centena = centena * 10;
        milhar = milhar / 10;
        dezenaDeMilhar = dezenaDeMilhar / 1000;
        centenaDeMilhar = centenaDeMilhar / 100000;

        palindromo = unidade + dezena + centena + milhar + dezenaDeMilhar + centenaDeMilhar;

        if (num == palindromo)
        {
            num = 1;
            return (num);
        }
        else
        {
            num = 0;
            return (num);
        }
    }

    else if (cont == 7)
    {
        unidade = num % 10;
        dezena = (num % 100) - unidade;
        centena = (num % 1000) - (unidade + dezena);
        milhar = (num % 10000) - (unidade + dezena + centena);
        dezenaDeMilhar = (num % 100000) - (unidade + dezena + centena + milhar);
        centenaDeMilhar = (num % 1000000) - (unidade + dezena + centena + milhar + dezenaDeMilhar);
        bilhar = (num % 10000000) - (unidade + dezena + centena + milhar + dezenaDeMilhar + centenaDeMilhar);
        unidade = unidade * 1000000;
        dezena = dezena * 10000;
        centena = centena * 100;
        dezenaDeMilhar = dezenaDeMilhar / 100;
        centenaDeMilhar = centenaDeMilhar / 10000;
        bilhar = bilhar / 1000000;

        palindromo = unidade + dezena + centena + milhar + dezenaDeMilhar + centenaDeMilhar + bilhar;

        if (num == palindromo)
        {
            num = 1;
            return (num);
        }
        else
        {
            num = 0;
            return (num);
        }
    }

    else if (cont == 8)
    {
        unidade = num % 10;
        dezena = (num % 100) - unidade;
        centena = (num % 1000) - (unidade + dezena);
        milhar = (num % 10000) - (unidade + dezena + centena);
        dezenaDeMilhar = (num % 100000) - (unidade + dezena + centena + milhar);
        centenaDeMilhar = (num % 1000000) - (unidade + dezena + centena + milhar + dezenaDeMilhar);
        bilhar = (num % 10000000) - (unidade + dezena + centena + milhar + dezenaDeMilhar + centenaDeMilhar);
        dezenaDeBilhar = (num % 100000000) - (unidade + dezena + centena + milhar + dezenaDeMilhar + centenaDeMilhar + bilhar);
        unidade = unidade * 10000000;
        dezena = dezena * 100000;
        centena = centena * 1000;
        milhar = milhar * 10;
        dezenaDeMilhar = dezenaDeMilhar / 10;
        centenaDeMilhar = centenaDeMilhar / 1000;
        bilhar = bilhar / 100000;
        dezenaDeBilhar = dezenaDeBilhar / 10000000;

        palindromo = unidade + dezena + centena + milhar + dezenaDeMilhar + centenaDeMilhar + bilhar + dezenaDeBilhar;

        if (num == palindromo)
        {
            num = 1;
            return (num);
        }
        else
        {
            num = 0;
            return (num);
        }
    }

    else if (cont == 9)
    {
        unidade = num % 10;
        dezena = (num % 100) - unidade;
        centena = (num % 1000) - (unidade + dezena);
        milhar = (num % 10000) - (unidade + dezena + centena);
        dezenaDeMilhar = (num % 100000) - (unidade + dezena + centena + milhar);
        centenaDeMilhar = (num % 1000000) - (unidade + dezena + centena + milhar + dezenaDeMilhar);
        bilhar = (num % 10000000) - (unidade + dezena + centena + milhar + dezenaDeMilhar + centenaDeMilhar);
        dezenaDeBilhar = (num % 100000000) - (unidade + dezena + centena + milhar + dezenaDeMilhar + centenaDeMilhar + bilhar);
        centenaDeBilhar = (num % 1000000000) - (unidade + dezena + centena + milhar + dezenaDeMilhar + centenaDeMilhar + bilhar + dezenaDeBilhar);
        unidade = unidade * 100000000;
        dezena = dezena * 1000000;
        centena = centena * 10000;
        milhar = milhar * 100;
        centenaDeMilhar = centenaDeMilhar / 100;
        bilhar = bilhar / 10000;
        dezenaDeBilhar = dezenaDeBilhar / 1000000;
        centenaDeBilhar = centenaDeBilhar / 100000000;
        palindromo = unidade + dezena + centena + milhar + dezenaDeMilhar + centenaDeMilhar + bilhar + dezenaDeBilhar + centenaDeBilhar;

        if (num == palindromo)
        {
            num = 1;
            return (num);
        }
        else
        {
            num = 0;
            return (num);
        }
    }

    else if (cont == 10)
    {
        unidade = num % 10;
        dezena = (num % 100) - unidade;
        centena = (num % 1000) - (unidade + dezena);
        milhar = (num % 10000) - (unidade + dezena + centena);
        dezenaDeMilhar = (num % 100000) - (unidade + dezena + centena + milhar);
        centenaDeMilhar = (num % 1000000) - (unidade + dezena + centena + milhar + dezenaDeMilhar);
        bilhar = (num % 10000000) - (unidade + dezena + centena + milhar + dezenaDeMilhar + centenaDeMilhar);
        dezenaDeBilhar = (num % 100000000) - (unidade + dezena + centena + milhar + dezenaDeMilhar + centenaDeMilhar + bilhar);
        centenaDeBilhar = (num % 1000000000) - (unidade + dezena + centena + milhar + dezenaDeMilhar + centenaDeMilhar + bilhar + dezenaDeBilhar);
        trilhar = (num % 10000000000) - (unidade + dezena + centena + milhar + dezenaDeMilhar + centenaDeMilhar + bilhar + dezenaDeBilhar + centenaDeBilhar);
        unidade = unidade * 1000000000;
        dezena = dezena * 10000000;
        centena = centena * 100000;
        milhar = milhar * 1000;
        dezenaDeMilhar = dezenaDeMilhar * 10;
        centenaDeMilhar = centenaDeMilhar / 10;
        bilhar = bilhar / 1000;
        dezenaDeBilhar = dezenaDeBilhar / 100000;
        centenaDeBilhar = centenaDeBilhar / 10000000;
        trilhar = trilhar / 1000000000;

        palindromo = unidade + dezena + centena + milhar + dezenaDeMilhar + centenaDeMilhar + bilhar + dezenaDeBilhar + centenaDeBilhar + trilhar;

        if (num == palindromo)
        {
            num = 1;
            return (num);
        }
        else
        {
            num = 0;
            return (num);
        }
    }
}