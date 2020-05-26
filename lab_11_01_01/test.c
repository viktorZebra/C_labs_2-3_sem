#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my_snprintf.h"

int main()
{
    char buffer[100] = { 0 };
    char my_buffer[100] = { 0 };

    int size = snprintf(buffer, 100, "hello world");
    int my_size = my_snprintf(my_buffer, 100, "hello world");

    printf("%d\n", strcmp(buffer, my_buffer));
    printf("%d\n\n", is_equ(size, my_size));

    size = snprintf(NULL, 0, "hello world");
    my_size = my_snprintf(NULL, 0, "hello world");

    printf("%d\n\n", is_equ(size, my_size));

    size = snprintf(buffer, 100, "hello %c%c world", 'm', 'y');
    my_size = my_snprintf(my_buffer, 100, "hello %c%c world", 'm', 'y');

    printf("%d\n", strcmp(buffer, my_buffer));
    printf("%d\n\n", is_equ(size, my_size));

    size = snprintf(buffer, 100, "%c hello %c%c world", 'i', 'm', 'y');
    my_size = my_snprintf(my_buffer, 100, "%c hello %c%c world", 'i', 'm', 'y');

    printf("%d\n", strcmp(buffer, my_buffer));
    printf("%d\n\n", is_equ(size, my_size));

    size = snprintf(buffer, 100, " ");
    my_size = my_snprintf(my_buffer, 100, " ");

    printf("%d\n", strcmp(buffer, my_buffer));
    printf("%d\n\n", is_equ(size, my_size));

    size = snprintf(buffer, 100, "%c hello %c%c world", '\0', 'm', 'y');
    my_size = my_snprintf(my_buffer, 100, "%c hello %c%c world", '\0', 'm', 'y');

    printf("%d\n", strcmp(buffer, my_buffer));
    printf("%d\n\n", is_equ(size, my_size));

    size = snprintf(buffer, 100, "%c hello %c%c world", '\0', '\n', 'y');
    my_size = my_snprintf(my_buffer, 100, "%c hello %c%c world", '\0', '\n', 'y');

    printf("%d\n", strcmp(buffer, my_buffer));
    printf("%d\n\n", is_equ(size, my_size));

    size = snprintf(buffer, 100, "%c hello %c%c world", '\0', '\n', '\r');
    my_size = my_snprintf(my_buffer, 100, "%c hello %c%c world", '\0', '\n', '\r');

    printf("%d\n", strcmp(buffer, my_buffer));
    printf("%d\n\n", is_equ(size, my_size));

    size = snprintf(buffer, 100, "%c hello %c%c world%c", '\0', '\n', '\r', '\t');
    my_size = my_snprintf(my_buffer, 100, "%c hello %c%c world%c", '\0', '\n', '\r', '\t');

    printf("%d\n", strcmp(buffer, my_buffer));
    printf("%d\n\n", is_equ(size, my_size));

    size = snprintf(buffer, 100, "%c hello %c%c world%c", '\t', '\n', '\0', '\t');
    my_size = my_snprintf(my_buffer, 100, "%c hello %c%c world%c", '\t', '\n', '\0', '\t');

    printf("%d\n", strcmp(buffer, my_buffer));
    printf("%d\n\n", is_equ(size, my_size));

    size = snprintf(buffer, 100, "%c %c hello %c%c world", '\r', '\0', '\n', 'y');
    my_size = my_snprintf(my_buffer, 100, "%c %c hello %c%c world", '\r', '\0', '\n', 'y');

    printf("%d\n", strcmp(buffer, my_buffer));
    printf("%d\n\n", is_equ(size, my_size));

    size = snprintf(buffer, 100, "%c %c hello %c%c%c world", '\r', 'w', '\0', '\n', 'y');
    my_size = my_snprintf(my_buffer, 100, "%c %c hello %c%c%c world", '\r', 'w', '\0', '\n', 'y');

    printf("%d\n", strcmp(buffer, my_buffer));
    printf("%d\n\n", is_equ(size, my_size));

    size = snprintf(buffer, 100, "%c hello world", '\0');
    my_size = my_snprintf(my_buffer, 100, "%c hello world", '\0');

    printf("%d\n", strcmp(buffer, my_buffer));
    printf("%d\n\n", is_equ(size, my_size));

    size = snprintf(buffer, 100, "%c hello world", '\r');
    my_size = my_snprintf(my_buffer, 100, "%c hello world", '\r');

    printf("%d\n", strcmp(buffer, my_buffer));
    printf("%d\n\n", is_equ(size, my_size));

    size = snprintf(buffer, 100, "%c hello world", '\t');
    my_size = my_snprintf(my_buffer, 100, "%c hello world", '\t');

    printf("%d\n", strcmp(buffer, my_buffer));
    printf("%d\n\n", is_equ(size, my_size));

    size = snprintf(buffer, 100, "%c hello world", '\n');
    my_size = my_snprintf(my_buffer, 100, "%c hello world", '\n');

    printf("%d\n", strcmp(buffer, my_buffer));
    printf("%d\n\n", is_equ(size, my_size));

    return 0;
}
