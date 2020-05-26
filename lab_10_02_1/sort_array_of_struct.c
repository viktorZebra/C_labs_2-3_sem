#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "CDIO_array_of_struct.h"
#include "struct.h"
#include "code_errors.h"
#include "const_parametrs.h"
#include "sort_array_of_struct.h"

int cmp_article(product_t *product_1, product_t *product_2)
{
    return strcmp(product_1->article, product_2->article);
}

int cmp_name(product_t *product_1, product_t *product_2)
{
    return strcmp(product_1->name, product_2->name);
}

int cmp_count(product_t *product_1, product_t *product_2)
{
    int code = 0;
    if (product_1->count > product_2->count)
        code = MORE;
    if (product_1->count < product_2->count)
        code = SMALLER;
    return code;
}

void sort_struct(product_t *products, int size, int (*cmp)(product_t *, product_t *))
{
    product_t buf;

    int index;

    for (int i = 0; i < size - 1; i++)
    {
        index = i;
        buf = *(products + i);

        for (int j = i + 1; j < size; j++)
        {
            if ((*cmp)(products + j, &buf) < 0)
            {
                buf = *(products + j);
                index = j;
            }
        }

        // добавлено для устойчивой сортировки
        for (int k = index; k > i; k--)
        {
            products[k] = products[k - 1];
        }
        products[i] = buf;
    }
}

void swap(product_t *product_1, product_t *product_2)
{
    product_t buf;

    buf = (*product_1);
    (*product_1) = (*product_2);
    (*product_2) = buf;
}

void choise_field(FILE *in, array_product_t *array_product, int *code_error)
{
    char choise[LEN_CHOISE];
    if (fscanf(in, "%s", choise) == 1)
    {
        if (!strcmp(choise, "ARTICLE"))
        {
            sort_struct(array_product->products, array_product->size, cmp_article);
        }
        else if (!strcmp(choise, "NAME"))
        {
            sort_struct(array_product->products, array_product->size, cmp_name);
        }
        else if (!strcmp(choise, "COUNT"))
        {
            sort_struct(array_product->products, array_product->size, cmp_count);
        }
        else
            *code_error = INPUT_ERROR;
    }
    else
        *code_error = INPUT_ERROR;
}
