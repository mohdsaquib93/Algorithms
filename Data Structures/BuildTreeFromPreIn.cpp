#include <iostream>
#include <algorithm>

using namespace std;

struct Node {
	char data;
	Node *left;
	Node *right;

	Node(int d): data(d), left(nullptr), right(nullptr) {}
};

Node *buildTree(string pre, string in, int inStart, int inEnd)
{
	if (inStart > inEnd)
		return nullptr;
	
	static int preIndex = 0;
	Node *node = new Node(pre.at(preIndex++));
	int rootIndex = find(in.begin(), in.end(), node->data) - in.begin();
	node->left = buildTree(pre, in, inStart, rootIndex - 1);
	node->right = buildTree(pre, in, rootIndex + 1, inEnd);
	return node;
}

void postorder(Node *t)
{
	if (t) {
		postorder(t->left);
		postorder(t->right);
		cout << t->data << " ";
	}
}

int main()
{
	string pre = "abdfecgh";
	string in = "fdbeacgh";
	Node *root = buildTree(pre, in, 0, in.length() - 1);
	postorder(root);
	cout << endl;
	return 0;
}
