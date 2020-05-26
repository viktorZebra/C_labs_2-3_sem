#include <stdio.h>
#include <stdlib.h>

#define MIN_SIZE 1
#define MAX_SIZE 10
#define INPUT_ERROR 1
#define OK 0

void check_input(int *array, int size, int *cursor_out);
void sort_selection(int *array, int size);
void swap(int *a, int *b);
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
            sort_selection(array, size);

            puts("Sort array: ");
            print(array, size);
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

// Сортировка выбором
void sort_selection(int *array, int size)
{
    int min_idx;

    for (int i = 0; i < size - 1; i++)
    {
        min_idx = i;

        for (int j = i + 1; j < size; j++)
        {
            if (array[j] < array[min_idx])
                min_idx = j;
        }

        if (i != min_idx)
            swap((array + i), (array + min_idx));
    }
}

void swap(int *a, int *b)
{
    int buf_val = *a;
    *a = *b;
    *b = buf_val;
}

void print(int *array, int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", array[i]);
}
