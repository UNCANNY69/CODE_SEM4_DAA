#include <stdio.h>
#include <stdlib.h>
char* copy(char *a , char *b,int n){
    if(a[n] == EOF){
        return b;
    }
    else{
        b[n] = a[n];
        copy(a,b,n+1);
    }
}
int main(){
    char a[] = "hello world";
    char b[] = "";
    copy(a,b,0);
    printf("%s",b);
}