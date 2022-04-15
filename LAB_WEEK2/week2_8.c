#include <stdio.h>
#include <stdlib.h>
int sum(int *n1,int *n2,int a , int b){
    if(a==-1){
        return(0);
    }
    else{
        n2[b] = n1[a];
        sum(n1,n2,a-1,b+1);
    }
}
int main(){
    int n1[10] = {0,1,2,3,4,5,6,7,8,9};
    int n2[10]; 
    int a = (sizeof(n1)/4)-1;
    int b = sum(n1,n2,a,0);
    for(int i=0;i<10;i++){
        printf("%d ",n2[i]);
    }
}