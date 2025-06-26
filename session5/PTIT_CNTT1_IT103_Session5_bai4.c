#include <stdio.h>

int tongKhoang(int fist, int second)
{
    if (fist > second)
    {
        return 0;
    }
    return fist + tongKhoang(fist + 1, second);
}
int main()
{
    int fist, second;
    printf("phan tu dau tien: ");
    scanf("%d", &fist);
    printf("nhap phan tu thu hai: ");
    scanf("%d", &second);
    if (fist < 0 || second < 0)
    {
        printf("khong hop le");
    }
    int ketQua = tongKhoang(fist,second);
    printf("tong khoang tu %d den %d la: %d", fist,second,ketQua);
    return 0;
}