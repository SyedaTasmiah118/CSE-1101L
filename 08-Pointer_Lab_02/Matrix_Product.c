#include <stdio.h>
#include <stdlib.h>

int main()
{
    int row = 4, column = 5;
    int **matrix;
    matrix = malloc(row * sizeof(int *));

    for (int i = 0; i < row; i++)
    {
        *(matrix + i) = malloc(column * sizeof(int));
    }

    int k = 1;
    for (int i = 0; i < row; i++)
    {
        int *temp = *(matrix + i);
        for (int j = 0; j < column; j++)
        {
            *(temp + j) = k++;
        }
    }

    printf("First Matrix:\n");
    for (int i = 0; i < row; i++)
    {
        int *temp = *(matrix + i);
        for (int j = 0; j < column; j++)
        {
            printf("%d\t", *(temp + j));
        }
        printf("\n");
    }
    printf("\n");

    int row1 = 5, column1 = 3;
    int **matrix1;
    matrix1 = malloc(row1 * sizeof(int *));

    for (int i = 0; i < row1; i++)
    {
        *(matrix1 + i) = malloc(column1 * sizeof(int));
    }

    int k1 = 21;
    for (int i = 0; i < row1; i++)
    {
        int *temp = *(matrix1 + i);
        for (int j = 0; j < column1; j++)
        {
            *(temp + j) = k1++;
        }
    }

    printf("Second Matrix:\n");
    for (int i = 0; i < row1; i++)
    {
        int *temp = *(matrix1 + i);
        for (int j = 0; j < column1; j++)
        {
            printf("%d\t", *(temp + j));
        }
        printf("\n");
    }
    printf("\n");

    int res_row = row;
    int res_column = column1;

    int **result_matrix;
    result_matrix = malloc(res_row * sizeof(int *));

    for (int i = 0; i < res_row; i++)
    {
        *(result_matrix + i) = malloc(res_column * sizeof(int));
    }

    for (int i = 0; i < res_row; i++)
    {
        int *res_temp = *(result_matrix + i);
        int *mat_temp = *(matrix + i);

        for (int j = 0; j < res_column; j++)
        {
            *(res_temp + j) = 0;

            for (int m = 0; m < column; m++)
            {
                int *mat1_temp = *(matrix1 + m);
                *(res_temp + j) += (*(mat_temp + m)) * (*(mat1_temp + j));
            }
        }
    }

    printf("Resultant Multiplied Matrix:\n");
    for (int i = 0; i < res_row; i++)
    {
        int *temp = *(result_matrix + i);
        for (int j = 0; j < res_column; j++)
        {
            printf("%d\t", *(temp + j));
        }
        printf("\n");
    }
    printf("\n");

    for (int i = 0; i < row; i++)
    {
        free(*(matrix + i));
    }
    free(matrix);

    for (int i = 0; i < row1; i++)
    {
        free(*(matrix1 + i));
    }
    free(matrix1);

    for (int i = 0; i < res_row; i++)
    {
        free(*(result_matrix + i));
    }
    free(result_matrix);

    return 0;
}
