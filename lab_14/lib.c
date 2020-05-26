#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "def.h"
#include "lib.h"
#include "ui.h"
#include "ui_input.h"

void print_array(double *array, int size)
{
    uiMultilineEntrySetText(mul_entry, "");
    char *product_info = malloc(sizeof(char) * 20);
    for (int i = 0; i < size; i++)
        {
            sprintf(product_info, "%.6lf ", array[i]);
            uiMultilineEntryAppend(mul_entry, product_info);
        }
}

void input_array(FILE *in, double **array, int size, int *out)
{
    my_realloc(array, &size, out);

    if (!(*out))
    {
        for (int i = 0; i < size; i++)
        {
            if (fscanf(in, "%lf", (*array) + i) != 1)
                (*out) = INPUT_ERROR;
        }
    }
}

double calculate_u1(double *array, int size)
{
    double average = 0;

    for (int i = 0; i < size; i++)
    {
        average += array[i];
    }

    average = average / size;

    return average;
}

void delete_elements(double **array, int *size, double element, int *out)
{
    int i;

    for (i = 0; i < *size; i++)
    {
        if ((*array)[i] - element > EPS)
        {
            for (int j = i; j < *size - 1; j++)
            {
                (*array)[j] = (*array)[j + 1];
            }

            if (i == *size - 1)
            {
                *size -= 1;
            }
            else
            {
                i--;
                *size -= 1;
            }
        }
    }
    my_realloc(array, size, out);
}

double calculate_u2(double *array, int size)
{
    double max_val = array[0];

    for (int i = 0; i < size; i++)
    {
        if (array[i] - max_val > EPS)
            max_val = array[i];
    }

    return max_val;
}

void add_elements(double **array, int *size, int position, double element, int *out)
{
    (*size) += 3; // adds three elements => size increases by three

    my_realloc(array, size, out);

    if (!(*out))
    {
        for (int i = (*size) - 3; i > position; i--)
        {
            (*array)[i] = (*array)[i - 1];
        }

        (*array)[position] = element;

        for (int i = (*size) - 2; i > 0; i--)
        {
            (*array)[i] = (*array)[i - 1];
        }

        (*array)[0] = element;
        (*array)[(*size) - 1] = element;
    }
}

void my_realloc(double **array, int *size, int *out)
{
    double *buf_array = (double*) realloc((*array), (*size) * sizeof(double));

    if (buf_array)
    {
        (*array) = buf_array;
        buf_array = NULL;
    }
    else
        (*out) = MEMORY_IS_OVER;
}
