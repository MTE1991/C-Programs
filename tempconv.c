#include <stdio.h>

int main(void)
{
	int centigrade[11] = {0, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

	printf("Celsius\tKelvin\n");

	for (int i = 0; i <= 10; i++)
	printf("%d \t %d\n", centigrade[i], centigrade[i] + 273);
	printf("\n");

	printf("Celsius\tFahrenheight\n");

	for (int i = 0; i <= 10; i++)
	printf("%d \t %.0f\n", centigrade[i], (1.8 * centigrade[i] + 32));
	printf("\n");

	return 0;
}

