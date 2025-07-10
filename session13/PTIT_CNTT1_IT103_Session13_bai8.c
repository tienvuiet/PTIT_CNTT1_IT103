#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Stack
{
    int *arr;
    int top;
    int cap;
} Stack;
Stack *createStack(int cap)
{
    Stack *newStack = (Stack *)malloc(sizeof(Stack));
    newStack->top = -1;
    newStack->cap = cap;
    newStack->arr = (int *)malloc(sizeof(int) * cap);
    return newStack;
}
int isFull(Stack *stack)
{
    if (stack->top == stack->cap - 1)
    {
        return 1;
    }
    return 0;
}
int push(Stack *stack, int data)
{
    if (isFull(stack))
    {
        printf("stack overflow");
        return 0;
    }
    stack->top = stack->top + 1;
    stack->arr[stack->top] = data;
    return 1;
}
int isEmpty(Stack *stack)
{
    if (stack->top == -1)
    {
        return 1;
    }
    return 0;
}
int pop(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("stack underflow");
        return 0;
    }
    stack->top = stack->top - 1;
    return stack->arr[stack->top + 1];
}
// int dauNgoac(char* str){
//     int len = strlen(str);
//     Stack* stack = createStack(len);
//     for(int i = 0 ; i< len ; i++){
//         if(str[i]=='('||str[i]=='['||str[i]=='{'){
//             push(stack, str[i]);
//         }
//     }
//     for(int i =0 ; i< len; i++){
//         if(pop(str[i]))
//     }
// }
int main()
{
    char str[100];
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")]='\0';

    return 0;
}