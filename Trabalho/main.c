#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef struct Jogador
{
    int pontos;
    int acertos;
    char nome[20];

} tJogador;

typedef struct Jogo
{
    int qtd_jogadores;
    tJogador jogador[4];
    char matrizPalavras[40][41];
    char dica[20];
    char palavra[20];
    char comecaJogo;

} tJogo;

typedef struct Playing
{
    int quemInicia;
    int qualPalavra;
    int tamanhoPalavra;
    char palavraVisivel[20];
    char letrasEscolhidas[26];
    char letra;

} tPlaying;

void TelaInicial();

tJogo InicializaJogo();

tJogo ModoJogo(tJogo jogo);

int NumeroJogadoresErrado(tJogo jogo);

tJogo QuantidadeJogadoresErrada(tJogo jogo);

tJogo PegaNomes(tJogo jogo);

int ComecaJogo(tJogo jogo);

tJogo RegistraPalavras(tJogo jogo);

tJogo RetiraBarraR(tJogo jogo);

tJogo PlayGame(tJogo jogo);

tPlaying InicializaPlaying(tJogo jogo);

tPlaying InicializaLetrasEscolhidas(tPlaying playing);

tPlaying InicializaPalavraVisivel(tPlaying playing);

tPlaying SorteioDicaPalavra(tPlaying playing);

tJogo ColetaDicaColetaPalavra(tJogo jogo, tPlaying playing);

tPlaying SorteioJogador(tJogo jogo, tPlaying playing);

tPlaying TamanhoPalavra(tJogo jogo, tPlaying playing);

tPlaying RegistraPalavraVisivel(tPlaying playing);

int AcabouJogo(tJogo jogo, tPlaying playing);

int ConferePalavra(tJogo jogo, tPlaying playing);

void CabecalhoJogo(tJogo jogo, tPlaying playing);

void ImprimeNomeJogadoresCabecalho(tJogo jogo);

void ImprimeEspacosNome(int cont_TamanhoNome);

void ImprimePalavraVisivel(tPlaying playing);

void ImprimeEspacosPalavraVisivel(tPlaying playing);

void ImprimeDica(tJogo jogo);

void ImprimeLetrasEscolhidas(tPlaying playing);

tPlaying Jogada(tJogo jogo, tPlaying playing);

int LetraRepetida(tPlaying playing, char letra);

tPlaying RegistraLetra(tPlaying playing, char letra);

tJogo RegistraAcertoOuErro(tJogo jogo, tPlaying playing);

tPlaying RegistraLetraNaPalavraVisivel(tJogo jogo, tPlaying playing);

tPlaying PassaJogada(tJogo jogo, tPlaying playing);

void ResultadoJogo(tJogo jogo);

void JogadorPerdeu(tJogo jogo, int cont);

void JogadorGanhou(tJogo jogo, int cont);

void DoisJogadoresEmpataram(tJogo jogo, int cont, int cont_2);

void TresJogadoresEmpataram(tJogo jogo, int cont, int cont_2, int cont_3);

void QuatroJogadoresEmpataram(tJogo jogo, int cont, int cont_2, int cont_3, int cont_4);

void ImprimeNomeJogadoresVencedor(tJogo jogo, int cont);

int JogarNovamente();

// CORRECAO.
tJogo RestauraParaJogarNovamente(tJogo jogo);

int main()
{
    int jogaramQuantasVezes = 0;
    tJogo jogo;

    system("clear");

    TelaInicial();

    system("clear");

    while (1)
    {
        while (1)
        {
            // Conseguir jogar novamente sem adicionar os nomes (CORRECAO).
            if (jogaramQuantasVezes == 0)
            {
                // Inicializo a struct para padronizar meu codigo sempre que há um jogo.
                jogo = InicializaJogo();

                jogo = ModoJogo(jogo);

                if (NumeroJogadoresErrado(jogo) == 1)
                {
                    jogo = QuantidadeJogadoresErrada(jogo);
                }

                else
                {
                    jogo = PegaNomes(jogo);
                }

                // Guarda as palavras do arquivo palavras.csv em uma matriz.
                jogo = RegistraPalavras(jogo);

                // No windows existe um '\r' que aparece antes do '\n' ao coletar as palavras do arquivo.
                // Entao foi criada uma funcao para retirar esse '\r' e deixar a struct padronizada (caso necessario).
                jogo = RetiraBarraR(jogo);
            }

            if (ComecaJogo(jogo) == 1)
            {
                break;
            }
        }

        jogo = PlayGame(jogo);

        ResultadoJogo(jogo);

        if (JogarNovamente() == 2)
        {
            break;
        }

        // Restaura tudo, tirando nomes e quantidade de jogadores (CORRECAO).
        else
        {
            jogo = RestauraParaJogarNovamente(jogo);
            jogaramQuantasVezes++;
        }
    }

    return 0;
}

void TelaInicial()
{
    char caracter, lixo;
    while (1)
    {
        printf(" ______________________________________________________________________________ \n");
        printf("|   ______                                                  (»»»)              |\n");
        printf("|  | _____|                                                 (»»»)              |\n");
        printf("|  | |____   ___   _ __   ____    ___ _                     (»»»)              |\n");
        printf("|  | _____| / _ \\ | '__| /  __|  / _ ' |                    (»»»)              |\n");
        printf("|  | |     | (_) || |   |  (__  | (_)  |                    (»»»)              |\n");
        printf("|  |_|      \\___/ |_|    \\ ___|  \\___,_|                    /»»/\\              |\n");
        printf("|                                                          / ,^. \\             |\n");
        printf("|                                                         / /   \\ \\            |\n");
        printf("|                                                        / /     \\ \\           |\n");
        printf("|                                                       ( (       ) )          |\n");
        printf("|                                                       ( (       ) )          |\n");
        printf("|                                                       ( (       ) )          |\n");
        printf("|                                                        \\ \\     / /           |\n");
        printf("|                                                         \\ '___' /            |\n");
        printf("|   Aperte ENTER para comecar a jogar                      '_____'             |\n");
        printf("|______________________________________________________________________________|\n\n");

        scanf("%c", &caracter);

        if (caracter == '\n')
        {
            break;
        }

        else
        {
            system("clear");
        }
    }
}

