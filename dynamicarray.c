#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, n, *arr, s = 0;  // *arr points to int
    scanf("%d",&n);
    
    // allocating 4n bytes of memory with malloc()
    arr = (int*)malloc(n*sizeof(int));
    
    for (i=0; i<n; i++)
    scanf("%d", arr + i);
    
    for (i=0; i<n; i++)
    s += *(arr + i); // s is incremented by the i th element of the array
    
    printf("%d\n",s);
    free(arr); // free the memory
    
    return 0;
}

