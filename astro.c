#include <stdio.h>
#include <math.h>
#include <string.h>

#define M_SUN 1.98847e30 // Solar mass (kg)
#define R_SUN 696340000 // radius of sun (m)
#define V_SUN 1.412e27 // Volume of sun (m^3)
#define PI 3.141592654
#define G 6.673e-11 // Nm^2 kg^-2
#define C 3e8 // m/s
#define AU 1.496e11 // m
#define LY 9.46e15 // m
#define PARSEC 3.26 // ly
#define gravity(m, r) ((G * m) / (r * r)) // gravity of any object in macro definition
#define v_escape(m, r) (sqrt(2*G*m / r))  // escape velocity
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

/* distance from sun in au: */
float dist_au[9] = {0.39, 0.723, 1, 1.524, 5.203, 9.539, 19.18, 30.06, 39.53};
/* radii of planets (km): */ 
float radii[9] = {2439.7, 6051.8, 6371, 3389.5, 69911, 58232, 25362, 24622, 1188.3};
/* planetary masses (kg): */
double mass[9] = {3.285e23, 4.867e24, 5.9722e24, 6.39e23, 1.898e27, 5.683e26, 8.681e25, 1.024e26, 1.309e22};

void sun_info(void);
void solarsys(void);
double conv_to_m(char unit[], double val); // Convert to metre
double r_s(double m, double r); // Schwarzchild radius
double d_s(double m); // Schwarzchild density

int main()
{
    int ch, ch2;
    double val;
    char unit1[] = "AU", unit2[] = "PARSEC", unit3[] = "LY";
    
    printf("Note: use SI units when inputting unit values other than AU, LY and PARSEC.\n\n");
    printf("1. Solar System info\n");
    printf("2. Astro-distance converter\n");
    printf("3. Schwarzchild radius and density of any object\n");
    printf("4. Gravity of any object\n");
    printf("5. Density of any object\n");
    printf("6. Info about sun\n\n");
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
    else if (ch == 5) {
        double m, v;
        printf("Enter mass and volume: ");
        scanf("%lf %lf", &m, &v);
        printf("Density = %.3e kg/m^3", density(m, v));
    }
    else if (ch == 6) sun_info();
    
	return 0;
}

void solarsys(void) {
    printf("Planet\t\tDistance from sun (AU)\t\tDistance from sun (m)\n");
    int i = 0;  
    for (i = 0; i <= 8; ++i) printf("%s\t\t%.3f\t\t\t\t%.3e\n", planets + i, dist_au[i], dist_au[i] * AU);
    printf("\n");
    printf("Planet\t\tMass (kg)\t\tRadius (km)\n");
    for (i = 0; i <= 8; ++i) printf("%s\t\t%.3e\t\t%.3f\n", planets + i, mass[i], radii[i]);
    printf("\n");
}

double conv_to_m(char unit[], double val) {
    if (strcmp(unit, "AU") == 0) return val * AU;
    else if (strcmp(unit, "PARSEC") == 0) return val * PARSEC * LY;
    else return val * LY;
}

double r_s(double m, double r) {
    return (2 * G * m) / pow(C, 2);
}

double d_s(double m) {
    return (3 * pow(C, 6)) / (32 * PI * pow(G, 3) * pow(m, 2));
}

void sun_info(void) {
    printf("Mass = %.3e kg\n", M_SUN);
    printf("Volume = %.3e m^3\n", V_SUN);
    printf("Density = %d kg/m^3\n", density(M_SUN, R_SUN));
    printf("Schwarzchild density = %.3e kg/m^3\n", d_s(M_SUN));
    printf("Radius = %.3e m\n", R_SUN);
    printf("Schwarzchild radius = %d m\n", r_s(M_SUN, R_SUN));
    printf("Escape velocity = %f m/s\n\n", v_escape(M_SUN, R_SUN));
}
