#include <stdio.h>
#include <stdlib.h>

#define MIN_SIZE 1
#define MAX_SIZE 10
#define INPUT_ERROR 1
#define OK 0

void check_input(int *array, int size, int *cursor_out);
int *sqr_clear(int *array, int *cursor_size, int *cursor_out);
int is_sqr(int *array, int i);
void print(int *array, int size);

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
            sqr_clear(array, &size, &out);

            if (out == OK)
            {
                puts("WITHOUT FULL SQRR");
                print(array, size);
            }
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
}

int *sqr_clear(int *array, int *cursor_size, int *cursor_out)
{
    int i;
    for (i = 0; i < (*cursor_size); i++)
    {
        if (is_sqr(array, i))
        {
            for (int j = i + 1; j < (*cursor_size); j++)
                array[j - 1] = array[j];

            (*cursor_size)--;
            i--;
        }
    }

    if ((*cursor_size) == 0)
        *cursor_out = INPUT_ERROR;

    return array;
}

int is_sqr(int *array, int i)
{
    int return_value = 0;

    int j = 0;
    while (j * j <= array[i])
    {
        if (j * j == array[i])
        {
            return_value = 1;
        }

        j++;
    }

    return return_value;
}

void print(int *array, int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", array[i]);
}
