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
int push(Stack *stack, int val)
{
    if (isFull(stack))
    {
        printf("stack overflow");
        return 0;
    }
    stack->top = stack->top + 1;
    stack->arr[stack->top] = val;
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
int pop(Stack *stack){
    if(isEmpty(stack)){
        printf("stack underflow");
        return 0;
    }
    stack->top = stack->top-1;
    return stack->arr[stack->top+1];
}
int dauHopLe(char *str){
    Stack *stack = createStack(strlen(str));
    for(int i = 0 ; i< str[i]!='\0'; i++){
        char c = str[i];
        if(c=='('||c=='['||c=='{'){
            push(stack, c);
        }
        else if(c==')'||c==']'||c=='}'){
            if(isEmpty(stack)){
                return 0;
            }
            char top = pop(stack);
            if((c==')' && top!='(')||(c==']' && top!='[')||(c=='}' && top!='{')){
                return 0;
            }
        }
    }
    return isEmpty(stack);
}
int main()
{
    char str[100];
    fgets(str, sizeof(str), stdin);
    
    if(dauHopLe(str)){
        printf("true");

    }else{
        printf("false");
    }
    return 0;
}