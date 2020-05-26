#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OK 0
#define ERROR 1
#define MAX_SIZE 256
#define MAX_SIZE_WORLD 16

void my_strtok(char *str, char *limiters, char **p_str, int *count_world, int *out);
int my_strpbrk(char str1, char *str2);
void transform(char *a, char **ap);
void duplicate_check(char **word_matrix, int *size);
void result(int count_world1, int count_world2, char **ap_str1, char **ap_str2);
void add_str(char **p_str, char *buf_str, int *count_world, int *out);

int main()
{
    int out = OK;

    char str1[MAX_SIZE];
    char str2[MAX_SIZE];

    int count_world1 = 0;
    int count_world2 = 0;

    char a_str1[MAX_SIZE];
    char *ap_str1[MAX_SIZE_WORLD];
    transform(a_str1, ap_str1);

    char a_str2[MAX_SIZE];
    char *ap_str2[MAX_SIZE_WORLD];
    transform(a_str2, ap_str2);

    char limiters[] = ",;:-.!? ";

    puts("Input first string: ");
    char *check_input_str1 = fgets(str1, MAX_SIZE, stdin);

    puts("Input second string: ");
    char *check_input_str2 = fgets(str2, MAX_SIZE, stdin);

    size_t str1_len = 0;
    size_t str2_len = 0;

    if (check_input_str1 != NULL && check_input_str2 != NULL && strrchr(str1, '\n') != NULL && strrchr(str2, '\n') != NULL)
    {
        my_strtok(str1, limiters, ap_str1, &count_world1, &out);
        duplicate_check(ap_str1, &count_world1);

        my_strtok(str2, limiters, ap_str2, &count_world2, &out);

        str1_len = strlen(str1);
        str2_len = strlen(str2);
    }
    else
        out = ERROR;

    if (count_world1 != 0 && count_world2 != 0 && ap_str1[0][0] != '\n' && ap_str2[0][0] != '\n' && str1_len <= MAX_SIZE && str2_len <= MAX_SIZE && out == OK)
        result(count_world1, count_world2, ap_str1, ap_str2);
    else
        out = ERROR;

    return out;
}

void transform(char *a, char **ap)
{
    for (int i = 0; i < MAX_SIZE_WORLD; i++)
        ap[i] = a + i * MAX_SIZE_WORLD;
}

void my_strtok(char *str, char *limiters, char **p_str, int *count_world, int *out)
{
    int flag = 0;

    int i = 0;
    while (str[i] != '\n' && !(*out))
    {
        char buf_str[MAX_SIZE_WORLD] = "";

        while (str[i] != '\n' && !my_strpbrk(*(str + i), limiters))
        {
            flag = 1;
            strncat(buf_str, str + i, 1);
            i++;
        }

        if (flag)
        {
            add_str(p_str, buf_str, count_world, out);

            flag = 0;
            (*count_world)++;
        }
        if (str[i] != '\n')
            i++;
    }
}

int my_strpbrk(char str1, char *str2)
{
    int j = 0;
    int flag = 1;
    int position;

    while (flag && str2[j])
    {
        if (str1 == str2[j])
        {
            flag = 0;
            position = 1;
        }
        j++;
    }
    if (flag)
        position = 0;

    return position;
}

void duplicate_check(char **word_matrix, int *size)
{
    for (int i = 0; i < *size - 1; i++)
    {
        for (int j = i + 1; j < *size; j++)
        {
            if (strcmp(word_matrix[i], word_matrix[j]) == 0)
            {
                for (int k = j; k < *size - 1; k++)
                    word_matrix[k] = word_matrix[k + 1];

                (*size)--;
                j--;
            }
        }
    }
}

void result(int count_world1, int count_world2, char **ap_str1, char **ap_str2)
{
    puts("Result:");

    for (int i = 0; i < count_world1; i++)
    {
        int flag = 1;

        for (int j = 0; flag && j < count_world2; j++)
        {
            if (strcmp(ap_str1[i], ap_str2[j]) == 0)
            {
                printf("%s yes\n", ap_str1[i]);
                flag = 0;
            }
        }

        if (flag)
        {
            printf("%s no\n", ap_str1[i]);
        }
    }
}

void add_str(char **p_str, char *buf_str, int *count_world, int *out)
{
    int j = 0;
    while (buf_str[j] && buf_str[j] != '\n')
    {
        p_str[*count_world][j] = buf_str[j];
        j++;
    }

    p_str[*count_world][j] = 0;

    if (j > MAX_SIZE_WORLD)
        *out = ERROR;
}
