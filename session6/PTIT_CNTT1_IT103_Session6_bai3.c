#include<stdio.h>
int sum(int n){
    if(n%10==0){
        return 0;
    }
    return n%10 +sum(n/10);
}
int main(){
    int n ; 
    printf("nhap vao so nguyen duong n: ");
    scanf("%d", &n);
    int ketQua = sum(n);
    printf("ket qua tong: %d",ketQua);
    return 0;
}