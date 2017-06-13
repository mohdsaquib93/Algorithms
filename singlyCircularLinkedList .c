#include <stdio.h>
#include <stdlib.h>

struct node {
	int info;
	struct node *link;
};

void traverse(struct node *last){
	if(!last){
		printf("List is empty\n");
		return;
	}
	struct node *p=last->link;
	do{
		printf("%d ",p->info);
		p=p->link;
	}while(p!=last->link);
	printf("\n");
}

struct node *insertBeg(struct node *last){
	int data;
	struct node *tmp=(struct node *)malloc(sizeof(struct node));
	printf("Enter data: ");
	scanf("%d",&data);
	tmp->info=data;
	if(!last){
		last=tmp;
		tmp->link=last;
		return last;
	}
	tmp->link=last->link;
	last->link=tmp;
	return last;
}

struct node *insertEnd(struct node *last){
	if(!last){
		printf("List is empty\n");
		return last;
	}
	struct node *p=last;
	int data;
	struct node *tmp=(struct node *)malloc(sizeof(struct node));
	printf("Enter data: ");
	scanf("%d",&data);
	tmp->info=data;
	tmp->link=last->link;
	last->link=tmp;
	last=tmp;
	return last;
}

void insertBef(struct node *last){
	if(!last){
		printf("List is empty\n");
		return;
	}
	int item;
	printf("Enter node info: ");
	scanf("%d",&item);
	struct node *p=last;
	do {
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
	} while(p!=last);
	printf("Element %d not present in list\n",item);
}

struct node *insertAft(struct node *last){
	if(!last){
		printf("List is empty\n");
		return last;
	}
	struct node *p=last;
	int item;
	printf("Enter node info: ");
	scanf("%d",&item);
	do {
		if(p->info==item){
			struct node *tmp=(struct node *)malloc(sizeof(struct node));
			int data;
			printf("Enter data: ");
			scanf("%d",&data);
			tmp->info=data;
			tmp->link=p->link;
			p->link=tmp;
			if(p==last)
				last=tmp;
			return last;
		}
		p=p->link;
	} while (p!=last);
	printf("Element %d not present in list\n",item);
	return last;
}

struct node *insertPos(struct node *last){
	int pos;
	printf("Enter position: ");
	scanf("%d",&pos);
	if(pos<=0){
		printf("Invalid position\n");
		return last;
	}
	if(!last && pos>1){
		printf("Invalid position\n");
		return last;
	}

	if(pos==1){
		last=insertBeg(last);
		return last;
	}
	struct node *p=last;
	int i=1;
	do {
		p=p->link;
	} while(i++<pos-1 && p!=last);
	if(i==pos){
		int data;
		struct node *tmp=(struct node *)malloc(sizeof(struct node));
		printf("Enter data: ");
		scanf("%d",&data);
		tmp->info=data;
		tmp->link=p->link;
		p->link=tmp;
		if(p==last)
			last=tmp;
		return last;
	}
	printf("Invalid position\n");
	return last;
}

struct node *insertMid(struct node *last){
	int ch;
	printf("\t1.Insert before a node\n");
	printf("\t2.Insert after a node\n");
	printf("\t3.Insert at a given position\n\n");
	printf("Enter choice: ");
	scanf("%d",&ch);
	switch(ch){
		case 1: insertBef(last); break;
		case 2: last=insertAft(last); break;
		case 3: last=insertPos(last); break;
		default: printf("Enter correct choice!!!\n");
	}
	return last;
}

struct node *insert(struct node *last){
	int ch;
	printf("\t1.Insert at beginning\n");
	printf("\t2.Insert in between\n");
	printf("\t3.Insert at the end\n\n");
	printf("Enter choice: ");
	scanf("%d",&ch);
	switch(ch){
		case 1: last=insertBeg(last); break;
		case 2: last=insertMid(last); break;
		case 3: last=insertEnd(last); break;
		default: printf("Enter correct choice!!!\n");
	}
	return last;
}

struct node *deleteBeg(struct node *last){
	if(!last){
		printf("List is empty\n");
		return last;
	}
	struct node *tmp=last->link;
	if(tmp==last){
		last=NULL;
		free(tmp);
		return last;
	}
	last->link=last->link->link;
	free(tmp);
	return last;
}

