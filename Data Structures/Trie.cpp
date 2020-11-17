#include <iostream>

using namespace std;

class Trie {
	public:
		static const int E = 26; 
		Trie *alphabet[E];
		bool isEOW;

		Trie() {
			for (int i = 0; i < E; ++i)
				alphabet[i] = nullptr;

			isEOW = false;
		}

		void insert(Trie *root, string word);
		bool search(Trie *root, string word);
		Trie *del(Trie *root, string word, int height);
};

void Trie::insert(Trie *root, string word)
{
	Trie *node = root;
	
	for (int i = 0; i < word.length(); ++i) {
		int index = word[i] - 'a';
		if (!node->alphabet[index])
			node->alphabet[index] = new Trie();
		node = node->alphabet[index];
	}

	node->isEOW = true;
}

bool Trie::search(Trie *root, string word)
{
	if (!root)
		return false;

	Trie *node = root;

	for (int i = 0; i < word.length(); ++i) {
		int index = word[i] - 'a';
		if (!node->alphabet[index])
			return false;
		node = node->alphabet[index];
	}
	
	return (node->isEOW);
}

bool hasNoChild(Trie *root)
{
	for(int i = 0; i < Trie::E; ++i)
		if (root->alphabet[i])
			return false;

	return true;
}

Trie *Trie::del(Trie *root, string word, int height = 0)
{
	if (!root)
		return root;
	
	if (height == word.length()) {
		root->isEOW = false;

		if (hasNoChild(root)) {
			delete root;
			root = nullptr;
		}
		return root;
	}

	int index = word[height] - 'a';
	root->alphabet[index] = del(root->alphabet[index], word, height + 1);

	if (hasNoChild(root) && !root->isEOW) {
		delete root;
		root = nullptr;
	}

	return root;
}

int main()
{
	string words[] = {"the", "their", "there", "start", "stop", "statue"};
	Trie *root = new Trie();
	for (string &i: words)
		root->insert(root, i);
	
	cout << (root->search(root, "statue") ? "Yes" : "No") << endl;
	cout << (root->search(root, "stops") ? "Yes" : "No") << endl;
	cout << (root->search(root, "sto") ? "Yes" : "No") << endl;
	cout << (root->search(root, "there") ? "Yes" : "No") << endl;

	root = root->del(root, "statue");
	cout << (root->search(root, "statue") ? "Yes" : "No") << endl;

	return 0;
}
