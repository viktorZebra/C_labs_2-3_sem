#include <stdio.h>
int nod(int m, int n);

int main()
{
    int m, n, rt;

    puts("Input numbers: ");
    int rc = scanf("%d %d", &m, &n);

    if ((rc == 2) && (m > 0) && (n > 0))
    {
        printf("NOD is: %d", nod(m, n));
        rt = 0;
    }
    else
    {
        printf("Input error");
        rt = 1;
    }

    return rt;
}

int nod(int m, int n)
{
    while ((m != 0) && (n != 0))
    {
        if (m > n)
            m = m % n;
        else
            n = n % m;
    }

    return m + n;
}
