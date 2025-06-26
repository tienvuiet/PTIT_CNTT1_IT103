#include<stdio.h>
int ketQua(int n ){

    if(n==1){
        return 1;
    }
    return n*ketQua(n-1);
}
int main(){
   int n ;
   printf("nhap so nguyen duong bat ki: " );
   scanf("%d", &n);
   if(n<0){
    printf("khong hop le");
    return 1;
   }
   int tong = ketQua(n);
   printf("%d", tong);
   return 0;
}