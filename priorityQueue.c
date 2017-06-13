#include <stdio.h>
#include <stdlib.h>

struct node {
	int priority;
	int info;
	struct node *link;
}*front=NULL;

void traverse(){
	struct node *p=front;
	if(!p){
		printf("List is empty\n");
		return;
	}
	while(p){
		printf("Priority: %d\t",p->priority);
		printf("Data: %d\n",p->info);
		p=p->link;
	}
	printf("\n");
}


void delete(){
	if(!front){
		printf("List is empty\n");
		return;
	}
	struct node *temp=front;
	front=front->link;
	free(temp);
}

void insert(){
	int data,priority;
	printf("Enter priority: ");
	scanf("%d",&priority);
	printf("Enter data: ");
	scanf("%d",&data);
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	if(!temp){
		printf("Memory not available\n");
		return;
	}
	temp->info=data;
	temp->priority=priority;
	if(!front || priority<front->priority){
		temp->link=front;
		front=temp;
		return;
	}
	struct node *p=front;
	while(p->link && p->link->priority<priority)
		p=p->link;
	temp->link=p->link;
	p->link=temp;
}

int main(void){
	int ch;
	while(1){
		printf("1. Insert\n");
		printf("2. Delete\n");
		printf("3. Display\n");
		printf("4. Exit\n\n");
		printf("Enter choice: ");
		scanf("%d",&ch);
		switch(ch){
			case 1: insert(); break;
			case 2: delete(); break;
			case 3: traverse(); break;
			case 4: exit(1);
			default: printf("Enter correct choice!!!\n");
		}
	}
	return 0;
}