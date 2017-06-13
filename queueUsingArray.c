#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int queue_arr[MAX];
int rear=-1,front=-1;

void checkUnderflow(){
	if(front==-1 || front==rear+1){
		printf("Underflow\n\n");
		exit(1);
	}
}

void checkOverflow(){
	if(rear==MAX-1){
		printf("Overflow\n\n");
		exit(1);
	}
}

void enqueue(){
	checkOverflow();
	int data;
	printf("Enter data: ");
	scanf("%d",&data);
	queue_arr[++rear]=data;
	if(front==-1)
		front=0;
	printf("\n%d inserted\n\n",data);
}

void dequeue(){
	checkUnderflow();
	printf("\n%d popped\n\n",queue_arr[front++]);
}

void displayFront(){
	checkUnderflow();
	printf("\nFront element is %d\n\n",queue_arr[front]);
}

void display(){
	checkUnderflow();
	for(int temp=front;temp<=rear;temp++)
		printf("%d ",queue_arr[temp]);
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