#include <stdio.h>
#include "main_processing.h"

int main()
{
    FILE *in_1 = fopen("in1.txt", "r");
    printf("%d\n", main_processing(in_1));
    fclose(in_1);

    FILE *in_2 = fopen("in2.txt", "r");
    printf("%d\n", main_processing(in_2));
    fclose(in_2);

    FILE *in_3 = fopen("in3.txt", "r");
    printf("%d\n", main_processing(in_3));
    fclose(in_3);

    FILE *in_4 = fopen("in4.txt", "r");
    printf("%d\n", main_processing(in_4));
    fclose(in_4);

    FILE *in_5 = fopen("in5.txt", "r");
    printf("%d\n", main_processing(in_5));
    fclose(in_5);

    FILE *in_6 = fopen("in6.txt", "r");
    printf("%d\n", main_processing(in_6));
    fclose(in_6);

    FILE *in_7 = fopen("in7.txt", "r");
    printf("%d\n", main_processing(in_7));
    fclose(in_7);

    FILE *in_8 = fopen("in8.txt", "r");
    printf("%d\n", main_processing(in_8));
    fclose(in_8);

    FILE *in_9 = fopen("in9.txt", "r");
    printf("%d\n", main_processing(in_9));
    fclose(in_9);

    return 0;
}
