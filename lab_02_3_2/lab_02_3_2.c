#include <stdio.h>

struct point
{
    double x;
    double y;
};
int position(struct point*a, struct point*b, struct point*c);

int main()
{
    int rt;
    struct point pn1;
    struct point pn2;
    struct point pn3;

    puts("Input coordinates: ");
    int rc = scanf("%lf %lf %lf %lf %lf %lf", &pn1.x, &pn1.y, &pn2.x, &pn2.y, &pn3.x, &pn3.y);

    if ((rc == 6) && ((pn1.x != pn2.x) || (pn1.y != pn2.y)))
    {
        printf("Position is: %d", position(&pn1, &pn2, &pn3));
        rt = 0;
    }
    else
    {
        puts("Input error");
        rt = 1;
    }

    return rt;
}

int position(struct point*a, struct point*b, struct point*c)
{
    int rt;
    int pos = (a->y - b->y) * c->x + (b->x - a->x) * c->y + (a->x * b->y - b->x * a->y);

    if (pos > 0)
        rt = 0;
    else if (pos < 0)
        rt = 2;
    else
        rt = 1;

    return rt;
}
