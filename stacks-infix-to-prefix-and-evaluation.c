#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

#define MAX 30

char infix[MAX], prefix[MAX];
int stack[MAX],top;

void push(int symbol);
int pop();
int isEmpty();
int priority(char symbol);
void infix_to_prefix();
int eval_pre();

int main()
{
    int value;
    top=-1;
    printf("Enter infix : ");
    gets(infix);
    infix_to_prefix();
    printf("Prefix : %s\n",prefix);
    value=eval_pre();
    printf("Value of expression : %d\n",value);
    return 0;
}

void infix_to_prefix()
{
    int i,j,p=0;
    char next,symbol,temp ;
    for(i=strlen(infix)-1; i>=0; i--)
    {
        symbol=infix[i];
        switch(symbol)
        {
            case ')':
                push(symbol);
                break;
            case '(':
                while((next=pop())!= ')')
                    prefix[p++] = next;
                break;
            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
                while(!isEmpty( ) && priority(stack[top])>= priority(symbol) )
                    prefix[p++] = pop();
                push(symbol);
                break;
            default:
                prefix[p++]=symbol;
        }
    }
    while(!isEmpty( ))
        prefix[p++] = pop();
    prefix[p] = '\0'; 
    for(i=0,j=p-1;i<j;i++,j--)
    {
        temp=prefix[i];
        prefix[i]=prefix[j];
        prefix[j]=temp;
    }
}

int eval_pre()
{
    int a,b,temp,result,i;
    for(i=strlen(prefix)-1;i>=0;i--)
    {
        if(prefix[i]<='9' && prefix[i]>='0')
            push(prefix[i]-'0' );
        else
        {
            b=pop();
            a=pop();
            switch(prefix[i])
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
        case ')':
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
        exit(2);
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
