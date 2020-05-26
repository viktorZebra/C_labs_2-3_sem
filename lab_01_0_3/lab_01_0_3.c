#include <stdio.h>
#include <math.h>

double weight(double h, double t);
double indx(double m, double h);

int main(void)
{
    double h, t, m;

    printf("Input growth in centimeters > ");
    scanf("%lf", &h);

    printf("Input chest circumference > ");
    scanf("%lf", &t);

    printf("Input weight > ");
    scanf("%lf", &m);

    printf("weight: %.5lf\n", weight(h, t));

    printf("index: %.5lf", indx(m, h));

    getchar();
    getchar();
    return 0;
}

double weight(double h, double t)
{
    return (h * t / 240);
}

double indx(double m, double h)
{
    h /= 100;

    return (m / pow(h, 2));
}
