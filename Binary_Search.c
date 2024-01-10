/*---BINARY SEARCH---*/
#include<stdio.h>
#include<conio.h>
void sorting(int [],int);
void binary_search(int [],int,int);
void main()
{
    int arr[100],i,n,sno;
    printf("Enter how many elements:");
    scanf("%d",&n);
    printf("Enter the array elements:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    sorting(arr,n);
    printf("\nEnter the element to be searched:");
    scanf("%d",&sno);
    binary_search(arr,n,sno);
    getch();
}
void sorting(int arr[],int n)
{
    int i,j;
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(arr[i]>arr[j])
            {
                arr[i]=arr[i]+arr[j];
                arr[j]=arr[i]-arr[j];
                arr[i]=arr[i]-arr[j];
            }
        }
    }
    printf("\nNow the sorted array is:");
    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
}
void binary_search(int arr[] , int n , int sno)
{
    int top,bottom,mid,p=0;
    top = n-1;
    bottom = 0;
    while (top >= bottom && p==0)
    {
        mid = (top+bottom)/2;
        if(arr[mid] == sno)
        {
            p=1;
        }
        else if(arr[mid]<sno)
        {
            bottom = mid+1;
        }
        else
        {
            top = mid-1;
        }
    }
    if(p==1)
        printf("\n%d is present",sno);
    else
        printf("\n%d is not present",sno);
}