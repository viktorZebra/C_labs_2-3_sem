#ifndef __SORT_ARRAY_OF_STRUCT__
#define __SORT_ARRAY_OF_STRUCT__

int cmp_article(product_t *product_1, product_t *product_2);
int cmp_name(product_t *product_1, product_t *product_2);
int cmp_count(product_t *product_1, product_t *product_2);
void sort_struct(product_t *products, int size, int (*cmp)(product_t *, product_t *));
void swap(product_t *product_1, product_t *product_2);
void choise_field(FILE *in, array_product_t *array_product, int *code_error);
#endif
