#include<stdio.h>
int tuyenTinh(int arr[], int n, int m ){
    for(int i=0; i< n ; i++){
        if(arr[i]==m){
            return i+1;
            break;
        }
    }
    return 0;
}
int main (){
    int n ;
    printf("nhap vao so luong phan tu mang: \n");
    scanf("%d", &n);
    int a[n];
    for(int i = 0; i< n ; i++){
    printf("a[%d]: ", i);
    scanf("%d",&a[i]);
    }
    int m ; 
    printf("nhap vao phan tu muon tim kiem: ");
    scanf("%d", &m);
    int ketQua = tuyenTinh(a, n , m);
    if(ketQua){
        printf("vi tri thu %d", ketQua);
    }else{
        printf("khong ton tai phan tu");
    }
    return 0;
}