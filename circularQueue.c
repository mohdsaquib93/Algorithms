#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int cir_queue_arr[MAX];
int front=-1;
int rear=-1;

int checkOverflow(){
	return front==(rear+1)%MAX?1:0;
}

void checkUnderflow(){
	if(front==-1){
		printf("Underflow\n");
		exit(1);
	}
}

void insert(){
	if(checkOverflow()){
		printf("Queue is full\n");
		return;
	}
	int data;
	printf("Enter data: ");
	scanf("%d",&data);
	++rear;
	if(rear==MAX)
		rear=0;
	cir_queue_arr[rear]=data;
	if(front==-1)
		front=0;
	printf("\n%d inserted\n\n",data);
}

void delete(){
	checkUnderflow();
	printf("\n%d deleted\n\n",cir_queue_arr[front]);
	if(front==rear)
		front=rear=-1;
	else {
		++front;
		if(front==MAX)
			front=0;
	}
}

void displayFront(){
	checkUnderflow();
	printf("\nElement at front is %d\n",cir_queue_arr[front]);
}

void display(){
	checkUnderflow();
	if(rear>=front && rear<=MAX-1){
		for(int temp=front;temp<=rear;temp++)
			printf("%d ",cir_queue_arr[temp]);
		printf("\n");
	}
	else {
		for(int temp=front;temp<=MAX-1;temp++)
			printf("%d ",cir_queue_arr[temp]);
		for (int temp=0;temp<=rear;temp++)
			printf("%d ",cir_queue_arr[temp]);
		printf("\n");
	}
}

void frontRear(){
	printf("Front: %d\n",front);
	printf("Rear: %d\n\n",rear);
}

int main(){
	int ch;
	while(1){
		printf("1. Insert\n");
		printf("2. Delete\n");
		printf("3. Print front and rear\n");
		printf("4. Display element at the front\n");
		printf("5. Display all elements\n");
		printf("6. Exit\n\n");

		printf("Enter choice: ");
		scanf("%d",&ch);

		switch(ch){
			case 1: insert(); break;
			case 2: delete(); break;
			case 3: frontRear(); break;
			case 4: displayFront(); break;
			case 5: display(); break;
			case 6: exit(1);
			default: printf("Enter correct choice!!!\n");
		}
	}
	return 0;
}
