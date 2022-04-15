#include <stdio.h>
#include <stdlib.h>
int fact(int n) { 
    if(n==0){
        return 1;
    }
    else{
        return n*(fact(n-1));
    }
}
int main() {
    int n = 5;
    int a;
    a = fact(n);
    printf("%d\n", a);
}