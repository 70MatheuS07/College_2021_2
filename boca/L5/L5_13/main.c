#include <stdio.h>
#include <stdlib.h>

int ComparaString(char *str1, char *str2);

int main()
{
    char str1[1000];
    char str2[1000];

    while (scanf("%s", &*str1) == 1 && scanf("%s", &*str2) == 1)
    {
        if (ComparaString(str1, str2))
        {
            printf("IGUAL\n");
        }
        else
        {
            printf("DIFERENTE\n");
        }
    }

    return 0;
}

int ComparaString(char *str1, char *str2)
{
    int i = 0;
    int cont = 0;
    int cont_str1 = 0;
    int cont_str2 = 0;

    while (str1[i] != '\0')
    {
        i++;
        cont_str1++;
    }

    i = 0;

    while (str2[i] != '\0')
    {
        i++;
        cont_str2++;
    }

    if (cont_str1 > cont_str2)
    {
        cont = 0;
        return cont;
    }

    else if (cont_str1 < cont_str2)
    {
        cont = 0;
        return cont;
    }

    else
    {
        for (i = 0; str1[i] != '\0'; i++)
        {
            if (str1[i] != str2[i])
            {
                cont = 0;
                return cont;
            }
            else
            {
                continue;
            }
        }
    }

    return 1;
}