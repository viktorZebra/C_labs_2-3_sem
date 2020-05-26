#include <stdio.h>
#include <stdlib.h>

#define ERROR -1
#define OK 0

int process(FILE *f, int  *out);

int main()
{
    int out = OK;

    FILE *f = stdin;
    if (f)
    {
        int max = process(f, &out);

        if (max)
            printf("%d", max);
    }
    else
        out = ERROR;

    fclose(f);

    return out;
}

int process(FILE *f, int *out)
{
    int value;
    int max_value = 0;
    int flag = 0;

    puts("Enter sequence: ");
    while (fscanf(f, "%d", &value) == 1)
    {
        if (value < 0)
        {
            flag = 1;
        }
        if (flag)
        {
            if (value > max_value)
                max_value = value;
        }
    }

    if (!max_value)
        *out = ERROR;

    return max_value;
}
