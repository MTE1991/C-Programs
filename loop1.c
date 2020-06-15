#include <stdio.h>

// program of a series that starts from 1 and ends in N:
int main(void)
{
    int i,n;
    printf("N =");
    scanf("%d",&n);

    for (i=1;i<n+1;i++)
        printf("%d\n",i);
}
