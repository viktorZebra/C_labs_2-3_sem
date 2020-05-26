#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "def.h"
#include "lib.h"

int main()
{
    int out = OK;
    int n;
    double *array = NULL;

    if (scanf("%d", &n) == 1 && n > 0)
    {
        input_array(&array, n, &out);

        if (!out)
        {
            double u1 = calculate_u1(array, n);
            delete_elements(&array, &n, u1, &out);

            if (!out)
            {
                double u2 = calculate_u2(array, n);
                int position;

                if (scanf("%d", &position) == 1 && (n > position) && (position >= 0))
                {
                    add_elements(&array, &n, position, u2, &out);

                    if (!out)
                        print_array(array, n);
                }
                else
                    out = OUTSIDE_OF_ARRAY;
            }
        }
        free(array);
    }
    else
        out = INPUT_ERROR;

    array = NULL;

    return out;
}

