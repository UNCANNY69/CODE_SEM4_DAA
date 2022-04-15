#include<stdio.h>
#include<stdlib.h>

int main(){
    int patt[] = {1,0,0,0,0};
    int source[1000];
    for(int i=0; i<1000; i++){
        source[i] = 0;
    }
    int i = 0,j=0,count = 0;
    while(i!=1000){
        if(j==5){
            j=0;
        }
        else if(source[i] == patt[j]){ 
            count++;
            i++;
            j++;
        }
        else{
            count++;
            j = 0;
            i++;
        }
    }
    printf("%d\n",count);
}