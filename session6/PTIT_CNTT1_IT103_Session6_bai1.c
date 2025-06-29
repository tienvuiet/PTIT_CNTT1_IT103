#include<stdio.h>
void nhiPhan(int n ){
    if(n>1){
        nhiPhan(n/2);
    }
    printf("%d", n%2);
}
int main (){
    int n ;
    printf("nhap vao so nguyen duong bat ki: ");
    scanf("%d", &n);
    nhiPhan(n);
    return 0;
}