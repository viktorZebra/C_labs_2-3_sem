#include <stdio.h>
#include <stdlib.h>

#define MIN_SIZE 1
#define MAX_SIZE 10
#define ERROR 1
#define OK 0

void transform(int *a, int **ap, int row, int col);
void check_input(int **ap, int row, int col, int *out);
void proccesing(int **ap, int *row, int col);
void print(int **ap, int row, int col);
void add_row(int **ap, int i, int row, int col);
int sum(int value);

int main()
{
    int out = OK;

    int a[2 * MAX_SIZE * MAX_SIZE];
    int *ap[2 * MAX_SIZE];

    int row, col;
    puts("Input rows and columns of array: ");

    if ((scanf("%d %d", &row, &col) == 2) && (row < 11 && col < 11) && (row > 0 && col > 0))
    {
        transform(a, ap, row, col);

        check_input(ap, row, col, &out);

        if (out == OK)
        {
            proccesing(ap, &row, col);

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
    for (int i = 0; i < 2 * MAX_SIZE; i++)
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

void proccesing(int **ap, int *row, int col)
{
    for (int i = 0; i < *row; i++)
    {
        int count = 0;

        for (int j = 0; j < col; j++)
        {
            if (sum(*(ap[i] + j)) % 2 != 0)
                count++;
        }

        if (count > 1)
        {
            add_row(ap, i, *row, col);
            (*row)++;
            i++;
        }
    }
}

int sum(int value)
{
    int s = 0;

    value = abs(value);

    while (value > 0)
    {
        s += value % 10;
        value = value / 10;
    }

    return s;
}

void add_row(int **ap, int i, int row, int col)
{
    for (int j = row - 1; j >= i; j--)
        for (int k = 0; k < col; k++)
            ap[j + 1][k] = ap[j][k];

    for (int j = 0; j < col; j++)
        ap[i][j] = -1;
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
