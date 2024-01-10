//---All OPERATIONS IN A DOUBLY LINKED LIST---//
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
void del_before();
void del_after();
void del_node();  
void del_list();
void searching();
void sorting();
void display();
void reverse_display(); 

/****for check is list have any node or not******/
int is_empty();
/****************/

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};
struct node *head=NULL,*current,*newnode,*ptr,*preptr;

void main()
{
    int ch;
    while(1)
    {
        printf("\nEnter\n1 for insert or create:\n2 for insert at begining:\n3 for insert at end:\n4 for for insert before the node:\n5 for insert after the node:\n6 for delete from the begening:\n7 for delete from the end:\n8 for delete from before the node:\n9 for delete after the node:\n10 for delete the node i.e is entered:\n11 for delete the list:\n12 for searching:\n13 for sorting the list:\n14 for display the list:\n15 for display in reverse:\n others for exit: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: insert();break;
            case 2: if(!is_empty())
                        printf("\nThere is no node now the list is empty:");
                    else
                       insert_beg();
                    break;
            case 3: if(!is_empty())
                        printf("\nThere is no node now the list is empty:");
                    else
                       insert_end();
                    break;
            case 4: if(!is_empty())
                        printf("\nThere is no node now the list is empty:");
                    else
                       insert_before();
                    break;
            case 5: if(!is_empty())
                        printf("\nThere is no node now the list is empty:");
                    else
                       insert_after();
                    break;
            case 6: if(!is_empty())
                        printf("\nThere is no node now the list is empty:");
                    else
                       del_beg();
                    break;
            case 7: if(!is_empty())
                        printf("\nThere is no node now the list is empty:");
                    else
                       del_end();
                    break;
            case 8: if(!is_empty())
                        printf("\nThere is no node now the list is empty:");
                    else
                       del_before();
                    break;
            case 9: if(!is_empty())
                        printf("\nThere is no node now the list is empty:");
                    else
                       del_after();
                    break;
            case 10: if(!is_empty())
                        printf("\nThere is no node now the list is empty:");
                    else
                       del_node();
                    break;
            case 11: if(!is_empty())
                        printf("\nThere is no node now the list is empty:");
                    else
                       del_list();
                    break;
            case 12: if(!is_empty())
                        printf("\nThere is no node now the list is empty:");
                    else
                       searching();
                    break;
            case 13: if(!is_empty())
                        printf("\nThere is no node now the list is empty:");
                    else
                       sorting();
                    break;
            case 14: if(!is_empty())
                        printf("\nThere is no node now the list is empty:");
                    else
                       display();
                    break;
            case 15: if(!is_empty())
                        printf("\nThere is no node now the list is empty:");
                    else
                       reverse_display();
                    break;
            default : exit(0);
        }
    }
}

void insert()
{
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the nodes data for the doubly link list:");
    scanf("%d",&newnode->data);
    if(head == NULL)
    {
        head=newnode;
        newnode->prev = NULL;
        newnode->next = NULL;
        current = newnode;
    }
    else
    {
        current->next = newnode;
        newnode->prev = current;
        newnode->next = NULL;
        current = newnode;
    }
    printf("\n%d is inserted to the double linked list",newnode->data);
}

/************/

void insert_beg()
{
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data to be inserted in the begening:");
    scanf("%d",&newnode->data);
    head->prev = newnode;
    newnode->next = head;
    newnode->prev = NULL;
    head = newnode;
}

/***********/