tJogo InicializaJogo()
{
    tJogo jogo;

    int i = 0, j = 0;

    jogo.qtd_jogadores = 0;
    jogo.comecaJogo = '\0';

    for (i = 0; i < 4; i++)
    {
        jogo.jogador[i].pontos = 6;
        jogo.jogador[i].acertos = 0;

        for (j = 0; j < 20; j++)
        {
            jogo.jogador[i].nome[j] = '\0';
            jogo.palavra[j] = '\0';
            jogo.dica[j] = '\0';
        }
    }

    for (i = 0; i < 40; i++)
    {
        for (j = 0; j < 41; j++)
        {
            jogo.matrizPalavras[i][j] = '\0';
        }
    }

    return jogo;
}

tJogo ModoJogo(tJogo jogo)
{
    char lixo;

    printf("+------------------------------------------------+\n");
    printf("| Informe a quantidade de jogadores disponiveis: |\n");
    printf("|                                                |\n");
    printf("| 1- Modo solo (Treinamento).                    |\n");
    printf("| 2- 2 jogadores.                                |\n");
    printf("| 3- 3 jogadores.                                |\n");
    printf("| 4- 4 jogadores.                                |\n");
    printf("| 0- Sair do Jogo.                               |\n");
    printf("+------------------------------------------------+\n\n");

    scanf("%d%c", &jogo.qtd_jogadores, &lixo);

    return jogo;
}

int NumeroJogadoresErrado(tJogo jogo)
{
    if (jogo.qtd_jogadores > 0 && jogo.qtd_jogadores < 5)
    {
        return 0;
    }

    return 1;
}

tJogo QuantidadeJogadoresErrada(tJogo jogo)
{
    if (jogo.qtd_jogadores == 0)
    {
        exit(0);
    }

    else
    {
        printf("Escolha um valor dentro das disponiveis:\n\n");

        // Como o numero esta errado, uso o '9' para retornar falso na funcao ComecaJogo.
        jogo.comecaJogo = '9';
    }

    return jogo;
}

tJogo PegaNomes(tJogo jogo)
{
    int i = 0, j = 0;
    char letra;

    for (i = 0; i < jogo.qtd_jogadores; i++)
    {
        system("clear");

        printf("+------------------------------+\n");
        printf("| Informe o nome do jogador %d: |\n", i + 1);
        printf("| 9 - Voltar                   |\n");
        printf("| 0 - Sair do Jogo             |\n");
        printf("+------------------------------+\n\n");

        printf("Nome: ");

        for (j = 0; j < 20; j++)
        {
            scanf("%c", &letra);

            if (letra == '0')
            {
                // O numero '0' é digitado quando o usuario quer sair do jogo, por isso há um exit(0).
                exit(0);
            }

            else if (letra == '\n')
            {
                break;
            }

            else if (letra == '9')
            {
                jogo.comecaJogo = letra;
                return jogo;
            }

            else
            {
                jogo.jogador[i].nome[j] = letra;
            }
        }
    }

    jogo.comecaJogo = '\0';
    return jogo;
}

int ComecaJogo(tJogo jogo)
{
    if (jogo.comecaJogo == '9')
    {
        return 0;
    }

    return 1;
}

tJogo RegistraPalavras(tJogo jogo)
{
    char caracter, lixo;

    int i = 0, j = 0;

    FILE *arquivo;

    arquivo = fopen("palavras.csv", "r");

    while (!feof(arquivo))
    {
        fscanf(arquivo, "%c", &caracter);

        // Esse if deixa todas as letras em maiusculo caso estejam em minusculo.
        if ((caracter >= 'a' && caracter <= 'z') && caracter != ' ')
        {
            caracter -= 32;
        }

        // O '\n' é um identificador de troca de linha e zera o 'j' para recomecar a contagem das colunas.
        if (caracter == '\n')
        {
            i++;
            j = 0;
        }

        else
        {
            jogo.matrizPalavras[i][j] = caracter;
            j++;
        }
    }

    fclose(arquivo);

    return jogo;
}

tJogo RetiraBarraR(tJogo jogo)
{
    int i = 0, j = 0;

    for (i = 0; i < 40; i++)
    {
        for (j = 0; j < 41; j++)
        {
            if (jogo.matrizPalavras[i][j] == '\r')
            {
                jogo.matrizPalavras[i][j] = '\0';
            }

            else if (jogo.matrizPalavras[i][j] == '\0')
            {
                break;
            }
        }
    }

    return jogo;
}

tJogo PlayGame(tJogo jogo)
{
    int i = 0, j = 0;

    tPlaying playing;

    playing = InicializaPlaying(jogo);

    playing = SorteioDicaPalavra(playing);

    jogo = ColetaDicaColetaPalavra(jogo, playing);

    playing = SorteioJogador(jogo, playing);

    playing = TamanhoPalavra(jogo, playing);

    playing = RegistraPalavraVisivel(playing);

    // Começa o game.
    while (1)
    {
        if (AcabouJogo(jogo, playing) == 1)
        {
            break;
        }

        CabecalhoJogo(jogo, playing);

        playing = Jogada(jogo, playing);

        jogo = RegistraAcertoOuErro(jogo, playing);

        playing = RegistraLetraNaPalavraVisivel(jogo, playing);

        playing = PassaJogada(jogo, playing);
    }

    return jogo;
}

tPlaying InicializaPlaying(tJogo jogo)
{
    tPlaying playing;

    playing.quemInicia = 0;
    playing.qualPalavra = 0;
    playing.tamanhoPalavra = 0;

    playing = InicializaLetrasEscolhidas(playing);
    playing = InicializaPalavraVisivel(playing);

    return playing;
}

tPlaying InicializaLetrasEscolhidas(tPlaying playing)
{
    int i = 0;

    for (i = 0; i < 26; i++)
    {
        playing.letrasEscolhidas[i] = '\0';
    }

    return playing;
}

tPlaying InicializaPalavraVisivel(tPlaying playing)
{
    int i = 0;

    for (i = 0; i < 20; i++)
    {
        playing.palavraVisivel[i] = '\0';
    }

    return playing;
}

tPlaying SorteioDicaPalavra(tPlaying playing)
{
    int num = 0;

    srand((unsigned)time(NULL));

    num = 1 + (rand() % 40);

    playing.qualPalavra = num;

    return playing;
}

