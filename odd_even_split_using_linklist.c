//*--Odd Even Split Using Linked List--*// 
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<malloc.h>
#define NULL 0
typedef struct node
{
    int data;
    struct node *next;
}st;
st *head=NULL,*current=NULL,*newnode,*ptr,*preptr,*even_head=NULL,*odd_head=NULL;

void creat();
void odd_even_split();
void display(st *);
void main()
{
    int ch;
    while(1)
    {
        printf("\nEnter 1 for creat list\n2 for odd_even list\n3 for display\nOthers for quit:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:creat();break;
            case 2:odd_even_split();break;
            case 3:printf("\n---THE MAIN LINK LIST---\n");display(head);
                   printf("\n---THE EVEN LINK LIST---\n");display(even_head);
                   printf("\n---THE ODD LINK LIST---\n");display(odd_head);
                   break;
            default:exit(0);
        }
    }
}
/**********/
void creat()
{
    newnode=(st*)malloc(sizeof(st));
    printf("Enter the data to be inserted:");
    scanf("%d",&newnode->data);
    if(head==NULL)
    {
        head=newnode;
        newnode->next=NULL;
        current=newnode;
    }
    else
    {
        current->next=newnode;
        newnode->next=NULL;
        current=newnode;
    }
    printf("\n%d is isnserted",newnode->data);
}
/**********/
void odd_even_split()
{
    st *current1,*newnode,*current2;
    for(ptr=head;ptr!=NULL;ptr=ptr->next)
    {
        newnode=(st*)malloc(sizeof(st));
        newnode->data=ptr->data;;
        if(ptr->data%2==0)
        {
            if(even_head==NULL)
            {
                even_head=newnode;
                newnode->next=NULL;
                current1=newnode;
            }
            else
            {
                current1->next=newnode;
                newnode->next=NULL;
                current1=newnode;

            }
        }     
        else
        {
            if(odd_head==NULL)
            {
                odd_head=newnode;
                newnode->next=NULL;
                current2=newnode;
            }
            else
            {
                current2->next=newnode;
                newnode->next=NULL;
                current2=newnode;

            }
        }     
    }
}
/**********/
void display( st *head)
{
    st *ptr=head;
    if(head==NULL)
    {
        printf("\nThe list is empty");
        return;
    }
    ptr=head;
    while(ptr!=NULL)
    {
        printf("------>%d",ptr->data);
        ptr=ptr->next;
    } 
}
    