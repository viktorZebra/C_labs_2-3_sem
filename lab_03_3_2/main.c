#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define ERROR -1
#define OK 0
#define SIGM_CHANCE 99.72

int find_count(FILE *f);
float find_average(FILE *f, int *count);
float find_dispersion(FILE *f, float *average, int *count);
int find_satisfy_value_count(FILE *f, float *average, float *dispersion);
int check_three_sigm(int *satisfy_value_count, int  *count);

int main(int argc, char **argv)
{
    int out = OK;

    if (argc == 2)
    {
        FILE *f = fopen(argv[1], "r");

        int count = find_count(f);
        if (count != 0)
        {
            float average = find_average(f, &count);
            float dispersion = find_dispersion(f, &average, &count);
            int satisfy_value_count = find_satisfy_value_count(f, &average, &dispersion);
            int check = check_three_sigm(&satisfy_value_count, &count);

            printf("%d", check);
        }
        else
            out = ERROR;

        fclose(f);
    }
    else
        out = ERROR;

    return out;
}

int check_three_sigm(int *satisfy_value_count, int  *count)
{
    int check_out = 0;

    float chance = *satisfy_value_count / *count;

    if (chance * 100 > SIGM_CHANCE)
        check_out = 1;

    return check_out;
}

float find_average(FILE *f, int *count)
{
    float average = 0;
    float value;

    while (fscanf(f, "%f", &value) == 1)
    {
        average += value;
    }

    average = average / (float)(*count);

    fseek(f, 0, 0);

    return average;
}

float find_dispersion(FILE *f, float *average, int *count)
{
    float value;

    double dispersion = 0;

    while (fscanf(f, "%f", &value) == 1)
        dispersion += pow((value - *average), 2) / (double)(*count);

    dispersion = sqrt(dispersion);

    fseek(f, 0, 0);

    return (float)dispersion;
}

int find_satisfy_value_count(FILE *f, float *average, float *dispersion)
{
    float value;

    int satisfy_value_count = 0;

    while (fscanf(f, "%f", &value) == 1)
    {
        if (((*average - 3 * (*dispersion)) <= value) && (value <= (*average + 3 * (*dispersion))))
            satisfy_value_count++;
    }

    fseek(f, 0, 0);

    return satisfy_value_count;
}

int find_count(FILE *f)
{
    float num_value;
    int num_count = 0;

    int char_count = 0;

    while (!feof(f))
    {
        int check_val = fscanf(f, "%f", &num_value);

        if (check_val == 1)
            num_count++;
        else
            char_count = 1;
    }


    if (char_count)
        num_count = 0;

    fseek(f, 0, 0);

    return num_count;
}
