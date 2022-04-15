#include <stdio.h>
#include <stdlib.h>
int comp(char *a , char *b,int n){
    if(a[n] == '\0' && b[n] == '\0'){
        return 1;
    }
    else{
        if(a[n] == b[n]){
            comp(a,b,n+1);
        }
        else{
            return 0;
        }
    }
}
int main(){
    char a[] = "hello world";
    char b[] = "hello worl";
    int x;
    x = comp(a,b,0);
    printf("%d\n",x);
}