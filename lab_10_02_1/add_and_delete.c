#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "CDIO_array_of_struct.h"
#include "struct.h"
#include "code_errors.h"
#include "const_parametrs.h"
#include "add_and_delete.h"
#include "sort_array_of_struct.h"

void add_name_into_article(array_product_t *array_product)
{
    for (int i = 0; i < array_product->size; i++)
    {
        array_product->products[i].article = (char *)realloc(array_product->products[i].article, (strlen(array_product->products[i].name) + strlen(array_product->products[i].article) + 1) * sizeof(char));
        strcat(array_product->products[i].article, array_product->products[i].name);
        my_toupper(array_product->products[i].article);
    }
}

void my_toupper(char *article)
{
    int len = strlen(article);
    for (int i = 0; i < len; i++)
    {
        article[i] = toupper(article[i]);
    }
}

void delete_product(array_product_t *array_product, char *field)
{
    for (int i = 0; i < array_product->size; i++)
    {
        if (!strcmp(array_product->products[i].article, field) && array_product->products[i].count == 0)
        {
            for (int j = i; j < array_product->size - 1; j++)
            {
                swap(array_product->products + j, array_product->products + j + 1);
            }

            array_product->size--;
            free(array_product->products[array_product->size].article);
            array_product->products[array_product->size].article = NULL;

            free(array_product->products[array_product->size].name);
            array_product->products[array_product->size].name = NULL;

            array_product->products = (product_t *)realloc(array_product->products, array_product->size * sizeof(product_t));
            i--;
        }
    }
}
