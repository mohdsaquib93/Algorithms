#include <iostream>
#include <memory>

class ArrayStack
{
	const static int CAPACITY = 1024;
	int N;
	int t;
	std::unique_ptr<int[]> stack;

	public:
		ArrayStack(int N = CAPACITY) {
			this->N = N;
			stack = std::make_unique<int[]>(N);
			t = -1;
		}

		void push(int item);
		void pop();
		int top();
		int size();
		bool isEmpty();
		void print();
};

void ArrayStack::push(int item) {
	if (t == N - 1) {
		std::cout << "Stack is full" << std::endl;
		exit(1);
	}

	stack[++t] = item;
}

void ArrayStack::pop() {
	if (isEmpty()) {
		std::cout << "Stack is empty" << std::endl;
		exit(1);
	}

	t--;
}

int ArrayStack::top() {
	if (isEmpty()) {
		std::cout << "Stack is empty" << std::endl;
		exit(1);
	}

	return stack[t];
}

int ArrayStack::size() {
	return t + 1;
}

bool ArrayStack::isEmpty() {
	return t == -1;
}

void ArrayStack::print() {
	for(int i = 0; i <= t; ++i)
		std::cout << stack[i] << " ";

	std::cout << std::endl;
}

