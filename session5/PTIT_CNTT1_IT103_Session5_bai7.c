#include <stdio.h>
int inFibonaci(int n)
{
    if (n == 0)
    {
        return 0;
    }
    if(n==1){
        return 1;
    }
    return inFibonaci(n-1)+inFibonaci(n-2);
}
int main()
{
    int n;
    printf("nhap vao so nguyen duong bat ki: ");
    scanf("%d", &n);
    if(n<=0){
        printf("input khong hop le!!");
        return 1;
    }
    int a[100];
    for(int i =0 ; i< n ; i++){
        a[i]=inFibonaci(i);
    }
    printf("mang fibonaci: ");
    for(int i =0; i< n ; i++){
        printf("%d, ",a[i]);
    }
    return 0;
}