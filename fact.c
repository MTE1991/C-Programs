#include <stdio.h>

int main()
{
    int n;
    long int fact = 1;
    
    printf("Enter any integer number: ");
    scanf("%d",&n);
    
    for (int i=1; i<=n; ++i){
        fact *= i;
    }
    
    printf("Factorial of %d is %ld",n,fact);
    
    return 0;
}