struct node *deleteElem(struct node *last){
	if(!last){
		printf("List is empty\n");
		return last;
	}
	int item;
	printf("Enter node info: ");
	scanf("%d",&item);
	struct node *p=last;
	do {
		if(p->link->info==item){
			struct node *tmp=p->link;
			p->link=p->link->link;
			if(tmp==last){
				if(last->link!=last)
					last=p;
				else last=NULL;
			}
			free(tmp);
			return last;
		}
		p=p->link;
	} while(p!=last);
	printf("Element %d not present in list\n",item);
	return last;
}

struct node *deletePos(struct node *last){
	if(!last){
		printf("List is empty\n");
		return last;
	}
	int pos;
	printf("Enter position: ");
	scanf("%d",&pos);
	if(pos<=0){
		printf("Invalid position\n");
		return last;
	}
	if(pos==1)
		return deleteBeg(last);
	if(last->link==last && pos>1){
		printf("Invalid position\n");
		return last;
	}
	struct node *p=last;
	int i=1;
	do {
		p=p->link;
	} while(i++<pos-1 && p!=last);
	if(i==pos && p!=last){
		struct node *tmp=p->link;
		p->link=tmp->link;
		if(tmp==last)
			last=p;
		free(tmp);
		return last;
	}
	printf("Invalid position\n");
	return last;
}

struct node *deleteEnd(struct node *last){
	if(!last){
		printf("List is empty\n");
		return last;
	}
	struct node *p=last->link;
	if(p==last){
		last=NULL;
		free(p);
		return last;
	}
	while(p->link!=last)
		p=p->link;
	struct node *tmp=last;
	p->link=last->link;
	last=p;
	free(tmp);
	return last;
}

struct node *deleteMid(struct node *last){
	int ch;
	printf("\t1.Delete an element\n");
	printf("\t2.Delete at a given position\n\n");
	printf("Enter choice: ");
	scanf("%d",&ch);
	switch(ch){
		case 1: last=deleteElem(last); break;
		case 2: last=deletePos(last); break;
		default: printf("Enter correct choice!!!\n");
	}
	return last;
}

struct node *delete(struct node *last){
	int ch;
	printf("\t1.Delete from beginning\n");
	printf("\t2.Delete in between\n");
	printf("\t3.Delete at the end\n\n");
	printf("Enter choice: ");
	scanf("%d",&ch);
	switch(ch){
		case 1: last=deleteBeg(last); break;
		case 2: last=deleteMid(last); break;
		case 3: last=deleteEnd(last); break;
		default: printf("Enter correct choice!!!\n");
	}
	return last;
}

void search(struct node *last){
	if(!last){
		printf("List is empty\n");
		return;
	}
	struct node *p=last->link;
	int item,pos=1;
	printf("Enter node info: ");
	scanf("%d",&item);
	do {
		if(p->info==item){
			printf("Element %d found at position %d\n",item,pos);
			return;
		}
		pos++;
		p=p->link;
	}while(p!=last->link);
	printf("Element %d not present in list\n",item);
}

struct node *reverse(struct node *last){
	if(!last){
		printf("List is empty\n");
		return last;
	}
	struct node *prev=last,*curr=last->link,*next;
	do {
		next=curr->link;
		curr->link=prev;
		prev=curr;
		curr=next;
	}while(prev!=last);
	last=curr;
	traverse(last);
	return last;
}

struct node *create(struct node *last){
	int num;
	printf("Enter no of elements in list: ");
	scanf("%d",&num);
	if(num<=0){
		printf("Invalid number!!!\n");
		return last;
	}
	last=insertBeg(last);
	for(int i=2;i<=num;i++)
		last=insertEnd(last);
	return last;
}

int main(){
	struct node *last=NULL;
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
			case 1: last=insert(last); break;
			case 2: last=create(last); break;
			case 3: last=delete(last); break;
			case 4: search(last); break;
			case 5: traverse(last); break;
			case 6: last=reverse(last); break;
			case 7: exit(1);
			default: printf("Enter correct choice!!!\n");
		}	
	}
	return 0;
}									
