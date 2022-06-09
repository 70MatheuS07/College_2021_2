#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main()
{
    int num = 0, id = 0;

    int unidade = 0, dezena = 0, centena = 0, milhar = 0;

    int aux = 0;

    scanf("%d %d", &num, &id);

    if (num < 10)
    {
        if (id == 0)
        {
            printf("VOID\n");
        }

        else
        {
            printf("%d\n", num);
        }
    }

    else
    {
        if (num < 100)
        {
            unidade = num % 10;

            dezena = num % 100;
            dezena /= 10;

            if (id == 0)
            {
                printf("%d\n", unidade);
            }

            else if (id == 1)
            {
                printf("%d\n", dezena);
            }

            else
            {
                if (unidade <= dezena)
                {
                    printf("%d, %d\n", unidade, dezena);
                }

                else
                {
                    printf("%d, %d\n", dezena, unidade);
                }
            }
        }

        else if (num < 1000)
        {
            unidade = num % 10;

            dezena = num % 100;
            dezena /= 10;

            centena = num % 1000;
            centena /= 100;

            if (id == 0)
            {
                if (dezena >= unidade)
                {
                    printf("%d, %d\n", unidade, dezena);
                }

                else
                {
                    printf("%d, %d\n", dezena, unidade);
                }
            }

            else if (id == 1)
            {
                if (centena >= unidade)
                {
                    printf("%d, %d\n", unidade, centena);
                }

                else
                {
                    printf("%d, %d\n", centena, unidade);
                }
            }

            else if (id == 2)
            {
                if (centena >= dezena)
                {
                    printf("%d, %d\n", dezena, centena);
                }

                else
                {
                    printf("%d, %d\n", centena, dezena);
                }
            }

            else
            {
                if (unidade >= centena)
                {
                    aux = centena;
                    centena = unidade;
                    unidade = aux;
                }

                if (unidade >= dezena)
                {
                    aux = dezena;
                    dezena = unidade;
                    unidade = aux;
                }

                if (dezena >= centena)
                {
                    aux = centena;
                    centena = dezena;
                    dezena = aux;
                }

                printf("%d, %d, %d\n", unidade, dezena, centena);
            }
        }

        else if (num < 10000)
        {
            unidade = num % 10;

            dezena = num % 100;
            dezena /= 10;

            centena = num % 1000;
            centena /= 100;

            milhar = num % 10000;
            milhar /= 1000;

            if (id == 0)
            {
                if (unidade > centena)
                {
                    aux = centena;
                    centena = unidade;
                    unidade = aux;
                }

                if (unidade > dezena)
                {
                    aux = dezena;
                    dezena = unidade;
                    unidade = aux;
                }

                if (dezena > centena)
                {
                    aux = centena;
                    centena = dezena;
                    dezena = aux;
                }

                printf("%d, %d, %d\n", unidade, dezena, centena);
            }

            else if (id == 1)
            {
                if (unidade > milhar)
                {
                    aux = milhar;
                    milhar = unidade;
                    unidade = aux;
                }

                if (unidade > dezena)
                {
                    aux = dezena;
                    dezena = unidade;
                    unidade = aux;
                }

                if (dezena > milhar)
                {
                    aux = milhar;
                    milhar = dezena;
                    dezena = aux;
                }

                printf("%d, %d, %d\n", unidade, dezena, milhar);
            }

            else if (id == 2)
            {
                if (unidade > milhar)
                {
                    aux = milhar;
                    milhar = unidade;
                    unidade = aux;
                }

                if (unidade > centena)
                {
                    aux = centena;
                    centena = unidade;
                    unidade = aux;
                }

                if (centena > milhar)
                {
                    aux = milhar;
                    milhar = centena;
                    centena = aux;
                }

                printf("%d, %d, %d\n", unidade, centena, milhar);
            }

            else if (id == 3)
            {
                if (dezena > milhar)
                {
                    aux = milhar;
                    milhar = dezena;
                    dezena = aux;
                }

                if (dezena > centena)
                {
                    aux = centena;
                    centena = dezena;
                    dezena = aux;
                }

                if (centena > milhar)
                {
                    aux = milhar;
                    milhar = centena;
                    centena = aux;
                }

                printf("%d, %d, %d\n", dezena, centena, milhar);
            }

            else
            {
                if (unidade > milhar)
                {
                    aux = milhar;
                    milhar = unidade;
                    unidade = aux;
                }

                if (unidade > centena)
                {
                    aux = centena;
                    centena = unidade;
                    unidade = aux;
                }

                if (unidade > dezena)
                {
                    aux = dezena;
                    dezena = unidade;
                    unidade = aux;
                }

                if (dezena > milhar)
                {
                    aux = milhar;
                    milhar = dezena;
                    dezena = aux;
                }

                if (dezena > centena)
                {
                    aux = centena;
                    centena = dezena;
                    dezena = aux;
                }

                if (centena > milhar)
                {
                    aux = milhar;
                    milhar = centena;
                    centena = aux;
                }

                printf("%d, %d, %d, %d\n", unidade, dezena, centena, milhar);
            }
        }
    }

    return 0;
}