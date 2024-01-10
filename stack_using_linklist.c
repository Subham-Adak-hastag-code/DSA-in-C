//**--STACK USING LINK LIST--**//
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<malloc.h>
#define NULL 0
typedef struct stack
{
    int data;
    struct stack *next;
}st;
st *top=NULL,*newnode,*ptr;
void push();
void pop();
int peek();
void display();

int is_empty();
void main()
{
    int ch;
    while(1)
    {
        printf("\nEnter 1 for push\n2 for pop\n3 for peek\n4 for display\nothers for quit:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:push();break;
            case 2:if(!is_empty())
                      printf("The stack is empty:");
                   else
                      pop();
                    break;
            case 3:if(!is_empty())
                      printf("The stack is empty:");
                    else
                        printf("\nTop of stack =%d",peek());
                    break;
            case 4:if(!is_empty())
                      printf("The stack is empty:");
                   else
                      display();
                       break;
            default:exit(0);
        }
    }
}
void push()
{
    newnode=(st*)malloc(sizeof(st));
    printf("Enter the new data to be inserted:");
    scanf("%d",&newnode->data);
    if(top==NULL)
    {
        top=newnode;
        newnode->next=NULL;
    }
    else
    {
        newnode->next=top;
        top=newnode;
    }
    printf("\n%d is isnserted",newnode->data);
}
/***********/
void pop()
{
    ptr=top;
    printf("%d is popped out from the stack",ptr->data);
    top=top->next;
    free(ptr);
    
}
int peek()
{
       return top->data;
}
/*************/
void display()
{
    printf("\nTHE STACK\n");
        ptr=top;
        while(ptr!=NULL)
        {
          printf("\n%d",ptr->data);
          ptr=ptr->next;
        }
    
}
/**********/
int is_empty()
{
    if(top==NULL)
        return 0;
    else
        return 1;
}
