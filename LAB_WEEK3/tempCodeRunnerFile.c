#include<stdio.h>
#include<stdlib.h>

int main(){
    char patt[] = "test";
    char source[] = "today the testest was a very hard test";
    int i = 0,j=0,count = 0;
    while(source[i] != '\0'){
        printf("s");
        if(patt[j] == '\0'){
            count++;
            j=0;
        }
        else if(source[i] == patt[j]){
            i++;
            j++;
        }
        else{
            i++;
        }
    }
    printf("%d\n",count);
}