//*--Infix to postfix expresion--*//
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 50
typedef struct stack
{
    char ar[SIZE];
    int top;
}st;
void push(st *,char);
char pop(st *);
char peek(st *);
int is_full(st *);
int is_empty(st *);
/**************/
void infix_to_postfix(char[],char[]);
int get_priority(char);
/*************/
void main()
{
    char infix[SIZE],postfix[SIZE];

    printf("Enter the expresion:");
    fgets(infix,SIZE,stdin);

    infix_to_postfix(infix,postfix);
    printf("The postfix expresion=");
    puts(postfix);
    getch();
}
/***************/
void push(st *ptr,char ch )
{
    ptr->top++;
    ptr->ar[ptr->top]=ch;
}
/**************/
char pop(st *ptr)
{
    char ch;
    ch=ptr->ar[ptr->top];
    ptr->top--;
    return ch;
}
/**************/
char peek(st *ptr)
{
    return ptr->ar[ptr->top];
}
/**************/
int is_full(st *ptr)
{
    if(ptr->top==SIZE-1)
       return 1;
    else
       return 0;
}
int is_empty(st *ptr)
{
    if(ptr->top==-1)
       return 1;
    else
       return 0;
}
/********infix-postfix conversion********/
void infix_to_postfix(char infix[],char postfix[])
{
    st s;
    char ch;
    int i,j;
    s.top==-1;
    for(i=0,j=0;infix[i]!='\0';i++)
    {
        if(infix[i]==' ')
        {
            continue;
        }
        else if(infix[i]=='(' || infix[i]=='{' || infix[i]=='[')
        {
            push(&s,infix[i]);
        }
        else if(infix[i]>=48 && infix[i]<=57 || infix[i]>=65 && infix[i]<=90 || infix[i]>=97 && infix[i]<=122)
        {
            postfix[j]=infix[i];
            j++;
        }
        else if(infix[i]=='+' || infix[i]=='-' || infix[i]=='*' || infix[i]=='/')
        {
            while(!is_empty(&s) && get_priority(infix[i])<=get_priority(peek(&s)) && peek(&s)!='(')
            {
                postfix[j]=pop(&s);
                j++;
            }
            push(&s,infix[i]);
        }
        else if(infix[i]==')' || infix[i]=='}' || infix[i]==']')
        {
            while(!is_empty(&s) && (ch=pop(&s)!='('))
            {
                postfix[j]=ch;
                j++;
            }
        }
        else
        {
            break;
        }
    }
    if(!is_empty(&s))
    {
         while(!is_empty(&s) && peek(&s)!='(')
         postfix[j]=pop(&s);
         j++;
    }
    postfix[j]='\0';
}
int get_priority(char ch)
{
    switch(ch)
    {
        case '+':
        case '-': return 0;
        case '*':
        case '/':return 1;
    }
}