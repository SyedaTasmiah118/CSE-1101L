#include <stdio.h>
#include <stdlib.h>

int main()
{

    int s = 0;
    printf("size : ");
    scanf("%d", &s);
    printf("Now give your inputs (space separated ints):\n");
    int *arr = (int *)malloc(s * sizeof(int));

    for (int i = 0; i < s; i++)
    {
        scanf("%d", (arr + i));
    }

    // first sorting the whole array

    int vMin;
    int vMinIndex;

    for (int i = 0; i < s; i++)
    {
        vMin = *(arr + i);
        vMinIndex = i;

        for (int j = i + 1; j < s; j++)
        {
            if (*(arr + j) < vMin)
            {
                vMin = *(arr + j);
                vMinIndex = j;
            }
        }
        int t = *(arr + i);
        *(arr + i) = vMin;
        *(arr + vMinIndex) = t;
    }

    printf("\n\ncurrent arr(after sorting):\n");

    for (int i = 0; i < s; i++)
    {
        printf("%d ", *(arr + i));
    }
    printf("\n");

    // Now removing all duplicates and creating a set
    int *uniqueArr = (int *)malloc(s * sizeof(int));
    int indexForUniqueArr = 0;
    for (int i = 0; i < s; i++)
    {
        if (i == 0)
        {
            *(uniqueArr + i) = *(arr + i);
            continue;
        }
        if (*(uniqueArr + indexForUniqueArr) != *(arr + i))
        {
            *(uniqueArr + indexForUniqueArr + 1) = *(arr + i);
            indexForUniqueArr++;
        }
    }

    printf("Array without duplicates:\n");

    for (int i = 0; i <= indexForUniqueArr; i++)
    {
        printf("%d ", *(uniqueArr + i));
    }

    printf("\n");
    free(arr);
    free(uniqueArr);

    return 0;
}