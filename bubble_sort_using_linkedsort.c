//*--Bubble sort using Linked List--*//
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
st *head=NULL,*current=NULL,*newnode,*ptr,*preptr;
void creat();
void bubble_sort();
void display();
void main()
{
    int ch;
    while(1)
    {
        printf("\nEnter 1 for creat list\n2 for sort list\n3 for display\nOthers for quit:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:creat();break;
            case 2:bubble_sort();break;
            case 3:display();break;
            default:exit(0);
        }
    }
}
void creat()
{
    newnode=(st*)malloc(sizeof(st));
    printf("Enter the new data to be inserted:");
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
void bubble_sort()
{
    st *p1,*p2;
    for(p1=head;p1->next!=NULL;p1=p1->next)
    {
        for(p2=p1->next;p2!=NULL;p2=p2->next)
        {
            if(p1->data > p2->data)
            {
                p1->data = p1->data + p2->data;
                p2->data = p1->data - p2->data;
                p1->data = p1->data - p2->data;
            }
        }
    }
}
/*********/
void display()
{
    printf("\nTHE SORTED LIST\n");
    if(head==NULL)
    {
        printf("\nThe stack is empty");
        return;
    }
    ptr=head;
    while(ptr!=NULL)
    {
        printf("------>%d",ptr->data);
        ptr=ptr->next;
    }  
}
