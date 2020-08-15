// Aritmetic finite series

#include <stdio.h>

int main()
{
    int i = 2, d = 2; // d is the common difference
    
    printf("The arithmetic series: ")
    do {
        printf("%d ",i);
        i+=2;
    } while (i<=d);

    return 0;
}
