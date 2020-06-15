#include <stdio.h>

main()
{
	int i, j;

	for (int i = 1; i <= 5; ++i)
	{
		for (int j = 1; j <= i; ++j)
		{
			printf("%d", j);
		}
	printf("\n");
	}
}

/* inner for loop is for increment.
outer for loop is for printing a new line 
and executing the inner for loop for 5 times */
