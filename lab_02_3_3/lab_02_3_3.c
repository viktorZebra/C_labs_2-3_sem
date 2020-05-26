#include <stdio.h>
#include <math.h>
double arctan(double x, double eps);
double relative_error(double x, double f, double s);

int main()
{
    int rt;
    double eps, x;

    puts("Input x, eps: ");
    int rc = scanf("%lf %lf", &x, &eps);

    if ((rc == 2) && (fabs(x) <= 1) && ((eps > 0) && (eps < 1)))
    {
        double f = atan(x);
        double s = arctan(x, eps);

        printf("S(x): %lf\n", s);
        printf("F(x): %lf\n", f);
        printf("Absolute error: %lf\n", fabs(f - s));
        printf("Relative error: %lf", relative_error(x, f, s));

        rt = 0;
    }
    else
    {
        puts("Input error");

        rt = 1;
    }

    return rt;
}

double arctan(double x, double eps)
{
    double rt;
    if (x != 0)
    {
        double m = 0;
        double a = x;
        int i = 1;

        while (fabs(a) > eps)
        {
            m += a;
            a *= (x * x) * (2 * i - 1) / (2 * i + 1) * (-1);
            i ++;
        }
        rt = m;
    }
    else
        rt = 0;

    return rt;
}

double relative_error(double x, double f, double s)
{
    double rt;
    if (x != 0)
        rt = fabs((f - s) / f);
    else
        rt = 0;

    return rt;
}
