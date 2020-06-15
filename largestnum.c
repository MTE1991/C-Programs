#include <stdio.h>

main(void)
{
    float a,b,c; 
    
    /* float numbers assigned as variables
    to make the program more flexible */

    printf("a =");
    scanf("%f",&a);
    printf("b =");
    scanf("%f",&b);
    printf("c =");
    scanf("%f",&c);

    // conditional blocks:
    if (a>b && a>c) printf("a is the largest number.\n");
    else if (b>a && b>c) printf("b is the largest number.\n");
    else if (c>a && c>b) printf("c is the largest number.\n");
}
