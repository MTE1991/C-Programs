// Aritmetic series

#include <stdio.h>

int main()
{
    int d = 2; // d is the common difference

    printf("The arithmetic series: ");
    
    for (int i=2; i<=d; i+=2)
        printf("%d ", i);

    return 0;
}

