#include <stdio.h>

int main(void)
{
    int horas, a = 0, l = 0;
    int cont_terra_visivel_atual = 0, cont_terra_visivel_pos = 0;
    int i = 0;

    scanf("%d", &horas);

    int w, h;

    scanf("%d %d", &w, &h);

    char matriz[h][w], matrizNova[h][w], c;

    for (a = 0; a < h; a++)
    {
        for (l = 0; l < w + 1; l++)
        {
            scanf("%c", &c);

            if (c != '\n')
            {
                matriz[a][l] = c;

                if (matriz[a][l] == '0')
                {
                    cont_terra_visivel_atual++;
                }
            }
        }
    }

    for (i = 0; i < horas; i++)
    {
        cont_terra_visivel_pos = 0;
        for (a = 0; a < h; a++)
        {
            for (l = 0; l < w + 1; l++)
            {
                if (matriz[a][l] == '1' || matriz[a][l - 1] == '1' || matriz[a][l + 1] == '1' || matriz[a + 1][l] == '1' || matriz[a - 1][l] == '1')
                {
                    matrizNova[a][l] = '1';
                }
                else
                {
                    matrizNova[a][l] = '0';
                    cont_terra_visivel_pos++;
                }
            }
        }
        for (a = 0; a < h; a++)
        {
            for (l = 0; l < w + 1; l++)
            {
                matriz[a][l] = matrizNova[a][l];
            }
        }
    }
    printf("%d %d\n", cont_terra_visivel_atual, cont_terra_visivel_pos);
    return 0;
}