#include <stdio.h>
#include <stdlib.h>
int timMax(int a[][100], int rows, int cols)
{
    int max = a[0][0];
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (a[i][j] > max)
            {
                max = a[i][j];
            }
        }
    }
    return max;
}

int timMin(int a[][100], int rows, int cols)
{
    int min = a[0][0];
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (a[i][j] < min)
            {
                min = a[i][j];
            }
        }
    }
    return min;
}
int main()
{
    int rows, cols;
    int a[100][100];
    printf("nhap vao so hang: ");
    scanf("%d", &rows);
    printf("nhap vao so cot: ");
    scanf("%d", &cols);
    if (rows < 0)
    {
        printf("so hang khong hop le");
    }
    else if (cols < 0)
    {
        printf("so cot khong hop le");
    }
    else if (cols == 0 && rows == 0)
    {
        printf("so hang va so cot khong hop le");
    }
    for(int i =0; i< rows; i++){
        for(int j =0; j<cols; j++){
            printf("a[%d][%d]: ", i,j);
            scanf("%d", &a[i][j]);
        }
    }
    printf("cac gia tri vua nhap la:\n");
    for(int i =0; i<rows; i++){
        for(int j = 0; j<cols; j++){
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    int ketQuaMax = timMax(a, rows, cols);
    int ketQuaMin = timMin(a, rows, cols);
    printf("max = %d\n", ketQuaMax);
    printf("min = %d", ketQuaMin);
    return 0;
}