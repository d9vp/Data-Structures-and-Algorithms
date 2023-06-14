// Dev Patel - 60009200016
#include <stdio.h>

#define MAX 30

int top=-1;

void push(char *p , char value)
{
    if(top==MAX-1){printf("Overflow \n");}
    else
    {
        top++;
        p[top]=value;
    }
}

int pop()
{
    char x;
    if(top==-1)
    {
        return -1;
    }
    top--;
    return 0;
}

void isWellFormed(char *expression , char *st)
{
    int i=0,c=0;
    while(expression[i]!='\0')
    {
       if(expression[i]=='(')
            push(st , '(');
       else if(expression[i]==')')
       {
            if(top==-1)
            {
                c=-1;
                break;
            }
            else
                c=pop();
        }
       i++;
    }
    if(top!=-1 || c)
        printf("Not Well Formed");
    else
        printf("Well Formed");
}

void main()
{
    char st[MAX] , expression[MAX];
    printf("Enter an expression: \n");
    gets(expression);
    isWellFormed (expression , st);
}