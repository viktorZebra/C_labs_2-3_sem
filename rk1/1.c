//Вариант 3

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define OK 0
#define ERROR 1

double sumOfRow(double x, double eps);

int main()
{
	int out = OK;
	double x;
	double eps;
	
	puts("input eps");
	int rc1 = scanf("%lf", &eps);
	
	puts("input X");
	int rc2 = scanf("%lf", &x);
	
	if ((fabs(x) > 1) || (rc1 != 1) || (rc2 != 1))
		out = ERROR;
	else
	{
		double ln = log(1 + x);
			
		printf("Summa: %.5lf\nln(1 + x): %.5lf", sumOfRow(x, eps), ln);
	}
	
	return out;
}

double sumOfRow(double x, double eps)
{
    double s = 1;
	int i = 1;
	
	while (fabs(x) > eps)
	{
		s += x;
			
		i++;
			
		x *= -1 * x * (i - 1) /i;
			
	}
	
	return s;
}
		