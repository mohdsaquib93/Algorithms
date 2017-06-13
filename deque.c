#include <stdio.h>
#include <stdlib.h>
#define MAX 7
int deque_arr[MAX];
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

void push(){
	if(checkOverflow()){
		printf("Queue is full\n");
		return;
	}
	int data;
	printf("Enter data: ");
	scanf("%d",&data);
	if(front==-1)
		front=rear=0;
	else if(front==0)
		front=MAX-1;
	else --front;
	deque_arr[front]=data;
	printf("\n%d inserted at front\n\n",data);
}

void inject(){
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
	deque_arr[rear]=data;
	if(front==-1)
		front=0;
	printf("\n%d inserted at rear\n\n",data);
}

void pop(){
	checkUnderflow();
	printf("\n%d deleted\n\n",deque_arr[front]);
	if(front==rear)
		front=rear=-1;
	else {
		++front;
		if(front==MAX)
			front=0;
	}
}

void eject(){
	checkUnderflow();
	printf("\n%d deleted\n\n",deque_arr[rear]);
	if(rear==0)
		rear=MAX-1;
	else if(front==rear)
		front=rear=-1;
	else --rear;
}

void displayFrontRear(){
	printf("\nFront: %d\n",front);
	printf("\nRear: %d\n\n",rear);
}

void display(){
	checkUnderflow();
	if(rear>=front && rear<=MAX-1){
		for(int temp=front;temp<=rear;temp++)
			printf("%d ",deque_arr[temp]);
		printf("\n");
	}
	else {
		for(int temp=front;temp<=MAX-1;temp++)
			printf("%d ",deque_arr[temp]);
		for (int temp=0;temp<=rear;temp++)
			printf("%d ",deque_arr[temp]);
		printf("\n");
	}
}

int main(){
	int ch;
	while(1){
		printf("1. Insert at front\n");
		printf("2. Insert at rear\n");
		printf("3. Delete from front\n");
		printf("4. Delete from rear\n");
		printf("5. Display Front/Rear\n");
		printf("6. Display\n");
		printf("7. Exit\n\n");

		printf("Enter choice: ");
		scanf("%d",&ch);

		switch(ch){
			case 1: push(); break;
			case 2: inject(); break;
			case 3: pop(); break;
			case 4: eject(); break;
			case 5: displayFrontRear(); break;
			case 6: display(); break;
			case 7: exit(1);
			default: printf("Enter correct choice!!!\n");
		}
	}
	return 0;
}