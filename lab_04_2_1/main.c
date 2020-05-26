#include <stdio.h>
#include <stdlib.h>

#define MIN_SIZE 1
#define MAX_SIZE 10
#define INPUT_ERROR 1
#define OK 0

void check_input(int *array, int size, int *cursor_out);
int sum(int *array, int size);
int count(int *array, int size);
double average(int *array, int size);

int main()
{
    int out = OK;
    int size;

    int array[MAX_SIZE];

    puts("Input size:");
    int rc = scanf("%d", &size);

    if ((rc == 1) && (size >= MIN_SIZE) && (size <= MAX_SIZE))
    {
        check_input(array, size, &out);
        if (out == OK)
        {
            printf("average Value %lf", average(array, size));
        }
    }
    else
        out = INPUT_ERROR;

    return out;
}

void check_input(int *array, int size, int *cursor_out)
{
    int rc;

    for (int i = 0; i < size; i++)
    {
        rc = scanf("%d", (array + i));

        if (rc != 1)
            *cursor_out = INPUT_ERROR;
    }

    if (count(array, size) == 0)
        *cursor_out = INPUT_ERROR;
}

double average(int *array, int size)
{
    int s = sum(array, size);
    int c = count(array, size);

    double x = (double) s / (double) c;

    return x;
}

int sum(int *array, int size)
{
    int s = 0;

    for (int i = 0; i < size; i++)
    {
        if (array[i] < 0)
            s += array[i];
    }

    return s;
}

int count(int *array, int size)
{
    int c = 0;

    for (int i = 0; i < size; i++)
    {
        if (array[i] < 0)
            c++;
    }

    return c;
}
