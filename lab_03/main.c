#include <stdio.h>
#include <stdlib.h>
#include<time.h>

#define ERROR -1
#define OK 0
#include <string.h>
#define MAX_COUNT 10

int get_number_by_pos(FILE *f, const int position);
void put_number_by_pos(FILE *f, int position, int number);
void sort_file(char *file_name, int *out, int count);
void print_file(char *file_name, int *out, int count);
int count_val(char *file_name);
void input_random_val(char *file_name);

int main(int argc, char **argv)
{
    int out = OK;

    if (argc == 3)
    {
        if (strcmp(argv[1], "c") == OK)
        {
            input_random_val(argv[2]);
        }

        if (strcmp(argv[1], "s") == OK)
        {
            int count = count_val(argv[2]);
            sort_file(argv[2], &out, count);
        }

        if (strcmp(argv[1], "p") == OK)
        {
            int count = count_val(argv[2]);
            print_file(argv[2], &out, count);
        }
    }
    else
        out = ERROR;

    return out;
}

void sort_file(char *file_name, int *out, int count)
{
    int ind_min;
    int a, b;

    FILE *f = fopen(file_name, "r + b");
    if (f)
    {
        for(int i = 0; i <= count; i++)
        {
            ind_min = i;

            for(int j = i + 1; j <= count; j++)
            {
                a = get_number_by_pos(f, j);
                b = get_number_by_pos(f, ind_min);

                if (a < b)
                    ind_min = j;
            }

            a = get_number_by_pos(f, i);
            b = get_number_by_pos(f, ind_min);
            put_number_by_pos(f, i, b);
            put_number_by_pos(f, ind_min, a);
        }
    }
    else
        *out = ERROR;
}

void print_file(char *file_name, int *out, int count)
{
    int value;

    FILE *f = fopen(file_name, "rb");
    if (f)
    {
        for(int i = 0; i < count; i++)
        {
            fread(&value, sizeof(int), 1, f);
            printf("%d ", value);
        }
    }
    else
        *out = ERROR;

    fclose(f);
}

void input_random_val(char *file_name)
{
    FILE *f = fopen(file_name, "wb");

    srand(time(NULL));

    for (int i = 0; i < MAX_COUNT; i++)
    {
        int ran_val = rand() % 101;
        fwrite(&ran_val, sizeof(int), 1, f);
    }

    fclose(f);
}

int count_val(char *file_name)
{
    int value;
    int count = 0;

    FILE *f = fopen(file_name, "rb");

    while (fread(&value, sizeof(int), 1, f) == 1)
    {
        count++;
    }

    return count;
}

int get_number_by_pos(FILE *f, const int position)
{
    int value;

    fseek(f, position * sizeof(int) - sizeof(int), SEEK_SET);
    fread(&value, sizeof(int), 1, f);

    return value;
}

void put_number_by_pos(FILE *f, int position, int value)
{
    fseek(f, position * sizeof(int) - sizeof(int), SEEK_SET);
    fwrite(&value, sizeof(int), 1, f);
}
