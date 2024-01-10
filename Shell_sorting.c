//---SHELL SORTING---//
#include <stdio.h>    
#include<conio.h>
void swap(int* a,int* b)
{  
    int t = *a;  
    *a = *b;  
    *b = t;  
} 

void Shell_sort(int arr[],int n)
{
    int i,j,gap;
    for(gap=n/2;gap>=1;gap=gap/2)
    {
        for(j=gap;j<n;j++)
        {
            for(i=j-gap;i>=0;i--)
            {
                if(arr[i+gap]>arr[i])
                   break;
                else
                   swap(&arr[i+gap],&arr[i]);
            }
        }
    }
}
 
void printArr(int arr[], int n) 
{  
    int i;  
    printf("\nAfter the SHELL SORT array elements are: ");
    for (i = 0; i < n; i++)  
        printf("%d ", arr[i]);  
}    
void main() 
{  
    int arr[50],i,n;
    printf("Enter how many elements:");
    scanf("%d",&n);
    printf("Enter the arry elements:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }   
    Shell_sort(arr, n);  
    printArr(arr, n);  
    getch();  
}  