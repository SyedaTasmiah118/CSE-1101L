#include <stdio.h>

void main()
{
    float v;
    int p;
    float total, pay, dis;
    int disp;

    printf("Enter cart value: \n");
    scanf("%f", &v);
    printf("Enter user point: \n");
    scanf("%d", &p);

    if (v > 5000)
    {
        if (v * 0.2 > 1200)
        {
            dis = 1200;
        }
        else
            dis = 5000 * 0.2;
    }
    else if (2000 <= v && v <= 3000)
    {
        if (v == 2027)
        {
            dis = 270;
        }
        else
        {
            dis = v * 0.05;
        }
    }
    else if (v >= 500 || (v > 3000 && v < 5000))
    {
        dis = 50;
    }

    disp = p / 400;
    pay = v - dis;

    if (disp > pay)
    {
        p = (disp - pay) * 400;
        dis = dis + disp - pay;
    }
    else
    {
        dis = dis + p / 400;
        p = pay / 400 + p % 400;
    }

    total = v - dis;

    if (total < 0)
    {
        total = 0;
    }

    printf("Payable amount: %f \n", total);
    printf("Discount: %f\n", dis);
    printf("Updated user point: %d \n", p);
}
