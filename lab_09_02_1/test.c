#include <stdio.h>
#include <stdlib.h>
#include "main_processing.h"

int main()
{
    FILE *f_in = fopen("in1.txt", "r");
    FILE *f_out = fopen("out1.txt", "w");
    printf("%d\n", processing(f_in, f_out));
    fclose(f_in);
    fclose(f_out);

    f_in = fopen("in2.txt", "r");
    f_out = fopen("out2.txt", "w");
    printf("%d\n", processing(f_in, f_out));
    fclose(f_in);
    fclose(f_out);

    f_in = fopen("in3.txt", "r");
    f_out = fopen("out3.txt", "w");
    printf("%d\n", processing(f_in, f_out));
    fclose(f_in);
    fclose(f_out);

    f_in = fopen("in1.txt", "r");
    f_out = fopen("out1.txt", "w");
    printf("%d\n", processing(f_in, f_out));
    fclose(f_in);
    fclose(f_out);

    f_in = fopen("in4.txt", "r");
    f_out = fopen("out4.txt", "w");
    printf("%d\n", processing(f_in, f_out));
    fclose(f_in);
    fclose(f_out);

    f_in = fopen("in5.txt", "r");
    f_out = fopen("out6.txt", "w");
    printf("%d\n", processing(f_in, f_out));
    fclose(f_in);
    fclose(f_out);

    f_in = fopen("in1.txt", "r");
    f_out = fopen("out1.txt", "w");
    printf("%d\n", processing(f_in, f_out));
    fclose(f_in);
    fclose(f_out);

    f_in = fopen("in7.txt", "r");
    f_out = fopen("out8.txt", "w");
    printf("%d\n", processing(f_in, f_out));
    fclose(f_in);
    fclose(f_out);

    f_in = fopen("in1.txt", "r");
    f_out = fopen("out1.txt", "w");
    printf("%d\n", processing(f_in, f_out));
    fclose(f_in);
    fclose(f_out);

    f_in = fopen("in9.txt", "r");
    f_out = fopen("out9.txt", "w");
    printf("%d\n", processing(f_in, f_out));
    fclose(f_in);
    fclose(f_out);

    f_in = fopen("in10.txt", "r");
    f_out = fopen("out10.txt", "w");
    printf("%d\n", processing(f_in, f_out));
    fclose(f_in);
    fclose(f_out);

    f_in = fopen("in11.txt", "r");
    f_out = fopen("out11.txt", "w");
    printf("%d\n", processing(f_in, f_out));
    fclose(f_in);
    fclose(f_out);

    f_in = fopen("in12.txt", "r");
    f_out = fopen("out12.txt", "w");
    printf("%d\n", processing(f_in, f_out));
    fclose(f_in);
    fclose(f_out);

    f_in = fopen("in13.txt", "r");
    f_out = fopen("out13.txt", "w");
    printf("%d\n", processing(f_in, f_out));
    fclose(f_in);
    fclose(f_out);

    f_in = fopen("in14.txt", "r");
    f_out = fopen("out14.txt", "w");
    printf("%d\n", processing(f_in, f_out));
    fclose(f_in);
    fclose(f_out);

    return 0;
}
