//*--QUEUE USING STRUCTURE--*//
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define SIZE 50

typedef struct Queue
{
  int arr[SIZE];
  int front, rear;
}st;

void enqueu(st * , int);
int dequeu(st * );
int peek(st *);
void display(st *);

int is_empty(st *);
int is_full(st *);



void main()
{
  int choice, val;
  st ptr;
  ptr.front = ptr.rear = -1;
  while (1) 
   {
      printf("\nEnter\n1for ENQUEUE\n2 for DEQUEUE\n3 for PEAK\n4 for DISPLAY\n5 for exit:");
      printf("\nEnter your option : ");
      scanf("%d",&choice);
      switch (choice)
      {
       case 1:if(is_full(&ptr))
              {
               printf("\nThe Queue is overflown");
              }
              else
              {
               printf("Enter the data to be inserted:");
               scanf("%d",&val);
               enqueu(&ptr, val);
              }
              break;
       case 2:if(is_empty(&ptr))
              {
               printf("\nThe Queue is underflown i.e empty:");
              }
              else
              {
               printf("\n%d is Dequeu out from thequeue ",dequeu(&ptr));
              }
              break;
       case 3:if(is_empty(&ptr))
              {
               printf("\nThe Queue is underflown i.e empty:");
              }
              else
              {
               printf("\nTop of Queue: %d",peek(&ptr));
              }
              break;
       case 4:if(is_empty(&ptr))
              {
               printf("\nThe Queue is underflown i.e empty:");
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
}

void enqueu(st *ptr,int data)
{
    if(ptr->rear == -1)
    {
        ptr->front = ptr->rear = 0;
    }
    else
    {
        ptr->rear++;
    }
    ptr->arr[ptr->rear]=data;
    printf("\n%d is inserted",data);
}

int dequeu(st * ptr)
{
  int num;
  num = ptr->arr[ptr->front];
  if(ptr->front == ptr->rear)
  {
    ptr->front = ptr->rear = -1;
  }
  else
  {
    ptr->front++;
  }
  return num;
}

int peek(st *ptr)
{
  return ptr->arr[ptr->front];
}

void display(st *ptr)
{
  int i;
  for(i=ptr->rear ; i>=ptr->front ; i--)
  {
    printf("%d ",ptr->arr[i]);
  }
}

int is_empty(st *ptr)
{
  if (ptr->front == -1 || ptr->front > ptr->rear)
    return 1;
  else
    return 0;
}

int is_full(st *ptr)
{
  if (ptr->rear == SIZE - 1)
    return 1;
  else
    return 0;
}
