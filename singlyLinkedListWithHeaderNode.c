#include <stdio.h>
#include <stdlib.h>

struct node {
	int info;
	struct node *link;
}header;

void traverse(struct node *head){
	struct node *p=head->link;
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

void insertEnd(struct node *head){
	struct node *p=head;
	while(p->link)
		p=p->link;
	int data;
	struct node *tmp=(struct node *)malloc(sizeof(struct node));
	printf("Enter data: ");
	scanf("%d",&data);
	tmp->info=data;
	tmp->link=p->link;
	p->link=tmp;
}

void insertBef(struct node *head){
	int item;
	printf("Enter node info: ");
	scanf("%d",&item);
	struct node *p=head;
	while(p->link){
		if(p->link->info==item){
			struct node *tmp=(struct node *)malloc(sizeof(struct node));
			int data;
			printf("Enter data: ");
			scanf("%d",&data);
			tmp->info=data;
			tmp->link=p->link;
			p->link=tmp;
			return;
		}
		p=p->link;
	}
	printf("Element %d not present in list\n",item);
}

void insertAft(struct node *head){
	struct node *p=head->link;
	int item;
	printf("Enter node info: ");
	scanf("%d",&item);
	while(p){
		if(p->info==item){
			struct node *tmp=(struct node *)malloc(sizeof(struct node));
			int data;
			printf("Enter data: ");
			scanf("%d",&data);
			tmp->info=data;
			tmp->link=p->link;
			p->link=tmp;
			return;
		}
		p=p->link;
	}
	printf("Element %d not present in list\n",item);
}

void insertPos(struct node *head){
	int pos;
	printf("Enter position: ");
	scanf("%d",&pos);
	if(pos<=0){
		printf("Invalid position!!!\n");
		return;
	}
	if(pos==1){
		printf("Header node is present here\n");
		return;
	}
	struct node *p=head;
	for(int i=1;i<pos-1 && p;i++)
		p=p->link;
	if(p){
		int data;
		struct node *tmp=(struct node *)malloc(sizeof(struct node));
		printf("Enter data: ");
		scanf("%d",&data);
		tmp->info=data;
		tmp->link=p->link;
		p->link=tmp;
		return;
	}
	printf("Invalid position\n");
}

void insertMid(struct node *head){
	int ch;
	printf("\t1.Insert before a node\n");
	printf("\t2.Insert after a node\n");
	printf("\t3.Insert at a given position\n\n");
	printf("Enter choice: ");
	scanf("%d",&ch);
	switch(ch){
		case 1: insertBef(head); break;
		case 2: insertAft(head); break;
		case 3: insertPos(head); break;
		default: printf("Enter correct choice!!!\n");
	}
}

void insert(struct node *head){
	int ch;
	printf("\t1.Insert in between\n");
	printf("\t2.Insert at the end\n\n");
	printf("Enter choice: ");
	scanf("%d",&ch);
	switch(ch){
		case 1: insertMid(head); break;
		case 2: insertEnd(head); break;
		default: printf("Enter correct choice!!!\n");
	}
}

void deleteElem(struct node *head){
	int item;
	printf("Enter node info: ");
	scanf("%d",&item);
	struct node *p=head;
	while(p->link){
		if(p->link->info==item){
			struct node *tmp=p->link;
			p->link=p->link->link;
			free(tmp);
			return;
		}
		p=p->link;
	}
	printf("Element %d not present in list\n",item);
}

void deletePos(struct node *head){
	if(!head->link){
		printf("List is empty\n");
		return;
	}
	int pos;
	printf("Enter position: ");
	scanf("%d",&pos);
	if(pos<=0){
		printf("Invalid position!!!\n");
		return;
	}
	if(pos==1){
		printf("Header node can't be deleted\n");
		return;
	}
	struct node *p=head;
	for(int i=1;i<pos-1 && p;i++)
		p=p->link;
	if(p && p->link){
		struct node *tmp=p->link;
		p->link=p->link->link;
		free(tmp);
		return;
	}
	printf("Invalid position\n");
}

void deleteEnd(struct node *head){
	if(!head->link){
		printf("List is empty\n");
		return;
	}
	struct node *p=head;
	while(p->link->link)
		p=p->link;
	struct node *tmp=p->link;
	p->link=p->link->link;
	free(tmp);
}

void deleteMid(struct node *head){
	int ch;
	printf("\t1.Delete an element\n");
	printf("\t2.Delete at a given position\n\n");
	printf("Enter choice: ");
	scanf("%d",&ch);
	switch(ch){
		case 1: deleteElem(head); break;
		case 2: deletePos(head); break;
		default: printf("Enter correct choice!!!\n");
	}
}

void delete(struct node *head){
	int ch;
	printf("\t1.Delete in between\n");
	printf("\t2.Delete at the end\n\n");
	printf("Enter choice: ");
	scanf("%d",&ch);
	switch(ch){
		case 1: deleteMid(head); break;
		case 2: deleteEnd(head); break;
		default: printf("Enter correct choice!!!\n");
	}
}

void search(struct node *head){
	if(!head->link){
		printf("List is empty\n");
		return;
	}
	struct node *p=head->link;
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

void reverse(struct node *head){
	struct node *prev=NULL,*curr=head->link,*next;
	while(curr){
		next=curr->link;
		curr->link=prev;
		prev=curr;
		curr=next;
	}
	head->link=prev;
	traverse(head);
}

void create(struct node *head){
	int num;
	printf("Enter no of elements in list: ");
	scanf("%d",&num);
	if(num<=0){
		printf("Invalid number!!!\n");
		return;
	}
	for(int i=1;i<=num;i++)
		insertEnd(head);
}

int main(){
	struct node *head=&header;
	header.info=0;
	header.link=NULL;
	int ch;
	while(1){
		printf("1. Insert\n");
		printf("2. Create\n");
		printf("3. Delete\n");
		printf("4. Search\n");
		printf("5. Traverse\n");
		printf("6. Reverse\n");
		printf("7. Exit\n\n");

		printf("Enter choice: ");
		scanf("%d",&ch);

		switch(ch){
			case 1: insert(head); break;
			case 2: create(head); break;
			case 3: delete(head); break;
			case 4: search(head); break;
			case 5: traverse(head); break;
			case 6: reverse(head); break;
			case 7: exit(1);
			default: printf("Enter correct choice!!!\n");
		}
	}
	return 0;
}