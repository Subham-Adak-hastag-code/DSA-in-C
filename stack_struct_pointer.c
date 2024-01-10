//*--Stack using struct pointer--*//
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define SIZE 60
typedef struct stack 
{
   int arr[SIZE];
   int top;
}st;
void push(st *, int);
int pop(st *);
int peek(st *);
void display(st *);

int is_full(st *);
int is_empty(st *);

void main() 
{
   int choice, val;
   st ptr; //struct stack type ptr as we use typedef thats why st type we declere//
   ptr.top=-1;
   while (1) 
   {
      printf("\nEnter\n1for PUSH\n2 for POP\n3 for PEAK\n4 for DISPLAY\n5 for exit:");
      printf("\nEnter your option : ");
      scanf("%d",&choice);
      switch (choice)
      {
       case 1:if(is_full(&ptr))
              {
               printf("\nThe stack is overflown");
              }
              else
              {
               printf("Enter the data to be inserted:");
               scanf("%d",&val);
               push(&ptr, val);
              }
              break;
       case 2:if(is_empty(&ptr))
              {
               printf("\nThe stack is underflown i.e empty:");
              }
              else
              {
               printf("\n%d is popped out from stack",pop(&ptr));
              }
              break;
       case 3:if(is_empty(&ptr))
              {
               printf("\nThe stack is underflown i.e empty:");
              }
              else
              {
               printf("\nTop of stack: %d",peek(&ptr));
              }
              break;
       case 4:if(is_empty(&ptr))
              {
               printf("\nThe stack is underflown i.e empty:");
              }
              else
              {
               display(&ptr);
              }
              break;
       case 5:exit(0);
       default: printf("\nEnter correct option!Try again.");
      }
   }
   getch();
}

/***********/

void push(st *ptr, int data)
{
   ptr->top++;
   ptr->arr[ptr->top] = data;
}

/***********/ 

int pop(st *ptr) 
{
   int num;
   num = ptr->arr[ptr->top];
   ptr->top--;
   return num;
}

/*************/

int peek(st *ptr)
{
    return ptr->arr[ptr->top];
}

/************/
 
void display(st *ptr)
{
   int i;
   for (i = ptr->top; i >= 0; i--)
      printf("\n%d", ptr->arr[i]);
}

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
