//---MERGE SORTING---//
#include <stdio.h> 
#include<conio.h> 
void merge(int a[], int lb, int mid, int ub) 
{ 
	int i, j, k,b[100]; 
	i=lb;
    j=mid+1;
    k=lb;
    while(i<=mid && j<=ub)
    {
        if(a[i]<=a[j])
        {
            b[k]=a[i];
            i++;
            k++;
        }
        else
        {
            b[k]=a[j];
            j++;
            k++;
        }
    }
    if(i>mid)
    {
        while(j<=ub)
        {
            b[k]=a[j];
            j++;
            k++;
        }
    }
    else
    {
        while(i<=mid)
        {
            b[k]=a[i];
            i++;
            k++;
        }
    }
    for(k=lb;k<=ub;k++)
    {
        a[k]=b[k];
    }
}

void mergeSort(int a[], int lb, int ub) 
{ 
	if (lb<ub)
    { 
		int mid = (lb+ub)/2; 
		mergeSort(a, lb, mid); 
		mergeSort(a, mid + 1, ub); 
		merge(a, lb, mid, ub); 
	} 
} 

void printArray(int a[], int n) 
{ 
	int i; 
	for (i = 0; i < n; i++) 
		printf("%d ", a[i]);  
} 

void main() 
{ int a[50],i,n;
    printf("Enter how many elements:");
    scanf("%d",&n);
    printf("Enter the arry elements:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }   
	mergeSort(a, 0, n-1); 
    printf("\nAfter Merge Sort the sorted array is: "); 
	printArray(a, n); 
	getch(); 
}
