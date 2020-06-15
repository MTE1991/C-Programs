#include <stdio.h>

int main(void)
{
    // Declaring a char type array:
    char myname[6] = "Ekleel";

    // int and float types:
    int marks[3] = {76,98,47};
    // printing...
    printf("%s\n",myname);
    
    for(int i=0;i<3;i++)
        printf("%d\n",marks[i]);
}