//---INSERTION SORTING---//
#include<stdio.h>
#include<conio.h>
void insertionSort(int arr[], int n)
{
	int i,key,j;
	for(i = 1; i < n; i++) 
	{
		key = arr[i];
		for(j=i - 1 ; j>=0 && arr[j]>key;j--) 
		{
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = key;
	}
}

void printArray(int arr[], int n)
{
	int i;
    printf("\nAfter the INSERTION SORT array elements are: ");
	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
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
	insertionSort(arr, n);
	printArray(arr, n);
    getch();
}