tJogo ColetaDicaColetaPalavra(tJogo jogo, tPlaying playing)
{
    int i = 0, j = 0;
    int trocar = 1;

    for (j = 0; j < 40; j++)
    {
        if (jogo.matrizPalavras[playing.qualPalavra - 1][j] == ',')
        {
            trocar = 2;
            j++;
        }

        if (trocar == 1)
        {
            if (j == 0)
            {
                jogo.dica[j] = jogo.matrizPalavras[playing.qualPalavra - 1][j];
            }

            else
            {
                jogo.dica[j] = jogo.matrizPalavras[playing.qualPalavra - 1][j];

                // Caso a dica tenha espaco, nao havera alteracao na sua forma.
                if (jogo.dica[j] != ' ')
                {
                    jogo.dica[j] += 32;
                }
            }
        }

        else
        {
            jogo.palavra[i] = jogo.matrizPalavras[playing.qualPalavra - 1][j];
            i++;
        }
    }

    return jogo;
}

tPlaying SorteioJogador(tJogo jogo, tPlaying playing)
{
    int num = 1;

    srand((unsigned)time(NULL));

    num = 1 + (rand() % jogo.qtd_jogadores);

    playing.quemInicia = num;

    return playing;
}

tPlaying TamanhoPalavra(tJogo jogo, tPlaying playing)
{
    int i = 0, result = 0;

    for (i = 0; i < 20; i++)
    {
        if (jogo.palavra[i] == '\0')
        {
            break;
        }

        else
        {
            result++;
        }
    }

    playing.tamanhoPalavra = result;

    return playing;
}

tPlaying RegistraPalavraVisivel(tPlaying playing)
{
    int i = 0;

    for (i = 0; i < 20; i++)
    {
        if (i < playing.tamanhoPalavra)
        {
            playing.palavraVisivel[i] = '_';
        }

        else
        {
            return playing;
        }
    }
}

int AcabouJogo(tJogo jogo, tPlaying playing)
{
    int i = 0, cont = 0;

    if (ConferePalavra(jogo, playing) == 1)
    {
        return 1;
    }

    for (i = 0; i < jogo.qtd_jogadores; i++)
    {
        if (jogo.jogador[i].pontos == 0)
        {
            cont++;
        }

        if (cont == jogo.qtd_jogadores)
        {
            return 1;
        }

        // CORRECAO: O jogo finaliza errado quando somente 1 jogador tem pontos

        if ((cont == (jogo.qtd_jogadores - 1)) && jogo.qtd_jogadores != 1)
        {
            return 1;
        }
    }

    return 0;
}

int ConferePalavra(tJogo jogo, tPlaying playing)
{
    int i = 0;

    for (i = 0; i < playing.tamanhoPalavra; i++)
    {
        if (jogo.palavra[i] != playing.palavraVisivel[i])
        {
            return 0;
        }
    }

    return 1;
}

void CabecalhoJogo(tJogo jogo, tPlaying playing)
{
    system("clear");
    printf("+-----------------------------------------------------------+\n");
    printf("| ######################### FORCA ######################### |\n");
    printf("|                                                           |\n");

    ImprimeNomeJogadoresCabecalho(jogo);

    ImprimePalavraVisivel(playing);

    ImprimeDica(jogo);

    ImprimeLetrasEscolhidas(playing);
}

void ImprimeNomeJogadoresCabecalho(tJogo jogo)
{
    int i = 0, j = 0;
    int cont_TamanhoNome = 0;

    for (i = 0; i < jogo.qtd_jogadores; i++)
    {
        cont_TamanhoNome = 0;

        printf("| Jogador %d: ", (i + 1));

        for (j = 0; j < 20; j++)
        {
            if (jogo.jogador[i].nome[j] == '\0')
            {
                break;
            }

            else
            {
                printf("%c", jogo.jogador[i].nome[j]);
                cont_TamanhoNome++;
            }
        }

        if (jogo.jogador[i].pontos == 0)
        {
            printf(" -> %d - Perdeu!", jogo.jogador[i].pontos);

            cont_TamanhoNome += 26;
            ImprimeEspacosNome(cont_TamanhoNome);
            printf("\n");
        }

        else
        {
            printf(" -> %d", jogo.jogador[i].pontos);

            cont_TamanhoNome += 16;
            ImprimeEspacosNome(cont_TamanhoNome);
            printf("\n");
        }
    }

    printf("|                                                           |\n");
    printf("|                                                           |\n");
}

void ImprimeEspacosNome(int cont_TamanhoNome)
{
    int i = 0;

    for (i = cont_TamanhoNome; i < 58; i++)
    {
        printf(" ");
    }

    printf("|");
}

void ImprimePalavraVisivel(tPlaying playing)
{
    int i = 0;

    printf("| ");

    for (i = 0; i < 20; i++)
    {
        if (i == playing.tamanhoPalavra - 1)
        {
            printf("%c", playing.palavraVisivel[i]);
            break;
        }

        else
        {
            printf("%c ", playing.palavraVisivel[i]);
        }
    }

    ImprimeEspacosPalavraVisivel(playing);
}

void ImprimeEspacosPalavraVisivel(tPlaying playing)
{
    int i = 0;

    // O i = (playing.tamanhoPalavra * 2) - 1) tira o espaco ja consumido pela palavraVisivel printada, mantendo a margem no lugar.
    for (i = ((playing.tamanhoPalavra * 2) - 1); i < 54; i++)
    {
        printf(" ");
    }

    // Pequeno EasterEgg ¯\_(ツ)_/¯ (somente uma decoracao).
    printf(" ツ ");

    printf("|\n");
    printf("+-----------------------------------------------------------+");
}

void ImprimeDica(tJogo jogo)
{
    int i = 0;

    printf("\n\nDica: ");

    for (i = 0; i < 20; i++)
    {
        if (jogo.dica[i] == '\0')
        {
            break;
        }

        else
        {
            printf("%c", jogo.dica[i]);
        }
    }

    printf("          ");
}

