#include<stdio.h>
int main(){
   int n =5;
   int sum =0;
   for(int i =0;i<n;i++){
    sum+=i;
   }
   printf("tong cach 1: %d ", sum);
   //cách 1 độ phức tạp O(n) vì nó chạy qua n lần, mỗi vòng thực hiện 1 phép cộng
   //
   int tong2 = n*(n+1)/2;
   printf("tong cach 2: %d",tong2);
   //cach 2 do phuc tap O(1), 1 phép tính toán toán học
}
