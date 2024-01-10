//*--Single Linked List--*//
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<malloc.h>   
#define NULL 0
void insert();
void insert_beg();
void insert_end();
void insert_before();
void insert_after();
void del_beg();
void del_end();
void del_node();
void del_after();
void del_list();
void search();
void sort_list();
void display();
struct  node
{
    int data;
    struct node *next;    
};
struct node *head=NULL,*current=NULL,*newnode,*ptr,*preptr;
int main()
{
    int ch;
    while(1)
    {
        printf("\nEnter 1 for creat or insert list data\n2 for insert at begining\n3 for insert at end\n4 for insert before the given node\n5 for insert data after a given node\n6 for delete data at beg\n7 for delete data at end\n8 for delet the node\n9 for delete after the given node\n10 for delete the list\n11 for seraching the node\n12 for sorting the list\n13 for display the list:");
        scanf("%d",&ch);
        switch (ch)
        {
           case 1:insert();break;
           case 2:insert_beg();break;
           case 3:insert_end();break;
           case 4:insert_before();break;
           case 5:insert_after();break;
           case 6:del_beg();break;
           case 7: del_end();break;
           case 8:del_node();break;
           case 9: del_after();break;
           case 10: del_list();break;
           case 11: search();break;
           case 12: sort_list();break;
           case 13: display();break;
           default: exit(0);
        }
    }
    return 0;
}

/**********/

void insert()
{
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the link list data for the node:");
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
        current=newnode;;
    }
    printf("\n%d is inserted",newnode->data);
}

/***************/

void insert_beg()
{
    if(head==NULL)
    {
        printf("\n NO node yet, the list is empty");
        return;
    }
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data to insert to beg:");
    scanf("%d",&newnode->data);
    newnode->next=head;
    head=newnode;
}

/***********/

void insert_end()
{
    if(head==NULL)
    {
        printf("\nNO node yet,the list is empty");
        return;
    }
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter the data to be inserted at end:");
    scanf("%d",&newnode->data);
    current->next=newnode;
    newnode->next=NULL;
    current=newnode;
}

/************/

void insert_before()
{
    int val,f=0;
    printf("Enter that node's data before which the new node we want to insert:");
    scanf("%d",&val);
    for(ptr=head,preptr=head ; ptr!=NULL && ptr->data!=val ; ptr=ptr->next)
    {
          preptr=ptr;
    }
    for(ptr=head;ptr!=NULL;ptr=ptr->next)
    {
        if(ptr->data==val)
        {
            newnode = (struct node*)malloc(sizeof(struct node));
            printf("Enter the data for the new node:");
            scanf("%d",&newnode->data);
            if(ptr == head)
            {
               newnode->next = ptr;
               head = newnode;
            }   
            else
            {
               newnode->next = ptr;
               preptr->next = newnode;
            }
            f=1;
             printf("%d is insterded before %d",newnode->data,val);
             break;
        }
    }
    if(f == 0)
    {
        printf("\n %d is not found,please enter valid node",val);
    }
}

/************/

void insert_after()
{
    int val,f=0;
    if(head==NULL)
    {
        printf("\nNo node yet,the ;list is empty");
        return;
    }
    printf("\nEnter the node after which node the new node is inserted:");
    scanf("%d",&val);
    for(ptr=head;ptr!=NULL;ptr=ptr->next)
    {
        if(ptr->data==val)
        {
            newnode=(struct node*)malloc(sizeof(struct node));
            printf("\nEnter the data to be inserted after:");
            scanf("%d",&newnode->data);   
            newnode->next=ptr->next;
            ptr->next=newnode;
            f++;
            if(newnode->next==NULL)
            {
                current=newnode;
            }
            printf("\n%d is inserted after %d",newnode->data,val);
            break;
        }
    }
    if(f==0)
    {
        printf("\nNodes data not found");
    }
}

/*************/

void del_beg()
{
    if(head==NULL)
    {
        printf("\nNo node yet,the ;list is empty");
        return;
    }   
    ptr=head;
    head=head->next;
    free(ptr);
}

/************/

