#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main()
{
    char letra;

    scanf("%c", &letra);

    if (letra >= 'a' && letra <= 'z')
    {
        letra -= 32;
        printf("%c(%d)", letra, letra);
    }

    else if (letra >= 'A' && letra <= 'Z')
    {
        printf("A letra deve ser minuscula!");
    }

    else
    {
        printf("Nao e letra!");
    }

    return 0;
}