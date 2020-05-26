#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "CDIO_array_of_struct.h"
#include "sort_array_of_struct.h"
#include "struct.h"
#include "code_errors.h"
#include "const_parametrs.h"
#include "add_and_delete.h"

int main_processing(FILE *in)
{
    array_product_t array_product;
    array_product.products = NULL;
    array_product.size = 0;
    int code_error = OK;
    FILE *f_out = fopen("stockpile.txt", "w");

    char buf_article[MAX_STR_LEN];
    char buf_name[MAX_STR_LEN];

    while (!code_error && fscanf(in, "%s", buf_article) == 1 && (strlen(buf_article) < MAX_STR_LEN) && strcmp(buf_article, "nothing"))
    {
        if (check_uppercase(buf_article) == OK && fscanf(in, "%s", buf_name) == 1 && (strlen(buf_name) < MAX_STR_LEN) && check_name(buf_name) == OK)
        {
            create_array_of_struct(&array_product, &code_error);
            input_struct(in, buf_article, buf_name, &array_product, &code_error);
            array_product.size++;
        }
        else
            code_error = INPUT_ERROR;
    }

    if (!code_error)
    {
        add_name_into_article(&array_product);
        delete_product(&array_product, DELETE_FIELD);

        if (array_product.size > 0)
        {
            choise_field(in, &array_product, &code_error);

            if (!code_error)
                output_struct_to_file(f_out, &array_product);
        }
        else
            code_error = ARRAY_IS_OVER;
    }

    delete_array_of_struct(&array_product);
    fclose(f_out);

    return code_error;
}
