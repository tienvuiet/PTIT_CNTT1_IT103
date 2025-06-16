#include<stdio.h>
int main (){
    int a[] ={1,3,4,2,2};
    int x ;
    int n = sizeof(a)/sizeof(a[0]);
    int dem = 0;
    int dem2=0;
    printf("nhap phan tu muon tim kiem: ");
    scanf("%d",&x);
    for(int i =0; i<n ;i ++){
        if(a[i]==x){
            dem2++;
        }
    }
    if(dem2==0){
        printf("khong co phan tu trong mang");
        return 0;
    }
    for(int i =0; i<n ; i++){
        if(a[i]==x){
            dem++;
        }
    }
    printf("phần tử %d xuất hiện %d lan", x, dem);
    return 0;
}
//độ phức tạp của thuật toán theo thời gian là O(n) tại vì nó lặp qua n phần tử ở vòng for