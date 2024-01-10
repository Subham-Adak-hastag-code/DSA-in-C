//**--QUEUE USING LINK LIST--**//
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<malloc.h>
#define NULL 0
typedef struct queue
{
    int data;
    struct queue *next;
}st;
st *front=NULL,*rear=NULL,*newdata,*ptr;
void insert();
void del();
int peek();
void display();

int is_empty();
void main()
{
    int ch;
    while(1)
    {
        printf("\nEnter 1 for insert\n2 for del\n3 for peek\n4 for display\nothers for quit:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:insert();break;
            case 2:if(!is_empty())
                     printf("The Queue is empty");
                   else
                     del();
                   break;
            case 3:if(!is_empty())
                     printf("The Queue is empty:");
                   else
                     printf("\nTop of Queue =%d",peek());
                   break;
            case 4:if(!is_empty())
                     printf("The Queue is empty:");
                   else
                     display();
                   break;
            default:exit(0);
        }
    }
}
void insert()
{
    newdata=(st*)malloc(sizeof(st));
    printf("Enter the data to be in serted:");
    scanf("%d",&newdata->data);
    if(front==NULL)
    {
        front=newdata;
        newdata->next=NULL;
        rear=newdata;
    }
    else
    {
        rear->next=newdata;
        newdata->next=NULL;
        rear=newdata;
    }
    printf("%d is inserted",newdata->data);
}
/************/
void del()
{
    ptr=front;
    printf("%d is deleted from the queue",ptr->data);
    front=front->next;
    free(ptr);
}
/************/
int peek()
{
       return front->data;       
}
/***********/
void display()
{
    printf("\nTHE QUEUE\n");
    ptr=front;
    while(ptr!=NULL)
    {
        printf("%d  ",ptr->data);
        ptr=ptr->next;
    }  
}
/**********/
int is_empty()
{
     if(front==NULL)
       return 0;
    else
       return 1;
}