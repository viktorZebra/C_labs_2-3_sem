#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my_snprintf.h"


int main()
{
    char buffer[100] = { 0 };
    char my_buffer[100] = { 0 };

    int size = snprintf(buffer, 4, "you shall not pass");
    int my_size = my_snprintf(my_buffer, 4, "you shall not pass");

    printf("%d\n", strcmp(buffer, my_buffer));
    printf("%d\n\n", is_equ(size, my_size));

    return 0;
}
