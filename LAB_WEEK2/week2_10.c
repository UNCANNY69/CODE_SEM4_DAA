#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double time_elapsed(struct timespec start, struct timespec end)
{
    double t;
    t = (end.tv_sec - start.tv_sec);                   
    t += (end.tv_nsec - start.tv_nsec) * 0.000000001;  
    return t;
}

int main(){
    struct timespec start;
    struct timespec end;
    int n = 100000;
    int a[n];
    for(int i = 0 ; i < n ; i++){
        a[i] = rand()%15000;
    }
    clock_gettime(CLOCK_REALTIME,&start);
    int b = a[0];
    int c =0;
    for(int i = 0 ; i < n ; i++){
        if(b<a[i]){
            b=a[i];
            c++;
        }
    }
    clock_gettime(CLOCK_REALTIME, &end);    
    printf("MAX:%d\nCOUNT OF OPERATIONS:%d\n",b,c);
    printf("time %.9f \n",time_elapsed(start, end)); 
}