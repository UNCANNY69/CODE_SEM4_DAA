#include <stdio.h>
#include <stdlib.h>
int fibb(int n,int *count){
    *count = *count+1;
    if(n<=1){
        return n;
    }
    else{
        return fibb(n-1,count)+fibb(n-2,count);
    }
}
int main(){
    FILE *fp = fopen("test3.txt","w");
    int a = 0;
    int count= 0;
    for(int i=1; i<10 ; i++){
        a = fibb(i,&count);
        fprintf(fp,"%d\t%d\n",i,count);
    }
}