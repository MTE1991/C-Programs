#include <stdio.h>

int main(void)
{
    int x=0;

    do{
        x = x+1;
        printf("%d\n",x);
    }while (x<10);
}