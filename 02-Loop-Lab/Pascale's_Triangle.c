#include <stdio.h>

int main()
{
    int n, i, j, space;
    int v;

    printf("Enter row number: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {

       
        for (space = 1; space <= n - i; space++)
        {
            printf("  "); 
        }

        v = 1;

        for (j = 0; j <= i; j++)
        {
          
            v = v * (i - j) / (j + 1);
        }
        printf("\n");
    }

    return 0;
}