#include <stdio.h>
#include <math.h>
double perimeter(double a, double b, double h);

int main()
{
    double a, b, h;

    puts("Input a smaller base: ");
    scanf("%lf", &a);

    puts("Input a larger base: ");
    scanf("%lf", &b);

    puts("Input height: ");
    scanf("%lf", &h);

    printf("Perimeter: %.5lf", perimeter(a, b, h));

    getchar();
    getchar();
    return 0;
}

double perimeter(double a, double b, double h)
{
    double side = sqrt(h * h + pow((b - a) / 2, 2));
    return (2 * side + a + b);
}
