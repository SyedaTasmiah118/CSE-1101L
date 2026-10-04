#include <stdio.h>

int main()
{
    int arr[] = {5, 2, 5, 8, 5, 9, 5};

    int x = 5;
    int y = 100;

    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
            arr[i] = y;
    }

    printf("Modified Array:\n");

    for (int i = 0; i < n; i++)
        printf("%d \n", arr[i]);

    return 0;
}
