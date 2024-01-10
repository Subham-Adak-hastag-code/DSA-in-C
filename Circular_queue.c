//*--Circular Queue--*//
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define SIZE 10
void insert();//enqueue
void delete();//dequeue
int peek();
int c_queue[SIZE],front=-1,rear=-1,data;
void display();
void main()
{
	int ch;
	while(1)
	{
		printf("\n enter 1 for insert in the queue \n enter 2 for delete element \n enter 3 for the peek operation \n enter 4 for  display\nothers for quit: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:insert();break;
			case 2:delete();break;
			case 3:printf("\nThe 1st value of circilar queue: %d",peek());break;
			case 4:display();break;
			default:exit(0);	
		}
	}	
}
void insert()
{	
	if((front == 0 && rear == SIZE-1)||(rear == front-1))
    {	 
 	    printf("\nThe queue is overflow");
 	    return;
    }
    printf("\nEnter the data to be inserted:");
 	scanf("%d",&data);	 
    if(front == -1 && rear == -1)
    {
 	   front=rear=0;
    }
    else if(rear == SIZE-1 && front!=0)
    {
 	   rear=0;   
 	}
    else
    {
 	   rear++;
    }
    c_queue[rear]=data;
    printf("%d is inserted in the circular queue:",data);
}
void delete()
{
	if(front==-1 && rear==-1)
	{
		printf("The Queue is underflow");
		return;
	}
    data=c_queue[front];
    if(front == rear)
    {
	   front = rear = -1;
    }
    else if(front == SIZE-1)
    {
	   front=0;
    }
    else
    {
	   front++;
    }
    printf("%d is delete",data);
}
int peek()
{
	if(front==-1 && rear==-1)
    {
		printf("\n queue is empty");
		return 0;
	}
	return c_queue[front];
}
void display()
{
	int i;
    printf("\n--The Circular Queue--\n");
	if(front==-1 && rear==-1)
	{
		printf(" \n queue is empty");
		return;
	}
	else if(front < rear)
	{
		for(i=front;i<=rear;i++)
		{
			printf("%d  ",c_queue[i]);
		}
	}
	else
    {
		for(i=front;i<SIZE;i++)
		    printf("%d  ",c_queue[i]);
		for(i=0;i<=rear;i++)
		    printf("%d  ",c_queue[i]);
	}
	
}