/*--BUBBLE SORTING--*/
#include<stdio.h>
#include<conio.h>
void swap(int *p,int *q)
{
    *p=*p+*q;
    *q=*p-*q;
    *p=*p-*q;
}
void bubble_sort(int a[],int n)
{
    int i,j;
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[i] > a[j])
            {
                swap(&a[i],&a[j]);  
            }
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
    bubble_sort(a,n);
    getch();
}
