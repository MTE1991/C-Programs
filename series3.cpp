#include <stdio.h>

int main(void)
{
	int i = 0, d;
	
	printf("Enter the value of d = ");
	scanf("%d", &d);
	
	printf("The arithmetic series: ");
	
	while (i<=d){
		i += 2;
		printf("%d ", i);
	}
	
	return 0;
}
