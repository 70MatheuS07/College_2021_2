#include <stdio.h>

int main()
{
    int delegacoes = 0, identificacao = 0, nota1 = 0, nota2 = 0, nota3 = 0, n = 0, melhorAtletaMasculino = 0, maiorNotaMasculino = -1, melhorNotaMasculino = -1, segundaNotaMasculino = -1;
    int terceiraNotaMasculino = -1, segundaMelhorNotaMasculino = -1, terceiraMelhorNotaMasculino = -1, melhorAtletaFeminino = 0, maiorNotaFeminino = -1, melhorNotaFeminino = -1;
    int segundaNotaFeminino = -1, terceiraNotaFeminino = -1, segundaMelhorNotaFeminino = -1, terceiraMelhorNotaFeminino = -1, piorNotaMasculino = 11, piorNotaFeminino = 11;
    int segundaPiorNotaMasculino = 11, terceiraPiorNotaMasculino = 11, segundaPiorNotaFeminino = 11, terceiraPiorNotaFeminino = 11, piorAtletaMasculino = 0, piorAtletaFeminino = 0;
    int somaMasculino = 0, somaFeminino = 0, maiorSomaMasculino = 0, maiorSomaFeminino = 0, delegacaoCampeaMasculino = 0, delegacaoCampeaFeminina = 0;
    char sexoAtleta;

    scanf("%d", &delegacoes);

    for (n = 1; n <= delegacoes; n++)
    {
        while (1) //sempre entra no loop.
        {
            scanf("%d", &identificacao);

            if (identificacao == -1)
            {
                melhorNotaMasculino = 0;
                piorNotaMasculino = 11;
                melhorNotaFeminino = 0;
                piorNotaFeminino = 11;
                break;
            }

            getchar();
            scanf("%c", &sexoAtleta);

            if (sexoAtleta == 'm' || sexoAtleta == 'M')
            {
                scanf("%d %d %d", &nota1, &nota2, &nota3);

                if (nota1 >= nota2 && nota1 >= nota3)
                {
                    if (nota2 >= nota3)
                    {
                        maiorNotaMasculino = nota1;
                        segundaNotaMasculino = nota2;
                        terceiraNotaMasculino = nota3;
                    }

                    if (nota3 > nota2)
                    {
                        maiorNotaMasculino = nota1;
                        segundaNotaMasculino = nota3;
                        terceiraNotaMasculino = nota2;
                    }
                }

                if (nota2 > nota1 && nota2 >= nota3)
                {
                    if (nota1 >= nota3)
                    {
                        maiorNotaMasculino = nota2;
                        segundaNotaMasculino = nota1;
                        terceiraNotaMasculino = nota3;
                    }

                    if (nota3 > nota1)
                    {
                        maiorNotaMasculino = nota2;
                        segundaNotaMasculino = nota3;
                        terceiraNotaMasculino = nota1;
                    }
                }

                if (nota3 > nota1 && nota3 > nota2)
                {

                    if (nota1 >= nota2)
                    {
                        maiorNotaMasculino = nota3;
                        segundaNotaMasculino = nota1;
                        terceiraNotaMasculino = nota2;
                    }

                    if (nota2 > nota1)
                    {
                        maiorNotaMasculino = nota3;
                        segundaNotaMasculino = nota2;
                        terceiraNotaMasculino = nota1;
                    }
                }

                somaMasculino += maiorNotaMasculino; //Acumulador.

                if (somaMasculino > maiorSomaMasculino)
                {
                    maiorSomaMasculino = somaMasculino;
                    delegacaoCampeaMasculino = n;
                }

                if (maiorNotaMasculino > melhorNotaMasculino)
                {
                    melhorNotaMasculino = maiorNotaMasculino;
                    segundaMelhorNotaMasculino = segundaNotaMasculino;
                    terceiraMelhorNotaMasculino = terceiraNotaMasculino;
                    melhorAtletaMasculino = identificacao;
                }

                if (maiorNotaMasculino == melhorNotaMasculino)
                {
                    if (segundaNotaMasculino > segundaMelhorNotaMasculino)
                    {
                        melhorNotaMasculino = maiorNotaMasculino;
                        segundaMelhorNotaMasculino = segundaNotaMasculino;
                        terceiraMelhorNotaMasculino = terceiraNotaMasculino;
                        melhorAtletaMasculino = identificacao;
                    }

                    if (segundaNotaMasculino == segundaMelhorNotaMasculino)
                    {
                        if (terceiraNotaMasculino > terceiraMelhorNotaMasculino)
                        {
                            melhorNotaMasculino = maiorNotaMasculino;
                            segundaMelhorNotaMasculino = segundaNotaMasculino;
                            terceiraMelhorNotaMasculino = terceiraNotaMasculino;
                            melhorAtletaMasculino = identificacao;
                        }
                    }
                }

                if (maiorNotaMasculino < piorNotaMasculino)
                {
                    piorNotaMasculino = maiorNotaMasculino;
                    segundaPiorNotaMasculino = segundaNotaMasculino;
                    terceiraPiorNotaMasculino = terceiraNotaMasculino;
                    piorAtletaMasculino = identificacao;
                }

                if (maiorNotaMasculino == piorNotaMasculino)
                {

                    if (segundaNotaMasculino < segundaPiorNotaMasculino)
                    {
                        piorNotaMasculino = maiorNotaMasculino;
                        segundaPiorNotaMasculino = segundaNotaMasculino;
                        terceiraPiorNotaMasculino = terceiraNotaMasculino;
                        piorAtletaMasculino = identificacao;
                    }

                    if (segundaNotaMasculino == segundaPiorNotaMasculino)
                    {
                        if (terceiraNotaMasculino < terceiraPiorNotaMasculino)
                        {
                            piorNotaMasculino = maiorNotaMasculino;
                            segundaPiorNotaMasculino = segundaNotaMasculino;
                            terceiraPiorNotaMasculino = terceiraNotaMasculino;
                            piorAtletaMasculino = identificacao;
                        }

                        if (terceiraNotaMasculino == terceiraPiorNotaMasculino)
                        {
                            if (maiorNotaMasculino == piorNotaMasculino)
                            {
                                if (identificacao > piorAtletaMasculino)
                                {
                                    piorNotaMasculino = maiorNotaMasculino;
                                    segundaPiorNotaMasculino = segundaNotaMasculino;
                                    terceiraPiorNotaMasculino = terceiraNotaMasculino;
                                    piorAtletaMasculino = identificacao;
                                }
                            }
                        }
                    }
                }
            }

            //Zero os valores porquê para quando retornar dentro do for não dar problema.

            maiorNotaMasculino = 0;
            segundaNotaMasculino = 0;
            terceiraNotaMasculino = 0;

            if (sexoAtleta == 'f' || sexoAtleta == 'F')
            {
                scanf("%d %d %d", &nota1, &nota2, &nota3);

                if (nota1 >= nota2 && nota1 >= nota3)
                {
                    if (nota2 >= nota3)
                    {
                        maiorNotaFeminino = nota1;
                        segundaNotaFeminino = nota2;
                        terceiraNotaFeminino = nota3;
                    }

                    if (nota3 > nota2)
                    {
                        maiorNotaFeminino = nota1;
                        segundaNotaFeminino = nota3;
                        terceiraNotaFeminino = nota2;
                    }
                }

                if (nota2 > nota1 && nota2 >= nota3)
                {
                    if (nota1 >= nota3)
                    {
                        maiorNotaFeminino = nota2;
                        segundaNotaFeminino = nota1;
                        terceiraNotaFeminino = nota3;
                    }

                    if (nota3 > nota1)
                    {
                        maiorNotaFeminino = nota2;
                        segundaNotaFeminino = nota3;
                        terceiraNotaFeminino = nota1;
                    }
                }
                if (nota3 > nota1 && nota3 > nota2)
                {
                    if (nota1 >= nota2)
                    {
                        maiorNotaFeminino = nota3;
                        segundaNotaFeminino = nota1;
                        terceiraNotaFeminino = nota2;
                    }

                    if (nota2 > nota1)
                    {
                        maiorNotaFeminino = nota3;
                        segundaNotaFeminino = nota2;
                        terceiraNotaFeminino = nota1;
                    }
                }

                somaFeminino += maiorNotaFeminino; //Acumulador.

                if (somaFeminino > maiorSomaFeminino)
                {
                    maiorSomaFeminino = somaFeminino;
                    delegacaoCampeaFeminina = n;
                }

                if (maiorNotaFeminino > melhorNotaFeminino)
                {
                    melhorNotaFeminino = maiorNotaFeminino;
                    segundaMelhorNotaFeminino = segundaNotaFeminino;
                    terceiraMelhorNotaFeminino = terceiraNotaFeminino;
                    melhorAtletaFeminino = identificacao;
                }

                if (maiorNotaFeminino == melhorNotaFeminino)
                {

                    if (segundaNotaFeminino > segundaMelhorNotaFeminino)
                    {
                        melhorNotaFeminino = maiorNotaFeminino;
                        segundaMelhorNotaFeminino = segundaNotaFeminino;
                        terceiraMelhorNotaFeminino = terceiraNotaFeminino;
                        melhorAtletaFeminino = identificacao;
                    }

                    if (segundaNotaFeminino == segundaMelhorNotaFeminino)
                    {
                        if (terceiraNotaFeminino > terceiraMelhorNotaFeminino)
                        {
                            melhorNotaFeminino = maiorNotaFeminino;
                            segundaMelhorNotaFeminino = segundaNotaFeminino;
                            terceiraMelhorNotaFeminino = terceiraNotaFeminino;
                            melhorAtletaFeminino = identificacao;
                        }
                    }
                }

                if (maiorNotaFeminino < piorNotaFeminino)
                {
                    piorNotaFeminino = maiorNotaFeminino;
                    segundaPiorNotaFeminino = segundaNotaFeminino;
                    terceiraPiorNotaFeminino = terceiraNotaFeminino;
                    piorAtletaFeminino = identificacao;
                }

                if (maiorNotaFeminino == piorNotaFeminino)
                {

                    if (segundaNotaFeminino < segundaPiorNotaFeminino)
                    {
                        piorNotaFeminino = maiorNotaFeminino;
                        segundaPiorNotaFeminino = segundaNotaFeminino;
                        terceiraPiorNotaFeminino = terceiraNotaFeminino;
                        piorAtletaFeminino = identificacao;
                    }

                    if (segundaNotaFeminino == segundaPiorNotaFeminino)
                    {
                        if (terceiraNotaFeminino < terceiraPiorNotaFeminino)
                        {
                            piorNotaFeminino = maiorNotaFeminino;
                            segundaPiorNotaFeminino = segundaNotaFeminino;
                            terceiraPiorNotaFeminino = terceiraNotaFeminino;
                            piorAtletaFeminino = identificacao;
                        }

                        if (terceiraNotaFeminino == terceiraPiorNotaFeminino)
                        {
                            if (maiorNotaFeminino == piorNotaFeminino)
                            {
                                if (identificacao > piorAtletaFeminino)
                                {
                                    piorNotaFeminino = maiorNotaFeminino;
                                    segundaPiorNotaFeminino = segundaNotaFeminino;
                                    terceiraPiorNotaFeminino = terceiraNotaFeminino;
                                    piorAtletaFeminino = identificacao;
                                }
                            }
                        }
                    }
                }
            }
        }

        //Zero os valores porquê para quando retornar dentro do for não da problema.

        maiorNotaFeminino = 0;
        segundaNotaFeminino = 0;
        terceiraNotaFeminino = 0;

        //Print dentro do loop para gerar as saídas corretamente.

        printf("MELHORES ATLETAS DA DELEGACAO %d\n", n);
        printf("MASCULINO: %d FEMININO: %d\n", melhorAtletaMasculino, melhorAtletaFeminino);
        printf("PIORES ATLETAS DA DELEGACAO %d\n", n);
        printf("MASCULINO: %d FEMININO: %d\n", piorAtletaMasculino, piorAtletaFeminino);
        printf("\n");

        //Zero os valores porquê para quando retornar dentro do for não da problema.

        melhorAtletaFeminino = 0;
        melhorAtletaMasculino = 0;
        piorAtletaFeminino = 0;
        piorAtletaMasculino = 0;
        somaMasculino = 0;
        somaFeminino = 0;
    }

    printf("DELEGACAO CAMPEA:\n");
    printf("MASCULINO: %d FEMININO: %d", delegacaoCampeaMasculino, delegacaoCampeaFeminina);

    return 0;
}