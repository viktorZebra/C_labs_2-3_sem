#include <stdio.h>
#include <stdlib.h>

#define MIN_SIZE 1
#define MAX_SIZE 10
#define ERROR 1
#define OK 0

void transform(int *a, int **ap, int row, int col);
void check_input(int **ap, int row, int col, int *out);
void sorting(int **ap, int row, int col);
void print(int **ap, int row, int col);
void swap(int **a, int **b);
int multiply(int **ap, int row, int col);

int main()
{
    int out = OK;

    int a[MAX_SIZE * MAX_SIZE];
    int *ap[MAX_SIZE];

    int row, col;
    puts("Input rows and columns of array: ");

    if ((scanf("%d %d", &row, &col) == 2) && (row < 11 && col < 11) && (row > 0 && col > 0))
    {
        transform(a, ap, row, col);

        check_input(ap, row, col, &out);

        if (out == OK)
        {
            sorting(ap, row, col);

            puts("Output: ");
            print(ap, row, col);
        }
    }
    else
        out = ERROR;

    return out;
}

void transform(int *a, int **ap, int row, int col)
{
    for (int i = 0; i < row; i++)
        ap[i] = a + i * col;
}

void check_input(int **ap, int row, int col, int *out)
{
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
        {
            if (scanf("%d", ap[i] + j) != 1)
                *out = ERROR;
        }
}

void print(int **ap, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            printf("%d ", ap[i][j]);
        puts("\n");
    }
}

int multiply(int **ap, int row, int col)
{
	int mltp = 1;

	for (int j = 0; j < col; j++)
		mltp *= ap[row][j];

	return mltp;
}

void swap(int **a, int **b)
{
	int *buf;

	buf = *b;
	*b = *a;
	*a = buf;
}

void sorting(int **ap, int row, int col)
{
	for (int i = 0; i < row; i++)
		for (int j = 0; j < row; j++)
		{
			if (multiply(ap, i, col) < multiply(ap, j, col))
				swap((ap + i), (ap + j));
		}
}



