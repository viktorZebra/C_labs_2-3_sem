#ifndef __STRUCT__
#define __STRUCT__

typedef struct
{
    char *article;
    char *name;
    int count;
} product_t;

typedef struct
{
    product_t *products;
    int size;
} array_product_t;

#endif
