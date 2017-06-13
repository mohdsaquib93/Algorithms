#include <stdio.h>
#include <stdlib.h>

struct node {
	int info;
	struct node *link;
};

void traverse(struct node *start){
	struct node *p=start;
	if(!p){
		printf("List is empty\n");
		return;
	}
	while(p){
		printf("%d ",p->info);
		p=p->link;
	}
	printf("\n");
}

void search(struct node *start){
	if(!start){
		printf("List is empty\n");
		return;
	}
	struct node *p=start;
	int item,pos=1;
	printf("Enter node info: ");
	scanf("%d",&item);
	while(p){
		if(p->info==item){
			printf("Element %d found at position %d\n",item,pos);
			return;
		}
		pos++;
		p=p->link;
	}
	printf("Element %d not present in list\n",item);
}

struct node *insert(struct node *start){
	int data;
	printf("Enter data: ");
	scanf("%d",&data);
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	temp->info=data;
	if(!start || data<start->info){
		temp->link=start;
		start=temp;
		return start;
	}
	struct node *p=start;
	while(p->link && p->link->info<data)
		p=p->link;
	temp->link=p->link;
	p->link=temp;
	return start;
}

int main(void){
	struct node *start=NULL;
	int ch;
	while(1){
		printf("1. Insert\n");
		printf("2. Display\n");
		printf("3. Search\n");
		printf("4. Exit\n\n");
		printf("Enter choice: ");
		scanf("%d",&ch);
		switch(ch){
			case 1: start=insert(start); break;
			case 2: traverse(start); break;
			case 3: search(start); break;
			case 4: exit(1);
			default: printf("Enter correct choice!!!\n");
		}
	}
	return 0;
}