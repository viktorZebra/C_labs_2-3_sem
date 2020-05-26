#ifndef __LIB_H__
#define __LIB_H__

double calculate_u1(double  *array, int size);
double calculate_u2(double  *array, int size);
void delete_elements(double  **array, int *size, double element, int *out);
void add_elements(double **array, int *size, int position, double element, int *out);
void print_array(double *array, int size);
void input_array(FILE *in, double **array, int size, int *out);
void my_realloc(double **array, int *size, int *out);



#endif
