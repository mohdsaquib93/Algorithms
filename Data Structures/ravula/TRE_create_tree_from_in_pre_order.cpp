#include <bits/stdc++.h>

using namespace std;

struct Node {
    char data;
    Node *left;
    Node *right;
};

Node *createNode(char data)
{
    Node *node = new Node();
    node->data = data;
    node->left = node->right = nullptr;
    return node;
}

Node *createTreeFromInPre(string in, string pre, int inStart, int inEnd)
{
    if(inStart > inEnd)
        return nullptr;

    static int preIndex = 0;
    Node *node = createNode(pre.at(preIndex++));

    if(inStart == inEnd)
        return node;

    string::iterator itr = find(in.begin(), in.end(), node->data);
    int inIndex = itr - in.begin();
    node->left = createTreeFromInPre(in, pre, inStart, inIndex - 1);
    node->right = createTreeFromInPre(in, pre, inIndex + 1, inEnd);
    return node;
}

Node *createTreeFromInPost(string in, string post, int inStart, int inEnd)
{
    if(inStart > inEnd)
        return nullptr;

    static int postIndex = post.size() - 1;
    Node *node = createNode(post.at(postIndex--));

//    if(inStart == inEnd)
//        return node;

    string::iterator itr = find(in.begin(), in.end(), node->data);
    int inIndex = itr - in.begin();
    node->right = createTreeFromInPost(in, post, inIndex + 1, inEnd);
    node->left = createTreeFromInPost(in, post, inStart, inIndex - 1);
    return node;
}

void preorder(Node *t)
{
    if(t) {
        cout << t->data;
        preorder(t->left);
        preorder(t->right);
    }
}

void postorder(Node *t)
{
    if(t) {
        postorder(t->left);
        postorder(t->right);
        cout << t->data;
    }
}

int main()
{
    string in, post;
    cout << "Enter inorder: ";
    cin >> in;
    cout << "Enter postorder: ";
    cin >> post;

    Node *node = createTreeFromInPost(in, post, 0, in.size() - 1);
    preorder(node);
    return 0;
}
