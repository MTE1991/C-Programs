#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, n;
    scanf("%d",&n);
    
    int arr[n];
    
    for (i=0; i<n; i++)
    scanf("%d",&arr[i]);
    
    for (i=n; i>0; i--)
    printf("%d ",arr[i-1]);

    return 0;
}
