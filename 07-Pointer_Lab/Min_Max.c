#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n = 7;
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }
    *(arr + 0) = 12;
    *(arr + 1) = 45;
    *(arr + 2) = 7;
    *(arr + 3) = 89;
    *(arr + 4) = 23;
    *(arr + 5) = 5;
    *(arr + 6) = 67;
    int *ptr = arr;
    int min = *ptr;
    int max = *ptr;
    for (int i = 1; i < n; i++)
    {
        if (*(ptr + i) < min)
        {
            min = *(ptr + i);
        }
        if (*(ptr + i) > max)
        {
            max = *(ptr + i);
        }
    }
    printf("Minimum = %d\n", min);
    printf("Maximum = %d\n", max);

    free(arr);
    return 0;
}