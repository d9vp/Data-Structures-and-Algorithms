#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

#define MAX 30

char infix[MAX], postfix[MAX];
int stack[MAX],top;

void push(int symbol);
int pop();
int isEmpty();
int priority(char symbol);
void infix_to_postfix();
int eval_post();

int main()
{
    int value;
    top=-1;
    printf("Enter infix : ");
    gets(infix);
    infix_to_postfix();
    printf("Postfix : %s\n",postfix);
    value=eval_post();
    printf("Value of expression : %d\n",value);
    return 0;
}

void infix_to_postfix()
{
    int i,p=0;
    char next,symbol;
    for(i=0;i<strlen(infix);i++)
    {
        symbol=infix[i];
        switch(symbol)
        {
            case '(':
                push(symbol);
                break;
            case ')':
                while((next=pop())!='(')
                    postfix[p++] = next;
                break;
            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
                while(!isEmpty( ) && priority(stack[top])>= priority(symbol) )
                    postfix[p++]=pop();
                push(symbol);
                break;
            default:
                postfix[p++]=symbol;
        }
    }
    while(!isEmpty( ))
        postfix[p++]=pop();
    postfix[p]='\0'; 
}

int eval_post()
{
    int a,b,temp,result,i;
    for(i=0;i<strlen(postfix);i++)
    {
        if(postfix[i]<='9' && postfix[i]>='0')
            push(postfix[i]-'0');
        else
        {
            a=pop();
            b=pop();
            switch(postfix[i])
            {
                case '+':
                    temp=b+a; 
                    break;
                case '-':
                    temp=b-a;
                    break;
                case '*':
                    temp=b*a;
                    break;
                case '/':
                    temp=b/a;
                    break;
                case '^':
                    temp=pow(b,a);
                    break;
            }
            push(temp);
        }
    }
    result=pop();
    return result;
}

int priority(char symbol)
{
    switch(symbol)
    {
        case '(':
            return 0;
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default :
            return 0;
    }
}

void push(int symbol)
{
    if(top>MAX)
    {
        printf("Stack overflow\n");
        exit(1);
    }
    stack[++top]=symbol;
}

int pop()
{
    if(top == -1)
    {
        printf("Stack underflow\n");
        exit(1);
    }
    return (stack[top--]);
}

int isEmpty()
{
    if(top==-1)
        return 1;
    else
        return 0;
}
