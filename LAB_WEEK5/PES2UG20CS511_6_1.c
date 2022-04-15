#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
typedef struct queue
{
    int *s;
    int front;
    int rear;
    int capacity;
} queue;
void create(queue *pst, int cap)
{
    pst->capacity = cap;
    pst->front = -1;
    pst->rear = -1;
    pst->s = malloc(sizeof(int) * cap);
}
int isemp(queue *pst)
{
    return ((pst->front == -1 && pst->rear == -1)||(pst->front > pst->rear));
}
int isfull(queue *pst)
{
    return ((pst->front + pst->rear) == (pst->capacity - 1));
}
void enqueue(queue *pst, int ele)
{
    if (isfull(pst))
    {
        printf("The queue is full\n");
    }
    else if (isemp(pst))
    {
        pst->front = 0;
        pst->rear = 0;
        pst->s[pst->rear] = ele;
    }
    else

    {
        (pst->rear)++;
        pst->s[pst->rear] = ele;
    }
}
int dequeue(queue *pst)
{
    if (isemp(pst))
    {
        printf("The list is empty\n");
    }
    else
    {
        (pst->front)++;
    }
}
void display(queue s)
{
    for (int i = s.front; i <= s.rear; i++)
    {
        printf("%d\t", s.s[i]);
    }
}

int main(){
    int n = 3,source=0,index=0,count=0;
    int mat[3][3] = {0,1,1,0,0,1,1,0,0};
    int in_deg[3] = {0,0,0};
    int out[3]={0,0,0};
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            in_deg[i] += mat[j][i];
        }
    }
    queue s;
    int cap = 4;
    create(&s , 40);
    for(int i = 0; i < n; i++){
        if(in_deg[i]==0){
            enqueue(&s,i);
            in_deg[i] = -1;
        }
    }
    //enqueue(&s,4);
    while(!isemp(&s)){   
        source = s.s[s.rear];
        dequeue(&s);
        out[index] = source;
        index++;
        for(int j = 0; j < n; j++){
            if(mat[source][j]==1){
                in_deg[j] -= 1;
                if(in_deg[j]==0){
                    enqueue(&s,j);
                    in_deg[j] = -1;
                }
            }
        }
    }
    for(int j = 0; j < n; j++){
        if(in_deg[j]!=-1){
            count++;
        }
    }
    if(count>0){
        printf("DAG ERROR");
    }
    else{
        for(int i = 0; i < n; i++){
            printf("%d\t",out[i]);
        }
    }
}