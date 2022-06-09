#include <stdlib.h>
#include <stdio.h>

int main()
{
    char letra;

    scanf("%c", &letra);

    if (letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u')
    {
        printf("Eh vogal\n");
    }

    else if (letra == 'A' || letra == 'E' || letra == 'I' || letra == 'O' || letra == 'U')
    {
        printf("Eh vogal\n");
    }

    else if (letra >= '1' && letra <= '9')
    {
        printf("Nao eh uma letra\n");
    }

    else
    {
        printf("Nao eh vogal\n");
    }

    return 0;
}