#include<stdio.h>
int fibonacci(int n ){
    if(n==0){
        return 0;
    }
    if(n==1){
        return 1;
    }
    return fibonacci(n-2)+fibonacci(n-1);
}
int main(){
    int n ; 
    printf("nhap vao so nguyen duong bat ki: ");
    scanf("%d", &n);
    if(n<=0){
        printf("input ko hop le");
        return 1;

    }
    int a[n];
    for(int i = 0; i< n ; i++){
        a[i]=fibonacci(i);
    }
    for(int i =n-1 ; i>=0; i--){
        printf("%d, ", a[i]);
    }
    return 0;

}