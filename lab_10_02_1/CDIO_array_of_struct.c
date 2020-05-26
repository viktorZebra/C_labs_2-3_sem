#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "CDIO_array_of_struct.h"
#include "struct.h"
#include "code_errors.h"
#include "const_parametrs.h"

void create_array_of_struct(array_product_t *array_product, int *code_error)
{
    product_t *buf = (product_t *)realloc(array_product->products, (array_product->size + 1) * sizeof(product_t));
    if (buf)
    {
        array_product->products = buf;
        buf = NULL;
    }
    else
        *code_error = MEMORY_ERROR;
}

void delete_array_of_struct(array_product_t *array_product)
{
    for (int i = 0; i < array_product->size; i++)
    {
        free(array_product->products[i].article);
        array_product->products[i].article = NULL;

        free(array_product->products[i].name);
        array_product->products[i].name = NULL;
    }
    free(array_product->products);
    array_product->products = NULL;
}

void input_struct(FILE *in, char *buf_article, char *buf_name, array_product_t *array_product, int *code_error)
{
    array_product->products[array_product->size].article = (char *)malloc((strlen(buf_article) + 1) * sizeof(char));
    strcpy(array_product->products[array_product->size].article, buf_article);

    array_product->products[array_product->size].name = (char *)malloc((strlen(buf_name) + 1) * sizeof(char));
    strcpy(array_product->products[array_product->size].name, buf_name);

    if ((fscanf(in, "%d", &(array_product->products[array_product->size].count)) != 1 || array_product->products[array_product->size].count < 0) || !code_error)
        *code_error = INPUT_ERROR;
}

void output_struct_to_file(FILE *f_out, array_product_t *array_product)
{
    for (int i = 0; i < array_product->size; i++)
    {
        fprintf(f_out, "%s\n", array_product->products[i].article);
        fprintf(f_out, "%s\n", array_product->products[i].name);
        fprintf(f_out, "%d\n", array_product->products[i].count);
    }
}

int check_uppercase(char *buf_field)
{
    int code_error = OK;

    for (int i = 0; i < strlen(buf_field) && !code_error; i++)
    {
        if (!(buf_field[i] >= 'A' && buf_field[i] <= 'Z'))
        {
            code_error = INPUT_ERROR;
        }
    }

    return code_error;
}

int check_name(char *buf_field)
{
    int code_error = OK;

    for (int i = 0; i < strlen(buf_field) && !code_error; i++)
    {
        if (!(buf_field[i] >= 'A' && buf_field[i] <= 'z'))
        {
            code_error = INPUT_ERROR;
        }
    }

    return code_error;
}
