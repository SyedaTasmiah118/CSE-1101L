#include <stdio.h>
#include <stdlib.h>
void arr_rev(int *arr, int i)
{
    if (i < 0)
    {
        return;
    }
    printf("%d ", *(arr + i));
    arr_rev(arr, i - 1);
}
int main()
{
    int size = 5;
    int *arr = (int *)malloc(size * sizeof(int));
    *(arr + 0) = 12;
    *(arr + 1) = 13;
    *(arr + 2) = 14;
    *(arr + 3) = 15;
    *(arr + 4) = 16;
    printf("Reversed array: ");
    arr_rev(arr, size - 1);
    free(arr);
    return 0;
}