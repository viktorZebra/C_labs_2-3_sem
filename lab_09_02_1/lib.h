#ifndef __LIB_H__
#define __LIB_H__

#include "matrix_struct.h"
void create_matrix(int *out, matrix_t *matrix);
void delete_matrix(matrix_t *matrix);
void input(FILE *in, int *out, matrix_t *matrix);
void output(FILE *out, matrix_t *matrix);

void delete_row(matrix_t *matrix, int num_row);
void delete_column(matrix_t *matrix, int num_column);

void delete_max(matrix_t *matrix);

void add_row(int *out, matrix_t *matrix);
void add_column(int *out, matrix_t *matrix);
int calc_average_in_column(matrix_t *matrix, int row, int column);
int search_min_in_row(matrix_t *matrix, int row);

void multiply_matrix(matrix_t *matrix_a, matrix_t *matrix_b, matrix_t *matrix_c);
void unit_matrix(matrix_t *matrix);
void vanishing_matrix(matrix_t *matrix);
void pow_matrix(int *out, int pow, matrix_t *matrix, matrix_t *mult_matrix);
void resize(int *out, matrix_t *matrix_a, matrix_t *matrix_b);
void resize_matrix(matrix_t *matrix, int count, int *out);
void reassign(matrix_t *matrix_from, matrix_t *matrix_to);

#endif
