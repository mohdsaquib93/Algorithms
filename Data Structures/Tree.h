#include <iostream>
using namespace std;
class Tree {
	public:
		char ch;
		Tree *left;
		Tree *right;
		Tree(): left(nullptr), right(nullptr) {}

		void populate(Tree *t);
		void postorder(Tree *t);
};

void Tree::populate(Tree *t)
{
	t->ch = 'a';
	Tree *b = new Tree();
	b->ch = 'b';
	t->left = b;
	Tree *c = new Tree();
	c->ch = 'c';
	t->right = c;
	Tree *d = new Tree();
	d->ch = 'd';
	b->left = d;
	Tree *e = new Tree();
	e->ch = 'e';
	b->right = e;
	Tree *f = new Tree();
	f->ch = 'f';
	e->right = f;
	Tree *g = new Tree();
	g->ch = 'g';
	c->right = g;
	Tree *h = new Tree();
	h->ch = 'h';
	g->left = h;
}

void Tree::postorder(Tree *t)
{
	if (t) {
		postorder(t->left);
		postorder(t->right);
		cout << t->ch << " ";
	}
}
