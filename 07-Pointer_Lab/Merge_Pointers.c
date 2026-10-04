#include <stdio.h>
#include <stdlib.h>

int main()
{

    int k;
    int s1 = 0;
    int s2 = 0;
    printf("size for 1st array: ");
    scanf("%d", &s1);

    printf("size for 2nd array: ");
    scanf("%d", &s2);

    printf("Input for 1ST Array (space separated ints):\n");
    int *arr1 = (int *)malloc(s1 * sizeof(int));
    int *arr2 = (int *)malloc(s2 * sizeof(int));
    int *arr3 = (int *)malloc((s1 + s2) * sizeof(int));

    for (int i = 0; i < s1; i++)
    {
        scanf("%d", (arr1 + i));
        *(arr3 + i) = *(arr1 + i);
    }

    printf("Input for 2ND Array (space separated ints):\n");
    for (int i = 0; i < s2; i++)
    {
        scanf("%d", (arr2 + i));
        *(arr3 + s1 + i) = *(arr2 + i);
    }
    // sorting the whole array

    int vMin;
    int vMinIndex;

    for (int i = 0; i < s1 + s2; i++)
    {
        vMin = *(arr3 + i);
        vMinIndex = i;

        for (int j = i + 1; j < s1 + s2; j++)
        {
            if (*(arr3 + j) < vMin)
            {
                vMin = *(arr3 + j);
                vMinIndex = j;
            }
        }
        int t = *(arr3 + i);
        *(arr3 + i) = vMin;
        *(arr3 + vMinIndex) = t;
    }

    printf("Merged Array (sorted): \n");
    for (int i = 0; i < s1 + s2; i++)
    {
        printf("%d ", *(arr3 + i));
    }

    free(arr1);
    free(arr2);
    free(arr3);

    printf("\n");
}