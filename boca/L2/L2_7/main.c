#include <stdio.h>

int main()
{
    int num = 0;

    scanf("%d", &num);

    if (((num % 2 != 0) && (num % 3 != 0) && (num % 5 != 0)) || (num == 2) || (num == 3) || (num == 5))
    {
        printf("Primo");
    }
    
    else
    {
        printf("Nao primo");
    }

    return 0;
}