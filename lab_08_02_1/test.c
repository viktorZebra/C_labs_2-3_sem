#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "def.h"
#include "lib.h"
#include "file_io.h"

int main()
{
    FILE *f_in1 = fopen("in_1.txt", "r");
    processing(f_in1, "out_1.txt");
    fclose(f_in1);

    FILE *f_in2 = fopen("in_2.txt", "r");
    processing(f_in2, "out_2.txt");
    fclose(f_in2);

    FILE *f_in3 = fopen("in_3.txt", "r");
    processing(f_in3, "out_3.txt");
    fclose(f_in3);

    FILE *f_in4 = fopen("in_4.txt", "r");
    processing(f_in4, "out_4.txt");
    fclose(f_in4);

    FILE *f_in5 = fopen("in_5.txt", "r");
    processing(f_in5, "out_5.txt");
    fclose(f_in5);

    FILE *f_in6 = fopen("in_6.txt", "r");
    processing(f_in6, "out_6.txt");
    fclose(f_in6);

    FILE *f_in7 = fopen("in_7.txt", "r");
    processing(f_in7, "out_7.txt");
    fclose(f_in7);

    FILE *f_in8 = fopen("in_8.txt", "r");
    processing(f_in8, "out_8.txt");
    fclose(f_in8);

    FILE *f_in9 = fopen("in_9.txt", "r");
    processing(f_in9, "out_9.txt");
    fclose(f_in9);

    return 0;
}
