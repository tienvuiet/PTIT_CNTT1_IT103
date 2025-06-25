#include<stdio.h>
int main (){
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
    int index = 0;
    int number ;
    int count = 0;
    printf("nhap vao so muon tim: ");
    scanf("%d", &number);
    for(int i = n-1; i>=0; i--){
        if(a[i]==number){
            index = i ;
            count ++;
            break;
        }
    }
    if(count !=0){
        printf("%d", index);
    }else{
        printf("khong tim thay phan tu trong mang");
        return 1;
    }
    return 0;
}