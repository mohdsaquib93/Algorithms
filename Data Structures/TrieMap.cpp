#include <iostream>
#include <unordered_map>

using namespace std;

class Trie {
	public:
		bool isEOW;
		unordered_map<char, Trie*> child;
		
		Trie(): isEOW(false) {}

	void insert(Trie *root, string word);
	bool search(Trie *root, string word);
	Trie *del(Trie *root, string word, int h);
};

void Trie::insert(Trie *root, string word)
{
	Trie *node = root;
	
	for (int i = 0; i < word.length(); ++i) {
		char chr = word[i];
		
		if (node->child.find(chr) == node->child.end())
			node->child[chr] = new Trie();
		
		node = node->child[chr];
	}
	
	node->isEOW = true;
}

Trie *Trie::del(Trie *root, string word, int h = 0)
{
	if (!root)
		return root;
	
	if (h == word.length()) {
		root->isEOW = false;
		
		if (root->child.empty()) {
			delete root;
			root = nullptr;
		}

		return root;
	}

	char chr = word[h];
	
	if (root->child.find(chr) == root->child.end())
		return root;
	
	root->child[chr] = del(root->child[chr], word, h + 1);
	
	if (!root->child[chr])
		root->child.erase(chr);
	
	if (root->child.empty() && !root->isEOW) {
		delete root;
		root = nullptr;
	}

	return root;
}

bool Trie::search(Trie *root, string word)
{
	if (!root)
		return false;
	
	for (int i = 0; i < word.length(); ++i) {
		char chr = word[i];

		if (root->child.find(chr) == root->child.end())
			return false;
		
		root = root->child[chr];
	}

	return root->isEOW;
}

int main()
{
    string words[] = {"the", "their", "there", "start", "stop", "statue"};
    Trie *root = new Trie();
    for (string &i: words)
       root->insert(root, i);

    cout << (root->search(root, "statue") ? "Yes" : "No") << endl;
    cout << (root->search(root, "game") ? "Yes" : "No") << endl;
    cout << (root->search(root, "sto") ? "Yes" : "No") << endl;
    cout << (root->search(root, "there") ? "Yes" : "No") << endl;

	root = root->del(root, "there");
    cout << (root->search(root, "there") ? "Yes" : "No") << endl;
    cout << (root->search(root, "the") ? "Yes" : "No") << endl;

    return 0;
}