void del_end()
{
    if(head==NULL)
    {
        printf("\nNo node yet,the ;list is empty");
        return;
    }
    ptr=head;
    while (ptr->next!=NULL)   //***//
    {
        preptr=ptr;
        ptr=ptr->next;
    }
    preptr->next=NULL;
    current=preptr;
    free(ptr);
}

/************/

void del_node()
{
    int val;
    if(head==NULL)
    {
        printf("\nNo node yet,the ;list is empty");
        return;
    }
    printf("\nEnter the node to be deleted:");
    scanf("%d",&val);
    ptr=head;
    if(ptr->data==val)
    {
        del_beg();
    }
    else
    {
        while(ptr->data!=val)
        {
            preptr=ptr;
            ptr=ptr->next;
        }
        preptr->next=ptr->next;
        if(preptr->next==NULL)
        {
            current=preptr;
        }
        free(ptr);
    }
}

/*********old code off my***

void del_after()
{
    int val;
    if(head==NULL)
    {
        printf("\nNo node yet,the ;list is empty");
        return;
    }
    printf("\nEnter the node after which node the node will delete:");
    scanf("%d",&val);
     //*----This if cheek part is write if we want to delete node after the last node----*
    if(current->data == val)
    {
        printf("\nAfter %d node there is no node,it's the last node",val);
        return;
    }
    ptr=head;
    if(ptr->data==val)
    {
        preptr=ptr->next;
        ptr->next=preptr->next;
        free(preptr);
    }
    else
    {
        preptr=ptr;          //// need to edit for last node?????
        while(preptr->data!=val)
        {
            preptr=ptr;
            ptr=ptr->next;
        }
        preptr->next=ptr->next;
        free(ptr);
    }
}*/

/******---updated code---*****/

void del_after()
{
    int val,f=0;
    struct node *nxtptr;
    printf("\nEnter that node after which node you want to delete:");
    scanf("%d",&val);
    //*----This if cheek part is write if we want to delete node after the last node----*//
    if(current->data == val)
    {
        printf("\nAfter %d node there is no node,it's the last node",val);
        return;
    }
    for(ptr=head;ptr!=NULL;ptr=ptr->next)
    {
        if(ptr->data == val)
        {
            nxtptr=ptr->next;
            if(nxtptr->next == NULL)
            {
                ptr->next = nxtptr->next;
                current = ptr;
            }
            else
            {
                ptr->next = nxtptr->next;
            }
            f=1;
            printf("\n%d is deleted from the list",nxtptr->data);
            free(nxtptr);
            break;
        }
    }
    if(f == 0)
    {
        printf("\n %d is not found,please enter valid node",val);
    }
}

/************/

void del_list()
{
    if(head==NULL)
    {
        printf("\nNo node yet,the ist is empty");
        return;
    }
    ptr=head;
    while(ptr!=NULL)
    {
        printf("\n%d is to be deleted",ptr->data);
        del_beg();
        ptr=head;
    }
    printf("\n Now the list is empty");
}

/************/

void search()
{
    int val;
    if(head==NULL)
    {
        printf("\nNo node yet,the ist is empty");
        return;
    }
    printf("\nEnter the node to be searched:");
    scanf("%d",&val);
    ptr=head;
    while(ptr!=NULL)
    {
        if(ptr->data==val)
        {
            printf("\n%d is present in the list",val);
            break;
        }
        ptr=ptr->next;
    }
}

/************/

void sort_list()
{
    struct node *p1,*p2;
    p1=head;
    while(p1->next!=NULL)
    {
        p2=p1->next;
        while(p2!=NULL)
        {
            if(p1->data > p2->data)
            {
                p1->data = p1->data + p2->data;
                p2->data = p1->data - p2->data;
                p1->data = p1->data - p2->data;
            }
            p2=p2->next;
        }
        p1=p1->next;
    }
}

/************/

void display()
{
    if(head==NULL)
    {
        printf("\nNo node to display");
        return;
    }
    printf("\nTHE COMPLETE LINKED LIST:\n");
    ptr=head;
    while(ptr!=NULL)
    {
        printf("------>%d ",ptr->data);
        ptr=ptr->next;
    }
}