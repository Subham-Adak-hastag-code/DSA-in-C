//*--Paraenthesis Checker--*//
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define SIZE 60
typedef struct stack 
{
   char arr[SIZE];
   int top;
}st;
void push(st *, char);
char pop(st *);
char peek(st *);
int is_full(st *);
int is_empty(st *);
/****for parenthesis check****/
char get_match_symbol(char);
char parenthesis_check(char[]);

void main() 
{
   char equation[100];
   printf("Enter the equation:");
   //fgets(equation,100,stdin);
   gets(equation);
   if(parenthesis_check(equation))
    {
        printf("Parenthesis are balenced");
    }
   else
   {
        printf("Parenthesis are not balenced");
   }
   getch();
}

/***********/

void push(st *ptr, char expr)
{
   ptr->top++;
   ptr->arr[ptr->top] = expr;
}

/***********/ 

char pop(st *ptr) 
{
   char brac;
   brac = ptr->arr[ptr->top];
   ptr->top--;
   return brac;
}

/*************/

char peek(st *ptr)
{
    return ptr->arr[ptr->top];
}

/************/
 
//check the empty and full of stack function//
int is_full(st *ptr)
{
   if(ptr->top == SIZE-1)
   {
      return 1;
   }
   else
   {
      return 0;
   }
}
/**********/
int is_empty(st *ptr)
{
   if(ptr->top == -1)
   {
      return 1;
   }
   else
   {
      return 0;
   }
}

/****************/

char get_match_symbol(char ch)
{
    switch(ch)
    {
        case '(': return')';
        case '{': return'}';
        case '[': return']';
        case ')': return'(';
        case '}': return'{';
        case ']': return'[';
    }
}

/*****************/

char parenthesis_check(char eq[])
{
    int i;
    st ptr;
    ptr.top=-1;
    for(i=0;eq[i];i++)
    {
        if(eq[i]=='(' || eq[i]=='{' || eq[i]=='[')
        {
            push(&ptr,eq[i]);
        }
        else if(eq[i]==')' || eq[i]=='}' || eq[i]==']')
        {
            if(peek(&ptr) == get_match_symbol(eq[i]))
            {
                pop(&ptr);
            }
            else
            {
                return 0;
            }
        }
    }
    if(!is_empty(&ptr))
        return 0;
    else
        return 1;
}