#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <math.h>
#include "main_processing.h"
#include "lib.h"
#include "def.h"

void create_matrix(int *out, matrix_t *matrix)
{
    int **buf_1 = (int **)malloc(matrix->row * sizeof(int *));
    if (buf_1)
    {
        matrix->matrix = buf_1;
        buf_1 = NULL;

        for (int i = 0; i < matrix->row && !(*out); i++)
        {
            int *buf_2 = (int *)malloc(matrix->column * sizeof(int));
            if (buf_2)
            {
                matrix->matrix[i] = buf_2;
                buf_2 = NULL;
            }
            else
                (*out) = MEMORY_ERROR;
        }
    }
    else
        (*out) = MEMORY_ERROR;
}

void delete_matrix(matrix_t *matrix)
{
    for (int i = 0; i < matrix->row; i++)
    {
        free(matrix->matrix[i]);
        matrix->matrix[i] = NULL;
    }

    free(matrix->matrix);
    matrix->matrix = NULL;
}

void input(FILE *in, int *out, matrix_t *matrix)
{
    for (int i = 0; i < matrix->row; i++)
        for (int j = 0; j < matrix->column; j++)
        {
            if (fscanf(in, "%d", matrix->matrix[i] + j) != 1)
                (*out) = INPUT_ERROR;
        }
}

void output(FILE *out, matrix_t *matrix)
{
    for (int i = 0; i < matrix->row; i++)
    {
        for (int j = 0; j < matrix->column; j++)
            fprintf(out, "%d ", matrix->matrix[i][j]);

        fputc('\n', out);
    }
}

void delete_row(matrix_t *matrix, int num_row)
{
    for (int i = num_row; i < matrix->row - 1; i++)
    {
        int *buf = matrix->matrix[i];
        matrix->matrix[i] = matrix->matrix[i + 1];
        matrix->matrix[i + 1] = buf;
    }

    free(matrix->matrix[matrix->row - 1]);
    matrix->matrix[matrix->row - 1] = NULL;

    matrix->row--;
}

void delete_column(matrix_t *matrix, int num_column)
{
    for (int i = 0; i < matrix->row; i++)
        for (int j = num_column; j < matrix->column - 1; j++)
        {
            matrix->matrix[i][j] = matrix->matrix[i][j + 1];
        }

    matrix->column--;
}

void delete_max(matrix_t *matrix)
{
    int max = matrix->matrix[0][0];
    int pos_i = 0;
    int pos_j = 0;

    for (int i = 0; i < matrix->row; i++)
        for (int j = 0; j < matrix->column; j++)
        {
            if (matrix->matrix[i][j] >= max)
            {
                max = matrix->matrix[i][j];
                pos_j = j;
                pos_i = i;
            }
        }

    if (matrix->row > matrix->column)
        delete_row(matrix, pos_i);
    else if (matrix->row < matrix->column)
        delete_column(matrix, pos_j);
}

void add_row(int *out, matrix_t *matrix)
{
    int **buf_1 = (int **)realloc(matrix->matrix, matrix->row * sizeof(int *));
    if (buf_1)
    {
        matrix->matrix = buf_1;
        buf_1 = NULL;

        int *buf_2 = (int *)malloc(matrix->column * sizeof(int));
        if (buf_2)
        {
            matrix->matrix[matrix->row - 1] = buf_2;
            buf_2 = NULL;

            for (int i = 0; !(*out) && i < matrix->column; i++)
            {
                matrix->matrix[matrix->row - 1][i] = calc_average_in_column(matrix, matrix->row - 1, i);
            }
        }
        else
            (*out) = MEMORY_ERROR;
    }
    else
        (*out) = MEMORY_ERROR;
}

void add_column(int *out, matrix_t *matrix)
{
    for (int i = 0; i < matrix->row && !(*out); i++)
    {
        int *buf = (int *)realloc(matrix->matrix[i], matrix->column * sizeof(int));
        if (buf)
        {
            matrix->matrix[i] = buf;
            buf = NULL;
        }
        else
            (*out) = MEMORY_ERROR;
    }

    for (int i = 0; !(*out) && i < matrix->row; i++)
    {
        matrix->matrix[i][matrix->column - 1] = search_min_in_row(matrix, i);
    }
}

int search_min_in_row(matrix_t *matrix, int row)
{
    int min = matrix->matrix[row][0];

    for (int i = 0; i < matrix->column - 1; i++)
        if (matrix->matrix[row][i] < min)
            min = matrix->matrix[row][i];

    return min;
}

int calc_average_in_column(matrix_t *matrix, int row, int column)
{
    double average = 0;

    for (int i = 0; i < row; i++)
        average += matrix->matrix[i][column];

    return (int)(floor(average / row));
}

void multiply_matrix(matrix_t *matrix_a, matrix_t *matrix_b, matrix_t *matrix_c)
{
    for (int i = 0; i < matrix_a->row; i++)
        for (int j = 0; j < matrix_a->column; j++)
        {
            for (int k = 0; k < matrix_a->column; k++)
            {
                matrix_c->matrix[i][j] += matrix_a->matrix[i][k] * matrix_b->matrix[k][j];
            }
        }
}

void unit_matrix(matrix_t *matrix)
{
    for (int i = 0; i < matrix->row; i++)
        for (int j = 0; j < matrix->column; j++)
        {
            if (i == j)
                matrix->matrix[i][j] = 1;
            else
                matrix->matrix[i][j] = 0;
        }
}

void vanishing_matrix(matrix_t *matrix)
{
    for (int i = 0; i < matrix->row; i++)
        for (int j = 0; j < matrix->column; j++)
        {
            matrix->matrix[i][j] = 0;
        }
}

void pow_matrix(int *out, int pow, matrix_t *matrix, matrix_t *mult_matrix)
{
    matrix_t buf_matrix;
    buf_matrix.matrix = NULL;
    buf_matrix.row = matrix->row;
    buf_matrix.column = matrix->column;

    create_matrix(out, &buf_matrix);
    vanishing_matrix(&buf_matrix);

    int flag = 1;

    if (pow == 0)
        unit_matrix(mult_matrix);
    else if (pow > 1)
    {
        for (int i = 1; i < pow; i++)
            if (flag)
            {
                flag = 0;
                multiply_matrix(matrix, matrix, mult_matrix);
            }
            else
            {
                multiply_matrix(mult_matrix, matrix, &buf_matrix);
                reassign(&buf_matrix, mult_matrix);
                vanishing_matrix(&buf_matrix);
            }
    }
    else
        reassign(matrix, mult_matrix);

    delete_matrix(&buf_matrix);
}

void reassign(matrix_t *matrix_from, matrix_t *matrix_to)
{
    for (int i = 0; i < matrix_from->row; i++)
        for (int j = 0; j < matrix_from->column; j++)
        {
            matrix_to->matrix[i][j] = matrix_from->matrix[i][j];
        }
}

void resize(int *out, matrix_t *matrix_a, matrix_t *matrix_b)
{
    int count = abs(matrix_a->row - matrix_b->row);

    if (matrix_a->row > matrix_b->row)
    {
        resize_matrix(matrix_b, count, out);
    }
    else
    {
        resize_matrix(matrix_a, count, out);
    }
}

void resize_matrix(matrix_t *matrix, int count, int *out)
{
    for (int i = 0; i < count; i++)
    {
        matrix->row++;
        add_row(out, matrix);
    }
    for (int i = 0; i < count; i++)
    {
        matrix->column++;
        add_column(out, matrix);
    }
}
