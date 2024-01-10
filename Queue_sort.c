#include<stdio.h>
#include<conio.h>
int partition(int [] , int , int);
void quick_sort(int [] , int , int);
void swap(int * , int *);
void display(int [] , int , int);
void main()
{
    int arr[50],i,n;
    printf("Enter how many elements:");
    scanf("%d",&n);
    printf("Enter the array elements:");
    for(i=0;i<n;i++)
       scanf("%d",&arr[i]);
    quick_sort(arr,0,n-1);
    printf("\n---SORTED ARRAY---\n");
    display(arr,0,n);
    getch();
}

void swap(int* a,int* b)
{  
    int t = *a;  
    *a = *b;  
    *b = t;  
}  

int partition(int arr[],int lb,int ub)
{
    int start,end,pivot;
    pivot=arr[lb];
    start=lb;
    end=ub;
    while(start<end)
    {
        while(arr[start]<=pivot)
             start++;
        while(arr[end]>pivot)
             end--;
        if(start<end)
        {
            swap(&arr[start],&arr[end]);
        }
    }
    swap(&arr[lb],&arr[end]);
    return end;
}

void quick_sort(int arr[],int lb, int ub)
{
    if(lb<ub)
    {
        int k = partition(arr,lb,ub);
        quick_sort(arr,lb,k-1);
        quick_sort(arr,k+1,ub);
    }
}

void display(int arr[],int i,int n)
{
    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
}