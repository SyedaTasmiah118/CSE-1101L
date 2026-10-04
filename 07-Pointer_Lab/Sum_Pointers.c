#include <stdio.h>
#include <stdlib.h>

int sum_p(int *p, int n)
{
    if (n <= 0)
    {

        return 0;
    }
    return *(p + n - 1) + sum_p(p, n - 1);
}

int main()
{
    int n;
    printf("Enter your size:\n");
    scanf("%d", &n);
    int *p = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        scanf(" %d", (p + i));
    }
    printf("%d", sum_p(p, n));
    free(p);
    return 0;
}