void ImprimeLetrasEscolhidas(tPlaying playing)
{
    int i = 0;

    printf("Letras ja escolhidas:");

    for (i = 0; i < 26; i++)
    {
        if (playing.letrasEscolhidas[i] == '\0')
        {
            break;
        }

        printf("%c ", playing.letrasEscolhidas[i]);
    }

    printf("\n\n");
}

tPlaying Jogada(tJogo jogo, tPlaying playing)
{
    int i = 0;

    char letra, lixo;

    printf("Jogador %d digite uma letra a sua escolha: ", playing.quemInicia);

    scanf("%c%c", &letra, &lixo);

    printf("\n");

    while (1)
    {
        if ((letra >= 'a' && letra <= 'z') || (letra >= 'A' && letra <= 'Z'))
        {
            if (letra >= 'a' && letra <= 'z')
            {
                letra -= 32;
            }

            if (LetraRepetida(playing, letra) == 0)
            {
                playing = RegistraLetra(playing, letra);

                break;
            }

            else
            {
                printf("A letra ja foi escolhida. Favor digitar uma outra letra: ");
                scanf("%c%c", &letra, &lixo);
            }
        }

        else
        {
            printf("Letra invalida, tente outra letra: ");
            scanf("%c%c", &letra, &lixo);
        }
    }

    return playing;
}

int LetraRepetida(tPlaying playing, char letra)
{
    int i = 0;

    for (i = 0; i < 26; i++)
    {
        if (playing.letrasEscolhidas[i] == '\0')
        {
            return 0;
        }

        else if (playing.letrasEscolhidas[i] == letra)
        {
            return 1;
        }
    }
}

tPlaying RegistraLetra(tPlaying playing, char letra)
{
    int i = 0;

    for (i = 0; i < 26; i++)
    {
        if (playing.letrasEscolhidas[i] == '\0')
        {
            playing.letrasEscolhidas[i] = letra;
            break;
        }
    }

    // Guardei a letra para registrar o acerto na funcao RegistraAcertoOuErro.
    playing.letra = letra;

    return playing;
}

tJogo RegistraAcertoOuErro(tJogo jogo, tPlaying playing)
{
    int i = 0;

    for (i = 0; i < 20; i++)
    {
        if (jogo.palavra[i] == playing.letra)
        {
            jogo.jogador[playing.quemInicia - 1].acertos++;

            // Para registrar apenas uma vez o acerto.
            return jogo;
        }
    }

    // Caso nao tenha a letra na palavra, ele perde ponto.
    jogo.jogador[playing.quemInicia - 1].pontos--;

    return jogo;
}

tPlaying RegistraLetraNaPalavraVisivel(tJogo jogo, tPlaying playing)
{
    int i = 0;

    for (i = 0; i < playing.tamanhoPalavra; i++)
    {
        if (jogo.palavra[i] == playing.letra)
        {
            playing.palavraVisivel[i] = playing.letra;
        }
    }

    return playing;
}

tPlaying PassaJogada(tJogo jogo, tPlaying playing)
{
    int cont = 0, i = 0;

    while (1)
    {
        if (playing.quemInicia == jogo.qtd_jogadores)
        {
            playing.quemInicia = 1;
        }

        else
        {
            playing.quemInicia += 1;
        }

        if (jogo.jogador[playing.quemInicia - 1].pontos > 0)
        {
            return playing;
        }

        for (i = 0; i < jogo.qtd_jogadores; i++)
        {
            if (jogo.jogador[i].pontos == 0)
            {
                cont++;
            }

            if (cont == jogo.qtd_jogadores)
            {
                return playing;
            }
        }

        cont = 0;
    }
}

// Da pra corrigir de duas formas, umas adicionando mais if's e outra com um if de restrição para pontos == 0.

