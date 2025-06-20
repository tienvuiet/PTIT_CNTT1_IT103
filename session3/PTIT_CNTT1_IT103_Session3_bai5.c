#include <stdio.h>
#include <stdlib.h>

int tongCheoChinh(int a[0][100], int rows, int cols)
{
    int tongCheoC = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (i == j)
            {
                tongCheoC += a[i][j];
            }
        }
    }
    return tongCheoC;
}

int tongCheoPhu(int a[0][100], int rows, int cols)
{
    int tongCheoP = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = cols - i - 1; j >= 0; j--)
        {
            tongCheoP += a[i][j];
            break;
        }
    }
    return tongCheoP;
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
    if (rows == cols)
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                printf("a[%d][%d]: ", i, j);
                scanf("%d", &a[i][j]);
            }
        }
        printf("cac gia tri vua nhap la:\n");
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                printf("%d ", a[i][j]);
            }
            printf("\n");
        }
        int ketCheoChinh = tongCheoChinh(a, rows, cols);
        int ketCheoPhu = tongCheoPhu(a, rows, cols);
        printf("tong duong cheo chinh la: %d", ketCheoChinh);
        printf("tong duong cheo phu la: %d", ketCheoPhu);
    }else{
        printf("khong ton tai duong cheo chinh, duong cheo phu");
        return 1;
    }

    return 0;
}