#include <stdio.h>
#include <stdlib.h>
int tongHangMang(int a[][100], int rows, int cols, int k)
{
    
    int tong = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (i = k - 1)
            {
                tong += a[i][j];
            }
        }
    }
    return tong;
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
    for(int i =0 ; i<rows; i++){
        for(int j =0; j<cols; j++){
            printf("a[%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
    printf("mang sau khi nhap la: \n");
    for(int i =0; i<rows; i++){
        for(int j =0; j<cols; j++){
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    int k;
    printf("nhap hang can tinh: ");
    scanf("%d", &k);
    int ketQua = tongHangMang(a, rows, cols, k);
    if (k > rows||k<0)
    {
        printf("hang can tinh khong ton tai");
        return 1;
    }else{
        printf("sum = %d", ketQua);
    }
    return 0;
}