void insert_end()
{
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data to be inserted  at end:");
    scanf("%d",&newnode->data);
    current->next = newnode;
    newnode->prev = current;
    newnode->next = NULL;
    current = newnode;
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
               ptr->prev = newnode;
               newnode->next = ptr;
               newnode->prev = NULL;
               head = newnode;
            }   
            else
            {
               newnode->prev = ptr->prev;
               newnode->next = ptr;
               ptr->prev = newnode;
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

/*************/

void insert_after()
{
    int val,f=0;
    printf("\nEnter that node after which node you want to insert:");
    scanf("%d",&val);
    for(ptr=head;ptr!=NULL;ptr=ptr->next)
    {
        if(ptr->data == val)
        {
            newnode = (struct node*)malloc(sizeof(struct node));
            printf("Enter the data for the new node:");
            scanf("%d",&newnode->data);
            newnode->prev = ptr;
            newnode->next = ptr->next;
            ptr->next = newnode;
            if(newnode->next == NULL)   // is used when the ptr(val node) node denote last node//
            {
                current = newnode;
            }
            else
            {
                ptr->next->prev = newnode;  // when ptr denote  not the last node//
            }
            f=1;
            printf("\n%d is inserted after %d",newnode->data,val);
            break;
        }
    }
    if(f == 0)
    {
        printf("\n %d is not found,please enter valid node",val);
    }
}

/*************/

void del_beg()
{
    if(head->next == NULL)   //--This if part is use if there is only one node--//
    {
        ptr = head;
        head = head->next;
        printf("\n%d is deleted from the list",ptr->data);
        free(ptr);
    }
    else                   //--This else part for when list has two or more nodes--//
    {
        ptr = head;
        head = head->next;
        head->prev = NULL;
        printf("\n%d is deleted form the doubly linked list",ptr->data);
        free(ptr);
    }
    
}

/************/

void del_end()
{
    if(head->next == NULL)   //--This if part is use if there is only one node--//
    {
        ptr = head;
        head = head->next;
        printf("\n%d is deleted from the list",ptr->data);
        free(ptr);
    }
    else                     //--This else part for when list has two or more nodes--//
    {
        for(ptr=head;ptr->next!=NULL;ptr=ptr->next)
        {
           preptr = ptr;
        }
        preptr->next = NULL;
        current = preptr;
        printf("\n%d is deleted from the list",ptr->data);
        free(ptr);
    }
    
}

/***********/

void del_before()
{
    int val,f=0;
    printf("Enter that node before which node you want to delete:");
    scanf("%d",&val);
    //*----This if check part is write if we want to delete node before the first node----*///
    if(head->data == val)
    {
        printf("\nbefore %d node there is no node,it's the first node",val);
        return;
    } 

    for(ptr=head,preptr=head ; ptr!=NULL && ptr->data!=val ; ptr=ptr->next)
    {
          preptr=ptr;
    }
    for(ptr=head;ptr!=NULL;ptr=ptr->next)
    {
        if(ptr->data == val)
        {
            if(preptr == head)  //if we want 1st node to delete.
            {
                preptr = head;
                head = ptr;
                head->prev = NULL;
            }
            else
            {
                ptr->prev = preptr->prev;
                preptr->prev->next = ptr; //here preptr->prev->next denote the preptr's previous nodes next part//
            }
            f=1;
            printf("\n%d is deleted from the list",preptr->data);
            free(preptr);  // both for if and else case preptr is the actual deleted node //
            break;
        }
    }
    if(f == 0)
    {
        printf("\n %d is not found,please enter valid node",val);
    }
}

/*************/

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
                nxtptr->next->prev = ptr;
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

/**************/

void del_node()
{
    int val,f=0;
    printf("Enter the node that you want to delete:");
    scanf("%d",&val);
    if(head->data == val)
    {
        del_beg();
        f=1;
    }
    else if(current->data == val)
    {
        del_end();
        f=1;
    }
    else
    {
        for(ptr=head;ptr!=NULL;ptr=ptr->next)
        {
            if(ptr->data == val)
            {
                ptr->prev->next = ptr->next;  // Here ptr->prev-> denote our deleted node's previous node's next part//
                ptr->next->prev = ptr->prev;  // Here ptr->next->prev denote out deleted node's next node's prev part//
                f=1;
                printf("\n%d is deleted from the list",ptr->data);
                free(ptr);
                break;
            }
        }
    }
    if(f == 0)
    {
        printf("\n %d is not found,please enter valid node",val);
    }
}

/*************/

void del_list() 
{
    ptr=head;
    while(ptr!=NULL)
    {
        del_beg(); 
        ptr=head;

        //*--if we want to run this function in independently then use under code--*//
        /*printf("\n%d is to be deleted",ptr->data);
        free(ptr);
        head=head->next;
        ptr=head*/
    }
    printf("\n\nNow the doubly linked list is empty");
}

/************/

void searching()
{
    int val,f=0;
    printf("\nEnter the node to be searched:");
    scanf("%d",&val);
    for(ptr=head;ptr!=NULL;ptr=ptr->next)
    {
        if(ptr->data==val)
        {
            printf("\n%d is present in the list",val);
            f=1;
            break;
        }
    }
    if(f == 0)
    {
        printf("\n %d is not found,please enter valid node",val);
    }
}

/***************/

void sorting()
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

/**************/

void display()
{
    printf("\n---THE DOUBLE LINKED LIST---\n");
    for(ptr=head;ptr!=NULL;ptr=ptr->next)
    {
        printf("----->%d",ptr->data);
    }
}

/***************/

void reverse_display()
{
    printf("\n---THE DOUBLE LINKED LIST in REVERSE---\n");
    for(ptr=current;ptr!=NULL;ptr=ptr->prev)
    {
        printf("----->%d",ptr->data);
    }
}

/***************/
int is_empty()
{
    if(head == NULL)
      return 0;
    else
      return 1;
}