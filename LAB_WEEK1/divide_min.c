#include <stdio.h>
#include <stdlib.h>

int divid_min(int start,int end ,int*arr){
    int a=0,b=0;
    if(end-start==1){
        return arr[end]<arr[start]?arr[end]:arr[start];
    }
    else{
        a=divid_min(start,(start+end)/2,arr);
        b=divid_min((start+end)/2,end,arr); `
        return a<b?a:b;
    }
}

int main(){
    int arr[9] = {2,3,4,5,6,7,8,9,10};
    int a = divid_min(0,9,arr);
    printf("%d\n",a);
}