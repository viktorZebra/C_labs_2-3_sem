#include <stdio.h>
#include <stdlib.h>

#define MIN_SIZE 1
#define MAX_SIZE 10
#define ERROR 1
#define OK 0

void transform(int *a, int **ap, int row, int col);
void check_input(int **ap, int row, int col, int *out);
void proccesing(int **ap, int *array, int row, int col);
void print(int *array, int size);

int main()
{
    int out = OK;

    int a[MAX_SIZE*MAX_SIZE];
    int *ap[MAX_SIZE];

    int array[MAX_SIZE] = { 0 };

    int row, col;
    puts("Input rows and columns of array: ");

    if ((scanf("%d %d", &row, &col) == 2) && (row < 11 && col < 11) && (row > 0 && col > 0))
    {
        transform(a, ap, row, col);

        check_input(ap, row, col, &out);

        if (out == OK)
        {
            proccesing(ap, array, row, col);

            puts("Output: ");
            print(array, col);
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

void proccesing(int **ap, int *array, int row, int col)
{
    if (row != 1)
    {
        for (int i = 0; i < col; i++)
        {
            int count = 0;

            for (int j = 0; j < row - 1; j++)
                if (ap[j][i] * ap[j + 1][i] < 0)
                    count++;

            if (count == row - 1)
                array[i] = 1;
        }
    }
}

void print(int *array, int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", array[i]);
}