void ResultadoJogo(tJogo jogo)
{
    int cont = 0, cont_2 = 0, cont_3 = 0, cont_4 = 0;

    system("clear");

    if (jogo.qtd_jogadores == 1)
    {
        if (jogo.jogador[cont].pontos == 0)
        {
            cont = 0;
            JogadorPerdeu(jogo, cont);
        }

        else
        {
            cont = 0;
            JogadorGanhou(jogo, cont);
        }
    }

    else if (jogo.qtd_jogadores == 2)
    {
        if (jogo.jogador[0].pontos > jogo.jogador[1].pontos)
        {
            cont = 0;
            JogadorGanhou(jogo, cont);
        }

        else if (jogo.jogador[1].pontos > jogo.jogador[0].pontos)
        {
            cont = 1;
            JogadorGanhou(jogo, cont);
        }

        else
        {
            if (jogo.jogador[0].acertos > jogo.jogador[1].acertos)
            {
                cont = 0;
                JogadorGanhou(jogo, cont);
            }

            else if (jogo.jogador[1].acertos > jogo.jogador[0].acertos)
            {
                cont = 1;
                JogadorGanhou(jogo, cont);
            }

            else
            {
                cont = 0;
                cont_2 = 1;
                DoisJogadoresEmpataram(jogo, cont, cont_2);
            }
        }
    }

    else if (jogo.qtd_jogadores == 3)
    {
        if (jogo.jogador[0].pontos > jogo.jogador[1].pontos && jogo.jogador[0].pontos > jogo.jogador[2].pontos)
        {
            cont = 0;
            JogadorGanhou(jogo, cont);
        }

        else if (jogo.jogador[1].pontos > jogo.jogador[0].pontos && jogo.jogador[1].pontos > jogo.jogador[2].pontos)
        {
            cont = 1;
            JogadorGanhou(jogo, cont);
        }

        else if (jogo.jogador[2].pontos > jogo.jogador[0].pontos && jogo.jogador[2].pontos > jogo.jogador[1].pontos)
        {
            cont = 2;
            JogadorGanhou(jogo, cont);
        }

        else if (jogo.jogador[0].pontos == jogo.jogador[1].pontos && jogo.jogador[0].pontos > jogo.jogador[2].pontos)
        {
            if (jogo.jogador[0].acertos > jogo.jogador[1].acertos)
            {
                cont = 0;
                JogadorGanhou(jogo, cont);
            }

            else if (jogo.jogador[1].acertos > jogo.jogador[0].acertos)
            {
                cont = 1;
                JogadorGanhou(jogo, cont);
            }

            else
            {
                cont = 0;
                cont_2 = 1;
                DoisJogadoresEmpataram(jogo, cont, cont_2);
            }
        }

        else if (jogo.jogador[0].pontos == jogo.jogador[2].pontos && jogo.jogador[0].pontos > jogo.jogador[1].pontos)
        {
            if (jogo.jogador[0].acertos > jogo.jogador[2].acertos)
            {
                cont = 0;
                JogadorGanhou(jogo, cont);
            }

            else if (jogo.jogador[2].acertos > jogo.jogador[0].acertos)
            {
                cont = 2;
                JogadorGanhou(jogo, cont);
            }

            else
            {
                cont = 0;
                cont_2 = 2;
                DoisJogadoresEmpataram(jogo, cont, cont_2);
            }
        }

        else if (jogo.jogador[1].pontos == jogo.jogador[2].pontos && jogo.jogador[1].pontos > jogo.jogador[0].pontos)
        {
            if (jogo.jogador[1].acertos > jogo.jogador[2].acertos)
            {
                cont = 1;
                JogadorGanhou(jogo, cont);
            }

            else if (jogo.jogador[2].acertos > jogo.jogador[1].acertos)
            {
                cont = 2;
                JogadorGanhou(jogo, cont);
            }

            else
            {
                cont = 1;
                cont_2 = 2;
                DoisJogadoresEmpataram(jogo, cont, cont_2);
            }
        }

        else
        {
            if (jogo.jogador[0].acertos > jogo.jogador[1].acertos && jogo.jogador[0].acertos > jogo.jogador[2].acertos)
            {
                cont = 0;
                JogadorGanhou(jogo, cont);
            }

            else if (jogo.jogador[1].acertos > jogo.jogador[0].acertos && jogo.jogador[1].acertos > jogo.jogador[2].acertos)
            {
                cont = 1;
                JogadorGanhou(jogo, cont);
            }

            else if (jogo.jogador[2].acertos > jogo.jogador[0].acertos && jogo.jogador[2].acertos > jogo.jogador[1].acertos)
            {
                cont = 2;
                JogadorGanhou(jogo, cont);
            }

            else if (jogo.jogador[0].acertos == jogo.jogador[1].acertos && jogo.jogador[0].acertos > jogo.jogador[2].acertos)
            {
                cont = 0;
                cont_2 = 1;
                DoisJogadoresEmpataram(jogo, cont, cont_2);
            }

            else if (jogo.jogador[0].acertos == jogo.jogador[2].acertos && jogo.jogador[0].acertos > jogo.jogador[1].acertos)
            {
                cont = 0;
                cont_2 = 2;
                DoisJogadoresEmpataram(jogo, cont, cont_2);
            }

            else if (jogo.jogador[1].acertos == jogo.jogador[2].acertos && jogo.jogador[1].acertos > jogo.jogador[0].acertos)
            {
                cont = 1;
                cont_2 = 2;
                DoisJogadoresEmpataram(jogo, cont, cont_2);
            }

            else
            {
                cont = 0;
                cont_2 = 1;
                cont_3 = 2;
                TresJogadoresEmpataram(jogo, cont, cont_2, cont_3);
            }
        }
    }

    else if (jogo.qtd_jogadores == 4)
    {
        if (jogo.jogador[0].pontos > jogo.jogador[1].pontos && jogo.jogador[0].pontos > jogo.jogador[2].pontos && jogo.jogador[0].pontos > jogo.jogador[3].pontos)
        {
            cont = 0;
            JogadorGanhou(jogo, cont);
        }

        else if (jogo.jogador[1].pontos > jogo.jogador[0].pontos && jogo.jogador[1].pontos > jogo.jogador[2].pontos && jogo.jogador[1].pontos > jogo.jogador[3].pontos)
        {
            cont = 1;
            JogadorGanhou(jogo, cont);
        }

        else if (jogo.jogador[2].pontos > jogo.jogador[0].pontos && jogo.jogador[2].pontos > jogo.jogador[1].pontos && jogo.jogador[2].pontos > jogo.jogador[3].pontos)
        {
            cont = 2;
            JogadorGanhou(jogo, cont);
        }

        else if (jogo.jogador[3].pontos > jogo.jogador[0].pontos && jogo.jogador[3].pontos > jogo.jogador[1].pontos && jogo.jogador[3].pontos > jogo.jogador[2].pontos)
        {
            cont = 3;
            JogadorGanhou(jogo, cont);
        }

        else if (jogo.jogador[0].pontos == jogo.jogador[1].pontos && jogo.jogador[0].pontos > jogo.jogador[2].pontos && jogo.jogador[0].pontos > jogo.jogador[3].pontos)
        {
            if (jogo.jogador[0].acertos > jogo.jogador[1].acertos)
            {
                cont = 0;
                JogadorGanhou(jogo, cont);
            }

            else if (jogo.jogador[1].acertos > jogo.jogador[0].acertos)
            {
                cont = 1;
                JogadorGanhou(jogo, cont);
            }

            else
            {
                cont = 0;
                cont_2 = 1;
                DoisJogadoresEmpataram(jogo, cont, cont_2);
            }
        }

        else if (jogo.jogador[0].pontos == jogo.jogador[2].pontos && jogo.jogador[0].pontos > jogo.jogador[1].pontos && jogo.jogador[0].pontos > jogo.jogador[3].pontos)
        {
            if (jogo.jogador[0].acertos > jogo.jogador[2].acertos)
            {
                cont = 0;
                JogadorGanhou(jogo, cont);
            }

            else if (jogo.jogador[2].acertos > jogo.jogador[0].acertos)
            {
                cont = 2;
                JogadorGanhou(jogo, cont);
            }

            else
            {
                cont = 0;
                cont_2 = 2;
                DoisJogadoresEmpataram(jogo, cont, cont_2);
            }
        }

        else if (jogo.jogador[0].pontos == jogo.jogador[3].pontos && jogo.jogador[0].pontos > jogo.jogador[1].pontos && jogo.jogador[0].pontos > jogo.jogador[2].pontos)
        {
            if (jogo.jogador[0].acertos > jogo.jogador[3].acertos)
            {
                cont = 0;
                JogadorGanhou(jogo, cont);
            }

            else if (jogo.jogador[3].acertos > jogo.jogador[0].acertos)
            {
                cont = 3;
                JogadorGanhou(jogo, cont);
            }

            else
            {
                cont = 0;
                cont_2 = 3;
                DoisJogadoresEmpataram(jogo, cont, cont_2);
            }
        }

        else if (jogo.jogador[1].pontos == jogo.jogador[2].pontos && jogo.jogador[1].pontos > jogo.jogador[0].pontos && jogo.jogador[1].pontos > jogo.jogador[3].pontos)
        {
            if (jogo.jogador[1].acertos > jogo.jogador[2].acertos)
            {
                cont = 1;
                JogadorGanhou(jogo, cont);
            }

            else if (jogo.jogador[2].acertos > jogo.jogador[1].acertos)
            {
                cont = 2;
                JogadorGanhou(jogo, cont);
            }

            else
            {
                cont = 1;
                cont_2 = 2;
                DoisJogadoresEmpataram(jogo, cont, cont_2);
            }
        }

        else if (jogo.jogador[1].pontos == jogo.jogador[3].pontos && jogo.jogador[1].pontos > jogo.jogador[0].pontos && jogo.jogador[1].pontos > jogo.jogador[2].pontos)
        {
            if (jogo.jogador[1].acertos > jogo.jogador[3].acertos)
            {
                cont = 1;
                JogadorGanhou(jogo, cont);
            }

            else if (jogo.jogador[3].acertos > jogo.jogador[1].acertos)
            {
                cont = 3;
                JogadorGanhou(jogo, cont);
            }

            else
            {
                cont = 1;
                cont_2 = 3;
                DoisJogadoresEmpataram(jogo, cont, cont_2);
            }
        }

        else if (jogo.jogador[2].pontos == jogo.jogador[3].pontos && jogo.jogador[2].pontos > jogo.jogador[0].pontos && jogo.jogador[2].pontos > jogo.jogador[1].pontos)
        {
            if (jogo.jogador[2].acertos > jogo.jogador[3].acertos)
            {
                cont = 2;
                JogadorGanhou(jogo, cont);
            }

            else if (jogo.jogador[3].acertos > jogo.jogador[2].acertos)
            {
                cont = 3;
                JogadorGanhou(jogo, cont);
            }

            else
            {
                cont = 2;
                cont_2 = 3;
                DoisJogadoresEmpataram(jogo, cont, cont_2);
            }
        }

        else if (jogo.jogador[0].pontos == jogo.jogador[1].pontos && jogo.jogador[0].pontos == jogo.jogador[2].pontos && jogo.jogador[0].pontos > jogo.jogador[3].pontos)
        {

            if (jogo.jogador[0].acertos > jogo.jogador[1].acertos && jogo.jogador[0].acertos > jogo.jogador[2].acertos)
            {
                cont = 0;
                JogadorGanhou(jogo, cont);
            }

            else if (jogo.jogador[1].acertos > jogo.jogador[0].acertos && jogo.jogador[1].acertos > jogo.jogador[2].acertos)
            {
                cont = 1;
                JogadorGanhou(jogo, cont);
            }

            else if (jogo.jogador[2].acertos > jogo.jogador[0].acertos && jogo.jogador[2].acertos > jogo.jogador[1].acertos)
            {
                cont = 2;
                JogadorGanhou(jogo, cont);
            }

            else if (jogo.jogador[0].acertos == jogo.jogador[1].acertos && jogo.jogador[0].acertos > jogo.jogador[2].acertos)
            {
                cont = 1;
                cont_2 = 2;
                DoisJogadoresEmpataram(jogo, cont, cont_2);
            }

            else if (jogo.jogador[0].acertos == jogo.jogador[2].acertos && jogo.jogador[0].acertos > jogo.jogador[1].acertos)
            {
                cont = 0;
                cont_2 = 2;
                DoisJogadoresEmpataram(jogo, cont, cont_2);
            }

            else if (jogo.jogador[1].acertos == jogo.jogador[2].acertos && jogo.jogador[1].acertos > jogo.jogador[0].acertos)
            {
                cont = 1;
                cont_2 = 2;
                DoisJogadoresEmpataram(jogo, cont, cont_2);
            }

            else
            {
                cont = 0;
                cont_2 = 1;
                cont_3 = 2;
                TresJogadoresEmpataram(jogo, cont, cont_2, cont_3);
            }
        }

        else if (jogo.jogador[0].pontos == jogo.jogador[1].pontos && jogo.jogador[0].pontos == jogo.jogador[3].pontos && jogo.jogador[0].pontos > jogo.jogador[2].pontos)
        {
            if (jogo.jogador[0].acertos > jogo.jogador[1].acertos && jogo.jogador[0].acertos > jogo.jogador[3].acertos)
            {
                cont = 0;
                JogadorGanhou(jogo, cont);
            }

            else if (jogo.jogador[1].acertos > jogo.jogador[0].acertos && jogo.jogador[1].acertos > jogo.jogador[3].acertos)
            {
                cont = 1;
                JogadorGanhou(jogo, cont);
            }

            else if (jogo.jogador[3].acertos > jogo.jogador[0].acertos && jogo.jogador[3].acertos > jogo.jogador[1].acertos)
            {
                cont = 3;
                JogadorGanhou(jogo, cont);
            }

            else if (jogo.jogador[0].acertos == jogo.jogador[1].acertos && jogo.jogador[0].acertos > jogo.jogador[3].acertos)
            {
                cont = 0;
                cont_2 = 1;
                DoisJogadoresEmpataram(jogo, cont, cont_2);
            }

            else if (jogo.jogador[0].acertos == jogo.jogador[3].acertos && jogo.jogador[0].acertos > jogo.jogador[1].acertos)
            {
                cont = 0;
                cont_2 = 3;
                DoisJogadoresEmpataram(jogo, cont, cont_2);
            }

            else if (jogo.jogador[1].acertos == jogo.jogador[3].acertos && jogo.jogador[1].acertos > jogo.jogador[0].acertos)
            {
                cont = 1;
                cont_2 = 3;
                DoisJogadoresEmpataram(jogo, cont, cont_2);
            }

            else
            {
                cont = 0;
                cont_2 = 1;
                cont_3 = 3;
                TresJogadoresEmpataram(jogo, cont, cont_2, cont_3);
            }
        }

        else if (jogo.jogador[0].pontos == jogo.jogador[2].pontos && jogo.jogador[0].pontos == jogo.jogador[3].pontos && jogo.jogador[0].pontos > jogo.jogador[1].pontos)
        {
            if (jogo.jogador[0].acertos > jogo.jogador[2].acertos && jogo.jogador[0].acertos > jogo.jogador[3].acertos)
            {
                cont = 0;
                JogadorGanhou(jogo, cont);
            }

            else if (jogo.jogador[2].acertos > jogo.jogador[0].acertos && jogo.jogador[2].acertos > jogo.jogador[3].acertos)
            {
                cont = 2;
                JogadorGanhou(jogo, cont);
            }

            else if (jogo.jogador[3].acertos > jogo.jogador[0].acertos && jogo.jogador[3].acertos > jogo.jogador[2].acertos)
            {
                cont = 3;
                JogadorGanhou(jogo, cont);
            }

            else if (jogo.jogador[0].acertos == jogo.jogador[2].acertos && jogo.jogador[0].acertos > jogo.jogador[3].acertos)
            {
                cont = 0;
                cont_2 = 2;
                DoisJogadoresEmpataram(jogo, cont, cont_2);
            }

            else if (jogo.jogador[0].acertos == jogo.jogador[3].acertos && jogo.jogador[0].acertos > jogo.jogador[2].acertos)
            {
                cont = 0;
                cont_2 = 3;
                DoisJogadoresEmpataram(jogo, cont, cont_2);
            }

            else if (jogo.jogador[2].acertos == jogo.jogador[3].acertos && jogo.jogador[2].acertos > jogo.jogador[0].acertos)
            {
                cont = 2;
                cont_2 = 3;
                DoisJogadoresEmpataram(jogo, cont, cont_2);
            }

            else
            {
                cont = 0;
                cont_2 = 2;
                cont_3 = 3;
                TresJogadoresEmpataram(jogo, cont, cont_2, cont_3);
            }
        }

        else if (jogo.jogador[1].pontos == jogo.jogador[2].pontos && jogo.jogador[1].pontos == jogo.jogador[3].pontos && jogo.jogador[1].pontos > jogo.jogador[0].pontos)
        {
            if (jogo.jogador[1].acertos > jogo.jogador[2].acertos && jogo.jogador[1].acertos > jogo.jogador[3].acertos)
            {
                cont = 1;
                JogadorGanhou(jogo, cont);
            }

            else if (jogo.jogador[2].acertos > jogo.jogador[1].acertos && jogo.jogador[2].acertos > jogo.jogador[3].acertos)
            {
                cont = 2;
                JogadorGanhou(jogo, cont);
            }

            else if (jogo.jogador[3].acertos > jogo.jogador[1].acertos && jogo.jogador[3].acertos > jogo.jogador[2].acertos)
            {
                cont = 3;
                JogadorGanhou(jogo, cont);
            }

            else if (jogo.jogador[1].acertos == jogo.jogador[2].acertos && jogo.jogador[1].acertos > jogo.jogador[3].acertos)
            {
                cont = 1;
                cont_2 = 2;
                DoisJogadoresEmpataram(jogo, cont, cont_2);
            }

            else if (jogo.jogador[1].acertos == jogo.jogador[3].acertos && jogo.jogador[1].acertos > jogo.jogador[2].acertos)
            {
                cont = 1;
                cont_2 = 3;
                DoisJogadoresEmpataram(jogo, cont, cont_2);
            }

            else if (jogo.jogador[2].acertos == jogo.jogador[3].acertos && jogo.jogador[2].acertos > jogo.jogador[1].acertos)
            {
                cont = 2;
                cont_2 = 3;
                DoisJogadoresEmpataram(jogo, cont, cont_2);
            }

            else
            {
                cont = 2;
                cont_2 = 3;
                cont_3 = 4;
                TresJogadoresEmpataram(jogo, cont, cont_2, cont_3);
            }
        }

        else
        {
            if (jogo.jogador[0].acertos > jogo.jogador[1].acertos && jogo.jogador[0].acertos > jogo.jogador[2].acertos && jogo.jogador[0].acertos > jogo.jogador[3].acertos)
            {
                cont = 0;
                JogadorGanhou(jogo, cont);
            }

            else if (jogo.jogador[1].acertos > jogo.jogador[0].acertos && jogo.jogador[1].acertos > jogo.jogador[2].acertos && jogo.jogador[1].acertos > jogo.jogador[3].acertos)
            {
                cont = 1;
                JogadorGanhou(jogo, cont);
            }

            else if (jogo.jogador[2].acertos > jogo.jogador[0].acertos && jogo.jogador[2].acertos > jogo.jogador[1].acertos && jogo.jogador[2].acertos > jogo.jogador[3].acertos)
            {
                cont = 2;
                JogadorGanhou(jogo, cont);
            }

            else if (jogo.jogador[3].acertos > jogo.jogador[0].acertos && jogo.jogador[3].acertos > jogo.jogador[1].acertos && jogo.jogador[3].acertos > jogo.jogador[2].acertos)
            {
                cont = 3;
                JogadorGanhou(jogo, cont);
            }

            else if (jogo.jogador[0].acertos == jogo.jogador[1].acertos && jogo.jogador[0].acertos > jogo.jogador[2].acertos && jogo.jogador[0].acertos > jogo.jogador[3].acertos)
            {
                cont = 0;
                cont_2 = 1;
                DoisJogadoresEmpataram(jogo, cont, cont_2);
            }

            else if (jogo.jogador[0].acertos == jogo.jogador[2].acertos && jogo.jogador[0].acertos > jogo.jogador[1].acertos && jogo.jogador[0].acertos > jogo.jogador[3].acertos)
            {
                cont = 0;
                cont_2 = 2;
                DoisJogadoresEmpataram(jogo, cont, cont_2);
            }

            else if (jogo.jogador[0].acertos == jogo.jogador[3].acertos && jogo.jogador[0].acertos > jogo.jogador[1].acertos && jogo.jogador[0].acertos > jogo.jogador[2].acertos)
            {
                cont = 0;
                cont_2 = 3;
                DoisJogadoresEmpataram(jogo, cont, cont_2);
            }

            else if (jogo.jogador[1].acertos == jogo.jogador[2].acertos && jogo.jogador[1].acertos > jogo.jogador[0].acertos && jogo.jogador[1].acertos > jogo.jogador[3].acertos)
            {
                cont = 1;
                cont_2 = 2;
                DoisJogadoresEmpataram(jogo, cont, cont_2);
            }

            else if (jogo.jogador[1].acertos == jogo.jogador[3].acertos && jogo.jogador[1].acertos > jogo.jogador[0].acertos && jogo.jogador[1].acertos > jogo.jogador[2].acertos)
            {
                cont = 1;
                cont_2 = 3;
                DoisJogadoresEmpataram(jogo, cont, cont_2);
            }

            else if (jogo.jogador[2].acertos == jogo.jogador[3].acertos && jogo.jogador[2].acertos > jogo.jogador[0].acertos && jogo.jogador[2].acertos > jogo.jogador[1].acertos)
            {
                cont = 2;
                cont_2 = 3;
                DoisJogadoresEmpataram(jogo, cont, cont_2);
            }

            else if (jogo.jogador[0].acertos == jogo.jogador[1].acertos && jogo.jogador[0].acertos == jogo.jogador[2].acertos && jogo.jogador[0].acertos > jogo.jogador[3].acertos)
            {
                cont = 0;
                cont_2 = 1;
                cont_3 = 2;
                TresJogadoresEmpataram(jogo, cont, cont_2, cont_3);
            }

            else if (jogo.jogador[0].acertos == jogo.jogador[1].acertos && jogo.jogador[0].acertos == jogo.jogador[3].acertos && jogo.jogador[0].acertos > jogo.jogador[2].acertos)
            {
                cont = 0;
                cont_2 = 1;
                cont_3 = 3;
                TresJogadoresEmpataram(jogo, cont, cont_2, cont_3);
            }

            else if (jogo.jogador[0].acertos == jogo.jogador[2].acertos && jogo.jogador[0].acertos == jogo.jogador[3].acertos && jogo.jogador[0].acertos > jogo.jogador[1].acertos)
            {
                cont = 0;
                cont_2 = 2;
                cont_3 = 3;
                TresJogadoresEmpataram(jogo, cont, cont_2, cont_3);
            }

            else if (jogo.jogador[1].acertos == jogo.jogador[2].acertos && jogo.jogador[1].acertos == jogo.jogador[3].acertos && jogo.jogador[1].acertos > jogo.jogador[0].acertos)
            {
                cont = 1;
                cont_2 = 2;
                cont_3 = 3;
                TresJogadoresEmpataram(jogo, cont, cont_2, cont_3);
            }

            else
            {
                cont = 0;
                cont_2 = 1;
                cont_3 = 2;
                cont_4 = 3;
                QuatroJogadoresEmpataram(jogo, cont, cont_2, cont_3, cont_4);
            }
        }
    }
}

