#include <stdio.h>
#include <stdlib.h>
void merge(int *arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));
    for (int i = 0; i < n1; i++)
        *(L + i) = *(arr + left + i);
    for (int j = 0; j < n2; j++)
        *(R + j) = *(arr + mid + 1 + j);
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (*(L + i) <= *(R + j))
            *(arr + k++) = *(L + i++);
        else
            *(arr + k++) = *(R + j++);
    }
    while (i < n1)
        *(arr + k++) = *(L + i++);
    while (j < n2)
        *(arr + k++) = *(R + j++);
    free(L);
    free(R);
}
void mergeSort(int *arr, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);

        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}
int main()
{
    int n = 7;
    int *arr = (int *)malloc(n * sizeof(int));
    *(arr + 0) = 38;
    *(arr + 1) = 27;
    *(arr + 2) = 43;
    *(arr + 3) = 3;
    *(arr + 4) = 9;
    *(arr + 5) = 82;
    *(arr + 6) = 10;
    mergeSort(arr, 0, n - 1);
    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", *(arr + i));
    free(arr);
    return 0;
}