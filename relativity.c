#include <stdio.h>
#include <math.h>

#define C 3e8

double v,t,t_0,l,l_0,m,m_0; // Global variables
int choice;

int t_dil(double v); // Time dilation
int l_cont(double v); // Length contraction
int mass_inc(double v); // Mass increase

int main()
{
    printf("v = ");
    scanf("%lf",&v);
    printf("1. Time dilation\n2. Length Contraction\n3. Mass Increase\nYour choice: ");
    scanf("%d",&choice);
    if (choice==1)
        t_dil(v);
    else if (choice==2)
        l_cont(v);
    else if (choice==3) 
        mass_inc(v);
    return 0;
}

int t_dil(double v)
{
    printf("t_0 = "); //Proper time
    scanf("%lf",&t_0);
    t = t_0/sqrt(1-pow(v,2)/pow(C,2));
    printf("t = %.5lf",t);
    return 0;
}

int l_cont(double v)
{
    printf("l_0 = "); //Proper length
    scanf("%lf",&l_0);
    l = l_0*sqrt(1-pow(v,2)/pow(C,2));
    printf("l = %.5lf",l);
    return 0;
}

int mass_inc(double v)
{
    printf("m_0 = "); // Rest mass
    scanf("%lf",&m_0);
    m = m_0/sqrt(1-pow(v,2)/pow(C,2));
    printf("m = %.5lf",m);
    return 0;
}
