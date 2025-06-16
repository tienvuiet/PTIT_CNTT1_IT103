#include<stdio.h>
int main(){
    int a[]={12,2,3,4,1};
    int check = 0 ;
    int n = sizeof(a)/sizeof(a[0]);
    for(int i =0; i<n; i++){
        for(int j =i+1; j<n; j++){
            if(a[i]==a[j]){
                printf("co phan tu trung lap");
                check++;
            }
        }
    }
    
    if(check==0){
        printf("khong co phan tu trung lap");
    }
    //cách 1 độ phức tạp O(n^2) vì có 2 vòng for lồng mỗi phòng chạy n lần  
    for(int i =0; i<n-1; i++){
        for(int j =0; j<n-1-i;j++){
            if(a[j]>a[j+1]){
                int temp = a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    for(int i =0; i< n-1 ; i++){
        if(a[i]==a[i+1]){
            printf("phan tu %d bi trung", a[i]);
        }
    }
    //cach 2 do phuc tap O(n) vì n -1 thi khong tinh he so lên con n 
    return 0;
}