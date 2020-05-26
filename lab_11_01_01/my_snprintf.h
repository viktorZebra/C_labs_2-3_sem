#ifndef __MY_SNPRINTF_H__
#define __MY_SNPRINTF_H__

#define ERROR -1
#define OK 0
int my_snprintf(char *buffer, int buf_size, const char *format, ...);
int is_equ(int a, int b);
int correct_buf(char *buffer, int buf_size, int count);

#endif
