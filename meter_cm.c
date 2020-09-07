#include <stdio.h>

typedef struct distance
{
	int meter;
	float cm;
} distances;

int main()
{
	distances d1;

	printf("Enter the value of meter: ");
	scanf("%d", &d1.meter);
	printf("Now enter the remaining value of centimeter: ");
	scanf("%f", &d1.cm);
	
	/* increment meter by 1 if cm is greater than 100: */
	while (d1.cm >= 100)
	{
		d1.cm = d1.cm - 100;
		d1.meter += 1;
	}

	printf("The distance is %d meter %.2f centimeter\n", d1.meter, d1.cm);

	return 0;
}
