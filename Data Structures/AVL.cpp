#include <iostream>

using namespace std;

struct Node {
	int data;
	Node *left;
	Node *right;
	int height;
};

void preorder(Node *t)
{
	if (t) {
		cout << t->data << " ";
		preorder(t->left);
		preorder(t->right);
	}
}

int h(Node *t)
{
	return !t ? 0 : t->height;
}

Node *createNode(int data)
{
	Node *node = new Node();
	node->data = data;
	node->left = nullptr;
	node->right = nullptr;
	node->height = 1;
	return node;
}

Node *rightRotate(Node *y)
{
	Node *x = y->left;
	Node *T2 = x->right;

	x->right = y;
	y->left = T2;

	x->height = 1 + max(h(x->left), h(x->right));
	y->height = 1 + max(h(y->left), h(y->right));
	return x;
}

Node *leftRotate(Node *x)
{
	Node *y = x->right;
	Node *T2 = y->left;

	x->right = T2;
	y->left = x;

	x->height = 1 + max(h(x->left), h(x->right));
	y->height = 1 + max(h(y->left), h(y->right));
	return y;
}

int getBalance(Node *t)
{
	return h(t->left) - h(t->right);
}

Node *insertNode(Node *node, int key)
{
	if (!node)
		return createNode(key);
	
	if (key < node->data)
		node->left = insertNode(node->left, key);

	else if (key > node->data)
		node->right = insertNode(node->right, key);

	else
		return node;

	node->height = 1 + max(h(node->left), h(node->right));
	int balance = getBalance(node);
	
	if (balance > 1 && key < node->left->data)
		return rightRotate(node);
	
	if (balance < -1 && key > node->right->data)
		return leftRotate(node);

	if (balance > 1 && key > node->left->data) {
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}

	if (balance < -1 && key < node->right->data) {
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}

	return node;
}

Node *deleteNode(Node *root, int key)
{
	if (!root)
		return root;
	
	if (key < root->data)
		root->left = deleteNode(root->left, key);
	
	else if (key > root->data)
		root->right = deleteNode(root->right, key);
	
	else {
		Node *temp;
		if (!root->left || !root->right) {
			temp = root->left ? root->left : root->right;
			if (!temp) {
				temp = root;
				root = nullptr;
			}
			else
				*root = *temp;
			delete temp;
		}

		else {
			Node *succ = root->right;
			while (succ->left)
				succ = succ->left;

			root->data = succ->data;
			root->right = deleteNode(root->right, succ->data);
		}
	}
	
	if (!root)
		return root;
	
	root->height = 1 + max(h(root->left), h(root->right));
	int balance = getBalance(root);

	if (balance > 1 && getBalance(root->left) >= 0)
		return rightRotate(root);
	
	if (balance > 1 && getBalance(root->left) < 0) {
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}

	if (balance < -1 && getBalance(root->right) <= 0)
		return leftRotate(root);
	
	if (balance < -1 && getBalance(root->right) > 0) {
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}

	return root;
}

int main()
{
	Node *root = nullptr;
/*    root = insertNode(root, 10);
    root = insertNode(root, 20);
    root = insertNode(root, 30);
    root = insertNode(root, 40);
    root = insertNode(root, 50);
    root = insertNode(root, 25);
*/
	root = insertNode(root, 9);
    root = insertNode(root, 5);
    root = insertNode(root, 10);
    root = insertNode(root, 0);
    root = insertNode(root, 6);
    root = insertNode(root, 11);
    root = insertNode(root, -1);
    root = insertNode(root, 1);
    root = insertNode(root, 2);

	preorder(root);
	cout << endl;

	root = deleteNode(root, 10);
	preorder(root);
	cout << endl;
	return 0;
}
