#include <stdio.h>
#include <math.h>
#include <string.h>

#define PI 3.141592654
#define G 6.673e-11 // Nm^2 kg^-2
#define C 3e8 // m/s
#define AU 1.496e11 // m
#define LY 9.46e15 // m
#define PARSEC 3.26 // ly
#define gravity(m, r) ((G * m) / (r * r)) // gravity of any object in macro definition
#define density(m, v) (m / v) // density in kgm^-3

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
double conv_to_m(char unit[], double val); // Convert to metre
double r_s(double m, double r); // Schwarzchild radius
double d_s(double m); // Schwarzchild density

int main(void)
{
	int ch, ch2; 
	double val;
	char unit1[] = "AU", unit2[] = "PARSEC", unit3[] = "LY";
	printf("Note: use SI units when inputting unit values other than AU, LY and PARSEC.\n\n");
	printf("1. Planets distance from sun\n");
	printf("2. Astro-distance converter\n");
	printf("3. Schwarzchild radius and density of any object\n");
	printf("4. Gravity of any object\n");
	printf("5. Density of any object\n");
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
	else if (ch == 3) {
		double m, r;
		printf("Enter the mass and radius: ");
		scanf("%lf %lf", &m, &r);
		printf("Schwarzchild radius = %.3lf m\n", r_s(m, r));
		printf("Schwarzchild density = %.3lf kg/m^3\n", d_s(m));
	}
	else if (ch == 4) {
		double m, r;
		printf("Enter mass and radius: ");
		scanf("%lf %lf", &m, &r);
		printf("g = %.3lf m/s^2\n", gravity(m, r));
	}
	else if (ch==5) {
		double m, v;
		printf("Enter mass and volume: ");
		scanf("%lf %lf", &m, &v);
		printf("Density = %.3e kg/m^3", density(m, v));
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

double r_s(double m, double r)
{
	return (2 * G * m) / pow(C, 2);
}

double d_s(double m)
{
	return (3 * pow(C, 6)) / (32 * PI * pow(G, 3) * pow(m, 2));
}
