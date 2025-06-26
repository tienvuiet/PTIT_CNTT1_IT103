#include<stdio.h>
void outValue(int n ){
    if(n<1){
        return ;
    }
    outValue(n-1);
    printf("%d\n", n);
}
int main(){
    int n ;
    printf("nhap gia tri: ");
    scanf("%d",&n);
    outValue(n);
    return 0;
}