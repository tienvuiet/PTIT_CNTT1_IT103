#include <stdio.h>
int sum(int n)
{
    if (n == 0)
    {
        return 0;
    }
    return n+sum(n-1);
}
int main (){
    int n ;
    printf("nhap vao phan tu muon tinh tong: ");
    scanf("%d", &n);
    int ketQua = sum(n);
    printf("%d",ketQua);
    return 0;
}