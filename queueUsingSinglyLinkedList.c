#include <stdio.h>
#include <stdlib.h>

struct node {
	int info;
	struct node *link;
}*rear=NULL,*front=NULL;

void checkUnderflow(){
	if(!front){
		printf("Underflow\n\n");
		exit(1);
	}
}

void checkOverflow(struct node *temp){
	if(!temp){
		printf("Overflow\n\n");
		exit(1);
	}
}

void enqueue(){
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	checkOverflow(temp);
	int data;
	printf("Enter data: ");
	scanf("%d",&data);
	temp->info=data;
	if(!front)
		front=temp;
	else rear->link=temp;
	temp->link=NULL;
	rear=temp;
	printf("\n%d inserted\n\n",data);
}

void dequeue(){
	checkUnderflow();
	printf("\n%d popped\n\n",front->info);
	struct node *temp=front;
	front=front->link;
	free(temp);
}

void displayFront(){
	checkUnderflow();
	printf("\nFront element is %d\n\n",front->info);
}

void display(){
	checkUnderflow();
	struct node *temp=front;
	while(temp!=NULL){
		printf("%d ",temp->info);
		temp=temp->link;
	}
	printf("\n");
}

int main(){
	int ch;
	while(1){
		printf("1. Insert\n");
		printf("2. Delete\n");
		printf("3. Display element at the front\n");
		printf("4. Display all elements\n");
		printf("5. Exit\n\n");

		printf("Enter choice: ");
		scanf("%d",&ch);

		switch(ch){
			case 1: enqueue(); break;
			case 2: dequeue(); break;
			case 3: displayFront(); break;
			case 4: display(); break;
			case 5: exit(1);
			default: printf("Enter correct choice!!!\n");
		}
	}
	return 0;
}