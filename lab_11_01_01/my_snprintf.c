#include <stdarg.h>
#include <string.h>
#include "my_snprintf.h"

int my_snprintf(char *buffer, int buf_size, const char *format, ...)
{
    int code_err = ERROR;
    int len_format = 0;


    va_list va;
    va_start(va, format);

    int j = 0;
    for (int i = 0; i < strlen(format); i++)
    {
        if (format[i] == '%')
        {
            if (format[i + 1] == 'c')
            {
                if (correct_buf(buffer, buf_size, i))
                {
                    buffer[j] = va_arg(va, int);
                    j++;
                    i++;
                }
                len_format++;
            }
            else if (format[i + 1] == '%')
            {
                if (correct_buf(buffer, buf_size, i))
                {
                    buffer[j] = '%';
                    j++;
                    i++;
                }
                len_format++;
            }
        }
        else
        {
            if (correct_buf(buffer, buf_size, i))
            {
                buffer[j] = format[i];
                j++;
            }
            len_format++;
        }
    }
    if (buffer && buf_size - 1)
    {
        buffer[j] = 0;
    }
    va_end(va);

    code_err = len_format;

    return code_err;
}

int is_equ(int a, int b)
{
    int code_return = ERROR;

    if (a == b)
        code_return = OK;

    return code_return;
}

int correct_buf(char *buffer, int buf_size, int count)
{
    int code_err = 0;
    if (buffer && buf_size - 1 && count < buf_size - 1)
        code_err = 1;
    return code_err;
}
