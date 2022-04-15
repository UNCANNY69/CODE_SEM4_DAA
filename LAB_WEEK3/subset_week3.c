// C program for implementation of selection sort
#include <stdio.h>

void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void selectionSort(int arr[], int n,int *swaping,int*comp)
{
	int i, j, min_idx;
    
	for (i = 0; i < n-1; i++)
	{
		
		min_idx = i;
		for (j = i+1; j < n; j++)
        //comp++;
		if (arr[j] < arr[min_idx]){
            *comp = *comp +1;
			min_idx = j;
        }
		swap(&arr[min_idx], &arr[i]);
        *swaping = *swaping + 1;
	}
}


void printArray(int arr[], int size)
{
	int i;
	for (i=0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

int main()
{
	int comp=0,swaping=0;
    int arr[] = {64, 25, 12, 22, 11};
	int n = sizeof(arr)/sizeof(arr[0]);
	selectionSort(arr, n,&swaping,&comp);
	printf("Sorted array: \n");
	printArray(arr, n);
    printf("comparison: %d\n ",comp);
    printf("Swap: %d ",swaping);
	return 0;
}