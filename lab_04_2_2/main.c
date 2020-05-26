#include <stdio.h>
#include <stdlib.h>

#define MIN_SIZE 1
#define MAX_SIZE 10
#define INPUT_ERROR 1
#define OK 0

void check_input(int *array, int size, int *cursor_out);
void forming_new_array(int *array, int size, int *new_array, int *cursor_new_size, int *cursor_out);
void print(int *array, int size);

int main()
{
    int out = OK;
    int size;
    int new_size = 0;

    int array[MAX_SIZE];
    int new_array[MAX_SIZE];

    puts("Input size:");
    int rc = scanf("%d", &size);

    if ((rc == 1) && (size >= MIN_SIZE) && (size <= MAX_SIZE))
    {
        check_input(array, size, &out);

        if (out == OK)
        {
            forming_new_array(array, size, new_array, &new_size, &out);
            if (out == OK)
            {
                puts("New array");
                print(new_array, new_size);
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

void forming_new_array(int *array, int size, int *new_array, int *cursor_new_size, int *cursor_out)
{
    int first_number;
    int last_number;
    int buf_number;
    int count = 0;

    for (int i = 0; i < size; i++)
    {
        last_number = abs(array[i]) % 10;
        buf_number = abs(array[i]);

        while (buf_number > 0)
        {
            first_number = buf_number % 10;
            buf_number = buf_number / 10;
        }

        if (last_number == first_number)
        {
            new_array[count] = array[i];
            count++;
        }
    }

    if (count == 0)
        *cursor_out = INPUT_ERROR;
    else
        (*cursor_new_size) = count;
}

void print(int *array, int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", array[i]);
}
