//IN general the quick sort is not stable and is in place
#include <stdio.h>
#include <stdlib.h>

void swap(int *arr, int a, int b)
{
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}
int partition(int *arr, int low, int high,int * count)
{
    int pivot_ele = arr[low];
    int i = low+1, j = high;
    while (j >= i)
    {
        
        *count = *count + 1;
        while (i <= high && arr[i] < pivot_ele)
        {
            *count = *count + 1;
            i++;
        }
        while (j > low && arr[j] >= pivot_ele)
        {
            *count = *count + 1;
            j--;
        }
        if (j > i)
        {
            *count = *count + 1;
            swap(arr, i, j);
        }
    }
    swap(arr, low, j);
    return j;
}

void quicksort(int *arr, int low, int high,int *count)
{
    int s = 0;
    if (low >= high)
        return;
    else
    {
        
        s = partition(arr, low, high,count);
        quicksort(arr, low, s - 1,count);
        quicksort(arr, s + 1, high,count);
    }
}
void display(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", i);
    }
}
int main()
{
    FILE *fp;
    fp =  fopen("out.txt","w");
    // printf("please enter the num\n");
    for (int i = 10000; i <=100000; i = i+500)
    {
        printf("%d ", i);
        int arr[i],count=0;
        for(int j = 0;j<i;j++){
            arr[j] = rand() % 100000;
        }
        //display(arr,i);
        quicksort(arr, 0,i-1,&count);
        fprintf(fp,"%d  %d\n",i,count);
    }
    
    // int count1=0,count2=0;
    // int arr1[] = {1,4,2,9,5,7,3,4,10,2};
    // int arr2[] = {10,9,8,7,6,5,4,3,2,1};
    // quicksort(arr1, 0,9,&count1);
    // quicksort(arr2, 0,9,&count2);
    // printf("best:%d\nworst:%d",count1,count2);
}