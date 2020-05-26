#include <stdio.h>
int bottles(int penny);


int main()
{
    int penny;

    puts("Input penny: ");
    scanf("%d", &penny);

    printf("Bottels: %d", bottles(penny));
    return 0;
}

int bottles(int penny)
{
    int int_bottle = 0;

    if (penny >= 45)
    {
        int_bottle = (penny - 20) / 25;
    }

    return (int_bottle);
}
