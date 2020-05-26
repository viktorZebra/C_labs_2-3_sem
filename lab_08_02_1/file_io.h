#ifndef __FILE_IO__
#define __FILE_IO__

void print_array_file(FILE *fout, double *array, int n);
void input_array_file(FILE *f_in, double **array, int n, int *out);

void processing(FILE *f_in, char *f_out);

#endif
