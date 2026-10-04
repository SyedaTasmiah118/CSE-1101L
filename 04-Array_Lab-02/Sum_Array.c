#include <stdio.h>

int sum_arr(int arr[], int n)
{

    if (n == 0)
        return 0;
    return arr[n - 1] + sum_arr(arr, n - 1);
}

int main()
{

    int arr[] = {23, 34, 19, 26, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Sum = %d\n", sum_arr(arr, n));

    return 0;
}
