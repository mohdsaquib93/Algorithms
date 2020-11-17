#include <iostream>
#include "SpecialStack.h"

using namespace std;

int main() {
	SpecialStack s;
	s.push(3); 
    s.push(5); 
    cout << "Min: " << s.getMin() << endl; 
    s.push(2); 
    s.push(1); 
    cout << "Min: " << s.getMin() << endl;
    s.pop(); 
    cout << "Min: " << s.getMin() << endl;
    s.pop();
	return 0;
}
