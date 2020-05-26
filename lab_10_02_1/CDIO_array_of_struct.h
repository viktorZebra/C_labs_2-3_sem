#ifndef __CDIO_ARRAY_OF_STRUCT__
#define __CDIO_ARRAY_OF_STRUCT__

#include "struct.h"
void create_array_of_struct(array_product_t *array_product, int *code_error);
void delete_array_of_struct(array_product_t *array_product);
void input_struct(FILE *in, char *buf_article, char *buf_name, array_product_t *array_product, int *code_error);
void output_struct_to_file(FILE *f_out, array_product_t *array_product);
int check_uppercase(char *buf_field);
int check_name(char *buf_field);

#endif