void JogadorPerdeu(tJogo jogo, int cont)
{
    printf("O ");

    ImprimeNomeJogadoresVencedor(jogo, cont);

    printf(" perdeu!\n");
}

void JogadorGanhou(tJogo jogo, int cont)
{
    printf("O jogador %d ganhou! ", (cont + 1));

    ImprimeNomeJogadoresVencedor(jogo, cont);

    printf(" se salvou da forca!\n");
}

void DoisJogadoresEmpataram(tJogo jogo, int cont, int cont_2)
{
    printf("O jogador %d e %d empataram! ", (cont + 1), (cont_2 + 1));

    ImprimeNomeJogadoresVencedor(jogo, cont);

    printf(" e ");

    cont = cont_2;

    ImprimeNomeJogadoresVencedor(jogo, cont);

    printf(" se salvaram da forca!\n");
}

void TresJogadoresEmpataram(tJogo jogo, int cont, int cont_2, int cont_3)
{

    printf("O jogador %d, %d e %d empataram! ", (cont + 1), (cont_2 + 1), (cont_3 + 1));

    ImprimeNomeJogadoresVencedor(jogo, cont);

    printf(", ");

    cont = cont_2;

    ImprimeNomeJogadoresVencedor(jogo, cont);

    printf(" e ");

    cont = cont_3;

    ImprimeNomeJogadoresVencedor(jogo, cont);

    printf(" se salvaram da forca!\n");
}

