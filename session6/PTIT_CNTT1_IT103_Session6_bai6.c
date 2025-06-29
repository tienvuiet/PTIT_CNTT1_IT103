#include<stdio.h>
int leoCT(int n ){
    if(n == 1||n==0){
        return 1;    
    }
    return leoCT(n-1)+leoCT(n-2);

}
int main(){
    int n ;
    printf("nhap vao so bạc cua cau thang: ");
    scanf("%d", &n);
    int dapAn = leoCT(n);
    printf("%d", dapAn);
    return 0;
}