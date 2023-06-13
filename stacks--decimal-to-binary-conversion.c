/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#define MAX 20
typedef struct Stack{
    int top;
    int data [MAX];
}Stack ;

void initialize(Stack *S)
{
    S -> top = -1;
}
int isEmpty(Stack* S)
{
    if (S -> top == -1)
        return 1;
    return 0;
}
int isFull(Stack* S)
{
    if (S -> top == MAX-1)
        return 1;
    return 0;
}
void push(Stack* S, int x)
{  
    S -> top = S -> top + 1;
    S-> data[S-> top] = x;
}
int pop(Stack* S)
{
    int x;
    x = S ->data[S-> top];
    S -> top = S -> top - 1;
    return x;
}
int peek(Stack *S)
{
    int x;
    if(S -> top != -1)
    {
        x= S -> data[top];
        return x; 
    }
    else
    {
        printf("Stack is empty");
        return -1;
    }
}

void initialize(Stack *S);
int isEmpty(Stack* S);
int isFull(Stack* S);
void push(Stack* S, int x);
int pop(Stack* S);
int peek(Stack *S, int pos);

int main()
{
    int x,temp;
    Stack s;
    initialize(&s);
    printf("Enter a decimal number: ");
    scanf("%d",&x);
    while(x!=0)
    {
        if (isFull(&s))
            printf("Stack Overflow");
        else
        {
            temp = x%2;
            push(&s,temp);
            x = x/2;
        }
    }
    while(!isEmpty(&s))
    {
        temp = pop(&s);
        printf("%d",temp);
    }
    return 0;
}

