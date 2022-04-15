#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	int data;
	struct node *link;
} sll;

sll *create()
{
	sll *temp = malloc(sizeof(struct node));
	return temp;
}
sll *insert_start(int ele, sll *start)
{
	sll *temp = create();
	temp->data = ele;
	temp->link = NULL;
	if (start != NULL);
	{
		temp->link = start;
	}
	start = temp;
	return start;
}
int count(sll*start,int n){
    if(start->link == NULL){
		return n+1;
	}
	else{
		count(start->link,n+1);
	}
}
int main(){
    sll *start = NULL;
    start = insert_start(1,start);
	start = insert_start(2,start);
	start = insert_start(3,start);
	start = insert_start(5,start);
	start = insert_start(4,start);
    int n = count(start , 0);
	printf("%d",n);
}