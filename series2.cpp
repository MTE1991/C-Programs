// Aritmatic series

#include <stdio.h>

int main()
{
    int d; // d is the common difference
    
    printf("Enter the value of d = ");
    scanf("%d", &d);
    
    printf("The arithmetic series: ");
    
    for (int i=2; i<=d; i+=2)
        printf("%d ", i);

    return 0;
}

