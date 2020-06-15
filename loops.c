#include <stdio.h>

main()
{
	int n, counter=1;
	printf("Enter N: ");
	scanf("%d",&n);

	do {
		printf("%d\n",counter);
	} while (++counter<=n);
	
	return 0;
}