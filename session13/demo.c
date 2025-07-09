#include <stdio.h>

#include <stdlib.h>
// cau truc du lieu stack
typedef struct Stack
{
    // mang dai dien cho ngan xep
    int *arr;
    // chi so phan tu dau ngan xep
    int top;
    // kich thuoc cua ngan xep
    int cap;
} Stack;

// xay dung ham khoi tao Stack
Stack *createStack(int cap)
{
    // b1: cap phat bo nho cho Stack
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    // b2: gan cac gia tri thuoc ve stack( top, cap)
    stack->top = -1;
    stack->cap = cap;
    // b3: Cap phat bo nho cho mang dai dien
    stack->arr = (int *)malloc(sizeof(int) * cap);
    // b4: tra ve dia chi ngan xep
    return stack;
}

// kiem tra day stack
int isFull(Stack *stack)
{
    if (stack->top == stack->cap - 1)
    {
        return 1;
    }
    return 0;
}

// xay dung ham them phan tu vao stack
int push(Stack *stack, int val)
{
    // b1: kiem tra tran ngan xep
    if (isFull(stack))
    {
        printf("stack overflow");
        return 0;
    }
    // 1 dai dien cho sai 0 dai dien cho dung
    // b2: tien hanh them phan tu vao stack
    // b2.1: cap nhat gia tri top
    stack->top = stack->top + 1;
    // b2.2: dia phan tu vao mang
    stack->arr[stack->top] = val;
    // b2.3: tra ve ket qua
    return 1;
}

// ham lay phan tu khoi stack
// kiem tra ngan xep trong
int isEmpty(Stack *stack)
{
    if (stack->top == -1)
    {
        return 1;
    }
    return 0;
}
// lay pahn tu khoi stack
int pop(Stack *stack)
{
    // b1: kiem tra ngan xep trong
    if (isEmpty(stack))
    {
        printf("stack underflow");
        return 0;
    }
    // b2: lay phan tu dau ngan xep
    // b2.1: cap nhat gia tri top
    stack->top = stack->top - 1;
    // b2.2: tra ve gia tri duoc lay ra
    return stack->arr[stack->top + 1];
}

// ham xem phan tu tren cung stack
int peek(Stack *stack)
{
    // b1: kiem tra danh sach trong
    if (isEmpty(stack))
    {
        printf("stack underflow");
        return 0;
    }
    // b2: tra ve phan tu co chi so la top
    return stack->arr[stack->top];
}
int main()
{
    Stack *stack = createStack(3);
    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    //thu them khi stack da day
    push(stack,40);

    printf("phan tu tren cung la: %d\n", peek(stack));
    printf("lay phan tu ra: %d\n", pop(stack));
    printf("lay phan tu ra: %d\n", pop(stack));
    printf("lay phan tu ra: %d\n", pop(stack));

    //thu pop khi stack rong
    pop(stack);
    return 0;
}
// #define MAX 100
// //trien khai ngan xep doi voi cau truc mang
// //khai bao mang
// int Stack[MAX];
// //khai bao dinh nghia bien top
// int top = -1;
// // ham kiem tra xem ngan xep co rong ko
// int isEmpty(){
//     if(top == -1){
//         return 1;
//     }
//     return 0;
// }
// // kiem tra xem ngan xep da day hay chua
// int isFull(){
//     if(top==MAX-1){
//         return 1;
//     }
//     return 0;
// }
// // ham them phan tu vao trong ngan xep
// void push (int x){
//     // khi them phan tu vao trong ngan xep, phai kiem tra xem ngan xep da day hay chua
//     if(isFull()){
//         return ;
//     }
//     top+=1;
//     Stack[top]=x;

// }
// //lay phan tu dinh ra
// int pop(){
//     if(isEmpty()){
//         return -1;
//     }
//     int temp = Stack[top];
//     top--;
//     return temp;

// }
// int main (){
//     int n = 5; //them 5 phan tu vao trong ngan xep
//     while(n--){
//         int t;
//         scanf("%d", &t);
//         push(t);

//     }
//     //hien thi cac phan tu trong ngan xep
//     while(!isEmpty()){
//         printf("%d", pop());
//     }
//     return 0;
// }