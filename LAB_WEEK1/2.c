#include <stdio.h>
#include <stdlib.h>
void main()
{
    int n[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,1,1,0,};
    int a = sizeof(n) / sizeof(n[0]),b;
    int flag=0;
    for (int i = 0; i < a && flag==0 ; i++){
        if(n[i] == 1){
           flag=1 ;
           b = i;
        }
    }
    printf("THE ONE WAS FOUND AT POSITION: %d\n",b+1);
}