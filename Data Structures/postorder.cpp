#include "Tree.h"
#include <stack>

void postOrder(Tree *t)
{
	if (!t)
		return;
	
	stack<Tree *> st;
	st.push(t);
	char ch;
	bool cnd = false;

	while (true) {
		while (t->left) {
			t = t->left;
			st.push(t);
		}

		if (!t->right)
			cnd = true;
		
		while (cnd) {
			ch = t->ch;
			st.pop();
			cout << ch << " ";

			if (st.empty())
				goto end;
			
			t = st.top();
			if (!t->right || t->right->ch == ch)
				cnd = true;
			else
				cnd = false;
		}

		t = t->right;
		st.push(t);
	}

	end: ;
}

int main()
{
	Tree *t = new Tree();
	t->populate(t);
	postOrder(t);
//	t->postorder(t);
	cout << endl;
	return 0;
}
