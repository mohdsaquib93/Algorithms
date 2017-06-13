#include <stdio.h>
#include <stdlib.h>

struct node {
	int info;
	struct node *link;
}*top=NULL;

void checkUnderflow(){
	if(top==NULL){
		printf("\nStack Underflow\n");
		exit(1);
	}
}

void push(){
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	if(temp==NULL){
		printf("\nStack Overflow\n\n");
		return;
	}
	int data;
	printf("Enter data: ");
	scanf("%d",&data);
	temp->info=data;
	temp->link=top;
	top=temp;
	printf("\n%d inserted\n\n",data);
}

void pop(){
	checkUnderflow();
	printf("\n%d popped\n\n",top->info);
	struct node *temp=top;
	top=top->link;
	free(temp);
}

void displayTop(){
	checkUnderflow();
	printf("\nTop element is %d\n\n",top->info);
}

void display(){
	checkUnderflow();
	struct node *temp=top;
	while(temp){
		printf("%d \n",temp->info);
		temp=temp->link;
	}
	printf("\n");
}

int main(){
	int ch;
	while(1){
		printf("1. Push\n");
		printf("2. Pop\n");
		printf("3. Display top element\n");
		printf("4. Display all elements\n");
		printf("5. Exit\n\n");

		printf("Enter choice: ");
		scanf("%d",&ch);

		switch(ch){
			case 1: push(); break;
			case 2: pop(); break;
			case 3: displayTop(); break;
			case 4: display(); break;
			case 5: exit(1);
			default: printf("Enter correct choice!!!\n");
		}
	}
	return 0;
}