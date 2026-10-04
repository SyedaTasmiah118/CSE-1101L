#include <stdio.h>

void arr_rev(int arr[], int i)
{

    if (i < 0)
    {
        return;
    }

    printf(" %d ", arr[i]);
    arr_rev(arr, i - 1);
}

int main()
{

    int arr[5] = {12, 13, 14, 15, 16};
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("Reversed array:");
    arr_rev(arr, size - 1);

    return 0;
}