void QuatroJogadoresEmpataram(tJogo jogo, int cont, int cont_2, int cont_3, int cont_4)
{

    printf("O jogador %d, %d, %d e %d empataram! ", (cont + 1), (cont_2 + 1), (cont_3 + 1), (cont_4 + 1));

    ImprimeNomeJogadoresVencedor(jogo, cont);

    printf(", ");

    cont = cont_2;

    ImprimeNomeJogadoresVencedor(jogo, cont);

    printf(", ");

    cont = cont_3;

    ImprimeNomeJogadoresVencedor(jogo, cont);

    printf(" e ");

    cont = cont_4;

    ImprimeNomeJogadoresVencedor(jogo, cont);

    printf(" se salvaram da forca!\n");
}

void ImprimeNomeJogadoresVencedor(tJogo jogo, int cont)
{
    int i = cont, j;

    for (j = 0; j < 20; j++)
    {
        if (jogo.jogador[i].nome[j] == '\0')
        {
            break;
        }

        else
        {
            printf("%c", jogo.jogador[i].nome[j]);
        }
    }
}

int JogarNovamente()
{
    int escolha = -1;
    char lixo;

    while (1)
    {
        printf("\nJogar novamente?\n");
        printf("1- Sim\n");
        printf("2- Nao\n\n");

        scanf("%d%c", &escolha, &lixo);

        if (escolha == 1 || escolha == 2)
        {
            break;
        }

        else
        {
            printf("Resposta invalida, tente de novo:\n\n");
        }
    }

    system("clear");

    return escolha;
}

tJogo RestauraParaJogarNovamente(tJogo jogo)
{
    int i = 0, j = 0;

    for (i = 0; i < 4; i++)
    {
        jogo.jogador[i].pontos = 6;
        jogo.jogador[i].acertos = 0;

        for (j = 0; j < 20; j++)
        {
            jogo.palavra[j] = '\0';
            jogo.dica[j] = '\0';
        }
    }
    return jogo;
}
