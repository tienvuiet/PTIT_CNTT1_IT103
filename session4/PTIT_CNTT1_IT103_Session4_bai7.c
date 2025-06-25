#include <stdio.h>
int main()
{
    int n;

    printf("nhap vao so luong phan tu mang: ");
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        printf("a[%d]: ", i);
        scanf("%d", &a[i]);
    }
    printf("cac phan tu trong mang vua nhap la: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    int countI =0;
    int countJ = 0;
    for(int i =0; i< n/2 ; i++){
        if(a[i]==a[n-1-i]);
        printf("\ndoi xung:(%d, %d) ",a[i], a[n-1-i]);
    }
    return 0;
}