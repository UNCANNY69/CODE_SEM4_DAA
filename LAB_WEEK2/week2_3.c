#include <stdio.h>
#include <stdlib.h>
int sum(int *n,int a){
    if(a==-1){
        return(0);
    }
    else{
        return n[a]+sum(n,a-1);
    }
}
int main(){
    int n[10] = {0,1,2,3,4,5,6,7,8,9};
    int a = (sizeof(n)/4)-1;
    int b = sum(n,a);
    printf("%d",b);
}