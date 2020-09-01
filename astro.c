#include <stdio.h>
#include <string.h>

#define C 3e8 // m/s
#define AU 1.496e11 // m
#define LY 9.46e15 // m
#define PARSEC 3.26 // ly

char planets[9][20] = {
		"Mercury",
		"Venus",
		"Earth",
		"Mars",
		"Jupiter",
		"Saturn",
		"Uranus",
		"Neptune",
		"Pluto"
	};

void solarsys(void);
double conv_to_m(char unit[], double val);

int main(void)
{
	int ch, ch2; 
	double val;
	char unit1[] = "AU", unit2[] = "PARSEC", unit3[] = "LY";

	printf("1. Planets distance from sun\n");
	printf("2. Astro-distance converter\n");
	printf("Your choice? > ");
	scanf("%d", &ch);

	if (ch == 1) solarsys();

	else if (ch == 2) {
		printf("Choose unit to convert to metre:\n");
		printf("1. AU\n2. PARSEC\n3.LY (light years)\nYour choice? > ");
		scanf("%d", &ch2);

		if (ch2 == 1) {
			printf("Enter a value in AU = ");
			scanf("%lf", &val);
			printf("%.3lf AU = %.3e m\n", val, conv_to_m(unit1, val));
		}

		else if (ch2 == 2) {
			printf("Enter a value in PARSEC = ");
			scanf("%lf", &val);
			printf("%.3lf PARSEC = %.3e m\n", val, conv_to_m(unit2, val));
		}

		else {
			printf("Enter a value in LY = ");
			scanf("%lf", &val);
			printf("%.3lf LY = %.3e m\n", val, conv_to_m(unit3, val));
		}
	}
	
	return 0;
}

void solarsys(void)
{
	/* distance from sun in au: */
	float dist_au[9] = {0.39, 0.723, 1, 1.524, 5.203, 9.539, 19.18, 30.06, 39.53}; 

	printf("Planet\t\tDistance from sun (AU)\n");
	
	int i = 0;
	
	for (i = 0; i < 9; ++i)
	{
		printf("%s\t\t%.3f \n", planets + i, dist_au[i]);
	}
}

double conv_to_m(char unit[], double val)
{
	if (strcmp(unit, "AU") == 0) return val * AU;
	else if (strcmp(unit, "PARSEC") == 0) return val * PARSEC * LY;
	else return val * LY;
}
