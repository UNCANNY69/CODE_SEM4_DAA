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

    
    int degree=2,x=3;
    int arr[50];
    //printf("Please enter the degree and the value if X:\n");
    //scanf("%d %d",&degree,&x);
    for(int i=0; i<degree; i++){
        arr[i] = rand()%40; 
    }
    int sum = arr[0];
    for(int i = 1; i < degree; i++){
        sum = sum*x + arr[i];
    }
    printf("%d ",sum); 
    sum = 0;
    sum = arr[0];
    for(int i = 0; i < degree; i++){
        for(int j = 0; j < i ; j++){
           sum += arr[i]*x; 
        } 
    }
printf("%d",sum);   
}