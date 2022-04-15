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
sll *reverse(sll*start , sll*curr , sll*prev){
   sll *temp = curr->link;
    if(curr == start){
        curr->link=NULL;
		prev=curr;
		curr = temp;
		reverse(start , curr , prev);
    }
    else if(curr->link == NULL){
        curr->link = prev;
		return curr;
    }
    else{
        curr->link = prev;
		prev = curr;
		curr = temp;
        reverse(start , curr , prev);
    }
	
}
void display(sll *start)
{
	while (start != NULL)
	{
		printf("%d\t", start->data);
		start = start->link;
	}
}
int main(){
    sll *start = NULL;
    start = insert_start(1,start);
	start = insert_start(2,start);
	start = insert_start(3,start);
	start = insert_start(4,start);
	start = insert_start(5,start);
	display(start);
	printf("\n");
    start = reverse(start , start , NULL);
	display(start);
}