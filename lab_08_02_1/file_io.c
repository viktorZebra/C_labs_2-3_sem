#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "def.h"
#include "lib.h"
#include "file_io.h"

void print_array_file(FILE *fout, double *array, int n)
{
    for (int i = 0; i < n; i++)
    {
        fprintf(fout, "%.6lf ", array[i]);
    }
}

void input_array_file(FILE *f_in, double **array, int n, int *out)
{
    double *buf_array = (double*) malloc(n * sizeof(double));

    if (buf_array)
    {
        (*array) = buf_array;
        buf_array = NULL;

        for (int i = 0; i < n; i++)
        {
            if (fscanf(f_in, "%lf", (*array) + i) != 1)
                (*out) = INPUT_ERROR;
        }
    }
    else
        (*out) = MEMORY_IS_OVER;
}

void processing(FILE *f_in, char *f_out)
{
    FILE *fout = fopen(f_out, "w");

    int out = OK;
    int n;
    double *array;

    if (fscanf(f_in, "%d", &n) == 1 && n > 0)
    {
        input_array_file(f_in, &array, n, &out);

        if (!out)
        {
            double u1 = calculate_u1(array, n);
            delete_elements(&array, &n, u1, &out);

            if (!out)
            {
                double u2 = calculate_u2(array, n);
                int position;

                if (fscanf(f_in, "%d", &position) == 1 && (n > position) && (position >= 0))
                {
                    add_elements(&array, &n, position, u2, &out);

                    if (!out)
                        print_array_file(fout, array, n);
                    else
                        fprintf(fout, "%d", out);
                }
                else
                {
                    out = OUTSIDE_OF_ARRAY;
                    fprintf(fout, "%d", out);
                }
            }
            else
                fprintf(fout, "%d", out);
        }
        else
            fprintf(fout, "%d", out);

        free(array);
    }
    else
    {
        out = INPUT_ERROR;
        fprintf(fout, "%d", out);
    }

    array = NULL;

    fclose(fout);
}
