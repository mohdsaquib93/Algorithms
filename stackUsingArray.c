#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int stack_arr[MAX];
int top=-1;

void checkUnderflow(){
	if(top==-1){
		printf("\nStack Underflow\n");
		exit(1);
	}
}

void push(){
	if(top==MAX-1){
		printf("\nStack Overflow\n\n");
		return;
	}
	int data;
	printf("Enter data: ");
	scanf("%d",&data);
	stack_arr[++top]=data;
	printf("\n%d inserted\n\n",data);
}

void pop(){
	checkUnderflow();
	printf("\n%d popped\n\n",stack_arr[top--]);
}

void displayTop(){
	checkUnderflow();
	printf("\nTop element is %d\n\n",stack_arr[top]);
}

void display(){
	checkUnderflow();
	for(int temp=top;temp!=-1;temp--)
		printf("%d ",stack_arr[temp]);
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