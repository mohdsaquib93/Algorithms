#include "ArrayStack.h"

class SpecialStack: public ArrayStack {
	ArrayStack min_stack;

	public:
		void push(int item);
		void pop();
		int getMin();
};

void SpecialStack::push(int item) {
	if (isEmpty()) {
		ArrayStack::push(item);
		min_stack.push(item);
	}

	else {
		ArrayStack::push(item);
		if (item <= min_stack.top())
			min_stack.push(item);
	}
}

void SpecialStack::pop() {
	int item = ArrayStack::top();
	ArrayStack::pop();
	if (item == min_stack.top())
		min_stack.pop();
}

int SpecialStack::getMin() {
	return min_stack.top();
}



