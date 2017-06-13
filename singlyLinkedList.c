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

struct node *insertBeg(struct node *start){
	int data;
	struct node *tmp=(struct node *)malloc(sizeof(struct node));
	printf("Enter data: ");
	scanf("%d",&data);
	tmp->info=data;
	tmp->link=start;
	start=tmp;
	return start;
}

void insertEnd(struct node *start){
	if(!start){
		printf("List is empty\n");
		return;
	}
	struct node *p=start;
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

struct node *insertBef(struct node *start){
	if(!start){
		printf("List is empty\n");
		return start;
	}
	int item;
	printf("Enter node info: ");
	scanf("%d",&item);
	if(start->info==item){
		struct node *tmp=(struct node *)malloc(sizeof(struct node));
		int data;
		printf("Enter data: ");
		scanf("%d",&data);
		tmp->info=data;
		tmp->link=start;
		start=tmp;
		return start;
	}
	struct node *p=start;
	while(p->link){
		if(p->link->info==item){
			struct node *tmp=(struct node *)malloc(sizeof(struct node));
			int data;
			printf("Enter data: ");
			scanf("%d",&data);
			tmp->info=data;
			tmp->link=p->link;
			p->link=tmp;
			return start;
		}
		p=p->link;
	}
	printf("Element %d not present in list\n",item);
	return start;
}

void insertAft(struct node *start){
	if(!start){
		printf("List is empty\n");
		return;
	}
	struct node *p=start;
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
	return;
}

struct node *insertPos(struct node *start){
	int pos;
	printf("Enter position: ");
	scanf("%d",&pos);
	if(pos<=0){
		printf("Invalid position!!!\n");
		return start;
	}
	if(pos==1)
		return insertBeg(start);
	struct node *p=start;
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
		return start;
	}
	printf("Invalid position\n");
	return start;
}

struct node *insertMid(struct node *start){
	int ch;
	printf("\t1.Insert before a node\n");
	printf("\t2.Insert after a node\n");
	printf("\t3.Insert at a given position\n\n");
	printf("Enter choice: ");
	scanf("%d",&ch);
	switch(ch){
		case 1: start=insertBef(start); break;
		case 2: insertAft(start); break;
		case 3: start=insertPos(start); break;
		default: printf("Enter correct choice!!!\n");
	}
	return start;
}

struct node *insert(struct node *start){
	int ch;
	printf("\t1.Insert at beginning\n");
	printf("\t2.Insert in between\n");
	printf("\t3.Insert at the end\n\n");
	printf("Enter choice: ");
	scanf("%d",&ch);
	switch(ch){
		case 1: start=insertBeg(start); break;
		case 2: start=insertMid(start); break;
		case 3: insertEnd(start); break;
		default: printf("Enter correct choice!!!\n");
	}
	return start;
}

struct node *deleteBeg(struct node *start){
	if(!start){
		printf("List is empty\n");
		return start;
	}
	struct node *tmp=start;
	start=start->link;
	free(tmp);
	return start;
}

struct node *deleteElem(struct node *start){
	if(!start){
		printf("List is empty\n");
		return start;
	}
	int item;
	printf("Enter node info: ");
	scanf("%d",&item);
	if(start->info==item)
		return deleteBeg(start);
	struct node *p=start;
	while(p->link){
		if(p->link->info==item){
			struct node *tmp=p->link;
			p->link=p->link->link;
			free(tmp);
			return start;
		}
		p=p->link;
	}
	printf("Element %d not present in list\n",item);
	return start;
}

struct node *deletePos(struct node *start){
	if(!start){
		printf("List is empty\n");
		return start;
	}
	int pos;
	printf("Enter position: ");
	scanf("%d",&pos);
	if(pos<=0){
		printf("Invalid position!!!\n");
		return start;
	}
	if(pos==1)
		return deleteBeg(start);
	struct node *p=start;
	for(int i=1;i<pos-1 && p;i++)
		p=p->link;
	if(p && p->link){
		struct node *tmp=p->link;
		p->link=p->link->link;
		free(tmp);
		return start;
	}
	printf("Invalid position\n");
	return start;
}

struct node *deleteEnd(struct node *start){
	if(!start){
		printf("List is empty\n");
		return start;
	}
	if(!(start->link)){
		struct node *tmp=start;
		start=start->link;
		free(tmp);
		return start;
	}
	struct node *p=start;
	while(p->link->link)
		p=p->link;
	struct node *tmp=p->link;
	p->link=p->link->link;
	free(tmp);
	return start;
}

struct node *deleteMid(struct node *start){
	int ch;
	printf("\t1.Delete an element\n");
	printf("\t2.Delete at a given position\n\n");
	printf("Enter choice: ");
	scanf("%d",&ch);
	switch(ch){
		case 1: start=deleteElem(start); break;
		case 2: start=deletePos(start); break;
		default: printf("Enter correct choice!!!\n");
	}
	return start;
}

struct node *delete(struct node *start){
	int ch;
	printf("\t1.Delete from beginning\n");
	printf("\t2.Delete in between\n");
	printf("\t3.Delete at the end\n\n");
	printf("Enter choice: ");
	scanf("%d",&ch);
	switch(ch){
		case 1: start=deleteBeg(start); break;
		case 2: start=deleteMid(start); break;
		case 3: start=deleteEnd(start); break;
		default: printf("Enter correct choice!!!\n");
	}
	return start;
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

struct node *reverse(struct node *start){
	struct node *prev=NULL,*curr=start,*next;
	while(curr){
		next=curr->link;
		curr->link=prev;
		prev=curr;
		curr=next;
	}
	start=prev;
	traverse(start);
	return start;
}

struct node *create(struct node *start){
	int num;
	printf("Enter no of elements in list: ");
	scanf("%d",&num);
	if(num<=0){
		printf("Invalid number!!!\n");
		return start;
	}
	start=insertBeg(start);
	for(int i=2;i<=num;i++)
		insertEnd(start);
	return start;
}

int main(){
	struct node *start=NULL;
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
			case 1: start=insert(start); break;
			case 2: start=create(start); break;
			case 3: start=delete(start); break;
			case 4: search(start); break;
			case 5: traverse(start); break;
			case 6: start=reverse(start); break;
			case 7: exit(1);
			default: printf("Enter correct choice!!!\n");
		}
	}
	return 0;
}