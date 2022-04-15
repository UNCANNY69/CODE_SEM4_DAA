#include<stdio.h>
#include<stdlib.h>

int main(){
    char patt[] = "00001";
    char source[1000];
    for(int i=0; i<1000; i++){
        source[i] = '0';
    }
    int i = 0,j=0,count = 0;
    while(i<1000){
        if(j==5){
            j=0;
            i++;
        }
        else if(source[i] == patt[j]){  
            if(i+j<=1000)  
            count++;
            i++;
            j++;
        }
        else{
            if(i+j<=1000)    
            count++;
            i -= (j-1);
            j = 0;
        }
    }
    printf("%d\n",count);
}