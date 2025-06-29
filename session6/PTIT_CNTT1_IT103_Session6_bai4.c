#include<stdio.h>
void thapHN(int n , int cot1, int cotTG, int cot3){
    if(n==1){
        printf("chuyen dia %d tu cot %d sang cot %d\n",n,cot1,cot3);
        return ;
    }
    thapHN(n-1, cot1, cot3, cotTG);
    printf("chuyen dia %d tu cot %d sang cot %d\n", n , cot1, cot3);
    thapHN(n-1, cotTG, cot1, cot3);
}
int main(){
    int n ;
    printf("nhap so dia: ");
    scanf("%d", &n);
    if(n<=0){
        printf("input khong hop le");
        return 1;
    }
    thapHN(n,1,2,3);
    return 0;
}