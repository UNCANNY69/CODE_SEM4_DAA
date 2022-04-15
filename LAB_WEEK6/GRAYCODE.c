#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void subset_gen(int *inp_array, int* code_arr,int n){
    for(int i = 0; i < n; i++){
        if(code_arr[i]&1){
            printf("%d ",inp_array[0]);
        }
        if(code_arr[i]&2){
            printf("%d ",inp_array[1]);
        }
        if(code_arr[i]&4){
            printf("%d ",inp_array[2]);
        }
        printf("\n");
    }
}
void subset_gen_dynamic(int *inp_arr, int* code_arr,int n,int a){
    int b;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < a; j++){
            b = pow(2,j);
            if(code_arr[i]&b){
                printf("%d ",inp_arr[j]);
            }
        }
        printf("\n");
    }
}
int main(){
    int n = 4,temp,a=4;
    int inp_arr[] = {1,2,3,4};
    n = pow(2,n);
    int code_arr[n];
    for(int i = 0; i < n; i++){
        temp = i>>1;
        code_arr[i] = i^temp;
    }
    //subset_gen(inp_arr,code_arr,n);
    subset_gen_dynamic(inp_arr,code_arr,n,a);
}