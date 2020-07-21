/* surface area & volume of a sphere */

#include <stdio.h>
#include <string.h>
#include <math.h>

#define PI 3.141592654

float area(float r);
float volume(float v);

void main()
{
    char choice [10];
    float r, a, v;
    
    printf("Enter the radius = ");
    scanf("%f", &r);
    
    printf("Area or Volume? > ");
    scanf("%s", choice);
    
    a = area(r);
    v = volume(r);
    
    if (strcmp(choice, "Area") == 0) printf("Area = %.3f\n", a);
    
    else if (strcmp(choice, "Volume") == 0) printf("Volume = %.3f\n", v);
}

float area(float r)
{
    float area = 4 * PI * powf(r, 2);
    return area;
}

float volume(float r)
{
    float volume = (4/3) * PI * powf(r, 3);
    return volume;
}
