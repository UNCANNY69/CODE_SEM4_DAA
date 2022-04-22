#include<stdio.h>
#include<stdlib.h>

int main(){
    int i=0,j=0,k = 0;
    int arr1[] = {1,2,3,6};
    int arr2[] = {7,9,10,11};
    int merg_arr[8];
    while(i<4 && j<4){
        if(arr1[i]>arr2[j]){
            merg_arr[k] = arr2[j];
            k++;j++;
        }
        else if(arr1[i]<arr2[j]){
            merg_arr[k] = arr1[i];
            k++;i++;
        }
        else{
            merg_arr[k] = arr2[j];
            j++;i++;k++;
        }
    }
    while(j<4){
        merg_arr[k] = arr2[j];
        k++;j++;
    }
    while(i<4){
        merg_arr[k] = arr1[i];
        k++;i++;
    }
}