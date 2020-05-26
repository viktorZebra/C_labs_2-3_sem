#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OK 0
#define ERROR 1

char *my_strpbrk(char *str1, char *str2);

int main(void)
{
    char *tests[7];

    char *test_s1 = "abcd45";
    char *test_s2 = "99";
    tests[0] = test_s1;
    tests[1] = test_s2;

    char *test_s3 = "6g fh";
    char *test_s4 = " ";
    tests[2] = test_s3;
    tests[3] = test_s4;

    char *test_s5 = "54577";
    char *test_s6 = "5888974";
    tests[4] = test_s5;
    tests[5] = test_s6;

    char *test_s7 = "";
    char *test_s8 = "";
    tests[6] = test_s7;
    tests[7] = test_s8;

    for (int i = 0; i < 7; i += 2)
    {
        printf("my_strpbrk result: %s\n", my_strpbrk(tests[i], tests[i + 1]));
        printf("strpbrk result: %s\n\n", strpbrk(tests[i], tests[i + 1]));
    }

    return 0;
}

char *my_strpbrk(char *str1, char *str2)
{
    int i = 0;
    int j = 0;
    int flag = 1;
    char *position;

    while (flag && str1[i])
    {
        while (flag && str2[j])
        {
            if (str1[i] == str2[j])
            {
                flag = 0;
                position = (str1 + i);
            }
            j++;
        }
        j = 0;
        i++;
    }

    if (flag)
        position = NULL;

    return position;
}
