#include<stdio.h>
#include<stdlib.h>
typedef struct jt{
    int val;
    int dir;
}jt;
int mobile(jt *arr_jt , int size ){
    int m = -1,flag =0;
    for(int i=size-1;i>=0;i--){
        if(arr_jt[i].dir == -1){
            if(i-1 >= 0 && arr_jt[i].val>arr_jt[i-1].val){
                if(m!=-1 && arr_jt[i].val >= arr_jt[m].val){
                    m = i;
                    flag = 1;
                }
                else if (m==-1){
                    m  = i;
                    flag = 1;
                }
            }
        }
        else{
            if(i+1<size && arr_jt[i].val>arr_jt[i+1].val){
                if(m!=-1 && arr_jt[i].val >= arr_jt[m].val){
                    m = i; 
                    flag = 1;
                }
                else if(m == -1){
                    m = i;
                    flag = 1;
                }
            }
        }
    }
    if(flag == 1)
        return m;
    else
        return -1;
}
void swap(jt *arr_jt,int m){
    jt temp;
    if(arr_jt[m].dir == 1){
        temp = arr_jt[m];
        arr_jt[m] = arr_jt[m+1];
        arr_jt[m+1] = temp;
    }
    else{
        temp = arr_jt[m];
        arr_jt[m] = arr_jt[m-1];
        arr_jt[m-1] = temp;
    }
}
void print(jt *arr_jt,int size) {
    for(int i=0;i<size;i++){
        printf("%d",arr_jt[i].val);
    }
    printf("\n");
}
void change_dir(jt *arr_jt,int m,int size){
    for(int i=0;i<size; i++){
        if(arr_jt[m].val<arr_jt[i].val){
            arr_jt[i].dir *= -1;
        }
    }   
}
int main(){
    int n = 8;
    jt arr_jt[n];
    int arr[] = {1,2,3,4,5,6,7,8},m=0,i=1;
    for(int i = 0; i < n; i++){
        arr_jt[i].val = arr[i];
        arr_jt[i].dir = -1;
    }
    print(arr_jt,n);
    while(m!=-1){
        i++;
        m = mobile(arr_jt,n);
        change_dir(arr_jt,m,n);
        swap(arr_jt,m);
        print(arr_jt,n); 
    }
    printf("%d",i);
}