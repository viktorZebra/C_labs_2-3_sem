#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "main_processing.h"
#include "lib.h"
#include "def.h"
#include "matrix_struct.h"

int processing(FILE *in, FILE *f_out)
{
    int out = OK;

    matrix_t matrix_a;
    matrix_a.matrix = NULL;

    matrix_t matrix_b;
    matrix_b.matrix = NULL;

    int powa;
    int powb;

    if (fscanf(in, "%d %d", &matrix_a.row, &matrix_a.column) == 2 && matrix_a.row > 0 && matrix_a.column > 0)
    {
        create_matrix(&out, &matrix_a);
        input(in, &out, &matrix_a);

        if (!out && fscanf(in, "%d %d", &matrix_b.row, &matrix_b.column) == 2 && matrix_b.row > 0 && matrix_b.column > 0)
        {
            create_matrix(&out, &matrix_b);
            input(in, &out, &matrix_b);

            if (!out && fscanf(in, "%d %d", &powa, &powb) == 2 && powa >= 0 && powb >= 0)
            {
                while (matrix_a.row != matrix_a.column)
                    delete_max(&matrix_a);

                while (matrix_b.row != matrix_b.column)
                    delete_max(&matrix_b);

                resize(&out, &matrix_a, &matrix_b);

                matrix_t mult_a;
                mult_a.matrix = NULL;
                mult_a.row = matrix_a.row;
                mult_a.column = matrix_a.column;

                matrix_t mult_b;
                mult_b.matrix = NULL;
                mult_b.row = matrix_b.row;
                mult_b.column = matrix_b.column;

                matrix_t mult_matrix;
                mult_matrix.matrix = NULL;
                mult_matrix.row = matrix_a.row;
                mult_matrix.column = matrix_b.column;

                create_matrix(&out, &mult_a);
                create_matrix(&out, &mult_b);
                create_matrix(&out, &mult_matrix);

                vanishing_matrix(&mult_a);
                vanishing_matrix(&mult_b);
                vanishing_matrix(&mult_matrix);

                pow_matrix(&out, powa, &matrix_a, &mult_a);
                pow_matrix(&out, powb, &matrix_b, &mult_b);

                multiply_matrix(&mult_a, &mult_b, &mult_matrix);

                output(f_out, &mult_matrix);

                delete_matrix(&mult_a);
                delete_matrix(&mult_b);
                delete_matrix(&mult_matrix);
            }
            else
                out = INPUT_ERROR;

            delete_matrix(&matrix_b);
        }
        else
            out = INPUT_ERROR;

        delete_matrix(&matrix_a);
    }
    else
        out = INPUT_ERROR;

    return out;
}
