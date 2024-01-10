/*--SELECTION SORTING--*/
#include<stdio.h>
#include<conio.h>
void swap(int *p,int *q)
{
    *p=*p+*q;
    *q=*p-*q;
    *p=*p-*q;
}
void selection_sort(int a[],int n)
{
    int i,j,low;
    for(i=0;i<n-1;i++)
    {
        low=i;
        for(j=i+1;j<n;j++)
        {
            if(a[low] > a[j])
            {
                low=j;
            }
        }
        if(i!=low)
        {
            swap(&a[i],&a[low]);
        }
    }
    printf("\nNow the Sorted array:");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}
void main()
{
    int a[20],i,n;
    printf("Enter how many elements:");
    scanf("%d",&n);
    printf("Enter the array elements:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    selection_sort(a,n);
    getch();
}